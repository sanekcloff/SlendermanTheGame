// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemodes/SMGameStateBase.h"
#include "Interactables/SMInteractableNote.h"
#include "Kismet/GameplayStatics.h"

ASMGameStateBase::ASMGameStateBase()
{
}

int32 ASMGameStateBase::GetCollectedNotesAmount() const
{
	return CollectedNotesAmount;
}

void ASMGameStateBase::IncreaseCollectedNotesAmount()
{
	CollectedNotesAmount = FMath::Clamp(++CollectedNotesAmount, 0, InGameNotesAmount);
	if (IsAllNotesAreCollected())
		OnAllNotesCollected();
	else
		OnCollectedNotesIncreased();
}

int32 ASMGameStateBase::GetInGameNotesAmount() const
{
	return InGameNotesAmount;
}

void ASMGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	SetGameState(ESMGameState::InProgress);

	InGameNotesAmount = CalculateInGameNotes();
	GEngine->AddOnScreenDebugMessage(100,5.0f,FColor::Cyan,FString::Printf(TEXT("%d notes in world"),InGameNotesAmount));
}

void ASMGameStateBase::OnAllNotesCollected()
{
	GEngine->AddOnScreenDebugMessage(100, 5.0f, FColor::Cyan, FString::Printf(TEXT("Complete %d/%d collected"), CollectedNotesAmount, InGameNotesAmount));
}

void ASMGameStateBase::OnCollectedNotesIncreased()
{
	GEngine->AddOnScreenDebugMessage(100, 5.0f, FColor::Cyan, FString::Printf(TEXT("%d/%d collected"), CollectedNotesAmount, InGameNotesAmount));
}

int32 ASMGameStateBase::CalculateInGameNotes()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASMInteractableNote::StaticClass(), FoundActors);

	return FoundActors.Num();
}

bool ASMGameStateBase::IsAllNotesAreCollected()
{
	return CollectedNotesAmount == InGameNotesAmount;
}

void ASMGameStateBase::SetGameState(ESMGameState State)
{
	if (GameState == State) return;

	GameState = State;
	OnGameStateChanged.Broadcast(GameState);
}

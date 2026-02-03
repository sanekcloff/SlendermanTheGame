// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemodes/SMGameStateBase.h"
#include "Interactables/SMInteractableNote.h"
#include "Kismet/GameplayStatics.h"

ASMGameStateBase::ASMGameStateBase()
{
	GameState = ESMGameState::WaitingToStart;
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

// for debuging
void ASMGameStateBase::StartGame()
{
	SetGameState(ESMGameState::InProgress);
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetInputMode(FInputModeGameOnly());
		PC->bShowMouseCursor = false;
	}
}

void ASMGameStateBase::PauseGame()
{
	SetGameState(ESMGameState::Paused);
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetInputMode(FInputModeUIOnly());
		PC->bShowMouseCursor = true;
	}
}

void ASMGameStateBase::EndGame()
{
	SetGameState(ESMGameState::GameOver);
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetInputMode(FInputModeUIOnly());
		PC->bShowMouseCursor = true;
	}
}

void ASMGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	InGameNotesAmount = CalculateInGameNotes();
	GEngine->AddOnScreenDebugMessage(100, 5.0f, FColor::Cyan, FString::Printf(TEXT("%d notes in world"), InGameNotesAmount));
	StartGame();
}

void ASMGameStateBase::OnAllNotesCollected()
{
	GEngine->AddOnScreenDebugMessage(100, 5.0f, FColor::Cyan, FString::Printf(TEXT("Complete %d/%d collected"), CollectedNotesAmount, InGameNotesAmount));
	EndGame();
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

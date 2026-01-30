// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/SMInteractableNote.h"
#include "Kismet/GameplayStatics.h"
#include "Gamemodes/SMGameStateBase.h"

void ASMInteractableNote::Interact(ASMPlayerCharacter* Player)
{
	if (!Player || !IsValid(this)) return;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::MakeRandomColor(), TEXT("Interacted!"));
	UWorld* World = GetWorld();
	if (World)
	{
		if (ASMGameStateBase* GameState = Cast<ASMGameStateBase>(UGameplayStatics::GetGameState(World)))
		{
			GameState->IncreaseCollectedNotesAmount();
		}
		else
		{

			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::MakeRandomColor(), TEXT("Failed to get SMGameStateBase"));
		}
	}
	Destroy();
}

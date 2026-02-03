// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemodes/SMGameModeBase.h"
#include "Characters/SMPlayerCharacter.h"
#include "Gamemodes/SMGameStateBase.h"
#include "UI/SMPlayerHUD.h"


ASMGameModeBase::ASMGameModeBase()
{
	DefaultPawnClass = ASMPlayerCharacter::StaticClass();
	GameStateClass = ASMGameStateBase::StaticClass();
	HUDClass = ASMPlayerHUD::StaticClass();
}
void ASMGameModeBase::StartGame()
{
	GetSMGameStateBase()->SetGameState(ESMGameState::InProgress);
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetInputMode(FInputModeGameOnly());
		PC->bShowMouseCursor = false;
	}
}

//void ASMGameModeBase::PauseGame()
//{
//
//	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
//	{
//		PC->SetInputMode(FInputModeUIOnly());
//		PC->bShowMouseCursor = true;
//	}
//}

void ASMGameModeBase::EndGame()
{
	GetSMGameStateBase()->SetGameState(ESMGameState::GameOver);
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetInputMode(FInputModeUIOnly());
		PC->bShowMouseCursor = true;
	}
}

bool ASMGameModeBase::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
	const auto PauseSet = Super::SetPause(PC, CanUnpauseDelegate);
	if (PauseSet)
	{
		GetSMGameStateBase()->SetGameState(ESMGameState::Paused);
	}
	return PauseSet;
}

bool ASMGameModeBase::ClearPause()
{
	const auto PauseCleared = Super::ClearPause();
	if (PauseCleared)
	{
		GetSMGameStateBase()->SetGameState(ESMGameState::InProgress);
	}
	return PauseCleared;
}

ASMGameStateBase* ASMGameModeBase::GetSMGameStateBase() const
{
	return GetGameState<ASMGameStateBase>();
}

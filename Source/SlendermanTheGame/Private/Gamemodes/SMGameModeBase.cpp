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

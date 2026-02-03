// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemodes/SMMenuGameMode.h"
#include "UI/SMBaseWidget.h"
#include "UI/SMMenuHUD.h"

ASMMenuGameMode::ASMMenuGameMode()
{
	//bStartPlayersAsSpectators = false;
	HUDClass = ASMMenuHUD::StaticClass();
}

void ASMMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetInputMode(FInputModeUIOnly());
		PC->bShowMouseCursor = true;
	}
}

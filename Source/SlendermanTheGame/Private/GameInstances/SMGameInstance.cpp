// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstances/SMGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void USMGameInstance::LoadMainMenu()
{
    UGameplayStatics::OpenLevel(GetWorld(), MainMenuLevelName);
}

void USMGameInstance::LoadTestLevel()
{
    UGameplayStatics::OpenLevel(GetWorld(), TestLevelName);
}

void USMGameInstance::QuitGame()
{
    UKismetSystemLibrary::QuitGame(GetWorld(),GetWorld()->GetFirstPlayerController(),EQuitPreference::Quit,true);
}
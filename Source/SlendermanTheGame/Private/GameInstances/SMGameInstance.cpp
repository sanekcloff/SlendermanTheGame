// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstances/SMGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void USMGameInstance::LoadMainMenu()
{
    if (CurrentLevelName == MainMenuLevelName) return;
    CurrentLevelName = MainMenuLevelName;
    UGameplayStatics::OpenLevel(GetWorld(), MainMenuLevelName);
}

void USMGameInstance::LoadTestLevel()
{
    if (CurrentLevelName == MainMenuLevelName) return;
    CurrentLevelName = TestLevelName;
    UGameplayStatics::OpenLevel(GetWorld(), TestLevelName);
}

void USMGameInstance::LoadGameLevel()
{
    if (CurrentLevelName == MainMenuLevelName) return;
    CurrentLevelName = GameLevelName;
    UGameplayStatics::OpenLevel(GetWorld(), GameLevelName);
}

void USMGameInstance::QuitGame()
{
    if (CurrentLevelName == MainMenuLevelName) return;
    UKismetSystemLibrary::QuitGame(GetWorld(),GetWorld()->GetFirstPlayerController(),EQuitPreference::Quit,true);
}
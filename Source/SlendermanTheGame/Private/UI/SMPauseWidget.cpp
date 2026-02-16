// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMPauseWidget.h"
#include "Components/Button.h"
#include "GameInstances/SMGameInstance.h"
#include "Gamemodes/SMGameModeBase.h"

void USMPauseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ResumeButton) ResumeButton->OnClicked.AddDynamic(this, &USMPauseWidget::OnResumeButtonClicked);
	if (QuitButton) QuitButton->OnClicked.AddDynamic(this, &USMPauseWidget::OnQuitButtonClicked);
}
void USMPauseWidget::OnResumeButtonClicked()
{
	if (ASMGameModeBase* Gamemode = Cast<ASMGameModeBase>(GetWorld()->GetAuthGameMode())) Gamemode->ClearPause();
}

void USMPauseWidget::OnQuitButtonClicked()
{
	if (USMGameInstance* GameInst = GetSMGameInstance()) GameInst->QuitGame();
}

USMGameInstance* USMPauseWidget::GetSMGameInstance() const
{
	if (!GetWorld())
		return nullptr;

	return GetWorld()->GetGameInstance<USMGameInstance>();
}
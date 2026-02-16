// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMGameOverWidget.h"
#include "Components/Button.h"
#include "GameInstances/SMGameInstance.h"

void USMGameOverWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (RestartLevelButton) RestartLevelButton->OnClicked.AddDynamic(this, &USMGameOverWidget::OnRestartLevelButtonClicked);
	if (QuitButton) QuitButton->OnClicked.AddDynamic(this, &USMGameOverWidget::OnQuitButtonClicked);
	if (MainMenuLevelButton) MainMenuLevelButton->OnClicked.AddDynamic(this, &USMGameOverWidget::OnMainMenuLevelButtonClicked);
}

void USMGameOverWidget::OnRestartLevelButtonClicked()
{
	USMGameInstance* GameInst = GetSMGameInstance();
	if (GameInst)
	{
		if (GameInst->GetCurrentLevelName() == GameInst->GetTestLevelName()) 
		{
			if (GameInst && GameInst->GetTestLevelName().IsNone())
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Test level name is none!"));
				return;
			}
			GameInst->LoadTestLevel();
		}
		else
		{
			if (GameInst && GameInst->GetGameLevelName().IsNone())
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Game level name is none!"));
				return;
			}
			GameInst->LoadGameLevel();
		}
	}
}

void USMGameOverWidget::OnMainMenuLevelButtonClicked()
{
	USMGameInstance* GameInst = GetSMGameInstance();
	if (GameInst && GameInst->GetMainMenuLevelName().IsNone())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Main menu level name is none!"));
		return;
	}
	GameInst->LoadMainMenu();
}

void USMGameOverWidget::OnQuitButtonClicked()
{
	if (USMGameInstance* GameInst = GetSMGameInstance()) GameInst->QuitGame();
}

USMGameInstance* USMGameOverWidget::GetSMGameInstance() const
{
	if (!GetWorld())
		return nullptr;

	return GetWorld()->GetGameInstance<USMGameInstance>();
}

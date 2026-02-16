// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMMenuWidget.h"
#include "Components/Button.h"
#include "GameInstances/SMGameInstance.h"

void USMMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (TestLevelButton) TestLevelButton->OnClicked.AddDynamic(this, &USMMenuWidget::OnTestLevelButtonClicked);
	if (QuitButton) QuitButton->OnClicked.AddDynamic(this, &USMMenuWidget::OnQuitButtonClicked);
	if (GameLevelButton) GameLevelButton->OnClicked.AddDynamic(this, &USMMenuWidget::OnGameLevelButtonClicked);
}

void USMMenuWidget::OnTestLevelButtonClicked()
{
	USMGameInstance* GameInst = GetSMGameInstance();
	if (GameInst && GameInst->GetTestLevelName().IsNone())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Test level name is none!"));
		return;
	}
	GameInst->LoadTestLevel();
}

void USMMenuWidget::OnGameLevelButtonClicked()
{
	USMGameInstance* GameInst = GetSMGameInstance();
	if (GameInst && GameInst->GetGameLevelName().IsNone())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Game level name is none!"));
		return;
	}
	GameInst->LoadGameLevel();
}

void USMMenuWidget::OnQuitButtonClicked()
{
	if (USMGameInstance* GameInst = GetSMGameInstance()) GameInst->QuitGame();
}

USMGameInstance* USMMenuWidget::GetSMGameInstance() const
{
	if (!GetWorld())
		return nullptr;

	return GetWorld()->GetGameInstance<USMGameInstance>();
}

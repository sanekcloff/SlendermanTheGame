// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMMenuWidget.h"
#include "Components/Button.h"
#include "GameInstances/SMGameInstance.h"
#include "Kismet/GameplayStatics.h"

void USMMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (TestLevelButton) TestLevelButton->OnClicked.AddDynamic(this, &USMMenuWidget::OnTestLevelButtonClicked);
	if (QuitButton) QuitButton->OnClicked.AddDynamic(this, &USMMenuWidget::OnQuitButtonClicked);
}

void USMMenuWidget::OnTestLevelButtonClicked()
{
	const USMGameInstance* GameInst = GetSMGameInstance();
	if (GameInst && GameInst->GetTestLevelName().IsNone())
	{
		GEngine->AddOnScreenDebugMessage(301, 5.0f, FColor::Red, TEXT("Menu level name is none!"));
		return;
	}
	UGameplayStatics::OpenLevel(this, GameInst->GetTestLevelName());
}

void USMMenuWidget::OnQuitButtonClicked()
{
	USMGameInstance* GameInst = GetSMGameInstance();
	if (GameInst) GameInst->QuitGame();
}

USMGameInstance* USMMenuWidget::GetSMGameInstance() const
{
	if (!GetWorld())
		return nullptr;

	return GetWorld()->GetGameInstance<USMGameInstance>();
}

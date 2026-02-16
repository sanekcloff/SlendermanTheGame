// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/SMBaseWidget.h"
#include "SMGameOverWidget.generated.h"

class UButton;
class USMGameInstance;

UCLASS()
class SLENDERMANTHEGAME_API USMGameOverWidget : public USMBaseWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
	UButton* RestartLevelButton;

	UPROPERTY(meta = (BindWidget))
	UButton* MainMenuLevelButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

	virtual void NativeOnInitialized() override;

private:

	UFUNCTION()
	void OnRestartLevelButtonClicked();
	UFUNCTION()
	void OnMainMenuLevelButtonClicked();
	UFUNCTION()
	void OnQuitButtonClicked();

	USMGameInstance* GetSMGameInstance() const;

};

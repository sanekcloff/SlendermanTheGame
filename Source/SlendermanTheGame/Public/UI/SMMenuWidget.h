// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/SMBaseWidget.h"
#include "SMMenuWidget.generated.h"

class UButton;
class USMGameInstance;

UCLASS()
class SLENDERMANTHEGAME_API USMMenuWidget : public USMBaseWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
	UButton* TestLevelButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

	virtual void NativeOnInitialized() override;

private:

	UFUNCTION()
	void OnTestLevelButtonClicked();
	UFUNCTION()
	void OnQuitButtonClicked();

	USMGameInstance* GetSMGameInstance() const;
};

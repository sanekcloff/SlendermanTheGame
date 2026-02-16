// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/SMBaseWidget.h"
#include "SMPauseWidget.generated.h"

class UButton;
class USMGameInstance;

UCLASS()
class SLENDERMANTHEGAME_API USMPauseWidget : public USMBaseWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* ResumeButton;
	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnResumeButtonClicked();
	UFUNCTION()
	void OnQuitButtonClicked();

	USMGameInstance* GetSMGameInstance() const;
};

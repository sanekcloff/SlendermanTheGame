// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Gamemodes/SMGameStateBase.h"
#include "SMPlayerHUD.generated.h"

class USMBaseWidget;

UCLASS()
class SLENDERMANTHEGAME_API ASMPlayerHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void DrawHUD() override;

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PlayerHudWidgetClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> PauseWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> GameOverWidgetClass;

	virtual void BeginPlay() override;

private:

	UPROPERTY()
	TMap<ESMGameState, USMBaseWidget*> GameWidgets;
	UPROPERTY()
	USMBaseWidget* CurrentWidget = nullptr;

	void OnGameStateChanged(ESMGameState State);
};

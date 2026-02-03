// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/SMBaseWidget.h"
#include "Core/Types/RestorableUnit.h"
#include "SMPlayerHudWidget.generated.h"

class UProgressBar;
UCLASS()
class SLENDERMANTHEGAME_API USMPlayerHudWidget : public USMBaseWidget
{
	GENERATED_BODY()

public:

	USMPlayerHudWidget();

	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetStaminaPercent() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetMindPercent() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	bool IsStaminaEmpty() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetCollectedNotesValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetInGameNotesValue() const;

protected:

	UPROPERTY(meta = (BindWidget))
	UProgressBar* StaminaProgressBar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	float PercentColorThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	FLinearColor StaminaGoodColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	FLinearColor StaminaBadColor;
	
	virtual void NativeConstruct() override;

private:
	FRestorableUnit StaminaRestorableUnit;
	FRestorableUnit MindRestorableUnit;
	void UpdateStaminaProgressBar();
	UFUNCTION()
	void OnStaminaChanged(FRestorableUnit RestorableUnit);
	UFUNCTION()
	void OnMindChanged(FRestorableUnit RestorableUnit);
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/Switchables/SMSwitchableBase.h"
#include "SMSwitchableLamp.generated.h"

class UPointLightComponent;

UCLASS()
class SLENDERMANTHEGAME_API ASMSwitchableLamp : public ASMSwitchableBase
{
	GENERATED_BODY()

public:
	ASMSwitchableLamp();
protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lighting")
	UPointLightComponent* LightingSource;

	virtual void TurnOff() override;
	virtual void TurnOn() override;
private:
	void ChangeLightingSourceVisibility(bool bIsVisible);
};

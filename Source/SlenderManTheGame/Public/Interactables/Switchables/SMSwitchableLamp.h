// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/Switchables/SMSwitchableBase.h"
#include "SMSwitchableLamp.generated.h"

class ALight;

UCLASS()
class SLENDERMANTHEGAME_API ASMSwitchableLamp : public ASMSwitchableBase
{
	GENERATED_BODY()
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lighting")
	ALight* LightingSource;

	virtual void TurnOff() override;
	virtual void TurnOn() override;
private:
	// изменение свойств для источника света
};

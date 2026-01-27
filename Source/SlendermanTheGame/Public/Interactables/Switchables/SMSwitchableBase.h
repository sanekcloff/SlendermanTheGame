// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/SMInteractableBase.h"
#include "SMSwitchableBase.generated.h"


UCLASS(Abstract, BlueprintType, Blueprintable)
class SLENDERMANTHEGAME_API ASMSwitchableBase : public ASMInteractableBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	virtual void Interact(ASMPlayerCharacter* Player);
protected:
	virtual void TurnOff();
	virtual void TurnOn();
	bool IsTurnedOff = false;
};

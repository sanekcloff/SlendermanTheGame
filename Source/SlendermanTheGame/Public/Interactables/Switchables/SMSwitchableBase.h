// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/SMInteractableBase.h"
#include "SMSwitchableBase.generated.h"



class ASMInteractableSwitch;

UCLASS(Abstract, BlueprintType, Blueprintable)
class SLENDERMANTHEGAME_API ASMSwitchableBase : public ASMInteractableBase
{
	GENERATED_BODY()

public:
	virtual void Interact(ASMPlayerCharacter* Player);
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lighting")
	bool IsTurnedOff = false;

	virtual void BeginPlay() override;
	virtual void TurnOff();
	virtual void TurnOn();
private:
	ASMInteractableSwitch* Owner;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/SMInteractableBase.h"
#include "SMInteractableSwitch.generated.h"

UCLASS()
class SLENDERMANTHEGAME_API ASMInteractableSwitch : public ASMInteractableBase
{
	GENERATED_BODY()
public:
	void Interact(ASMPlayerCharacter* Player) override;

protected:
	// массив всех светильников
	virtual void BeginPlay() override;
};

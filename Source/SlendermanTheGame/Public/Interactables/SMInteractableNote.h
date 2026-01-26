// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/SMInteractableBase.h"
#include "SMInteractableNote.generated.h"

/**
 * 
 */
UCLASS()
class SLENDERMANTHEGAME_API ASMInteractableNote : public ASMInteractableBase
{
	GENERATED_BODY()
public:
	void Interact(ASMPlayerCharacter* Player) override;
};

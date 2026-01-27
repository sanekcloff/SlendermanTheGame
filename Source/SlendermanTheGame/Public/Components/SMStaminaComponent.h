// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SMRestorableStatComponentBase.h"
#include "SMStaminaComponent.generated.h"

/**
 * 
 */
UCLASS()
class SLENDERMANTHEGAME_API USMStaminaComponent : public USMRestorableStatComponentBase
{
	GENERATED_BODY()
public:
	USMStaminaComponent();
	virtual void BeginPlay() override;
private:
	void OnJumpStarted();
	void OnJumpStoped();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SMCharacterMovementComponent.generated.h"

UCLASS(Blueprintable,BlueprintType)
class SLENDERMANTHEGAME_API USMCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement",meta = (ClampMin = "1.1",ClampMax = "3.0"))
	float RunModifier = 1.2f;
	virtual float GetMaxSpeed()const override;
};

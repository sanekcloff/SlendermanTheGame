// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SMRestorableUnit.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FRestorableUnit
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MinValue = 0;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxValue = 0;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CurrentValue = MaxValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float UseValue = 4;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float UseRate = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bIsMustRestore = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bIsMustRestore"))
	float RestoreValue = 2;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bIsMustRestore"))
	float RestoreRate = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bIsMustRestore"))
	float RestoreDelay = 5;

	FRestorableUnit operator +(float Value);
	
	FRestorableUnit operator -(float Value);
	
	FRestorableUnit& operator +=(float Value);
	
	FRestorableUnit& operator -=(float Value);
	
};

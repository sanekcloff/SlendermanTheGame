// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RestorableUnit.generated.h"


USTRUCT(BlueprintType, Blueprintable)
struct SLENDERMANTHEGAME_API FRestorableUnit
{
	GENERATED_BODY()

	FRestorableUnit();
	FRestorableUnit(float Min,float Max,float Current);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MinValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CurrentValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float UseValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float UseRate;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FTimerHandle UsageTimerHandle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bIsMustRestore;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bIsMustRestore"))
	float RestoreValue;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bIsMustRestore"))
	float RestoreRate;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bIsMustRestore"))
	float RestoreDelay;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "bIsMustRestore"))
	FTimerHandle RestoreTimerHandle;
	bool IsCanUse() const;
	bool IsEmpty() const;
	bool IsFulled() const;

	FRestorableUnit operator +(float Value);
	FRestorableUnit operator +(const FRestorableUnit& Unit);

	FRestorableUnit operator -(float Value);
	FRestorableUnit operator -(const FRestorableUnit& Unit);

	FRestorableUnit& operator +=(float Value);
	FRestorableUnit& operator +=(const FRestorableUnit& Unit);

	FRestorableUnit& operator -=(float Value);
	FRestorableUnit& operator -=(const FRestorableUnit& Unit);

	bool operator == (const FRestorableUnit& Other) const;
	bool operator == (float Other) const;
	bool operator != (const FRestorableUnit& Other) const;
	bool operator != (float Other) const;

	FRestorableUnit& operator=(float NewCurrentValue);
	FRestorableUnit& operator=(const FRestorableUnit& Other);


};

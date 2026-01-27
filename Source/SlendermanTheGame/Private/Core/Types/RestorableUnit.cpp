// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Types/RestorableUnit.h"

FRestorableUnit::FRestorableUnit() :MinValue(0.0f), MaxValue(100.0f), CurrentValue(MaxValue), UseValue(0.5f),UseRate(0.25f), bIsMustRestore(true), RestoreValue(1), RestoreRate(0.5f),RestoreDelay(5.0f) { }

FRestorableUnit::FRestorableUnit(float Min, float Max, float Current) :MinValue(Min), MaxValue(Max), UseValue(0.5f),UseRate(0.25f), bIsMustRestore(true), RestoreValue(1), RestoreRate(0.5f),RestoreDelay(5.0f) 
{
	CurrentValue = FMath::Clamp(Current,Min,Max);
}

bool FRestorableUnit::IsCanUse() const
{
	return CurrentValue > MinValue && CurrentValue > UseValue;
}

bool FRestorableUnit::IsEmpty() const
{
	return CurrentValue == MinValue;
}

bool FRestorableUnit::IsFulled() const
{
	return CurrentValue == MaxValue;
}

FRestorableUnit FRestorableUnit::operator+(float Value)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue + Value, this->MinValue, this->MaxValue);
	return *this;
}

FRestorableUnit FRestorableUnit::operator+(const FRestorableUnit& Unit)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue+Unit.CurrentValue,this->MinValue,this->MaxValue);
	return *this;
}

FRestorableUnit FRestorableUnit::operator-(float Value)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue - Value, this->MinValue, this->MaxValue);
	return *this;
}

FRestorableUnit FRestorableUnit::operator-(const FRestorableUnit& Unit)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue - Unit.CurrentValue, this->MinValue, this->MaxValue);
	return *this;
}

FRestorableUnit& FRestorableUnit::operator+=(float Value)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue + Value, this->MinValue, this->MaxValue);
	return *this;
}

FRestorableUnit& FRestorableUnit::operator+=(const FRestorableUnit& Unit)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue + Unit.CurrentValue,this->MinValue,this->MaxValue);
	return *this;
}

FRestorableUnit& FRestorableUnit::operator-=(float Value)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue - Value, this->MinValue, this->MaxValue);
	return *this;
}

FRestorableUnit& FRestorableUnit::operator-=(const FRestorableUnit& Unit)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue + Unit.CurrentValue, this->MinValue, this->MaxValue);
	return *this;
}

bool FRestorableUnit::operator==(const FRestorableUnit& Other) const
{
	return FMath::IsNearlyEqual(MinValue,Other.MinValue,KINDA_SMALL_NUMBER) &&
		FMath::IsNearlyEqual(MaxValue, Other.MaxValue, KINDA_SMALL_NUMBER) &&
		FMath::IsNearlyEqual(CurrentValue, Other.CurrentValue, KINDA_SMALL_NUMBER) &&
		FMath::IsNearlyEqual(UseValue, Other.UseValue, KINDA_SMALL_NUMBER) &&
		FMath::IsNearlyEqual(UseRate, Other.UseRate, KINDA_SMALL_NUMBER) &&
		bIsMustRestore == Other.bIsMustRestore &&
		FMath::IsNearlyEqual(RestoreValue,Other.RestoreValue,KINDA_SMALL_NUMBER) &&
		FMath::IsNearlyEqual(RestoreRate, Other.RestoreRate, KINDA_SMALL_NUMBER) &&
		FMath::IsNearlyEqual(RestoreDelay, Other.RestoreDelay, KINDA_SMALL_NUMBER);
}

bool FRestorableUnit::operator==(float Other) const
{
	return CurrentValue == Other;
}

bool FRestorableUnit::operator!=(const FRestorableUnit& Other) const
{
	return !(*this == Other);
}

bool FRestorableUnit::operator!=(float Other) const
{
	return !(CurrentValue == Other);
}

FRestorableUnit& FRestorableUnit::operator=(const FRestorableUnit& Other)
{
	if (this != &Other)
	{
		MinValue = Other.MinValue;
		MaxValue = Other.MaxValue;
		CurrentValue = Other.CurrentValue;
		UseValue = Other.UseValue;
		UseRate = Other.UseRate;
		bIsMustRestore = Other.bIsMustRestore;
		RestoreValue = Other.RestoreValue;
		RestoreRate = Other.RestoreRate;
		RestoreDelay = Other.RestoreDelay;
	}
	return *this;
}

FRestorableUnit& FRestorableUnit::operator=(float NewCurrentValue)
{
	if (CurrentValue != NewCurrentValue)
	{
		CurrentValue = NewCurrentValue;
	}
	return *this;
}

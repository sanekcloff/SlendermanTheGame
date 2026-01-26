// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/SMRestorableUnit.h"

FRestorableUnit FRestorableUnit::operator+(float Value)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue + Value, this->MinValue, this->MaxValue);
	return *this;
}

FRestorableUnit FRestorableUnit::operator-(float Value)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue - Value, this->MinValue, this->MaxValue);
	return *this;
}

FRestorableUnit& FRestorableUnit::operator+=(float Value)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue + Value, this->MinValue, this->MaxValue);
	return *this;
}

FRestorableUnit& FRestorableUnit::operator-=(float Value)
{
	this->CurrentValue = FMath::Clamp(this->CurrentValue - Value, this->MinValue, this->MaxValue);
	return *this;
}


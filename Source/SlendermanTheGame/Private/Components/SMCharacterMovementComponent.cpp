// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SMCharacterMovementComponent.h"
#include "Characters/SMPlayerCharacter.h"

float USMCharacterMovementComponent::GetMaxSpeed() const
{
	const float MaxSpeed = Super::GetMaxSpeed();
	const ASMPlayerCharacter* Player = Cast<ASMPlayerCharacter>(GetPawnOwner());

	return Player && Player->IsMustRun() ? MaxSpeed * RunModifier : MaxSpeed;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Switchables/SMSwitchableBase.h"

void ASMSwitchableBase::Interact(ASMPlayerCharacter* Player)
{
	if (IsTurnedOff)
	{
		TurnOn();
	}
	else
	{
		TurnOff();
	}
}

void ASMSwitchableBase::TurnOff()
{
	IsTurnedOff = true;
}

void ASMSwitchableBase::TurnOn()
{
	IsTurnedOff = false;
}

void ASMSwitchableBase::BeginPlay()
{
	Super::BeginPlay();
	// проверить на наличие владельца
}

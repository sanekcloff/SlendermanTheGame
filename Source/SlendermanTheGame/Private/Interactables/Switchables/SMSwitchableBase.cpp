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
}

void ASMSwitchableBase::TurnOn()
{
}

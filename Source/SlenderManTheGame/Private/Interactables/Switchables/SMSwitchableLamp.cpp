// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Switchables/SMSwitchableLamp.h"
#include "Engine/Light.h"

void ASMSwitchableLamp::TurnOff()
{
	Super::TurnOff();
	// выключить свет
}

void ASMSwitchableLamp::TurnOn()
{
	Super::TurnOn();
	// включить свет
}

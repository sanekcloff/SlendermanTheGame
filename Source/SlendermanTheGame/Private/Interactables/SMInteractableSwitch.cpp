// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/SMInteractableSwitch.h"
#include "Interactables/Switchables/SMSwitchableBase.h"
#include "Engine/Engine.h"

ASMInteractableSwitch::ASMInteractableSwitch()
{
	bSwitchActivated = false;
}

void ASMInteractableSwitch::Interact(ASMPlayerCharacter* Player)
{
	Super::Interact(Player);
	bSwitchActivated = !bSwitchActivated;
	UpdateAllSwitchables();
}

bool ASMInteractableSwitch::IsSwitchActivated() const
{
	return bSwitchActivated;
}

void ASMInteractableSwitch::UpdateSwitchableStates()
{
	UpdateAllSwitchables();
}

void ASMInteractableSwitch::BeginPlay()
{
	Super::BeginPlay();

	for (auto SwitchableObject : SwitchableObjects)
	{
		if (IsValid(SwitchableObject))
		{
			SwitchableObject->SetSwitchOwner(this);
			if (bSwitchActivated)
			{
				SwitchableObject->TurnOn();
			}
			else
			{
				SwitchableObject->TurnOff();
			}
		}
	}
}

#if WITH_EDITOR
void ASMInteractableSwitch::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName = (PropertyChangedEvent.Property != nullptr)
		? PropertyChangedEvent.Property->GetFName()
		: NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(ASMInteractableSwitch, bSwitchActivated)
|| PropertyName == GET_MEMBER_NAME_CHECKED(ASMInteractableSwitch, SwitchableObjects))
	{
		SyncStateInEditor();
	}
}

void ASMInteractableSwitch::SyncStateInEditor()
{
	if (GIsEditor && !IsRunningGame())
	{
		for (auto SwitchableObject : SwitchableObjects)
		{
			if (IsValid(SwitchableObject))
			{
				SwitchableObject->SetSwitchOwner(this);

				if (bSwitchActivated)
				{
					SwitchableObject->TurnOn();
				}
				else
				{
					SwitchableObject->TurnOff();
				}
			}
		}

		MarkComponentsRenderStateDirty();

		RerunConstructionScripts();
	}
}
#endif

void ASMInteractableSwitch::UpdateAllSwitchables()
{
	for (auto SwitchableObject : SwitchableObjects)
	{
		if (IsValid(SwitchableObject))
		{
			if (bSwitchActivated)
			{
				SwitchableObject->TurnOn();
			}
			else
			{
				SwitchableObject->TurnOff();
			}
		}
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Switchables/SMSwitchableBase.h"
#include "Interactables/SMInteractableSwitch.h"

#if WITH_EDITOR
#include "Editor.h"
#endif

ASMSwitchableBase::ASMSwitchableBase()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(GetRootComponent());

	SwitchOwner = nullptr;
	bIsActivated = false;
}

ASMInteractableSwitch* ASMSwitchableBase::GetSwitchOwner() const
{
	return SwitchOwner;
}

void ASMSwitchableBase::SetSwitchOwner(ASMInteractableSwitch* Value)
{
	if (SwitchOwner != Value)
	{
		SwitchOwner = Value;

		if (SwitchOwner)
		{
			SetOwner(SwitchOwner);

			SwitchOwner->IsSwitchActivated() ? TurnOn() : TurnOff();
		}
	}
	
}

void ASMSwitchableBase::TurnOff()
{
	bIsActivated = false;
	OnTurnedOff();
}

void ASMSwitchableBase::TurnOn()
{
	bIsActivated = true;
	OnTurnedOn();
}

#if WITH_EDITOR
void ASMSwitchableBase::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	MarkComponentsRenderStateDirty();
}
#endif

void ASMSwitchableBase::BeginPlay()
{
	Super::BeginPlay();
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Switchables/SMSwitchableLamp.h"
#include "Components/PointLightComponent.h"

#if WITH_EDITOR
#include "Editor/UnrealEdEngine.h"
#endif

ASMSwitchableLamp::ASMSwitchableLamp()
{
	LightingSource = CreateDefaultSubobject<UPointLightComponent>("LightSource");
	LightingSource->SetupAttachment(StaticMesh);

	LightingSource->SetIntensity(1000.0f);
	LightingSource->SetLightColor(FLinearColor::White);
	LightingSource->SetAttenuationRadius(500.0f);
	LightingSource->SetVisibility(true);
}

void ASMSwitchableLamp::TurnOff()
{
	Super::TurnOff();
	ChangeLightingSourceVisibility(false);
#if WITH_EDITOR
	if (GEditor && !GEditor->IsPlaySessionInProgress())
	{
		LightingSource->MarkRenderStateDirty();
	}
#endif

}

void ASMSwitchableLamp::TurnOn()
{
	Super::TurnOn();
	ChangeLightingSourceVisibility(true);
#if WITH_EDITOR
	if (GEditor && !GEditor->IsPlaySessionInProgress())
	{
		LightingSource->MarkRenderStateDirty();
	}
#endif
}

void ASMSwitchableLamp::ChangeLightingSourceVisibility(bool bIsVisible)
{
	if (LightingSource)
	{
		LightingSource->SetVisibility(bIsVisible);

#if WITH_EDITOR

		if (GIsEditor && !GIsPlayInEditorWorld)
		{
			LightingSource->MarkRenderStateDirty();

			if (GEngine)
			{
				GEngine->ForceGarbageCollection(true);
			}
		}
#endif
	}
}

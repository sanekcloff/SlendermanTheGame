// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SMStaminaComponent.h"
#include "Characters/SMPlayerCharacter.h"

USMStaminaComponent::USMStaminaComponent()
{
}

void USMStaminaComponent::BeginPlay()
{
	Super::BeginPlay();

	if (ASMPlayerCharacter* PlayerCharacter = Cast<ASMPlayerCharacter>(GetOwner()))
	{
		GEngine->AddOnScreenDebugMessage(2, 3.0f, FColor::Emerald, FString::Printf(TEXT("On jump binded to %s"),*PlayerCharacter->GetName()));
		PlayerCharacter->OnJumpStarted.AddDynamic(this, &USMStaminaComponent::OnJumpStarted);
		PlayerCharacter->OnJumpStoped.AddDynamic(this, &USMStaminaComponent::OnJumpStoped);

		if (!PlayerCharacter->OnJumpStarted.IsBound())
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow,
				TEXT("StaminaComponent: Binding to OnJumpStarted"));
		}
	}
}

void USMStaminaComponent::OnJumpStarted()
{
	if (bIsUsingResource)
	{
		GEngine->AddOnScreenDebugMessage(2, 3.0f, FColor::Emerald, TEXT("On jump called!"));
		StopUsingResource();
	}
}

void USMStaminaComponent::OnJumpStoped()
{

}
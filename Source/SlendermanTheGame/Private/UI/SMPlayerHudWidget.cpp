// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMPlayerHudWidget.h"
#include "Characters/SMPlayerCharacter.h"
#include "Components/SMStaminaComponent.h"
#include "Gamemodes/SMGameStateBase.h"
#include "Components/ProgressBar.h"

USMPlayerHudWidget::USMPlayerHudWidget()
{
	StaminaGoodColor = FLinearColor::Yellow;
	StaminaBadColor = FLinearColor::Red;
	PercentColorThreshold = 0.3f;
	if (StaminaProgressBar)
		StaminaProgressBar->SetFillColorAndOpacity(StaminaGoodColor);
}

float USMPlayerHudWidget::GetStaminaPercent() const
{
	return StaminaRestorableUnit.CurrentValue / StaminaRestorableUnit.MaxValue;
}

float USMPlayerHudWidget::GetMindPercent() const
{
	return MindRestorableUnit.CurrentValue / MindRestorableUnit.MaxValue;
}

bool USMPlayerHudWidget::IsStaminaEmpty() const
{
	if (const ASMPlayerCharacter* PlayerCharacter = Cast<ASMPlayerCharacter>(GetOwningPlayerPawn()))
	{
		const USMStaminaComponent* StaminaCompoent = PlayerCharacter->GetStaminaComponent();
		return !StaminaCompoent->CanBeUsed();
	}
	return true;
}

int32 USMPlayerHudWidget::GetCollectedNotesValue() const
{
	if (const ASMGameStateBase* CurrentGameState = Cast<ASMGameStateBase>(GetWorld()->GetGameState()))
	{
		return CurrentGameState->GetCollectedNotesAmount();
	}
	return 0;
}

int32 USMPlayerHudWidget::GetInGameNotesValue() const
{
	if (const ASMGameStateBase* CurrentGameState = Cast<ASMGameStateBase>(GetWorld()->GetGameState()))
	{
		return CurrentGameState->GetInGameNotesAmount();
	}
	return 0;
}

void USMPlayerHudWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (const ASMPlayerCharacter* PlayerCharacter = Cast<ASMPlayerCharacter>(GetOwningPlayerPawn()))
	{
		USMStaminaComponent* StaminaComponent = PlayerCharacter->GetStaminaComponent();
		StaminaComponent->OnValueChanged.AddUniqueDynamic(this, &USMPlayerHudWidget::OnStaminaChanged);
	}
}

void USMPlayerHudWidget::UpdateStaminaProgressBar()
{
	if (StaminaProgressBar)
	{
		StaminaProgressBar->SetFillColorAndOpacity(GetStaminaPercent() > PercentColorThreshold ? StaminaGoodColor : StaminaBadColor);
	}
}

void USMPlayerHudWidget::OnStaminaChanged(FRestorableUnit RestorableUnit)
{
	StaminaRestorableUnit = RestorableUnit;
	UpdateStaminaProgressBar();
}

void USMPlayerHudWidget::OnMindChanged(FRestorableUnit RestorableUnit)
{
	MindRestorableUnit = RestorableUnit;
}

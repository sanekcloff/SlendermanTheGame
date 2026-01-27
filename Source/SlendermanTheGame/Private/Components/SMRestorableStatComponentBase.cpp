#include "Components/SMRestorableStatComponentBase.h"

USMRestorableStatComponentBase::USMRestorableStatComponentBase()
{
	PrimaryComponentTick.bCanEverTick = false;
	RestorableUnit = FRestorableUnit(0, 100, 100);
}

void USMRestorableStatComponentBase::BeginPlay()
{
	Super::BeginPlay();
}

void USMRestorableStatComponentBase::Spend()
{
	RestorableUnit -= RestorableUnit.UseValue;
	OnValueChanged.Broadcast(RestorableUnit);
	if (!RestorableUnit.IsFulled())
	{
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Yellow, FString::Printf(TEXT("%s spended %f/%f"), *GetClass()->GetName(), RestorableUnit.CurrentValue, RestorableUnit.MaxValue));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Yellow, FString::Printf(TEXT("%s no resource %f/%f"), *GetClass()->GetName(), RestorableUnit.CurrentValue, RestorableUnit.MaxValue));
	}
}

void USMRestorableStatComponentBase::Restore()
{
	RestorableUnit += RestorableUnit.RestoreValue;
	OnValueChanged.Broadcast(RestorableUnit);
	if (RestorableUnit.IsFulled())
	{
		StopRestoringResource();
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Yellow, FString::Printf(TEXT("%s resource restored %f/%f"), *GetClass()->GetName(), RestorableUnit.CurrentValue, RestorableUnit.MaxValue));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Yellow, FString::Printf(TEXT("%s restoring %f/%f"), *GetClass()->GetName(), RestorableUnit.CurrentValue, RestorableUnit.MaxValue));
	}
}

void USMRestorableStatComponentBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USMRestorableStatComponentBase::StartUsingResource()
{
	bIsUsingResource = true;

	if (GetWorld()->GetTimerManager().IsTimerActive(RestorableUnit.RestoreTimerHandle) || GetWorld()->GetTimerManager().TimerExists(RestorableUnit.RestoreTimerHandle))
	{
		StopRestoringResource();
	}

	if (RestorableUnit.IsCanUse())
	{
		GetWorld()->GetTimerManager().SetTimer(RestorableUnit.UsageTimerHandle, this, &USMRestorableStatComponentBase::Spend, RestorableUnit.UseRate, true, 0);
	}
}

void USMRestorableStatComponentBase::StopUsingResource()
{
	bIsUsingResource = false;
	GetWorld()->GetTimerManager().ClearTimer(RestorableUnit.UsageTimerHandle);
	if (RestorableUnit.bIsMustRestore)
		StartRestoringResource();
}

void USMRestorableStatComponentBase::StartRestoringResource()
{
	GetWorld()->GetTimerManager().SetTimer(RestorableUnit.RestoreTimerHandle, this, &USMRestorableStatComponentBase::Restore, RestorableUnit.RestoreRate, true, RestorableUnit.RestoreDelay);
}

void USMRestorableStatComponentBase::StopRestoringResource()
{
	GetWorld()->GetTimerManager().ClearTimer(RestorableUnit.RestoreTimerHandle);
}

bool USMRestorableStatComponentBase::CanBeUsed() const
{
	return RestorableUnit.IsCanUse();
}

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RestorableUnit.h"
#include "SMRestorableStatComponentBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValueChanged, FRestorableUnit, NewValue); // Called if value could be changed
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnitValueEmpty); // Called if unit value equals to min


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Abstract, BlueprintType, Blueprintable)
class SLENDERMANTHEGAME_API USMRestorableStatComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "Restorable|Events")
	FOnValueChanged OnValueChanged;

	UPROPERTY(BlueprintAssignable, Category = "Restorable|Events")
	FOnUnitValueEmpty OnUnitValueEmpty;

	USMRestorableStatComponentBase();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Restorable")
	void StartUsingResource();

	UFUNCTION(BlueprintCallable, Category = "Restorable")
	void StopUsingResource();

	UFUNCTION(BlueprintCallable, Category = "Restorable")
	bool CanBeUsed() const;

	UFUNCTION(BlueprintCallable, Category = "Restorable")
	float GetMaxValue() const { return RestorableUnit.MaxValue; };
	UFUNCTION(BlueprintCallable, Category = "Restorable")
	float GetMinValue() const { return RestorableUnit.MinValue; };
	UFUNCTION(BlueprintCallable, Category = "Restorable")
	float GetCurrentValue() const { return RestorableUnit.CurrentValue; };

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Restorable|Settings")
	FRestorableUnit RestorableUnit;

	UPROPERTY(BlueprintReadOnly, Category = "Restorable|State")
	bool bIsUsingResource;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Restorable")
	void StartRestoringResource();

	UFUNCTION(BlueprintCallable, Category = "Restorable")
	void StopRestoringResource();

private:
	void Spend();
	void Restore();
};

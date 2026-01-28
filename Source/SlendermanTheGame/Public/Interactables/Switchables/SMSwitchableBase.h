// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMSwitchableBase.generated.h"

class ASMInteractableSwitch;
class UStaticMeshComponent;

UCLASS(Abstract, BlueprintType, Blueprintable)
class SLENDERMANTHEGAME_API ASMSwitchableBase : public AActor
{
	GENERATED_BODY()

public:
	ASMSwitchableBase();
	
	UFUNCTION(BlueprintCallable, Category = "Switchable|Owner")
	ASMInteractableSwitch* GetSwitchOwner() const;

	UFUNCTION(BlueprintCallable, Category = "Switchable|Owner")
	void SetSwitchOwner(ASMInteractableSwitch* Value);

	UFUNCTION(BlueprintCallable, Category = "Switchable")
	bool IsActivated() const { return bIsActivated; }

	virtual void TurnOff();
	virtual void TurnOn();

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Switchable")
	bool bIsActivated;

	virtual void BeginPlay() override;
	
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Switchable")
	void OnTurnedOn();

	UFUNCTION(BlueprintImplementableEvent, Category = "Switchable")
	void OnTurnedOff();

private:
	ASMInteractableSwitch* SwitchOwner;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/SMInteractableBase.h"
#include "SMInteractableSwitch.generated.h"

class ASMSwitchableBase;

UCLASS()
class SLENDERMANTHEGAME_API ASMInteractableSwitch : public ASMInteractableBase
{
	GENERATED_BODY()
public:

	ASMInteractableSwitch();
	virtual void Interact(ASMPlayerCharacter* Player) override;

	UFUNCTION(BlueprintCallable, Category = "SwitchControls")
	bool IsSwitchActivated() const;

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "SwitchControls")
	void UpdateSwitchableStates();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ControlledSwitchableSources",
		meta = (DisplayName = "Switchable Objects"))
	TArray<ASMSwitchableBase*> SwitchableObjects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ControlledSwitchableSources",
		meta = (DisplayName = "Switch Activated"))
	bool bSwitchActivated;

	virtual void BeginPlay() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	void UpdateAllSwitchables();
	void SyncStateInEditor();
};

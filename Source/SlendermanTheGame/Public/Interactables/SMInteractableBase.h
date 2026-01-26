// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMInteractableBase.generated.h"

class ASMPlayerCharacter;
class UStaticMeshComponent;

UCLASS(Abstract, Blueprintable)
class SLENDERMANTHEGAME_API ASMInteractableBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ASMInteractableBase();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	virtual void Interact(ASMPlayerCharacter* Player);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* StaticMesh;

	virtual void BeginPlay() override;

};

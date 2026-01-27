// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SMPlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class USMRestorableStatComponentBase;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnJumpStarted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnJumpStoped);

UCLASS()
class SLENDERMANTHEGAME_API ASMPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Character|Jump")
	FOnJumpStarted OnJumpStarted;

	UPROPERTY(BlueprintAssignable, Category = "Character|Jump")
	FOnJumpStoped OnJumpStoped;

	ASMPlayerCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USMRestorableStatComponentBase* StaminaComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USMRestorableStatComponentBase* MindComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Actions")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Actions")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Actions")
	UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Actions")
	UInputAction* InteractAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Actions")
	UInputAction* RunAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interaction")
	float InteractDistance = 300.0f;

	virtual void BeginPlay() override;
	virtual void Jump() override;
	virtual void StopJumping() override;

private:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Interact();
	void StartRun();
	void StopRun();
	void LoseMind();
	void RegainMind();

};

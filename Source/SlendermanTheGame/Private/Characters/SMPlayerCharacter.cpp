// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SMPlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"
#include "Interactables/SMInteractableBase.h"
#include "Components/SMStaminaComponent.h"
#include "Components/SMMindComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Gamemodes/SMGameModeBase.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ASMPlayerCharacter::ASMPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SocketOffset = FVector(0.0f, 0.0f, 50.0f);
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->bEnableCameraRotationLag = true;
	SpringArmComponent->CameraLagSpeed = 10.0f;
	SpringArmComponent->TargetArmLength = 0.0f;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;

	StaminaComponent = CreateDefaultSubobject<USMStaminaComponent>("StaminaComponent");
	MindComponent = CreateDefaultSubobject<USMMindComponent>("MindComponent");

}

// Called when the game starts or when spawned
void ASMPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASMPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASMPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (!InputMapping) return;
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (!JumpAction) return;
		Input->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		Input->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		Input->BindAction(RunAction, ETriggerEvent::Started, this, &ASMPlayerCharacter::StartRun);
		Input->BindAction(RunAction, ETriggerEvent::Completed, this, &ASMPlayerCharacter::StopRun);
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASMPlayerCharacter::Move);
		Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASMPlayerCharacter::Look);
		Input->BindAction(InteractAction, ETriggerEvent::Started, this, &ASMPlayerCharacter::Interact);
		Input->BindAction(PauseAction, ETriggerEvent::Started, this, &ASMPlayerCharacter::TogglePause);
	}
}

void ASMPlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2D Vector = Value.Get<FVector2D>();
	if (Controller)
	{
		AddMovementInput(GetActorForwardVector(), Vector.Y);
		AddMovementInput(GetActorRightVector(), Vector.X);
	}
}

void ASMPlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D Vector = Value.Get<FVector2D>();
	if (Controller)
	{
		AddControllerYawInput(Vector.X);
		AddControllerPitchInput(Vector.Y);
	}
}

void ASMPlayerCharacter::Interact()
{
	if (!CameraComponent) return;
	FHitResult HitResult;
	FVector Start = CameraComponent->GetComponentLocation();
	FVector End = Start + (CameraComponent->GetForwardVector() * InteractDistance);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	QueryParams.bTraceComplex = true;

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility, QueryParams);
#if WITH_EDITOR
	DrawDebugLine(GetWorld(), Start, End, bHit ? FColor::Green : FColor::Red, false, 2.0f, 0, 1.0f);
	if (bHit)
	{
		DrawDebugSphere(GetWorld(), HitResult.Location, 10.0f, 8, FColor::Blue, false, 2.0f);
	}
#endif 
	if (bHit)
	{
		if (ASMInteractableBase* InteractableObject = Cast<ASMInteractableBase>(HitResult.GetActor()))
		{
				InteractableObject->Interact(this);
		}
	}
}

void ASMPlayerCharacter::StartRun()
{
	if (!StaminaComponent && !StaminaComponent->CanBeUsed()) return;
	if (GetCharacterMovement()->IsFalling()) return;
	StaminaComponent->StartUsingResource();
	bWantsToRun = true;
}

void ASMPlayerCharacter::StopRun()
{
	if (StaminaComponent)
		StaminaComponent->StopUsingResource();
	bWantsToRun = false;
}

void ASMPlayerCharacter::LoseMind()
{
	if (MindComponent)
		MindComponent->StartUsingResource();
}

void ASMPlayerCharacter::RegainMind()
{
	if (MindComponent)
		MindComponent->StopUsingResource();
}

void ASMPlayerCharacter::TogglePause()
{
	if (!GetWorld()) return;

	if (UGameplayStatics::IsGamePaused(GetWorld()))
	{
		if (ASMGameModeBase* CurrentGameMode = Cast<ASMGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			CurrentGameMode->ClearPause();
		}
	}
	else
	{
		if (ASMGameModeBase* CurrentGameMode = Cast<ASMGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			CurrentGameMode->SetPause(Cast<APlayerController>(GetController()));
		}
	}
	
}


bool ASMPlayerCharacter::IsMustRun() const
{
	return StaminaComponent->CanBeUsed() && bWantsToRun;
}
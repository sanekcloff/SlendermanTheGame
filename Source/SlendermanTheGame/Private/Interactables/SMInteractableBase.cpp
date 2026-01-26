#include "Interactables/SMInteractableBase.h"

ASMInteractableBase::ASMInteractableBase()
{
	PrimaryActorTick.bCanEverTick = false;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(GetRootComponent());
}

void ASMInteractableBase::Interact(ASMPlayerCharacter* Player)
{
	return;
}

void ASMInteractableBase::BeginPlay()
{
	Super::BeginPlay();
	if (!GEngine) return;
	GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::MakeRandomColor(),FString::Printf(TEXT("%s spawned in world"),*this->GetName()));
}



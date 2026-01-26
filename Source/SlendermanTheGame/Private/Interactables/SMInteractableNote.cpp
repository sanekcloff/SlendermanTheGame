// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/SMInteractableNote.h"

void ASMInteractableNote::Interact(ASMPlayerCharacter* Player)
{
	if (!Player || !IsValid(this)) return;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::MakeRandomColor(), TEXT("Interacted!"));
	Destroy();
}

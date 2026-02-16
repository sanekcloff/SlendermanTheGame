// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SMGameStateBase.generated.h"

UENUM()
enum class ESMGameState
{
	WaitingToStart=0,
	InProgress,
	Paused,
	GameOver,
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnGameStateChangedSignature, ESMGameState)

UCLASS()
class SLENDERMANTHEGAME_API ASMGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:

	FOnGameStateChangedSignature OnGameStateChanged;

	ASMGameStateBase();

	UFUNCTION(BlueprintCallable, Category = "GameSession|Notes")
	int32 GetCollectedNotesAmount() const;

	UFUNCTION(BlueprintCallable, Category = "GameSession|Notes")
	void IncreaseCollectedNotesAmount();

	UFUNCTION(BlueprintCallable, Category = "GameSession|Notes")
	int32 GetInGameNotesAmount() const;

	UFUNCTION(BlueprintCallable, Category = "GameSession|State")
	void SetGameState(ESMGameState State);

	UFUNCTION(BlueprintCallable, Category = "GameSession|State")
	ESMGameState GetSMGameState() const;
	

protected:

	virtual void BeginPlay() override;

	void OnAllNotesCollected();
	void OnCollectedNotesIncreased();

private:
	ESMGameState GameState;
	int32 CollectedNotesAmount;
	int32 InGameNotesAmount;

	int32 CalculateInGameNotes();
	bool IsAllNotesAreCollected();

};

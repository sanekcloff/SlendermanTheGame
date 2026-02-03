// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SMGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SLENDERMANTHEGAME_API ASMGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASMGameModeBase();
	UFUNCTION(BlueprintCallable, Category = "GameSession|State")
	void StartGame();
	UFUNCTION(BlueprintCallable, Category = "GameSession|State")
	void EndGame();

	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;

	virtual bool ClearPause() override;
private:
	UFUNCTION()
	ASMGameStateBase* GetSMGameStateBase() const;
};

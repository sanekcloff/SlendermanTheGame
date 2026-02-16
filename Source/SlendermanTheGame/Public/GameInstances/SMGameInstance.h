// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SMGameInstance.generated.h"


UCLASS()
class SLENDERMANTHEGAME_API USMGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="Menu")
	void LoadMainMenu();

	UFUNCTION(BlueprintCallable, Category="Menu")
	void LoadTestLevel();

	UFUNCTION(BlueprintCallable, Category="Menu")
	void LoadGameLevel();

	UFUNCTION(BlueprintCallable, Category="Menu")
	void QuitGame();

	UFUNCTION(BlueprintCallable, Category="Menu")
	FName GetTestLevelName() const { return TestLevelName; }

	UFUNCTION(BlueprintCallable, Category = "Menu")
	FName GetMainMenuLevelName() const { return MainMenuLevelName; }

	UFUNCTION(BlueprintCallable, Category = "Menu")
	FName GetGameLevelName() const { return GameLevelName; }
	UFUNCTION(BlueprintCallable, Category = "Menu")
	FName GetCurrentLevelName() const { return CurrentLevelName; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Levels")
	FName TestLevelName;

	UPROPERTY(EditDefaultsOnly, Category = "Levels")
	FName MainMenuLevelName;

	UPROPERTY(EditDefaultsOnly, Category = "Levels")
	FName GameLevelName;

private:
	//FName StartupLevelName;
	FName CurrentLevelName;
};

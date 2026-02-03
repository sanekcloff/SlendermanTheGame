// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SMMenuGameMode.generated.h"

class USMBaseWidget;

UCLASS()
class SLENDERMANTHEGAME_API ASMMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASMMenuGameMode();
protected:
	virtual void BeginPlay() override;
};

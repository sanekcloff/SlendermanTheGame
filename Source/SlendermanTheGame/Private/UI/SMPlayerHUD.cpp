// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMPlayerHUD.h"
#include "Gamemodes/SMGameStateBase.h"
#include "UI/SMBaseWidget.h"
#include "Gamemodes/SMGameModeBase.h"

void ASMPlayerHUD::DrawHUD()
{
	Super::DrawHUD();
}

void ASMPlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	GameWidgets.Add(ESMGameState::InProgress, CreateWidget<USMBaseWidget>(GetWorld(), PlayerHudWidgetClass));
	GameWidgets.Add(ESMGameState::Paused, CreateWidget<USMBaseWidget>(GetWorld(), PauseWidgetClass));
	GameWidgets.Add(ESMGameState::GameOver, CreateWidget<USMBaseWidget>(GetWorld(), GameOverWidgetClass));

	for (auto GameWidgetPair : GameWidgets)
	{
		const auto GameWidget = GameWidgetPair.Value;
		if (!GameWidget) continue;

		GameWidget->AddToViewport();
		GameWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	if (GetWorld())
	{
		if (const auto GameState = Cast<ASMGameStateBase>(GetWorld()->GetGameState()))
		{
			GameState->OnGameStateChanged.AddUObject(this, &ASMPlayerHUD::OnGameStateChanged);
		}
		if (auto Gamemode = Cast<ASMGameModeBase>(GetWorld()->GetAuthGameMode()))
		{
			Gamemode->StartGame();
		}
	}
}

void ASMPlayerHUD::OnGameStateChanged(ESMGameState State)
{
	if (CurrentWidget)
	{
		CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	if (GameWidgets.Contains(State))
	{
		CurrentWidget = GameWidgets[State];
	}
	if (CurrentWidget)
	{
		CurrentWidget->SetVisibility(ESlateVisibility::Visible);
		CurrentWidget->Show();
	}
}
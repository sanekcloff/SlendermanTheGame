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

			ESMGameState CurrentState = GameState->GetSMGameState(); // или GetSMGameState(), смотря как называется метод
			FString StateString = TEXT("Unknown");

			// Получаем имя enum'а через рефлексию
			if (UEnum* EnumPtr = StaticEnum<ESMGameState>())
			{
				StateString = EnumPtr->GetNameStringByValue((int64)CurrentState);
			}

			// Сообщение на экран
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
				FString::Printf(TEXT("Current GameState: %s"), *StateString));

			OnGameStateChanged(GameState->GetSMGameState());
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
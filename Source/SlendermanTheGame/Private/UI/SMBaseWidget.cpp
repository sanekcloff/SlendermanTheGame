// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMBaseWidget.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

void USMBaseWidget::Show()
{
	PlayAnimation(ShowAnimation);
	UGameplayStatics::PlaySound2D(GetWorld(),OpenSound);
}

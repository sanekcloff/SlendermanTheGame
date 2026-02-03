// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SMMenuHUD.h"
#include "UI/SMBaseWidget.h"

void ASMMenuHUD::DrawHUD()
{
	Super::DrawHUD();
}

void ASMMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (USMBaseWidget* MenuWidget = CreateWidget<USMBaseWidget>(GetWorld(), MenuWidgetClass)) MenuWidget->AddToViewport();
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
    HUD = CreateWidget(this, CrosshairClass);
    if (HUD != nullptr)
    {
        HUD->AddToViewport();
    }
}

void AShooterPlayerController::GameHasEnded(class AActor *EndGameFocus, bool bIsWinner) 
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    
    if (HUD != nullptr)
    {
        HUD->RemoveFromViewport();
    }

    if (bIsWinner)
    {
        UUserWidget *VictoryScreen = CreateWidget(this, VictoryScreenClass);
        if (VictoryScreen != nullptr)
        {
            VictoryScreen->AddToViewport();
        }
    }
    else
    {
        UUserWidget* DefeatScreen = CreateWidget(this, DefeatScreenClass);
        if (DefeatScreen != nullptr)
        {
            DefeatScreen->AddToViewport();
        }
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}


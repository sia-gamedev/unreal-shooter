// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSGameMode.h"
#include "KillAllEnemiesGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API AKillAllEnemiesGameMode : public AFPSGameMode
{
	GENERATED_BODY()
	
public:
	virtual void PawnKilled(APawn* PawnKilled) override;

private:
	void EndGame(bool bIsPlayerWinner);

};

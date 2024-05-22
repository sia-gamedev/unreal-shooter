// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABarrel.generated.h"

UCLASS()
class FPS_API AABarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;
    void Explode();

private:
	UPROPERTY(EditAnywhere)
	float MaxHealth = 1;

	UPROPERTY(VisibleAnywhere)
	float Health;

	UPROPERTY(EditAnywhere)
	float Damage = 50;

	UPROPERTY(EditAnywhere)
	float Radius = 100;

	UPROPERTY(EditAnywhere)
	UParticleSystem *ExplosionEffect;

	UPROPERTY(EditAnywhere)
	USoundBase *ExplosionSound;

	bool bExploded = false;
};

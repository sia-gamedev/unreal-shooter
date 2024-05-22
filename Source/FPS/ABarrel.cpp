// Fill out your copyright notice in the Description page of Project Settings.


#include "ABarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AABarrel::AABarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AABarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AABarrel::TakeDamage(float DamageAmount, FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser)
{
    float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Barrel health: %f"), Health);

	if (Health <= 0)
	{
		Explode();
	}

	return DamageToApply;
}

void AABarrel::Explode()
{
	if (!bExploded)
	{
		bExploded = true;

		if (ExplosionEffect)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, this->GetActorLocation(), this->GetActorRotation());
		}

		if (ExplosionSound)
		{
			UE_LOG(LogTemp, Warning, TEXT("Boom!"));
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, this->GetActorLocation());
		}

		TArray<AActor*> IgnoredActors;
		IgnoredActors.Add(this);

		UGameplayStatics::ApplyRadialDamage(
			this,
			Damage,
			GetActorLocation(),
			Radius,
			UDamageType::StaticClass(),
			IgnoredActors,
			this
		);
	}
	
    Destroy();
}

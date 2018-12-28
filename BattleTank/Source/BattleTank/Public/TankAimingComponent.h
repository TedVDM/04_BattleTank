// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Locked,
	Aiming,
	OutOfAmmo
};

class UTankBarrel; 
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, category = "Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, category = "Firing")
	int GetRoundsLeft() const;
	
	void AimAt(FVector HitLocation);
	bool IsBarrelMoving();
	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	void MoveBarrelTowards(FVector AimDirection);
	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	
	double LastFireTime = 0;
	FVector AimDirection;
	int RoundsLeft = 3;
};
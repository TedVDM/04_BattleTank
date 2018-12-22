// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "CoreMinimal.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;
	
	UFUNCTION(BlueprintImplementableEvent, category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairLocationX = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float  CrossHairLocationY = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float  LineTraceRange = 1000000;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	void AimTowardsCrosshair();

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
};

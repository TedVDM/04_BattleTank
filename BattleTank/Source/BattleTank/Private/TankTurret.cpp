// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<int>(RelativeSpeed, -1, 1);

	auto RotaionChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotaionChange;

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank found: %s"), *(PlayerTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player tank found"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) 
	{ 
		GetControlledTank()->AimAt(GetPlayerTank()->GetTargetLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PlayerPawn)
	{
		return Cast<ATank>(PlayerPawn);
	}
	else
	{
		return nullptr;
	}
} 

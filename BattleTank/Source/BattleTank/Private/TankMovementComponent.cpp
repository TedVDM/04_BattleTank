// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiForwardIntention = MoveVelocity.GetSafeNormal();
	
	auto ForwardThrow = FVector::DotProduct(TankForwardDirection, AiForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForwardDirection, AiForwardIntention).Z;
	IntendTurnRight(RightThrow);
}

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
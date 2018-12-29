// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void LaunchProjectile(float speed);

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpire();

	UProjectileMovementComponent* ProjectileMovement = nullptr;
	
	UPROPERTY(EditAnywhere, category = "Components")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(EditAnywhere, category = "Components")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(EditAnywhere, category = "Components")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(EditAnywhere, category = "Components")
	URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(EditDefaultsOnly, category = "Setp")
	float DestroyDelay = 10.f;
};

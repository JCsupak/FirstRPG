// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

AFloatingActor::AFloatingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));
	
	InitialLocation = FVector(0.0f, 0.0f, 0.0f);
	PlacedLocation = FVector(0.0f, 0.0f, 0.0f);
	WorldOrigin = FVector(0.0f, 0.0f, 0.0f);

	InitialDirection = FVector(0.0f, 0.0f, 0.0f);

	bInitializeFloatingActorLocations = false;
	bShouldFloat = false;
}

void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();

	PlacedLocation = GetActorLocation();

	if (bInitializeFloatingActorLocations)
	{
		SetActorLocation(InitialLocation);
	}
}

void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FHitResult HitResult;
		AddActorLocalOffset(InitialDirection, false, &HitResult, ETeleportType::None);
	}
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"
#include "Components/StaticMeshComponent.h"

AFloatingActor::AFloatingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	RotationRate = FRotator(0.0f, 0.0f, 0.0f);
	PlacedLocation = FVector(0.0f, 0.0f, 0.0f);
	InitializedLocation = FVector(0.0f, 0.0f, 0.0f);

	bInitializeFloatingActorLocations = false;
	bShouldFloat = false;

	Amplitude = 0.5f;
	Period = 1.0f;
	PhaseShift = 0.0f;
	VerticalShift = 2.0f;

	RunningTime = 0.0f;
}

void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();

	PlacedLocation = GetActorLocation();
	InitializedLocation = FVector(PlacedLocation.X, PlacedLocation.Y, 0.0f + VerticalShift);

	if (bInitializeFloatingActorLocations)
	{
		SetActorLocation(InitializedLocation);
	}
}

void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.Z = NewLocation.Z + (Amplitude * FMath::Sin(Period * RunningTime));

		SetActorLocation(NewLocation);
		RunningTime += DeltaTime;
	}

	AddActorLocalRotation(RotationRate * DeltaTime);
}


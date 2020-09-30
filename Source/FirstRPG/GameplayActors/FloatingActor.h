// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class FIRSTRPG_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AFloatingActor();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ActorMeshComponents")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "FloatingVariables")
	FVector InitializedLocation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "FloatingVariables")
	FVector PlacedLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloatingVariables")
	bool bShouldFloat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FloatingVariables")
	bool bInitializeFloatingActorLocations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingVariables")
	FRotator RotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingVariables")
	float Amplitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingVariables")
	float Period;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingVariables")
	float PhaseShift;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingVariables")
	float VerticalShift;

private:
	float RunningTime;

protected:
	virtual void BeginPlay() override;
};

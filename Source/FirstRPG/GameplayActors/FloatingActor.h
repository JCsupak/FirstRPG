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

	UPROPERTY(VisibleAnywhere, Category = "ActorMeshComponents")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "FloatingActorVariables")
	FVector InitialLocation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "FloatingActorVariables")
	FVector PlacedLocation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "FloatingActorVariables")
	FVector WorldOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloatingActorVariables")
	FVector InitialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FloatingActorVariables")
	bool bShouldFloat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FloatingActorVariables")
	bool bInitializeFloatingActorLocations;

protected:
	virtual void BeginPlay() override;

	

};

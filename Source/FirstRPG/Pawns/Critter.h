// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Critter.generated.h"

class UCameraComponent;
class UInputComponent;

UCLASS()
class FIRSTRPG_API ACritter : public APawn
{
	GENERATED_BODY()

public:
	ACritter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed;

private:
	UPROPERTY(EditDefaultsOnly, Category = "CameraSettings")
	FVector CameraOffset;

	UPROPERTY(EditDefaultsOnly, Category = "CameraSettings")
	FRotator CameraRotation;

protected:
	virtual void BeginPlay() override;

	void Move(float DeltaTime);
	void MoveForward(float value);
	void StrafeRight(float value);
	void Jump();

	FVector CurrentVelocity;
};

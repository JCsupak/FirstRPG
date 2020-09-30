// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include "Components/StaticMeshComponent.h" 
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h" 

ACritter::ACritter()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());
	CameraOffset = FVector(-300.0f, 0.0f, 300.0f);
	CameraRotation = FRotator(-45.0f, 0.0f, 0.0f);
	Camera->SetRelativeLocation(CameraOffset);
	Camera->SetRelativeRotation(CameraRotation);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	CurrentVelocity = FVector(0.0f);
	MaxSpeed = 500.0f;
}

void ACritter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACritter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("StrafeRight"), this, &ACritter::StrafeRight);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACritter::Jump);
}

void ACritter::Move(float DeltaTime)
{
	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);

	SetActorLocation(NewLocation);
}

void ACritter::MoveForward(float value)
{
	CurrentVelocity.X = FMath::Clamp(value, -1.0f, 1.0f) * MaxSpeed;
}

void ACritter::StrafeRight(float value)
{
	CurrentVelocity.Y = FMath::Clamp(value, -1.0f, 1.0f) * MaxSpeed;
}

void ACritter::Jump()
{

}


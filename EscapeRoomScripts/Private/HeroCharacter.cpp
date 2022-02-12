// Fill out your copyright notice in the Description page of Project Settings.

#include "HeroCharacter.h"
#include "Engine.h"

AHeroCharacter::AHeroCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;
	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->AttachTo(RootComponent);
	cam->SetRelativeLocation(FVector(0, 0, 40));
}

// Called when the game starts or when spawned
void AHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AHeroCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Horizontal", this, &AHeroCharacter::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &AHeroCharacter::VertMove);

	InputComponent->BindAxis("HorizontalRot", this, &AHeroCharacter::HorizontalRot);
	InputComponent->BindAxis("VerticalRot", this, &AHeroCharacter::VertRot);
	InputComponent->BindAxis("Interact", this, &AHeroCharacter::PreformRaycast);
}

//This function is responsible for the movement Horizontally on the binds that are set in SetupPlayerInputComponent
void AHeroCharacter::HorizontalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorRightVector(), value * AHeroCharacter::speedMultiplier);
	}
}

//This function is responsible for the movement vertically on the binds that are set in SetupPlayerInputComponent
void AHeroCharacter::VertMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value * AHeroCharacter::speedMultiplier);
	}
}

// this function is responsible for the rotation of the player when the mouse is being moved horizontally 
void AHeroCharacter::HorizontalRot(float value)
{
	if (value)
	{
		AddActorLocalRotation(FRotator(0, value * AHeroCharacter::rotationMultiplier, 0));
	}
}

// this function is responsible for the rotation of the player/camera when the mouse is being moved verticaly 
void AHeroCharacter::VertRot(float value)
{
	if (value)
	{
		float temp = cam->GetRelativeRotation().Pitch + value;

		if (temp < 65 && temp > -65) // clamps the rotation
		{
			cam->AddLocalRotation(FRotator(value * AHeroCharacter::rotationMultiplier, 0, 0));
		}
	}
}

/// This function is responsible for making raycast on mouse hold 
void AHeroCharacter::PreformRaycast(float value)
{
	if (value > 0) // if the mouse is hold/clicked execute the code
	{
		FHitResult *hitResult = new FHitResult();// create hit result
		AHeroCharacter::startTrace = cam->GetComponentLocation(); // set up the start position of the raycast
		AHeroCharacter::endTrace = ((cam->GetForwardVector() * pickUpRange) + startTrace); // set the end position of the raycast
		itemPos = ((cam->GetForwardVector() * holdRange) + startTrace); // set the item holding position

		if (GetWorld()->LineTraceSingleByChannel(*hitResult, startTrace, endTrace, ECC_Visibility))
		{
			// check if the hit actor is a Throwable and if yes the resters its physiscsVelocity so it doesn't exelerate and clip through walls
			if (hitResult->GetActor()->ActorHasTag(("Throwable")))
			{
				pickUp_Item = Cast<UPrimitiveComponent>(hitResult->GetActor()->GetRootComponent());
				pickUp_Item->SetPhysicsLinearVelocity(FVector().ZeroVector);
				pickUp_Item->SetPhysicsAngularVelocity(FVector().ZeroVector);
				hitResult->GetActor()->SetActorLocation(itemPos, false, 0, ETeleportType::ResetPhysics); // set the position close to the player
			}
		}
	}
}

void AHeroCharacter::CheckInteractable()
{
	FHitResult *hitResult = new FHitResult();
	AHeroCharacter::startTrace = cam->GetComponentLocation();
	AHeroCharacter::endTrace = ((cam->GetForwardVector() * pickUpRange) + startTrace);

	if (GetWorld()->LineTraceSingleByChannel(*hitResult, startTrace, endTrace, ECC_Visibility))
	{
		if (hitResult->GetActor()->ActorHasTag(("Throwable")))
		{
			isInteractable = true;
		}
		else
		{
			isInteractable = false;
		}
	}
	else
	{
		isInteractable = false;
	}
}

void AHeroCharacter::Tick(float DeltaTime)
{
	CheckInteractable();
	Super::Tick(DeltaTime);
}

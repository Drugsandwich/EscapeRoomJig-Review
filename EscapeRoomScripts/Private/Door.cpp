// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	endPointVector = GetActorLocation();
	endPointVector.Z += openMaxZ; // set the endpoint where the door is oppened on  the Z axist that are given in the editor
}

//This function is responsible for openning the door by checking if its open if yes then door slowly goes to the given target position
void ADoor::UnlockChecker()
{
	if(isUnlocked)
	{
		SetActorLocation(FMath::VInterpTo(GetActorLocation(),endPointVector,GetWorld()->GetDeltaSeconds(),speed));
	}
}

//this function can be called outside this cpp so when a puzzle is compelete it can be called
void ADoor::UnlockDoor()
{
	isUnlocked = true;
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UnlockChecker();
}


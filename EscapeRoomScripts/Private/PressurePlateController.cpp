// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlateController.h"
#include "Door.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
APressurePlateController::APressurePlateController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APressurePlateController::BeginPlay()
{
	TArray<AActor*> searchActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "PressureDoor",searchActor); // get the pressure door actor in a array by tag
	doorComp = Cast<ADoor>(searchActor[0]); // set the component to the first array element

	Super::BeginPlay();
}

//this function is responsible for checking if enough pressure plates are active to open the door
void APressurePlateController::ActivatedCheck()
{
	if(curretActived >= activeNeeded)
	{
		doorComp->UnlockDoor();
	}
}

// Called every frame
void APressurePlateController::Tick(float DeltaTime)
{
	ActivatedCheck();
	Super::Tick(DeltaTime);
}


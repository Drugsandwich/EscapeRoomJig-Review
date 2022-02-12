// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"
#include "PressurePlateController.h"
// Sets default values
APressurePlate::APressurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	OnActorBeginOverlap.AddDynamic(this,&APressurePlate::CollisionChecker);// set up the trigger to call the function on start colliding event
	OnActorEndOverlap.AddDynamic(this,&APressurePlate::CollisionCheckerOut); // set up the trigger to call the function on end colliding event
}

// Called when the game starts or when spawned
void APressurePlate::BeginPlay()
{
	Super::BeginPlay();
	pressureController = Cast<APressurePlateController>(GetAttachParentActor());
}

//This function is responsible for getting the actor that is colliding with the pressure plate trigger
void APressurePlate::CollisionChecker(class AActor* overlappedActor,class AActor* other)
{
	//if the actor is a heavy and the pressure plate needs heavy and is not currently active then set it to active
	//and add 1 to currentActivated in the pressure controller
	//also set the activator Object to the colliding object
	if(other->ActorHasTag("Heavy") && isHeavy && !isActive)
	{
		activatorObj = other;
		pressureController->curretActived++;
		isActive = true;
	}

	//if the actor is a light and the pressure plate needs light and is not currently active then set it to active
	//and add 1 to currentActivated in the pressure controller
	//also set the activator Object to the colliding object
	if(other->ActorHasTag("Light") && !isHeavy && !isActive)
	{
		activatorObj = other;
		pressureController->curretActived++;
		isActive = true;
	}
}

//this function is responsible for checking if a heavy/light cube has exited the trigger collision
void APressurePlate::CollisionCheckerOut(class AActor* overlappedActor,class AActor* other)
{
	// if the object is heavy and its the activator then set the activatorObj to null and deactivate the pressur plate and remove 
	// 1 of currentActivated from pressureController
	if(other->ActorHasTag("Heavy") && isHeavy && isActive && other == activatorObj)
	{
		pressureController->curretActived--;
		activatorObj = nullptr;
		isActive = false;
	}

	// if the object is light and its the activator then set the activatorObj to null and deactivate the pressur plate and remove 
	// 1 of currentActivated from pressureController
	if(other->ActorHasTag("Light") && !isHeavy && isActive && other == activatorObj)
	{
		pressureController->curretActived--;
		activatorObj = nullptr;
		isActive = false;
	}
}

// Called every frame
void APressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



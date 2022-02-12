// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyLocker.h"
#include "Door.h"
// Sets default values
AKeyLocker::AKeyLocker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	OnActorBeginOverlap.AddDynamic(this,&AKeyLocker::CollisionChecker);
}

// Called when the game starts or when spawned
void AKeyLocker::BeginPlay()
{
	Super::BeginPlay();
	doorComp = Cast<ADoor>(GetAttachParentActor());
}

//this function will check if the current keys are more the equal to the keys needed to open the door
void AKeyLocker::KeyChecker()
{
	if(currentKeyCount >= keysNeeded) // if the current keys are more or equal then open the door
	{
		doorComp->UnlockDoor();
	}
}

//this function check for collision/trigger
void AKeyLocker::CollisionChecker(class AActor* overlappedActor,class AActor* other)
{
	// if the actor that collided with the keylocker is a key then add it to current key count and destroy the key
	if(other->ActorHasTag("Key"))
	{
		currentKeyCount++;
		other->Destroy();
		KeyChecker();
	}
}

// Called every frame
void AKeyLocker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


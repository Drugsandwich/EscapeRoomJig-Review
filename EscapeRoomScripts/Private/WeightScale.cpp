// Fill out your copyright notice in the Description page of Project Settings.


#include "WeightScale.h"
#include "WeightObject.h"
#include "Components/TextRenderComponent.h"
#include "Door.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWeightScale::AWeightScale()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OnActorBeginOverlap.AddDynamic(this,&AWeightScale::CollisionChecker); //collosionCheck will be called when evenBeing Overlap is caleld
	OnActorEndOverlap.AddDynamic(this,&AWeightScale::CollisionCheckerOut);//collosionCheckout will be called when evenEnd Overlap is caleld
}

// Called when the game starts or when spawned
void AWeightScale::BeginPlay()
{
	Super::BeginPlay();

	//set the weight door component by seaching the world for actors with targ WeightDoor
	TArray<AActor*> searchActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "WeightDoor",searchActor);
	doorComp = Cast<ADoor>(searchActor[0]); // assign the first element to the component

	weightText = FindComponentByClass<UTextRenderComponent>();//get the text renderer 
	weightText->SetText(FText::FromString(FString::FromInt(currentWeight))); // set it to 0

}

//This function is responsible for checking collision/trigger in with another actor
void AWeightScale::CollisionChecker(class AActor* overlappedActor,class AActor* other)
{
	//if the actor is WeightObjcet then we get the object component and we add its weight to the scale
	if(other->ActorHasTag("WeightObj"))
	{
		AWeightObject* tempObj = Cast<AWeightObject>(other);
		currentWeight += tempObj->weight;
		weightText->SetText(FText::FromString(FString::FromInt(currentWeight))); // its converted to Ftext because string is deprecated 
	}
}

//This function is responsible for checking collision/trigger in with another actor when going out of the trigger
void AWeightScale::CollisionCheckerOut(class AActor* overlappedActor,class AActor* other)
{
	//if the actor is WeightObjcet then we get the object component and we take out its weight to the scale
	if(other->ActorHasTag("WeightObj"))
	{
		AWeightObject* tempObj = Cast<AWeightObject>(other);
		currentWeight -= tempObj->weight;
		weightText->SetText(FText::FromString(FString::FromInt(currentWeight)));// its converted to Ftext because string is deprecated 
	}
}

void AWeightScale::WeightCheck()
{
	if(currentWeight == weightNeeded)
	{
		doorComp->UnlockDoor();
	}
}

// Called every frame
void AWeightScale::Tick(float DeltaTime)
{
	WeightCheck();
	Super::Tick(DeltaTime);

}


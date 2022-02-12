// Fill out your copyright notice in the Description page of Project Settings.


#include "WeightObject.h"

// Sets default values
AWeightObject::AWeightObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWeightObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeightObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


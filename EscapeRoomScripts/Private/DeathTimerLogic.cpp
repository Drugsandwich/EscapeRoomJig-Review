// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathTimerLogic.h"
// Sets default values
ADeathTimerLogic::ADeathTimerLogic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeathTimerLogic::BeginPlay()
{
	Super::BeginPlay();
	curretT = startTime; // set the start time on the one its set
}

// this function will change the current time until it hits 0
void ADeathTimerLogic::Timer()
{
	if(curretT >= 0.0f)
	{
		curretT -= GetWorld()->GetDeltaSeconds();
	}
}

// Called every frame
void ADeathTimerLogic::Tick(float DeltaTime)
{
	Timer();
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathTimerText.h"
#include "DeathTimerLogic.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADeathTimerText::ADeathTimerText()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeathTimerText::BeginPlay()
{
	TArray<AActor*> searchActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "DeathTimer",searchActor); // get all actors from world that contain that tag
	logicComp = Cast<ADeathTimerLogic>(searchActor[0]); // get the component from world

	timeText = FindComponentByClass<UTextRenderComponent>();
	Super::BeginPlay();
	
}

// Called every frame
void ADeathTimerText::Tick(float DeltaTime)
{
	timeText->SetText(FText::FromString(FString::FromInt(logicComp->curretT)));  // set the text to the time
	Super::Tick(DeltaTime);

}


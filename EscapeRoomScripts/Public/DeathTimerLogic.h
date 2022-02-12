// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeathTimerLogic.generated.h"

UCLASS()
class ESCAPEROOM_API ADeathTimerLogic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeathTimerLogic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
   UPROPERTY(EditAnywhere, Category = "DeathTime")
   float startTime;

   void Timer();
public:	
    UPROPERTY(BlueprintReadWrite)
    float curretT;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

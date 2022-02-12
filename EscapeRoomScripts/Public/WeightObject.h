// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeightObject.generated.h"

UCLASS()
class ESCAPEROOM_API AWeightObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeightObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
    UPROPERTY(EditAnywhere, Category = "Weight")
    int weight;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

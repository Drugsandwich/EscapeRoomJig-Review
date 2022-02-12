// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PressurePlate.generated.h"

class APressurePlateController;
UCLASS()
class ESCAPEROOM_API APressurePlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APressurePlate();

private:
    UFUNCTION() // collision checker 
	void CollisionChecker(class AActor* overlappedActor,class AActor* other);

	UFUNCTION() // collision checker 
	void CollisionCheckerOut(class AActor* overlappedActor,class AActor* other);

	UPROPERTY(EditAnywhere, Category = "Heavy")
	bool isHeavy;
	bool isActive;

	AActor* activatorObj;
	APressurePlateController* pressureController;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

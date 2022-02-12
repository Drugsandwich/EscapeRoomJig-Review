// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class ESCAPEROOM_API ADoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UnlockDoor(); // door opener function

private:
	void UnlockChecker(); // door opener checker
	FVector endPointVector;

	UPROPERTY(EditAnywhere, Category = "OpenSpeed")
	float speed;

	UPROPERTY(EditAnywhere, Category = "Unlocked")
	bool isUnlocked;

	UPROPERTY(EditAnywhere, Category = "OpenMax")
	float openMaxZ;
};

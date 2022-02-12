// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeyLocker.generated.h"

class ADoor;
UCLASS()
class ESCAPEROOM_API AKeyLocker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeyLocker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
    ADoor * doorComp;

	UPROPERTY(EditAnywhere, Category = "KeysNeeded")
	int keysNeeded;
	int currentKeyCount;

	UFUNCTION() // collision checker 
	void CollisionChecker(class AActor* overlappedActor,class AActor* other);

	void KeyChecker();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

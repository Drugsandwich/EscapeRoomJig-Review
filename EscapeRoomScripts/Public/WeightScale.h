// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeightScale.generated.h"

class UTextRenderComponent;
class ADoor;
UCLASS()
class ESCAPEROOM_API AWeightScale : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeightScale();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "WeightNeeded")
    int weightNeeded;
	
	int currentWeight;

	ADoor* doorComp;
	UTextRenderComponent* weightText;

	void WeightCheck();

	UFUNCTION()  // collision checker 
	void CollisionChecker(class AActor* overlappedActor,class AActor* other);

	UFUNCTION()  // collision checker 
	void CollisionCheckerOut(class AActor* overlappedActor,class AActor* other);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

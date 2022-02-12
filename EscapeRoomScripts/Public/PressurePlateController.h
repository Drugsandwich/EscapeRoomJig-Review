// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PressurePlateController.generated.h"

class ADoor;
UCLASS()
class ESCAPEROOM_API APressurePlateController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APressurePlateController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "PressurePlates")
    ADoor * doorComp;

	UPROPERTY(EditAnywhere, Category = "PressurePlates")
	int activeNeeded;

	void ActivatedCheck();

public:	
	int curretActived;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

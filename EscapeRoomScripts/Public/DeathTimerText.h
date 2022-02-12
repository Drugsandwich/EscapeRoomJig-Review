// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeathTimerText.generated.h"

class ADeathTimerLogic;
class UTextRenderComponent;
UCLASS()
class ESCAPEROOM_API ADeathTimerText : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeathTimerText();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
    UTextRenderComponent* timeText;
	ADeathTimerLogic* logicComp;  

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

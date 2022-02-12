// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "HeroCharacter.generated.h"

class UPrimitiveComponent;
UCLASS()
class ESCAPEROOM_API AHeroCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
	

public:
    AHeroCharacter();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
    virtual void Tick(float DeltaTime) override;   

    UPROPERTY(BlueprintReadWrite)
    bool isInteractable;

private:
	void HorizontalMove(float value); // movement function Horizontal
	void VertMove(float value); // movement function vertical

	void HorizontalRot(float value); // rotation function Horizontal
	void VertRot(float value); //rotation function Vertical

	void PreformRaycast(float value); // pick up Raycast function
	void CheckInteractable(); // raycast fucntion to check if its interactable item

	UPROPERTY(EditAnywhere,Category = "Movement")
	float speedMultiplier;

	UPROPERTY(EditAnywhere,Category = "Movement")
	float rotationMultiplier;

    UPROPERTY(EditAnywhere,Category = "RayCast")
	float pickUpRange;

	UPROPERTY(EditAnywhere,Category = "RayCast")
	float holdRange;

	FVector endTrace;
	FVector startTrace;
	FVector itemPos;
	
	UPROPERTY(EditAnywhere,Category = "Camera")
	UCameraComponent* cam;	

	UPROPERTY(EditAnywhere,Category = "PickUp")
	UPrimitiveComponent* pickUp_Item;	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABatteryPickup();

	/* Override the WasCollected function - used implementation because it's a blueprint native event */
	void WasCollected_Implementation() override;

	/* Public way to access the battery power level */
	float GetPower();
	
protected:
	/* set the amount of power battery gives to character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "power", Meta = (BlueprintProtected = "true"))
	float BatteryPower;
	
};

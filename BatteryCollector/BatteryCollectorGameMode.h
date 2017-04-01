// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

// enum to store current state of gameplay
UENUM(BlueprintType)
enum class EBatteryPlayState
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float DeltaTime) override;

	// Returns power needed to win the game 
	UFUNCTION(BlueprintPure , Category = "Power")
	float GetPowerToWin() const;

	virtual void BeginPlay() override;

	// Returns the current playing state
	UFUNCTION(BlueprintPure, Category = "Power")
	EBatteryPlayState GetCurrentState() const;

	// Sets the new playing state
	void SetCurrentState(EBatteryPlayState NewState);

protected:
	// The rate at which character loses power
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float DecayRate;

	// Power needed to win the game
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	float PowerToWin;

	// The widget class to use for HUD Screen 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	// The instance of the HUD 
	UPROPERTY()
	class UUserWidget* CurrentWidget;

private:

	// Keep track of current playing state
	EBatteryPlayState CurrentState;

	// array to store spawn volumes
	TArray<class ASpawnVolume*> SpawnVolumeActors;

	// handle any function calls that rely upon changing the playing state of our game 
	void HandleNewState(EBatteryPlayState NewState);
};




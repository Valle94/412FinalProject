// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "FinalProjectCharacter.h"
#include "ShooterAI.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AShooterAI : public AAIController
{
	GENERATED_BODY()

protected:

	/** Gameplay initialization */
	virtual void BeginPlay() override;

public: 

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyAIBehaviorTree;

	AFinalProjectCharacter* PlayerCharacter;
	AFinalProjectCharacter* MyCharacter;

	void StartBehaviorTree(AFinalProjectCharacter* Player);
	
};

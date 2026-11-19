// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinalProjectGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "FinalProjectCharacter.h"
#include "ShooterAI.h"

AFinalProjectGameMode::AFinalProjectGameMode()
{
	// stub
}

void AFinalProjectGameMode::BeginPlay()
{
	Super::BeginPlay();

	AFinalProjectCharacter* Player = Cast<AFinalProjectCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	TArray<AActor*> ShooterAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterAI::StaticClass(), ShooterAIActors);

	for (AActor* ShooterAIActor : ShooterAIActors)
	{
		AShooterAI* ShooterAI = Cast<AShooterAI>(ShooterAIActor);

		if (ShooterAI)
		{
			ShooterAI->StartBehaviorTree(Player);
		}
	}
}

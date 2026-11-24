// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_Shoot.h"

#include "ShooterAI.h"

UBTTaskNode_Shoot::UBTTaskNode_Shoot()
{
	NodeName = TEXT("Shoot At Player");
}

EBTNodeResult::Type UBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	EBTNodeResult::Type Result = EBTNodeResult::Failed;

	AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());
	if (OwnerController)
	{
		AFinalProjectCharacter* OwnerCharacter = OwnerController->MyCharacter;
		AFinalProjectCharacter* PlayerCharacter = OwnerController->PlayerCharacter;
		AGun* OwnerGun = OwnerController->MyCharacter->Gun;

		if (OwnerCharacter && PlayerCharacter && PlayerCharacter->IsAlive)
		{
			OwnerCharacter->Shoot();
			if (OwnerGun->Ammo <= 0)
			{
				OwnerCharacter->Reload();
			}

			Result = EBTNodeResult::Succeeded;
		}
	}

	return Result;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MyFindRandomPos.h"
#include "MyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_MyFindRandomPos::UBTTask_MyFindRandomPos()
{
	NodeName = TEXT("FindRandomPos");
}

EBTNodeResult::Type UBTTask_MyFindRandomPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	FNavLocation RandomLocation;

	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 100.f, RandomLocation))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("RandomPos")), RandomLocation.Location); 
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

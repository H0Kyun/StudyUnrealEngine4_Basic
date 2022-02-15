// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SearchTarget.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTService_SearchTarget::UBTService_SearchTarget()
{
	NodeName = TEXT("SearchTarget");
	Interval = 1.0f;
}

void UBTService_SearchTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// 현재 AI를 실행하는 Pawn을 찾는다.
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return;

	UWorld* World = CurrentPawn->GetWorld(); // Pawn이 있는 월드
	FVector Center = CurrentPawn->GetActorLocation();
	float SearchRadius = 250.f;

	if (World == nullptr)
		return;

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams QueryParams(NAME_None, false, CurrentPawn);

	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(SearchRadius),
		QueryParams
	);

	if (bResult)
	{
		for (auto& OverlapResult : OverlapResults)
		{
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor());
			if (MyCharacter && MyCharacter->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), MyCharacter);
				
				DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Cyan, false, 0.2f);

				return;
			}
		}
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);
	}

	DrawDebugSphere(World, Center, SearchRadius, 16, FColor::Blue, false, 0.2f);
}

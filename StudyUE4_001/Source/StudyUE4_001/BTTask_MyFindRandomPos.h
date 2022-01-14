// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_MyFindRandomPos.generated.h"

/**
 * 
 */
UCLASS()
class STUDYUE4_001_API UBTTask_MyFindRandomPos : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTask_MyFindRandomPos();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

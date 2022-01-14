// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class STUDYUE4_001_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AMyAIController();

	// 폰에 빙의하여 컨트롤 해줌
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

private:
	void RandomMove();

private:
	FTimerHandle TimerHandle;

	UPROPERTY()
	class UBehaviorTree* BehaviorTree;

	UPROPERTY()
	class UBlackboardData* BlackboardData;
};

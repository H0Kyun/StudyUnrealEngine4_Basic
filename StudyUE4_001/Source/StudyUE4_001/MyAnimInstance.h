// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * Animation 관리를 위해 만든 클래스
 * 움직이는 캐릭터의 클래스에 움직일때마다 애니메이션이 실행되게하는 코드를 작성하면
 * 관리하기 어렵기 때문에 여기서 모아서 관리
 */
UCLASS()
class STUDYUE4_001_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Pawon, Meta=(AllowPrivateAccess=true))
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawon, Meta = (AllowPrivateAccess = true))
	bool IsFalling;
};

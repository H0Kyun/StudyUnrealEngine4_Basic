// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Greystone_Skeleton_Montage.Greystone_Skeleton_Montage'"));

	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

// 엔진이 입력 시스템 먼저 호출 -> 컨텐츠 로직 실행 -> 최종적으로 업데이트 함수 호출
void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	UAnimInstance::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();
		}
	}
}


// 클릭한 순간에만 호출될 수 있게 제작
void UMyAnimInstance::PlayAttackMontage()
{
	/*
	델리게이트를 사용할 경우 불필요하게 다시 체크할 필요가 없어진다
	if (!Montage_IsPlaying(AttackMontage))
	{
		Montage_Play(AttackMontage, 1.f);
	}
	*/
	Montage_Play(AttackMontage, 1.f);
}

void UMyAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}

FName UMyAnimInstance::GetAttackMontageName(int32 SectionIndex)
{

	return FName(*FString::Printf(TEXT("Attack%d"),SectionIndex));
}

void UMyAnimInstance::AnimNotify_AttackHit()
{
	//사운드 넣어보자
}


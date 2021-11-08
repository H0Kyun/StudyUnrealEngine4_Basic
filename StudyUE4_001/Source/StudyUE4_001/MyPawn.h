// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class STUDYUE4_001_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void UpDown(float Value);
	void LeftRight(float Value);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	//Tranform을 이용해 캐릭터의 움직임을 구현하면 물, 눈 등 환경에 따른 변경을 하기어렵다
	// 그래서 언리얼에서는 움직임도 하나의 컴포넌트로 관리해준다
	UPROPERTY(VisibleAnywhere)
	class UFloatingPawnMovement* Movement;
};

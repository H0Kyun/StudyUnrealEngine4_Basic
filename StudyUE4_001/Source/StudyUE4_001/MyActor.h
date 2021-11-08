// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class STUDYUE4_001_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// C++에는 없는 리플렉션 기술을 언리얼에서 구현
	// 공식 문서를 보면 다양한 기능의 변수?를 찾을 수 있다
	UPROPERTY(VisibleAnywhere) 
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = State)
	int32 Hp;

	UPROPERTY(EditAnywhere, Category = State)
	int32 Mp;

	UPROPERTY(EditAnywhere, Category = State)
	float RotateSpeed = 30.f;
};

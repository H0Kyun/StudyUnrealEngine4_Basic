// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// TEXT 같은 경우 어느 환경에서나 문자열이 호환될 수 있게 만든 것
	// CreateDefaultSubobject는 일종의 스마트 포인터처럼 메모리를 자동 관리해준다.
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	if (SM.Succeeded()) 
	{
		Mesh->SetStaticMesh(SM.Object);
	}

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	//디버깅 방법
	//1. 아래와 같이 로그를 쓴다.
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
	//2. 언리얼 엔진을 종료하고 브레이크포인트를 잡은 후 
	//Visual Studio의 디버깅을 사용한다. 어리면 디버깅 종료시 언리얼 꺼짐
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Tick은 매프레임마다 호출됨
	//DeltaTime은 Tick 함수 호출 간의 간격 
	//속도 같은 것에 DeltaTime을 곱하여 호출되는 프레임 수와 관계없이
	//1초에 가는 거리를 맞춰줌
	AddActorLocalRotation(FRotator(0.f, RotateSpeed * DeltaTime, 0.f));
}


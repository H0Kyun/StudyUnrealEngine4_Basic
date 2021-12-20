// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));

	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
// 입력을 컴포넌트로 받아서 어떤 입력을 받았을 때 어떤 함수가 호출되야 하는지를 매핑해준다
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Axis는 조이스틱 키, Action은 버튼 생각하면 된다
	//this 다음에 오는게 호출할 함수 헤더에 정의해 둔다
	//플레이어 컨트롤러 클래스로 이전 가능
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);

	
}

void AMyPawn::UpDown(float Value)
{

}

void AMyPawn::LeftRight(float Value)
{
	//Tranform을 이용해 캐릭터의 움직임을 구현하면 물, 눈 등 환경에 따른 변경을 하기어렵다
	// 그래서 언리얼에서는 움직임도 하나의 컴포넌트로 관리해준다
	AddMovementInput(GetActorRightVector(), Value);

}


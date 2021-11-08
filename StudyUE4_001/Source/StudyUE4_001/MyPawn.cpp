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
// �Է��� ������Ʈ�� �޾Ƽ� � �Է��� �޾��� �� � �Լ��� ȣ��Ǿ� �ϴ����� �������ش�
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Axis�� ���̽�ƽ Ű, Action�� ��ư �����ϸ� �ȴ�
	//this ������ ���°� ȣ���� �Լ� ����� ������ �д�
	//�÷��̾� ��Ʈ�ѷ� Ŭ������ ���� ����
	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);

	
}

void AMyPawn::UpDown(float Value)
{

}

void AMyPawn::LeftRight(float Value)
{
	//Tranform�� �̿��� ĳ������ �������� �����ϸ� ��, �� �� ȯ�濡 ���� ������ �ϱ��ƴ�
	// �׷��� �𸮾󿡼��� �����ӵ� �ϳ��� ������Ʈ�� �������ش�
	AddMovementInput(GetActorRightVector(), Value);

}

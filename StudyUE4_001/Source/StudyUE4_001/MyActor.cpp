// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// TEXT ���� ��� ��� ȯ�濡���� ���ڿ��� ȣȯ�� �� �ְ� ���� ��
	// CreateDefaultSubobject�� ������ ����Ʈ ������ó�� �޸𸮸� �ڵ� �������ش�.
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
	
	//����� ���
	//1. �Ʒ��� ���� �α׸� ����.
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
	//2. �𸮾� ������ �����ϰ� �극��ũ����Ʈ�� ���� �� 
	//Visual Studio�� ������� ����Ѵ�. ��� ����� ����� �𸮾� ����
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Tick�� �������Ӹ��� ȣ���
	//DeltaTime�� Tick �Լ� ȣ�� ���� ���� 
	//�ӵ� ���� �Ϳ� DeltaTime�� ���Ͽ� ȣ��Ǵ� ������ ���� �������
	//1�ʿ� ���� �Ÿ��� ������
	AddActorLocalRotation(FRotator(0.f, RotateSpeed * DeltaTime, 0.f));
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// MyCharacter.h 파일에 include 하지 않고 MyCharacter.cpp 파일에 include 하는 이유
// MyCharacter.h 파일을 다른 파일이 include할 경우 불필요한 헤더가
// include 되지 않게 막기 위함이다
#include "GameFramework/SpringArmcomponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 500.f;
	SpringArm->SetRelativeLocationAndRotation(FVector(0.f, 0.f, 44.f), FRotator(0.f, 0.f, 0.f));

	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0.f, 0.f, -88.f), FRotator(0.f, 0.f, 0.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone'"));

	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);

}

void AMyCharacter::UpDown(float Value)
{

}

void AMyCharacter::LeftRight(float Value)
{
	//Tranform을 이용해 캐릭터의 움직임을 구현하면 물, 눈 등 환경에 따른 변경을 하기어렵다
	// 그래서 언리얼에서는 움직임도 하나의 컴포넌트로 관리해준다
	AddMovementInput(GetActorRightVector(), Value);

}


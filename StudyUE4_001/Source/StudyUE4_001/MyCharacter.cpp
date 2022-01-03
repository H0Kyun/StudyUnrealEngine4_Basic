// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// MyCharacter.h 파일에 include 하지 않고 MyCharacter.cpp 파일에 include 하는 이유
// MyCharacter.h 파일을 다른 파일이 include할 경우 불필요한 헤더가
// include 되지 않게 막기 위함이다
#include "GameFramework/SpringArmcomponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "MyAnimInstance.h"

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
	
	// 자주 쓰는 변수는 멤버 변수로 만들자, 생명주기에 맞춰 적절한 위치에서 초기화하자
	AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	// 델리게이트 함수는 정해진 규칙을 따라 제작해야 한다
	AnimInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::OnAttackMontageEnded);
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

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);

}

void AMyCharacter::Attack()
{
	/*
	바인딩 된 키가 프레스되어 호출되면 AnimInstance를 참고해 내부의 PlayAttackMontage를 호출한다
	auto AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	if (AnimInstance)
	{
		AnimInstance->PlayAttackMontage();
	}
	*/

	// 델리게이트를 사용하면 위와 같이 복잡한 체크는 필요없어진다.
	if (IsAttacking)
		return;

	AnimInstance->PlayAttackMontage();
	AnimInstance->JumpToSection(AttackIndex);
	AttackIndex = (AttackIndex + 1) % 3;

	IsAttacking = true;
}

void AMyCharacter::UpDown(float Value)
{

}

void AMyCharacter::LeftRight(float Value)
{
	LeftRightValue = Value;
	//Tranform을 이용해 캐릭터의 움직임을 구현하면 물, 눈 등 환경에 따른 변경을 하기어렵다
	// 그래서 언리얼에서는 움직임도 하나의 컴포넌트로 관리해준다
	AddMovementInput(GetActorRightVector(), Value);

}

void AMyCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	IsAttacking = false;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStatComponent.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	bWantsInitializeComponent = true;

	Level = 1;
}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMyStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetLevel(Level);
}

void UMyStatComponent::SetLevel(int32 NewLevel)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(NewLevel);
		if (StatData)
		{
			Level = StatData->Level;
			SetHp(StatData->MaxHp);
			MaxHp = StatData->MaxHp;
			Attack = StatData->Attack;
		}
	}
}

void UMyStatComponent::SetHp(int32 NewHp)
{
	// Hp를 총괄하는 메소드를 만들어서 데미지를 받았을 때 뿐만 아니라 힐을 받았을 때 등
	// Hp의 변화가 발생했을 때 바로 관리하기 쉽게 하고 UI와 연동할 수 있게 한다.

	Hp = NewHp;
	if (Hp < 0)
		Hp = 0;

	OnHpChanged.Broadcast();
}

void UMyStatComponent::OnAttacked(float DamageAmount)
{
	/*
	Hp -= DamageAmount;
	if (Hp < 0)
		Hp = 0;
	Hp의 효율적인 관리를 위해 아래와 같이 변경한다.
	*/

	int32 NewHp = Hp - DamageAmount;
	SetHp(NewHp);

	UE_LOG(LogTemp, Warning, TEXT("OnAttacked %d"), Hp);
}

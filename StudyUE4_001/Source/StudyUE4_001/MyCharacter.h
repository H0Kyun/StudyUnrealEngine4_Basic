// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEnd);

UCLASS()
class STUDYUE4_001_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack();
	void AttackCheck();

	FOnAttackEnd OnAttackEnd;

	void UpDown(float Value);
	void LeftRight(float Value);

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

private:

	// 일반적으로 캐릭터를 따라가는 카메라 제작 방법
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY()
	class UMyAnimInstance* AnimInstance;

	UPROPERTY(VisibleAnywhere, Category=Pawn)
	bool IsAttacking = false;

	UPROPERTY()
	int32 AttackIndex = 0;
public:

	UPROPERTY()
	float LeftRightValue = 0;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Weapon;

	UPROPERTY(VisibleAnywhere)
	class UMyStatComponent* Stat;

	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* HpBar;
};

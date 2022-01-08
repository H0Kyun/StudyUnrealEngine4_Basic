// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class STUDYUE4_001_API UMyCharacterWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindHp(class UMyStatComponent* StatComp);

	void UpdateHp();

private:
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;

	// meta가 bindwidget이기 때문에 블루프린트에서 만든 프로그레스 바를 자동으로 찾아준다.
	// 언리얼 기능을 사용 안 할시 직접 cast를 해줘야 한다.
	UPROPERTY(meta=(BindWidget)) 
	class UProgressBar* PB_HpBar;
};

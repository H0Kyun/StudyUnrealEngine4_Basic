// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"

/*
* 넘겨줘야 할 데이터가 적을 경우 클래스만 넘겨받아 종속성을 낮추는 것도 나쁘지 않은 방법이다 
*/
void UMyCharacterWidget::BindHp(class UMyStatComponent* StatComp)
{
	CurrentStatComp = StatComp;
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHp);
}

void UMyCharacterWidget::UpdateHp()
{
	if (CurrentStatComp.IsValid())
		PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}

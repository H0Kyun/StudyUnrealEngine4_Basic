// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "MyGameInstance.generated.h"

/*
* 게임 데이터는 JASON 파일 같은 것으로 관리하는게 편하다
*/
USTRUCT()
struct FMyCharacterData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHp;
};

/**
 * 게임이 실행되면 한 번 초기화되는 인스턴스
 * 스탯 관리에 도움이 된다.
 */
UCLASS()
class STUDYUE4_001_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMyGameInstance();

	virtual void Init() override;

	FMyCharacterData* GetStatData(int32 Level);

private:
	UPROPERTY()
	class UDataTable* MyStats;
};

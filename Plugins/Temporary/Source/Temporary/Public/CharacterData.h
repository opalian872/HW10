// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TEMPORARY_API UCharacterData : public UObject
// API에 프로젝트명이 아닌 플러그인 명이 들어가 있다는 점 확인
{
	GENERATED_BODY()
public:
	UCharacterData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Data")
	float Mana;

	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_LocalSplit.generated.h"

/**
 * 
 */
UCLASS()
class PROJET_IT_TAKES_TWO_API AGM_LocalSplit : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

private:
	void AdjustSplitScreen();
};

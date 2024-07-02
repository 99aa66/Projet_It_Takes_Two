// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GM_Project.generated.h"

/**
 * 
 */
UCLASS()
class SPLITSCREEN_MANU_API AGM_Project : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGM_Project();

protected:

    UFUNCTION(BlueprintCallable, Category = "Viewport")
	void ModifySplitscreen(ECustomSplitScreenType::Type NewSplitType);
};

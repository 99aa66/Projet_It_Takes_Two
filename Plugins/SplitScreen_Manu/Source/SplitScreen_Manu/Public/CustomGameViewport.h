// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "Engine/ViewportSplitScreen.h"
#include "CustomGameViewport.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
namespace ECustomSplitScreenType
{
    enum Type
    {
        // 0 value required by UE
        None,
        OnePlayer,
        // Custom Splitscreen, next value after last built-in splitscreen type
        TwoPlayer = ESplitScreenType::SplitTypeCount,
        SplitTypeCount
    };
}

UCLASS()
class SPLITSCREEN_MANU_API UCustomGameViewport : public UGameViewportClient
{
	GENERATED_BODY()
public:
    UCustomGameViewport();  // Constructor declaration

    virtual void UpdateActiveSplitscreenType() override;  // Method declaration
    void ModifySplitscreen(ECustomSplitScreenType::Type NewSplitType);

 };

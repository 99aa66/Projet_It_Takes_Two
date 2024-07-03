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


USTRUCT(BlueprintType)
struct FSplitScreenValues
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Splitscreen")
    float SizeX1;

    UPROPERTY(BlueprintReadOnly, Category = "Splitscreen")
    float SizeY1;

    UPROPERTY(BlueprintReadOnly, Category = "Splitscreen")
    float OriginX1;

    UPROPERTY(BlueprintReadOnly, Category = "Splitscreen")
    float OriginY1;

    UPROPERTY(BlueprintReadOnly, Category = "Splitscreen")
    float SizeX2;

    UPROPERTY(BlueprintReadOnly, Category = "Splitscreen")
    float SizeY2;

    UPROPERTY(BlueprintReadOnly, Category = "Splitscreen")
    float OriginX2;

    UPROPERTY(BlueprintReadOnly, Category = "Splitscreen")
    float OriginY2;

    FSplitScreenValues()
        : SizeX1(0.f), SizeY1(0.f), OriginX1(0.f), OriginY1(0.f),
        SizeX2(0.f), SizeY2(0.f), OriginX2(0.f), OriginY2(0.f)
    {}
};


UCLASS()
class SPLITSCREEN_MANU_API UCustomGameViewport : public UGameViewportClient
{
    GENERATED_BODY()
public:
    UCustomGameViewport();  // Constructor declaration

    virtual void UpdateActiveSplitscreenType() override;  // Method declaration
    void ModifySplitscreen(ECustomSplitScreenType::Type NewSplitType);

    void SetSpecificSplitscreen(float SizeX1, float SizeY1, float OriginX1, float OriginY1,
        float SizeX2, float SizeY2, float OriginX2, float OriginY2);

    UFUNCTION(BlueprintCallable, Category = "Splitscreen")
    FSplitScreenValues GetSplitscreenValue();
 };

// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameViewport.h"
#include "Engine/ViewportSplitScreen.h"

UCustomGameViewport::UCustomGameViewport()
    : Super(FObjectInitializer::Get())
{
    // Resize SplitscreenInfo to fit our custom config
    SplitscreenInfo.SetNum(ECustomSplitScreenType::SplitTypeCount, false);

}
void UCustomGameViewport::UpdateActiveSplitscreenType()
{
    ECustomSplitScreenType::Type SplitType = ECustomSplitScreenType::None;
    const int32 NumPlayers = GEngine->GetNumGamePlayers(GetWorld());

    if (NumPlayers == 2)
    {
        // If Player count is equal 2, select custom Splitscreen
        ActiveSplitscreenType = static_cast<ESplitScreenType::Type>(ECustomSplitScreenType::TwoPlayer);
        // Fill the custom config
        SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.5f, 1.0f, 0.0f, 0.0f)); //1
        SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.5f, 1.0f, 0.5f, 0.0f)); //2
    }
    else
    {
        // Otherwise fallback to default behaviour
        Super::UpdateActiveSplitscreenType();
    }
}

void UCustomGameViewport::ModifySplitscreen(ECustomSplitScreenType::Type NewSplitType)
{
    switch (NewSplitType)
    {
    case ECustomSplitScreenType::OnePlayer:
    {
        ActiveSplitscreenType = static_cast<ESplitScreenType::Type>(ECustomSplitScreenType::TwoPlayer);
        SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Reset();
        SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(1.0f, 1.0f, 0.0f, 0.0f)); //1
        SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.0f, 0.0f, 0.5f, 0.0f)); //2
    }
    break;
    case ECustomSplitScreenType::TwoPlayer:
    {
        ActiveSplitscreenType = static_cast<ESplitScreenType::Type>(ECustomSplitScreenType::TwoPlayer);
        SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Reset();
        SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.5f, 1.0f, 0.0f, 0.0f)); //1
        SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.5f, 1.0f, 0.5f, 0.0f)); //2
    }
    break;
    case ECustomSplitScreenType::None:
    default:
    {
        Super::UpdateActiveSplitscreenType();
    }
    break;
    }
}


void UCustomGameViewport::SetSpecificSplitscreen(float SizeX1, float SizeY1, float OriginX1, float OriginY1,
    float SizeX2, float SizeY2, float OriginX2, float OriginY2)
{
    ActiveSplitscreenType = static_cast<ESplitScreenType::Type>(ECustomSplitScreenType::TwoPlayer);
    SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Reset();
    SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(SizeX1, SizeY1, OriginX1, OriginY1)); //1
    SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(SizeX2, SizeY2, OriginX2, OriginY2)); //2
}

FSplitScreenValues UCustomGameViewport::GetSplitscreenValue()
{
    FSplitScreenValues SplitScreenValues;


        const TArray<FPerPlayerSplitscreenData>& PlayerData = SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData;

        if (PlayerData.Num() > 0)
        {
            SplitScreenValues.SizeX1 = PlayerData[0].SizeX;
            SplitScreenValues.SizeY1 = PlayerData[0].SizeY;
            SplitScreenValues.OriginX1 = PlayerData[0].OriginX;
            SplitScreenValues.OriginY1 = PlayerData[0].OriginY;
        }

        if (PlayerData.Num() > 1)
        {
            SplitScreenValues.SizeX2 = PlayerData[1].SizeX;
            SplitScreenValues.SizeY2 = PlayerData[1].SizeY;
            SplitScreenValues.OriginX2 = PlayerData[1].OriginX;
            SplitScreenValues.OriginY2 = PlayerData[1].OriginY;
        }

    return SplitScreenValues;
}

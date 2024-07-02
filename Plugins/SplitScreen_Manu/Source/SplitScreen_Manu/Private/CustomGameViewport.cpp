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

// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameViewport.h"
#include "Engine/ViewportSplitScreen.h"

UCustomGameViewport::UCustomGameViewport()
    : Super(FObjectInitializer::Get())
{
    // Resize SplitscreenInfo to fit our custom config
    SplitscreenInfo.SetNum(ECustomSplitScreenType::SplitTypeCount, false);

    // Fill the custom config
    SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.5f, 1.00f, 0.00f, 0.00f)); //1
    SplitscreenInfo[ECustomSplitScreenType::TwoPlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.5f, 1.00f, 0.5f, 0.00f)); //2
}

void UCustomGameViewport::UpdateActiveSplitscreenType()
{
    ECustomSplitScreenType::Type SplitType = ECustomSplitScreenType::None;
    const int32 NumPlayers = GEngine->GetNumGamePlayers(GetWorld());

    if (NumPlayers == 2)
    {
        // If Player count is equal 3, select custom Splitscreen
        ActiveSplitscreenType = static_cast<ESplitScreenType::Type>(ECustomSplitScreenType::TwoPlayer);
       
    }
    else
    {
        // Otherwise fallback to default behaviour
        Super::UpdateActiveSplitscreenType();
    }
}
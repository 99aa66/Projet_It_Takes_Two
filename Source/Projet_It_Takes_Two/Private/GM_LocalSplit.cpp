// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_LocalSplit.h"
#include "Engine/World.h"
#include "Engine/GameViewportClient.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

void AGM_LocalSplit::BeginPlay()
{
    Super::BeginPlay();

    // Ajouter un deuxième joueur pour activer le split screen
    UGameplayStatics::CreatePlayer(GetWorld(), 1, true);

    AdjustSplitScreen();
}

void AGM_LocalSplit::AdjustSplitScreen()
{
    UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
    if (ViewportClient)
    {
        ViewportClient->SetForceDisableSplitscreen(true);

        TArray<ULocalPlayer*> LocalPlayers = ViewportClient->GetGameInstance()->GetLocalPlayers();

        if (LocalPlayers.Num() > 1)
        {
            /*
            
            FViewportSplitScreenInfo SplitInfo;
            SplitInfo.PlayerData[0].OriginX = 0.0f;
            SplitInfo.PlayerData[0].OriginY = 0.0f;
            SplitInfo.PlayerData[0].SizeX = 0.5f; // Largeur du premier écran
            SplitInfo.PlayerData[0].SizeY = 1.0f; // Hauteur du premier écran

            SplitInfo.PlayerData[1].OriginX = 0.5f; // Début du deuxième écran
            SplitInfo.PlayerData[1].OriginY = 0.0f;
            SplitInfo.PlayerData[1].SizeX = 0.5f; // Largeur du deuxième écran
            SplitInfo.PlayerData[1].SizeY = 1.0f; // Hauteur du deuxième écran

            ViewportClient->UpdateViewports(SplitInfo);

            */
        }
    }
}

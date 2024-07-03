#include "GM_Project.h"
#include "CustomGameViewport.h"
#include "Engine/Engine.h"

AGM_Project::AGM_Project()
{
    // Constructeur
}

void AGM_Project::SetSplitScreen(float SizeX1, float SizeY1, float OriginX1, float OriginY1,
    float SizeX2, float SizeY2, float OriginX2, float OriginY2)
{
    if (GEngine && GEngine->GameViewport)
    {
        UCustomGameViewport* CustomViewport = Cast<UCustomGameViewport>(GEngine->GameViewport);

        if (CustomViewport)
        {
            CustomViewport->SetSpecificSplitscreen(SizeX1, SizeY1, OriginX1, OriginY1,
                SizeX2, SizeY2, OriginX2, OriginY2);
        }
    }
}

FSplitScreenValues AGM_Project::GetCurrentSplitscreenValue() const
{
    FSplitScreenValues SplitScreenValues;

    if (GEngine && GEngine->GameViewport)
    {
        UCustomGameViewport* CustomViewport = Cast<UCustomGameViewport>(GEngine->GameViewport);

        if (CustomViewport)
        {
            SplitScreenValues = CustomViewport->GetSplitscreenValue();
        }
    }

    return SplitScreenValues;
}
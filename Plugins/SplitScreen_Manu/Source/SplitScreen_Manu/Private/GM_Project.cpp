// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Project.h"
#include "CustomGameViewport.h"

AGM_Project::AGM_Project()
{

}


void AGM_Project::ModifySplitscreen(ECustomSplitScreenType::Type NewSplitType)
{
    if (GEngine && GEngine->GameViewport)
    {
        UCustomGameViewport* CustomViewport = Cast<UCustomGameViewport>(GEngine->GameViewport);

        if (CustomViewport)
        {
            CustomViewport->ModifySplitscreen(NewSplitType);
        }
    }
}
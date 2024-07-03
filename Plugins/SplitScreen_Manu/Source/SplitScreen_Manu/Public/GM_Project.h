#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CustomGameViewport.h"
#include "GM_Project.generated.h"

/**<
 * Structure pour stocker les valeurs de splitscreen
 */

UCLASS()
class SPLITSCREEN_MANU_API AGM_Project : public AGameModeBase
{
    GENERATED_BODY()

public:
    AGM_Project();

    UFUNCTION(BlueprintCallable, Category = "Splitscreen")
    FSplitScreenValues GetCurrentSplitscreenValue() const;

protected:
    UFUNCTION(BlueprintCallable, Category = "Viewport")
    void SetSplitScreen(float SizeX1, float SizeY1, float OriginX1, float OriginY1,
        float SizeX2, float SizeY2, float OriginX2, float OriginY2);
};
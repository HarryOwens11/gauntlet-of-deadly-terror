// Copyright Epic Games, Inc. All Rights Reserved.

#include "GauntletDeadlyTerrorGameMode.h"
#include "GauntletDeadlyTerrorCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGauntletDeadlyTerrorGameMode::AGauntletDeadlyTerrorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

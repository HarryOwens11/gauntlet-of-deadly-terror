// Copyright Epic Games, Inc. All Rights Reserved.

#include "GauntletDeadlyTerror/Public/GameModes/GameModeMain.h"
#include "GauntletDeadlyTerror/Public/Actors/Player/MainCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameModeMain::AGameModeMain()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

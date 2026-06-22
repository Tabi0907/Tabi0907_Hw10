// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModuleAndPluginGameMode.h"
#include "ModuleAndPluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

AModuleAndPluginGameMode::AModuleAndPluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

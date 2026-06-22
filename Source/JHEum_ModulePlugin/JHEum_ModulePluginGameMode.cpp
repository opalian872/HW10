// Copyright Epic Games, Inc. All Rights Reserved.

#include "JHEum_ModulePluginGameMode.h"
#include "JHEum_ModulePluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJHEum_ModulePluginGameMode::AJHEum_ModulePluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game_CGameMode.h"
#include "Game_CHUD.h"
#include "Game_CCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGame_CGameMode::AGame_CGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGame_CHUD::StaticClass();
}

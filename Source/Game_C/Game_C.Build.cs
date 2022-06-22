// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Game_C : ModuleRules
{
	public Game_C(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}

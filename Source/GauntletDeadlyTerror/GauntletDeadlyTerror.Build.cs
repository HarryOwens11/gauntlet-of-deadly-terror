// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GauntletDeadlyTerror : ModuleRules
{
	public GauntletDeadlyTerror(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Saveload : ModuleRules
{
	public Saveload(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "JsonUtilities", "Json" });
	}
}

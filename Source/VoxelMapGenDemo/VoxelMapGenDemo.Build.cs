// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VoxelMapGenDemo : ModuleRules
{
	public VoxelMapGenDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"VoxelMapGenDemo",
			"VoxelMapGenDemo/Variant_Horror",
			"VoxelMapGenDemo/Variant_Horror/UI",
			"VoxelMapGenDemo/Variant_Shooter",
			"VoxelMapGenDemo/Variant_Shooter/AI",
			"VoxelMapGenDemo/Variant_Shooter/UI",
			"VoxelMapGenDemo/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

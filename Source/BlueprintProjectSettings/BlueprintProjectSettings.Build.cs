// Copyright Noa Second 2026. All Rights Reserved.
using UnrealBuildTool;

public class BlueprintProjectSettings : ModuleRules
{
	public BlueprintProjectSettings(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"EngineSettings",
			}
		);
	}
}
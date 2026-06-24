// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JHEum_ModulePlugin : ModuleRules
{
	public JHEum_ModulePlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Test" //Test 모듈 참조 추가
		});
	}
}

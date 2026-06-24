// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class JHEum_ModulePluginTarget : TargetRules
{
	public JHEum_ModulePluginTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		ExtraModuleNames.Add("JHEum_ModulePlugin");
		RegisterModulesCreatedByRider();//라이더에서 생한 모듈 전부를 ExtraModuleNames.Add 해주는 함수
	}

	private void RegisterModulesCreatedByRider()
	{
		ExtraModuleNames.AddRange(new string[] { "Test" });
	}
}

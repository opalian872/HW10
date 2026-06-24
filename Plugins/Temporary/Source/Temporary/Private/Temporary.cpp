// Copyright Epic Games, Inc. All Rights Reserved.

#include "Temporary.h"

#define LOCTEXT_NAMESPACE "FTemporaryModule"

void FTemporaryModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// 플러그인 모듈이 프로젝트에 의해 로드되었는지 확인하기 위해 StartupModule에서 로그 출력
	UE_LOG(LogTemp, Warning, TEXT("Temporary Plugin Started"));
}

void FTemporaryModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	//에디터 상에선 확인 불가능(셧다운과 함께 에디터도 종료되기 때문 -> Saved 폴더의 로그 확인)
	UE_LOG(LogTemp, Warning, TEXT("Temporary Plugin Shutdown"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTemporaryModule, Temporary)
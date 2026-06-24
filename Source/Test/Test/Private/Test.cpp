#include "Test.h"

#define LOCTEXT_NAMESPACE "FTestModule"

void FTestModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Test Module Started")); //모듈 시작/종료 로그
}

void FTestModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Test Module ShutDown")); //모듈 시작/종료 로그
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FTestModule, Test) // 생성자, 소멸자 사용 가능한 커스텀 모듈로 생성함.

// IMPLEMENT_MODULE은 Unreal Build Tool이 Test 모듈을 런타임에 로드할 수 있도록 등록한다.
// IMPLEMENT_MODULE(FDefaultModuleImpl, Test) -> 언리얼에서 기본 제공하는 모듈
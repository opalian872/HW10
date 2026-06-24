#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FTestModule : public IModuleInterface
// FTestModule을 직접 구현하면 StartupModule과 ShutdownModule에서 모듈 로드/언로드 시점을 로그로 확인할 수 있다.
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

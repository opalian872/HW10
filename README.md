# 모듈 작성

# 기본 프로젝트 생성

* 언리얼 C++ 기반 Third Person Template 이용한 프로젝트 생성.

# 모듈 작성

## 기본 세팅

* Source/Test 폴더를 생성하고 `Build.cs` 파일과 헤더/cpp 파일을 생성하는 게 과제 내용
* 과제 내용을 직접 따라갈 수도 있지만, 라이더 사용법과 함께 익히기 위해 라이더의 Add - Add Unreal Module 기능을 사용하였다.
* Build.cs 내부의 `PublicDependencyModuleNames`나 `IMPLEMENT_MODULE`, `.uproject` 파일 내부의 모듈 리스트에 추가, `Target.cs` 내부에 추가 등을 라이더에서 직접 해주는 걸 확인 가능

  * 메인 모듈의 `Build.cs` 에서도 PublicDependencyModuleNames에 Test 추가된 것 확인
* 이 때 `Test.cpp` 내부의 `IMPLEMENT_MODULE` 의 경우, Default Module이 아닌 `StartupModule()`과 `ShutdownModule()`을 직접 작성할 수 있는 커스텀 모듈 FTestModule로 생성해 준다.

  * `StartupModule()`과 `ShutdownModule()` 내부에서 로그를 찍어 모듈 로딩/언로딩을 확인할 수 있다.

## TestActor 상호작용 구현

* 언리얼 에디터에서 C++ 클래스 추가를 선택 후, 생성할 모듈을 Test로 설정해 생성할 수 있다.

  * 이외에도 라이더 IDE에서 추가도 가능하긴 하지만, 안전을 위해 에디터에서 생성.
  * 해당 액터의 스폰을 확인하기 위해선 BeginPlay 내부에 `AddOnScreenDebugMessage` 만 하면 되겠지만, 시각적인 확인을 위해 Static Mesh Component를 추가하고 Cube Mesh를 기본 스태틱 메쉬로 지정해 주었다.
* 이후 기본적으로 생성되어 있는 프로젝트 캐릭터 클래스 내부의 BeginPlay에서 `GetWorld()->SpawnActor<>()` 함수를 통해 TestActor를 스폰해 주었다.

  * 메인 모듈의 `Build.cs`에 `"Test"` 의존성을 추가했기 때문에 `#include "TestActor.h"` 형식으로 Test 모듈의 Actor를 사용할 수 있었다.

# 플러그인 작성

## 기본 세팅

* 플러그인 역시 라이더의 기능을 이용해 Plugins 폴더 내부에 Temporary 라는 이름의 플러그인을 생성하였다.
* `Temporary.uplugin` 파일은 JSON형식으로 플러그인 정보를 저장하는데, Name, Type, LoadingPhase 등은 과제 지시 사항과 맞춰주었다.
* 이후 기본 `.uproject` 파일의 `"Plugins"` 배열에 Temporary 이름과 "Enabled": true 를 저장해 주었다.

## 플러그인 확인용 모듈 설정.

* 플러그인 생성과 함께 생성된 플러그인 기본 모듈 파일인 `Temporary.h` 와 `Temporary.cpp` 파일을 활용해 플러그인 로딩을 확인할 수 있다.
* 해당 클래스의 `StartupModule()`과 `ShutdownModule()` 내부에 `UE_LOG` 를 찍으면 플러그인 로딩 타이밍을 알 수 있다.

  * 셧다운의 경우 에디터 내부에선 확인할 수 없지만, Saved 폴더 내부의 로그를 확인해 Shutdown 로그 역시 제대로 기능하는 걸 확인할 수 있다.

## 학습 정리

이번 과제를 통해 프로젝트 내부 모듈과 플러그인의 차이를 확인했다.

`Test` 모듈은 현재 프로젝트의 `Source` 폴더 아래에 포함되는 프로젝트 전용 코드 단위이다. 반면 `Temporary` 플러그인은 `Plugins` 폴더 아래에 독립적인 구조를 가지며, `.uplugin` 파일을 통해 프로젝트에 등록된다.

또한 다른 모듈의 클래스를 사용하려면 단순히 헤더를 include하는 것뿐 아니라, 사용하는 쪽 모듈의 `Build.cs`에 의존성을 추가해야 한다는 점을 확인했다.


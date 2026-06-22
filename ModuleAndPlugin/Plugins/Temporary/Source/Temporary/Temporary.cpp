#include "Temporary.h"
#include "Engine/Engine.h"

void FTemporaryModule::StartupModule()
{
	// 플러그인이 로드될 때 로그를 남깁니다.
	UE_LOG(LogTemp, Warning, TEXT("=== Temporary 플러그인이 활성화되었습니다! ==="));
}

void FTemporaryModule::ShutdownModule()
{
}

// 일반 모듈 매크로 대신 플러그인 모듈 매크로를 사용합니다.
IMPLEMENT_MODULE(FTemporaryModule, Temporary)
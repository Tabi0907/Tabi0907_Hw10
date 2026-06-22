#include "Temporary.h"
#include "Engine/Engine.h"

// 플러그인이 엔진 부팅 단계 또는 런타임에 메모리에 성공적으로 인클루드되었을 때 수행할 기능
void FTemporaryModule::StartupModule()
{
	// [필수 과제] 플러그인이 활성화 및 로드되었음을 엔진 콘솔 로그에 기록하여 수동 조립 검증
	UE_LOG(LogTemp, Warning, TEXT("=== Temporary 플러그인이 활성화되었습니다! ==="));
}

// 플러그인이 정상 종료되거나 언로드될 때 리소스를 해제 및 정리할 기능
void FTemporaryModule::ShutdownModule()
{
	
}

// 일반 모듈 매크로 대신 플러그인의 커스텀 생명주기를 바인딩하기 위해 FTemporaryModule 클래스를 확장 모듈로 엔진에 등록
IMPLEMENT_MODULE(FTemporaryModule, Temporary)
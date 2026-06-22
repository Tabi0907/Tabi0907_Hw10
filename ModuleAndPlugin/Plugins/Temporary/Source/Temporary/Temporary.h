#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/* 독립 플러그인 전용 모듈 인터페이스 클래스
 * 플러그인이 로드되거나 언로드되는 시점의 글로벌 이벤트를 후킹하기 위해 IModuleInterface를 상속
 */
class FTemporaryModule : public IModuleInterface
{
public:
	/** 플러그인 모듈이 메모리에 최초로 로드되어 시작될 때 자동으로 실행되는 라이프사이클 함수 */
	virtual void StartupModule() override;

	/** 플러그인 모듈이 메모리에서 해제되어 종료될 때 자동으로 실행되는 라이프사이클 함수 */
	virtual void ShutdownModule() override;
};
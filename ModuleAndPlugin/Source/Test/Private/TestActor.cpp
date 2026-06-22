#include "TestActor.h"
#include "Engine/Engine.h" // GEngine 객체를 통해 화면에 메시지를 출력하기 위해 포함

// 생성자 구현: 액터의 기본 프로퍼티를 초기화
ATestActor::ATestActor()
{
	// 최적화를 위해 이 액터는 런타임에 매 프레임 Tick 함수를 호출하지 않도록 설정
	PrimaryActorTick.bCanEverTick = false;
}

// 게임이 시작되거나 월드에 액터가 스폰될 때 1회 호출되는 생명주기 함수
void ATestActor::BeginPlay()
{
	// 부모 클래스인 AActor의 BeginPlay 로직을 우선적으로 실행
	Super::BeginPlay();

	// [필수 과제] 출력 로그(Output Log) 창에 Warning 단계로 정상 생성되었음을 기록
	UE_LOG(LogTemp, Warning, TEXT("=== TestActor가 성공적으로 생성되었습니다! ==="));

	// [필수 과제] 새로 만든 모듈이 정상 작동하는지 눈으로 확인할 수 있도록 화면(Viewport)에 메시지를 출력
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,               // 고유 Key (기존 메시지를 지우지 않고 새로 누적시킴)
			10.0f,            // 화면에 텍스트가 머무를 시간 (10초)
			FColor::Cyan,     // 텍스트 색상 (청록색)
			TEXT("Hello! Test Module is working properly!") // 출력할 성공 문자열
		);
	}
}

// 매 프레임 실행되는 주기 함수 (현재는 호출이 꺼져 있는 상태)
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
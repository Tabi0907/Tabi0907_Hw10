#include "TestActor.h"
#include "Engine/Engine.h" // GEngine을 사용하기 위해 포함

ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	// 1. 출력 로그 창에 Warning으로 로그 남기기
	UE_LOG(LogTemp, Warning, TEXT("=== TestActor가 성공적으로 생성되었습니다! ==="));

	// 2. 게임 화면에 10초 동안 파란색 글씨로 메시지 띄우기
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, TEXT("Hello! Test Module is working properly!"));
	}
}

void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
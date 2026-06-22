using UnrealBuildTool;


public class Test : ModuleRules
{
    public Test(ReadOnlyTargetRules Target) : base(Target)
    {
        // 사용 규칙을 설정, 빌드 속도를 최적화
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // [필수 과제] 헤더(.h)와 소스(.cpp) 모두에서 범용적으로 사용할 필수 모듈 종속성 기술
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",         // 언리얼 엔진의 기본 프레임워크 (기본 데이터 타입, 컨테이너 등)
            "CoreUObject",  // UObject 시스템, 리플렉션, 가비지 컬렉션 등 엔진 핵심 모듈
            "Engine",       // AActor, 월드, 게임 프레임워크 핵심 클래스 포함
            "InputCore"     // 마우스 및 키보드 등 기본 입력 처리를 위한 라이브러리
        });

        // 소스(.cpp) 파일 내부에서만 참조할 프라이빗 종속성 모듈
        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
using UnrealBuildTool;

public class Temporary : ModuleRules
{
    public Temporary(ReadOnlyTargetRules Target) : base(Target)
    {
        // 플러그인 빌드 속도 최적화를 위한 사전 컴파일 헤더(PCH) 규칙 세팅
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // 플러그인 모듈 코드가 컴파일되기 위해 필요한 주 엔진 라이브러리 목록 지정
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore"
        });
    }
}
언리얼 엔진 모듈 \& 플러그인 수동 구축





프로젝트 주요 구조

text

ModuleAndPlugin/

├── ModuleAndPlugin.uproject      // 주 모듈 및 Temporary 플러그인 활성화 설정 (PreDefault/Default)

├── Source/

│   ├── ModuleAndPlugin/         // Primary 게임 모듈 (주 모듈)

│   │   ├── ModuleAndPluginCharacter.cpp  // TestActor를 런타임에 Spawn하는 로직 구현

│   │   └── ModuleAndPlugin.Build.cs      // "Test" 모듈을 PublicDependency에 추가

│   └── Test/                    // 새 런타임 모듈

│       ├── Test.Build.cs        // 필수 종속성 정의

│       ├── Public/

│       │   ├── Test.h           // IMPLEMENT\_MODULE 매크로 구동을 위한 모듈 헤더

│       │   └── TestActor.h      // 주 모듈에서 참조 가능하도록 TEST\_API 매크로가 반영된 액터

│       └── Private/

│           ├── Test.cpp         // IMPLEMENT\_MODULE(FDefaultModuleImpl, Test) 구현

│           └── TestActor.cpp    // BeginPlay 시 화면(Viewport) 및 로그창에 성공 메시지 출력

└── Plugins/

&#x20;   └── Temporary/               // 재사용 가능한 독립 플러그인 구조

&#x20;       ├── Temporary.uplugin    // 플러그인 메타데이터 및 모듈 로드 정의 (JSON)

&#x20;       └── Source/

&#x20;           └── Temporary/       // 플러그인 내부 전용 모듈

&#x20;               ├── Temporary.Build.cs

&#x20;               ├── Temporary.h / .cpp  // IModuleInterface(Startup/ShutdownModule) 구현

&#x20;               └── TemporaryDummy.h / .cpp // 에디터 내 C++ 클래스 폴더 노출을 위한 더미 오브젝트



1. 수동 모듈(Test) 및 타겟 시스템 연결

Source/Test 하위에 Public, Private 폴더 트리를 수동으로 구축했습니다.



Test.Build.cs 내에 엔진 프레임워크 접근을 위한 필수 모듈(Core, CoreUObject, Engine)을 종속성으로 명시했습니다.



프로젝트 타겟 설정 파일(\*.Target.cs)의 ExtraModuleNames에 "Test"를 추가하고, .uproject 파일의 모듈 리스트에 등록하여 주 모듈보다 먼저 메모리에 올라가도록 PreDefault 로딩 페이즈를 바인딩했습니다.



2\. 모듈 간 상호작용 및 디버그 검증

Test 모듈 내에 타 모듈에서 접근할 수 있도록 링킹 매크로(TEST\_API)가 적용된 ATestActor 클래스를 생성했습니다.



주 게임 모듈(ModuleAndPlugin)의 빌드 규칙 파일에 "Test" 모듈을 의존성 배열로 추가하여 참조 제약을 해제했습니다.



캐릭터의 BeginPlay() 타이밍에 GetWorld()->SpawnActor()를 호출하여 외부 모듈의 액터를 정상 스폰하고 월드 구동을 검증했습니다.\\



3\. 독립 플러그인(Temporary) 수동 패키징 과정

독립 구조화: 프로젝트 루트에 Plugins/Temporary 구조를 생성하고, 독립 모듈의 메타데이터를 담은 Temporary.uplugin을 JSON 포맷으로 직접 코딩했습니다.



플러그인 라이프사이클 훅: IModuleInterface를 상속받아 플러그인이 로드되는 시점(StartupModule)에 콘솔에 성공 로그(UE\_LOG)가 찍히도록 설계하고 IMPLEMENT\_MODULE 매크로로 결합했습니다.



에디터 뷰포트 노출 보완: 소스코드 파일만 존재할 시 에디터 콘텐츠 브라우저에서 폴더가 숨겨지는 언리얼 빌드 특성을 고려하여, 인스턴스화가 가능한 더미 오브젝트(UTemporaryDummy) 클래스를 내부에 추가 탑재함으로써 에디터 내에서 Plugins/Temporary/C++ 클래스 구조가 완벽히 검증되도록 처리했습니다.


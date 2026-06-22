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


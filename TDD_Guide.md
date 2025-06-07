# ✅ TDD 작업 흐름 가이드 (C++ / GoogleTest / CMake 기반)

## 1. 테스트 코드 작성

- `tests/` 디렉토리에 새로운 테스트 파일을 생성합니다.
- 예: `tests/test_NewFeature.cpp`
- 테스트 케이스는 `TEST` 매크로를 사용하고, 명확한 테스트 이름을 지정합니다.

```cpp
#include <gtest/gtest.h>
#include "WarGame2/NewFeature.h"

TEST(NewFeatureTest, SampleCase) {
    EXPECT_EQ(WarGame2::NewFeature::Function(), ExpectedValue);
}
```

## 2. 프로덕션 코드 작성

- `include/WarGame2/`에 헤더 파일을,
- `src/`에 구현 파일을 생성합니다.

```cpp
// include/WarGame2/NewFeature.h
#pragma once

namespace WarGame2 {
    class NewFeature {
    public:
        static ReturnType Function();
    };
}
```

```cpp
// src/NewFeature.cpp
#include "WarGame2/NewFeature.h"

namespace WarGame2 {
    ReturnType NewFeature::Function() {
        // 구현 내용
    }
}
```

## 3. 빌드 및 테스트 실행

```bash
mkdir build
cd build
cmake ..
cmake --build .
ctest --verbose
```

## 4. 테스트 결과 확인 및 리팩토링

- 테스트 실패 → 코드 수정 반복
- 테스트 성공 → 리팩토링 수행

---

## ⚙️ 유용한 명령어

```bash
rm -rf build              # 빌드 디렉토리 삭제
ctest -R TestName         # 특정 테스트만 실행
```

```powershell
$env:CLICOLOR_FORCE = "1"  # 컬러 출력 강제
ctest --verbose
```

---

## 📝 주의사항

- 테스트는 `tests/` 디렉토리에 작성
- 헤더는 `include/WarGame2/`, 구현은 `src/`에 작성
- `build/`는 `.gitignore`에 등록
- 테스트는 독립적으로 작성

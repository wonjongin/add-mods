# Add Mods

마인크래프트에서 모드랑 리소스팩을 넣기 힘들었죠? 이제 드래그앤 드롭으로 간편하게 넣으세요

## 설치

아직 개발 중 이에요. 조금 기다려 주세요.

## 스크린샷

![mac1](img/mac1.png)

## 빌드

이 프로젝트는 다음의 의존성이 필요합니다.

```
QtCore
QtGui
QtWidgets

cmake
make
g++
```

준비가 되었으면 다음과 같이 입력해 주세요.

```
git clone https://github.com/wonjongin/add-mods.git

cmake -Bbuild -DCMAKE_PREFIX_PATH=/path/to/Qt/version/compiler/lib/cmake/

make -C build

./build/src/add-mods
```

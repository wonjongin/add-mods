## 빌드

이 프로젝트는 다음의 의존성이 필요해요.

```
QtCore
QtGui
QtWidgets

python3
cmake
make
g++
```

준비가 되었으면 다음과 같이 입력해 주세요.

### 윈도우

```
git clone https://github.com/wonjongin/add-mods.git

cmake -Bbuild -DCMAKE_PREFIX_PATH=/path/to/Qt/version/compiler/lib/cmake/

make -C build

python ./scripts/winPack.py

.\dist\add-mods.exe

```

### 리눅스/macos
```
git clone https://github.com/wonjongin/add-mods.git

cmake -Bbuild -DCMAKE_PREFIX_PATH=/path/to/Qt/version/compiler/lib/cmake/

make -C build

./build/src/add-mods
```

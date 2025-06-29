### [2025 - 06 - 27] 텍스트 기반 RPG 게임



# **🐱 주인님과 고양이의 수수께끼 모험 🐱**

### 📌 개요
---
이 프로젝트는 C++로 만든 텍스트 기반 RPG 게임입니다.

사용자는 캐릭터로 다양한 몬스터들을 무찌르고

경험치를 얻어 강해지며

골드를 모아 상점에서 아이템을 구매할 수 있으며

최종 보스인 드래곤을 무찌르는 것이 최종 목표입니다.

---

### 🎮 주요 기능

- **캐릭터 생성 및 능력치 확인**
- **몬스터와의 전투**
- **아이템 획득 및 사용**
- **상점에서 아이템 거래**
- **레벨업과 능력치의 상승**
- **게임 로그 시스템**

---

### 💻 개발 환경

- **언어**: C++
- **IDE**: Visual Studio 2022
- **Compiler**: MSVC v14.3 이상
- **C++ 표준**: C++17 이상
- **운영체제**: Windows 10 / 11

---

### ▶️ 실행 방법

1. Visual Studio에서 새 콘솔 프로젝트 생성

2. 'Character.h', 'Monster.h', 'GameManager.h', 'Shop.h', 'FItem.h', 'Monster.cpp', 'Master.cpp'를 모두 프로젝트에 추가

3. 'Master.cpp'를 시작 파일로 설정

4. Ctrl + F5 또는 실행 버튼 클릭

---

### 📦 의존 라이브러리 / 패키지

이 프로젝트는 따로 설치해야 하는 라이브러리는 존재하지 않습니다.
기본적으로 C++에서 제공해주는 기능들만 사용하였습니다.

- **iostream**: 화면에 글자를 보여주거나 입력 받을 때 사용

- **string**: 문자열을 다룰 때 사용

- **vector**, **map**, **unordered_map**: 여러 개의 데이터를 저장할 때 사용

- **memory**: 스마트 포인터를 다룰 때 사용

- **cstdlib**, **ctime**: 랜덤 숫자를 만들기 위해 사용

- **random**: **cstdlib**, **ctime**보다 정밀한 랜덤 숫자 생성

---

### 📁 주요 파일 설명

- **Master.cpp** /
   게임 진행 코드

- **Character.h** /
   캐릭터 클래스

- **GameManager.h** /
   게임 전투, 로그 관리

- **Monster.h** /
   몬스터 클래스 (고블린, 오크, 트롤, 슬라임, 드래곤)

- **Item.h** /
   아이템 클래스 (포션, 공격 포션)

- **Shop.h** /
   상점 클래스

- **README.md** /
   설명 문서

---

### 📚 주요 클래스 간단 설명

**Character**: 플레이어의 체력, 공격력, 골드, 레벨, 아이템 등을 관리

**Monster**: 몬스터 기본 클래스. Goblin, Orc 같은 몬스터가 상속

**Item**: 아이템 추상 클래스. 포션, 무기

**GameManager**: 전투 진행, 아이템, 레벨업, 로그 출력 관리

**Shop**: 골드로 아이템을 거래 할 수 있는 상점

---

### ➕ 추가 구현 사항

- **드래곤 등장 시 게임 클리어 처리 및 결과 로그 출력**

- **전투 시 랜덤 아이템 드랍**

- **몬스터별 처치 수 기록 기능**

- **체력이 절반 이하로 떨어지면 자동으로 포션 사용**

- **상점에서 골드로 아이템을 구매 / 판매 가능**

------



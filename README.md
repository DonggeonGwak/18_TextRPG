# [2025 - 06 - 23] 텍스트 기반 RPG 게임

### 프로젝트 소개
---
**냥냥 모험**

### 개요
---
이 프로젝트는 C++로 만든 텍스트 기반 RPG 게임입니다.

사용자는 캐릭터로 다양한 몬스터들을 무찌르고

경험치를 얻어 강해지며

골드를 모아 상점에서 아이템을 구매할 수 있으며

최종 보스인 드래곤을 무찌르는 것이 최종 목표입니다.

### 주요 기능
---

- 캐릭터 생성, 능력치 확인
- 몬스터와의 전투
- 아이템 획득, 사용
- 상점에서 아이템 구매
- 레벨업과 능력치의 상승

- vector
아이템 목록, 몬스터 목록
- map, unordered_map
인벤토리, 몬스터 처치 수 기록
- string
캐릭터 이름, 아이템 이름 처리

## 개발 환경
사용한 언어 및 도구
언어: C++

IDE: Visual Studio 2022

Compiler: MSVC 14.3 이상

C++ 표준: C++17 이상

운영체제: Windows 11


### 빌드, 실행 방법
Visual Studio 기준 (Windows 사용자)
Visual Studio에서 새 콘솔 프로젝트 생성

Character.h, Monster.h, GameManager.h, Shop.h, FItem.h, Monster.cpp, Master.cpp 모두 프로젝트에 추가

Master.cpp를 시작 파일로 설정

Ctrl + F5 또는 실행 버튼 클릭

(의존 라이브러리/패키지 넣기)

MeowAdventure/
Master.cpp           # 메인 게임 실행
Character.h          # 캐릭터 관련 기능
GameManager.h        # 전투 등 게임 진행 관리
Monster.h            # 몬스터 종류
FItem.h              # 아이템 종류
Shop.h               # 상점 시스템
README.md

### 주요 클래스 간단 설명

Character
플레이어의 체력, 공격력, 골드, 레벨, 아이템 등을 관리

Monster
몬스터 기본 클래스. Goblin, Orc, Troll, Slime, Dragon 같은 몬스터가 상속

FItem
아이템 공통 틀. 포션, 무기

GameManager
전투 진행, 아이템, 레벨업, 로그 출력 관리

Shop
골드로 아이템을 살 수 있는 상점

## 추가 구현 사항
드래곤 등장 시 게임 클리어 처리 및 결과 로그 출력
전투 시 랜덤 아이템 드랍
몬스터별 처치 수 기록 기능



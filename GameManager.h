
#pragma once
#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "Monster.h"
#include "Character.h"
 // C++11부터 제공되는 난수 생성 라이브러리

using namespace std;

//플레이어 HP가 0 이상일 경우 게임을 계속 진행
//플레이어 HP가 0 이하일 경우 게임을 종료합니다.
//자동 반복 턴제어를 하는 게임 매니저 클래스
//게임 매니저 클래스는 플레이어와 몬스터의 상태를 관리하고, 전투를 진행합니다.
// 게임 매니저 클래스는 플레이어와 몬스터의 상태를 출력합니다.
// 게임 매니저 클래스는 플레이어와 몬스터의 상태를 업데이트합니다.
// 캐릭터가 레벨업 할 때 마다 경험치를 획득하고, 레벨을 올립니다.
// 배틀	클래스는 플레이어와 몬스터의 상태를 관리하고, 전투를 진행합니다.

class GameManager {
public:
	void randomMonster(vector<Monster*> monsters)
	{
		if (monsters.empty()) {
			cout << "No monsters available." << endl;
			return;
		}
		int randomIndex = rand() % monsters.size();
		monsters[randomIndex]->displayinfo();
	}
		
};






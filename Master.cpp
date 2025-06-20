
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "GameManager.h"
#include "Monster.h"
#include "Character.h"
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif


using namespace std;

void clearScreen() 
{
	system(CLEAR_COMMAND);
}

int main()
{
	GameManager manager; // GameManager 객체 생성
	Character player; // Player 객체 생성
	Goblin goblin() ; // Goblin 객체 생성
	Orc orc(); // Orc 객체 생성
	Troll troll(); // Troll 객체 생성
	Slime slime(); // Slime 객체 생성



	string CharacterName;
	
	cout << "냥냥 월드에 오신 것을 환영한다냥!!" << endl;
	cout << "주인님,이름을 작성해 한다냥: " << endl;
	cin >> CharacterName;
	player.setName(CharacterName);
		player.displayStatus();

	while (player.getHp() > 0 && player.getLevel() < 10)
	{
		
		cout << "주인님, " << CharacterName << " 님의 모험을 시작한다냥!" << endl;
		cout << "1. 플레이어 스텟이다냥!!" << endl;
		cout << "2. 싸움 시작이다냥!!" << endl;
		cout << "3. 게임 종료이다냥!!" << endl;
		

		int choice;
		cin >> choice;
		clearScreen();
		if (cin.fail()) { // 숫자가 아닌 입력이 들어왔을 때 처리
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = 0;
		}

		if (choice == 1)
		{
			player.displayStatus(); // 플레이어 스텟 출력 함수 호출
		}
		else if (choice == 2)
		{
			cout << "적과의 전투가 시작된다냥!" << endl;

			manager.battle(player);

		}
		else if (choice == 3)
		{
			cout << "게임 종료다냥..>_<" << endl;
			cout << "주인님, 다음에 또 봐냥!!" << endl;
			break;
		}
		else
		{
			cout << "잘못된 입력값이다냥. 1,2,3,4 중에 입력하라냥." << endl;
		}
	}
	
	return 0;
}
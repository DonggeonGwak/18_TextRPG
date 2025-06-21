
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
	Goblin goblin(); // Goblin 객체 생성
	Orc orc(); // Orc 객체 생성
	Troll troll(); // Troll 객체 생성
	Slime slime(); // Slime 객체 생성



	string CharacterName;
	cout << "========================================" << endl;
	cout << "=                                      =" << endl;
	cout << "=   냥냥 월드에 오신 것을 환영한다냥!  =" << endl;
	cout << "=                                      =" << endl;
	cout << "=      주인님! 이름을 알려달라냥!      =" << endl;
	cout << "=                                      =" << endl;
	cout << "========================================" << endl << endl;
	cout << " 나의 이름 : ";
	getline(cin, CharacterName);
	player.setName(CharacterName);

	clearScreen();

	cout << CharacterName << " 님의 모험을 시작한다냥!" << endl << endl;

	while (player.getLevel() < 10)
	{
		cout << "========================================" << endl;
		cout << "=                                      =" << endl;
		cout << "=        무엇을 하시겠습니까?          =" << endl;
		cout << "=                                      =" << endl;
		cout << "=      1. 플레이어 정보 확인           =" << endl;
		cout << "=      2. 전투 시작                    =" << endl;
		cout << "=      3. 아이템 사용                  =" << endl;
		cout << "=      4. 게임 종료                    =" << endl;
		cout << "=                                      =" << endl;
		cout << "========================================" << endl << endl;
		cout << "진행 선택 : ";

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
			cout << endl;
		}
		else if (choice == 2)
		{

			manager.battle(player);

		}
		else if (choice == 3)
		{
			cout << "무슨 아이템 쓸거냥..>_<" << endl;
			
						
		}
		else if (choice == 4)
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
	cout << "만랩을 달성했습니다 ! 게임 클리어 !" << endl;
	return 0;
}
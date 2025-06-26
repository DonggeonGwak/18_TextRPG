
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "GameManager.h"
#include "Monster.h"
#include "Character.h"
#include "Shop.h"
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
	Shop shop;
	Goblin goblin(); // Goblin 객체 생성
	Orc orc(); // Orc 객체 생성
	Troll troll(); // Troll 객체 생성
	Slime slime(); // Slime 객체 생성



	string CharacterName;
	cout << "========================================" << endl;
	cout << "=                                      =" << endl;
	cout << "= <<주인님과 고양이의 수수께끼 모험>>  =" << endl;
	cout << "=                                      =" << endl;
	cout << "=      주인님! 이름을 알려달라냥!      =" << endl;
	cout << "=                                      =" << endl;
	cout << "========================================" << endl << endl;
	cout << " 주인님의 이름 : ";
	getline(cin, CharacterName);
	player.setName(CharacterName);

	clearScreen();

	cout << CharacterName << " 님의 모험을 시작한다냥!" << endl << endl;

	while (true)
	{
		cout << "========================================" << endl;
		cout << "=                                      =" << endl;
		cout << "=       뭐 하고 싶은 기분이냥?         =" << endl;
		cout << "=                                      =" << endl;
		cout << "=      1. 주인님 정보 확인             =" << endl;
		cout << "=      2. 모험 시작                    =" << endl;
		cout << "=      3. 상점                         =" << endl;
		cout << "=      4. 현재 로그 사용               =" << endl;
		cout << "=      5. 게임 종료                    =" << endl;
		cout << "=                                      =" << endl;
		cout << "========================================" << endl << endl;
		cout << "진행 선택 : ";

		int choice;
		cin >> choice;
		clearScreen();
		if (cin.fail()) 
		{ // 숫자가 아닌 입력이 들어왔을 때 처리
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = 0;
		}

		if (choice == 1)
		{
			player.displayStatus(); // 플레이어 스텟 출력 함수 호출
			player.ItemList(); // 플레이어 인벤토리 출력 함수 호출
			cout << endl;

		}
		else if (choice == 2)
		{
			manager.battle(player);
		}
	
		else if (choice == 3)
		{
			while (true)
			{
				shop.displayItems();

				int shopchoice;
				cout << "1. 아이템 구매" << endl;
				cout << "2. 아이템 판매" << endl;
				cout << "3. 상점 나가기" << endl;
				cout << "입력 : ";
				cin >> shopchoice;

				if (shopchoice == 1)
				{
					int index1;
					cout << "구매할 아이템을 선택하라냥 : ";
					cin >> index1;
					clearScreen();
					shop.buyItem(index1, player);
					cout << endl;
					
				}
				else if (shopchoice == 2)
				{
					int index2;
					cout << "판매할 아이템 : ";
					cin >> index2;
					clearScreen();
					shop.sellItem(index2, player);
					cout << endl;
					
				}
				else if (shopchoice == 3)
				{
					clearScreen();
					break;
				}
				else
				{
					cout << "잘못된 입력입니다." << endl;
				}
			}
		}
		else if (choice == 4)
		{
			manager.displayMonsterKillCounts(); // 플레이어가 처치한 몬스터 수 출력 함수 호출
		}
		else if (choice == 5)
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
	
	manager.gameOverLog(player);

	return 0;
}
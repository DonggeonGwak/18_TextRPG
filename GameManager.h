
#pragma once
#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "Monster.h"
#include "Character.h"
 // C++11���� �����Ǵ� ���� ���� ���̺귯��

using namespace std;

//�÷��̾� HP�� 0 �̻��� ��� ������ ��� ����
//�÷��̾� HP�� 0 ������ ��� ������ �����մϴ�.
//�ڵ� �ݺ� ����� �ϴ� ���� �Ŵ��� Ŭ����
//���� �Ŵ��� Ŭ������ �÷��̾�� ������ ���¸� �����ϰ�, ������ �����մϴ�.
// ���� �Ŵ��� Ŭ������ �÷��̾�� ������ ���¸� ����մϴ�.
// ���� �Ŵ��� Ŭ������ �÷��̾�� ������ ���¸� ������Ʈ�մϴ�.
// ĳ���Ͱ� ������ �� �� ���� ����ġ�� ȹ���ϰ�, ������ �ø��ϴ�.
// ��Ʋ	Ŭ������ �÷��̾�� ������ ���¸� �����ϰ�, ������ �����մϴ�.

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






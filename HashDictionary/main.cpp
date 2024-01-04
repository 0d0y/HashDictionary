#include "MyHash.h"
#include "StdHash.h"
#include "Timer.h"
#include <conio.h>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;

set<string> g_SetAll;	// ���� ���� Ʈ��

void LoadWordsFromFile(set<string>& cotainer)
{
	/// ���Ͽ��� ��� ������ �о, set<string>�� �ִ´�.
	fstream file;
	string word, t, q, filename;

	filename = "../english3.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		cotainer.insert(word);
	}
	cout << "���� �ε� �Ϸ�!" << endl;
}

int main()
{
	/// �ð� ��� �Լ�
	Timer _profiler;
	LoadWordsFromFile(g_SetAll);

	Hash* myHash = new MyHash();
	Hash* stdHash = new StdHash();
	//_getch(); // Ű�� ������ ����

	std::cout << "myHash LoadDictionary";
	_profiler.Start(); // �ð� ���� ����
	myHash->LoadDictionary(g_SetAll);
	_profiler.End();   // �ð� ���� ��
	_profiler.GetElaspedTime(); // �ð� ���

	std::cout << "stdHash LoadDictionary";
	_profiler.Start(); // �ð� ���� ����
	stdHash->LoadDictionary(g_SetAll);
	_profiler.End();   // �ð� ���� ��
	_profiler.GetElaspedTime(); // �ð� ���

	std::cout << "myHash Find" << std::endl;
	_profiler.Start(); // �ð� ���� ����
	myHash->Find("fantasy");
	_profiler.End();   // �ð� ���� ��
	_profiler.GetElaspedTime(); // �ð� ���

	std::cout << "stdHash Find" << std::endl;
	_profiler.Start(); // �ð� ���� ����
	stdHash->Find("fantasy");
	_profiler.End();   // �ð� ���� ��
	_profiler.GetElaspedTime(); // �ð� ���

	myHash->PrintIssue();
	stdHash->PrintIssue();

	//delete myHash;
	delete stdHash;
	return 0;
}



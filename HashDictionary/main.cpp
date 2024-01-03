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

set<string> g_SetAll;	// 완전 이진 트리

void LoadWordsFromFile(set<string>& cotainer)
{
	/// 파일에서 모든 내용을 읽어서, set<string>에 넣는다.
	fstream file;
	string word, t, q, filename;

	filename = "../english3.txt";
	file.open(filename.c_str());
	while (file >> word)
	{
		cotainer.insert(word);
	}
	cout << "파일 로드 완료!" << endl;
}

int main()
{
	/// 시간 재는 함수
	Timer _profiler;
	LoadWordsFromFile(g_SetAll);

	Hash* myHash = new MyHash();
	Hash* stdHash = new StdHash();
	//_getch(); // 키를 눌러야 진행

	std::cout << "myHash LoadDictionary";
	_profiler.Start(); // 시간 측정 시작
	myHash->LoadDictionary(g_SetAll);
	_profiler.End();   // 시간 측정 끝
	_profiler.GetElaspedTime(); // 시간 출력

	std::cout << "stdHash LoadDictionary";
	_profiler.Start(); // 시간 측정 시작
	stdHash->LoadDictionary(g_SetAll);
	_profiler.End();   // 시간 측정 끝
	_profiler.GetElaspedTime(); // 시간 출력

	std::cout << "myHash Find" << std::endl;
	_profiler.Start(); // 시간 측정 시작
	myHash->Find("fantasy");
	_profiler.End();   // 시간 측정 끝
	_profiler.GetElaspedTime(); // 시간 출력

	std::cout << "stdHash Find" << std::endl;
	_profiler.Start(); // 시간 측정 시작
	stdHash->Find("fantasy");
	_profiler.End();   // 시간 측정 끝
	_profiler.GetElaspedTime(); // 시간 출력

	myHash->PrintIssue();
	stdHash->PrintIssue();

	//delete myHash;
	delete stdHash;
	return 0;
}



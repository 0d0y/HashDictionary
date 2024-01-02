#pragma once

#include <windows.h>

/// <summary>
/// 수행 시간을 재는 클래스
/// 자료구조&알고리즘 수업을 위해서 만들다.
///
/// 2020.10.23 LeHide
/// </summary>
class Timer
{
public:
	Timer();


	void Start();
	void End();

	double GetElaspedTime();

private:
	// 수행시간을 재 보자.
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER Endtime;
};


#pragma once
#include "stdafx.h"
#include <cctype>

enum _flag { SUCCESS, EMPTY, FULL, NOTARGET, INVALID, ALREADYEXIST, NOSPACE }; //각 함수들의 리턴값

struct commands //undo를 위한 구조체
{
	CString data[40];
	CPoint data2[144];
	int size;
	int size2;
	bool max;
	bool min;
	commands() { size = 0, size2 = 0, max = false, min = false; }
};

class DataStructure
{
private :

public :
	virtual _flag Insert(CString data) = 0;
	virtual _flag Delete(CString data) = 0;
	virtual _flag Clear() = 0;
	
	virtual _flag Sort() { return INVALID; } //리스트의 소트를 위한 함수
	
	virtual BOOL IsEmpty() = 0;
	virtual BOOL IsFull() = 0;
	virtual int GetSize() = 0;

	BOOL max, min; //FALSE로 초기화. 트리에서 맥스힙버튼이 눌린 후에 max가 TRUE, min이 FALSE. 민힙버튼 경우 반대.
	BOOL HeapWait; //TRUE로 초기화. 멕스힙이나 민힙버튼 누르면 FALSE가 되고 진행 후 다시 TRUE. TRUE일 때 힙업 과정이 보인다.
	int sort1, sort2; //현재 swap 되는 데이터를 품고 있는 박스의 인덱스

	CPaintDC *pDC; //뷰의 CPaintDC를 받아와서 적절한 때에 데이터 출력
	CDialogEx *pDlg; //뷰를 받아와서 적절한 때에 Invalidate함수 호출
	virtual void print(CRect * Box, CString recent) {}; //데이터 출력

	//undo를 위한 함수
	virtual commands getData() = 0; //최근 데이터를 받아와서
	virtual void changeData(commands com) = 0; //현재 데이터를 받아온 데이터로 교체

	void Wait(DWORD dwMillisecond) //Sleep 역할
	{
		MSG msg;
		DWORD t0, t1, diff;

		t0 = GetTickCount();
		while (TRUE)
		{
			t1 = GetTickCount();

			if (t0 <= t1)
			{
				diff = t1 - t0;
			}
			else
			{
				diff = 0xFFFFFFFF - t0 + t1;
			}
			if (diff > dwMillisecond)
			{
				break;
			}

			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			Sleep(1);
		}
	}
	
	bool cmp(CString a, CString b) //CString 비교 함수 >=와 같음
	{
		if (a.GetLength() > b.GetLength())
		{
			return TRUE;
		}
		else if (a.GetLength() == b.GetLength())
		{
			for (int i = 0; i < a.GetLength(); i++)
			{
				if (a[i] < b[i])
				{
					return FALSE;
				}
				else if (a[i] > b[i])
				{
					return TRUE;
				}
			}
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	bool isNumeric(CString str) //숫자인지 체크
	{
		for (int i = 0; i<str.GetLength(); i++) 
		{
			if (!std::isdigit(str[i]))
			{
				return false;
			}
		}
		return true;
	}
};
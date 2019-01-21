#pragma once
#include "stdafx.h"
#include <cmath>
#include "DataStructure.h"

class Graph : public DataStructure
{
private:
	CArray<CString, CString&> graph; //엣지 저장하는 어레이
	CArray<CPoint, CPoint&> vertex; //벌텍스 저장하는 어레이

public:
	virtual _flag Insert(CString data);
	virtual _flag Delete(CString data);
	virtual _flag Clear();

	_flag Add_Vertex(int start, int end);
	_flag Delete_Vertex(int start, int end);

	virtual BOOL IsEmpty();
	virtual BOOL IsFull();
	virtual int GetSize();
	int vGetSize(); //벌텍스의 사이즈 반환

	virtual void print(CRect * Box, CString recent); //데이터 출력
	void printLine(CRect* Box); //벌텍스 출력
	virtual commands getData();
	virtual void changeData(commands com);
};
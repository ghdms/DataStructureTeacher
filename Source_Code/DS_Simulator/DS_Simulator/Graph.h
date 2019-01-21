#pragma once
#include "stdafx.h"
#include <cmath>
#include "DataStructure.h"

class Graph : public DataStructure
{
private:
	CArray<CString, CString&> graph; //���� �����ϴ� ���
	CArray<CPoint, CPoint&> vertex; //���ؽ� �����ϴ� ���

public:
	virtual _flag Insert(CString data);
	virtual _flag Delete(CString data);
	virtual _flag Clear();

	_flag Add_Vertex(int start, int end);
	_flag Delete_Vertex(int start, int end);

	virtual BOOL IsEmpty();
	virtual BOOL IsFull();
	virtual int GetSize();
	int vGetSize(); //���ؽ��� ������ ��ȯ

	virtual void print(CRect * Box, CString recent); //������ ���
	void printLine(CRect* Box); //���ؽ� ���
	virtual commands getData();
	virtual void changeData(commands com);
};
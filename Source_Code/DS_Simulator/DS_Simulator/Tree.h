#pragma once
#include "stdafx.h"
#include "DataStructure.h"
const int MAX_SIZE = 15;

class Tree : public DataStructure
{
private :
	CArray<CString, CString&> tree;
	int size;

public :
	void init();
	virtual _flag Insert(CString data);
	virtual _flag Delete(CString data);
	virtual _flag Clear();

	void MaxHeapUp(int nodeIndex, CArray<CString, CString&>& data);
	//void MaxHeapDown(int nodeIndex);
	void MinHeapUp(int nodeIndex, CArray<CString, CString&>& data);
	//void MinHeapDown(int nodeIndex);
	
	_flag toBST();
	_flag MakeMaxheap(); //맥스힙버튼 누르면 호출. 맥스힙으로 변환
	_flag MakeMinheap(); //민힙버튼 누르면 호출. 민힙으로 변환

	virtual BOOL IsEmpty();
	virtual BOOL IsFull();
	virtual int GetSize();

	bool isExist(CString a); //중복 검사
	bool isNull(int a); //NULL인지 체크

	virtual void print(CRect * Box, CString recent);
	virtual commands getData();
	virtual void changeData(commands com);
};
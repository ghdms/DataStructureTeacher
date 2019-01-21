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
	_flag MakeMaxheap(); //�ƽ�����ư ������ ȣ��. �ƽ������� ��ȯ
	_flag MakeMinheap(); //������ư ������ ȣ��. �������� ��ȯ

	virtual BOOL IsEmpty();
	virtual BOOL IsFull();
	virtual int GetSize();

	bool isExist(CString a); //�ߺ� �˻�
	bool isNull(int a); //NULL���� üũ

	virtual void print(CRect * Box, CString recent);
	virtual commands getData();
	virtual void changeData(commands com);
};
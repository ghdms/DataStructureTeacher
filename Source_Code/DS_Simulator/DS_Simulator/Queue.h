#pragma once
#include "stdafx.h"
#include "DataStructure.h"

class Queue : public DataStructure
{
private:
	CList<CString> queue;

public:
	virtual _flag Insert(CString data);
	virtual _flag Delete(CString data);
	virtual _flag Clear();
	virtual commands getData();
	virtual BOOL IsEmpty();
	virtual BOOL IsFull();
	virtual int GetSize();
	

	virtual void print(CRect * Box, CString recent);
	virtual void changeData(commands com);
};
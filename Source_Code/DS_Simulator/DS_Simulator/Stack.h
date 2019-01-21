#pragma once
#include "stdafx.h"
#include "DataStructure.h"

class Stack : public DataStructure
{
private:
	CList<CString> stack;

public:

	virtual _flag Insert(CString data);
	virtual _flag Delete(CString data);
	virtual _flag Clear();
	
	virtual BOOL IsEmpty();
	virtual BOOL IsFull();
	virtual int GetSize();

	virtual void print(CRect * Box, CString recent);
	virtual commands getData();
	virtual void changeData(commands com);
};
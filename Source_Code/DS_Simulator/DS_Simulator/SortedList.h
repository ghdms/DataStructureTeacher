#pragma once
#include "stdafx.h"
#include "DataStructure.h"

class SortedList : public DataStructure
{
private:
	CList<CString> sortedlist;

public:
	virtual _flag Insert(CString data);
	virtual _flag Delete(CString data);

	virtual BOOL IsEmpty();
	virtual BOOL IsFull();
	virtual int GetSize();

	virtual void print(CRect * Box);
};
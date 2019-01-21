#pragma once
#include "stdafx.h"
#include "SortedList.h"

_flag SortedList ::Insert(CString data)
{ 
	if (!IsFull())
	{
		CString temp;
		POSITION pos = sortedlist.GetHeadPosition();
		while (pos != NULL)
		{
			temp = sortedlist.GetAt(pos);
			if (data.GetLength() < temp.GetLength())
			{
				sortedlist.InsertBefore(pos, data);
				return SUCCESS;	
			}
			else if (data.GetLength() == temp.GetLength())
			{
				if (data < temp)
				{
					sortedlist.InsertBefore(pos, data);
					return SUCCESS;
				}
			}	
			sortedlist.GetNext(pos);
		}
		sortedlist.AddTail(data);
		return NOTARGET; 
	}
	else
	{
		return FULL;
	}
}	

_flag SortedList::Delete(CString data)
{
	if (!IsEmpty())
	{
		CString temp;
		POSITION pos = sortedlist.GetHeadPosition();
		while (pos != NULL)
		{
			temp = sortedlist.GetAt(pos);
			if (temp == data)
			{
				sortedlist.RemoveAt(pos);
				return SUCCESS;
			}
			sortedlist.GetNext(pos);
		}
		return NOTARGET;
	}
	else
	{
		return EMPTY;
	}
}

BOOL SortedList::IsEmpty() 
{ 
	if (GetSize())
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

BOOL SortedList::IsFull()
{ 
	if (GetSize() == 30)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int SortedList::GetSize()
{ 
	return sortedlist.GetSize();
}

void SortedList::print(CRect * Box)
{
	int idx = 0;
	POSITION pos = sortedlist.GetHeadPosition();
	CString item;

	if (pDC != NULL)
	{
		while (pos != NULL)
		{
			item = sortedlist.GetAt(pos);
			pDC->TextOutA(Box[idx].left + 30, Box[idx].top + 30, item);
			sortedlist.GetNext(pos);
			idx++;
		}
	}
}
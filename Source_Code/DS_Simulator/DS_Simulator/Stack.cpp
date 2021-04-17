#pragma once
#include "stdafx.h"
#include "Stack.h"

_flag Stack :: Insert(CString data)
{
	if (!IsFull())
	{
		if (data == "")
		{
			return INVALID;
		}
		stack.AddTail(data);
		return SUCCESS;
	}
	else
	{
		return FULL;
	}
}

_flag Stack::Delete(CString data)
{ 
	if (!IsEmpty())
	{
		stack.RemoveTail();
		return SUCCESS;
	}
	else
	{
		return EMPTY;
	}
}

_flag Stack::Clear()
{
	stack.RemoveAll();
	return SUCCESS;
}

BOOL Stack::IsEmpty() 
{ 
	return GetSize() == 0;
}

BOOL Stack::IsFull() 
{ 
	return GetSize() == 30;
}

int Stack::GetSize() 
{
	return (int)stack.GetSize();
}

void Stack::print(CRect * Box, CString recent)
{
	int idx = GetSize() - 1;
	POSITION pos = stack.GetTailPosition(); //끝부터 탐색하는 이유는 가장 마지막에 입력한 데이터를 빨간색 볼드체로
	//처리하려 하는데 스택에선 중복 검사를 하지 않아서 더 뒤에 있는 데이터가 더 최근에 넣은 데이터이므로 뒤부터 탐색
	CString item;
	BOOL check = FALSE; //가장 마지막에 넣은 데이터의 값과 같은 값이 있는지 체크
	if (pDC != NULL)
	{
		while (pos != NULL)
		{
			item = stack.GetAt(pos);
			if (item == recent && !check) //가장 마지막에 넣은 데이터라면 빨간색 볼드체 처리
			{
				CFont cFont;
				cFont.CreateFont(15, 10, 0, 0, FALSE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
					CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("굴림체"));
				pDC->SelectObject(cFont);
				pDC->SetTextColor(RGB(255, 0, 0));
				check = TRUE;
			}
			pDC->DrawText(CString(item), -1, &Box[idx],
				DT_CENTER | DT_VCENTER | DT_SINGLELINE); //박스 중앙 정렬로 데이터 출력
			stack.GetPrev(pos);
			idx--;

			pDC->SetTextColor(RGB(0, 0, 0));
			CFont ff;
			ff.CreatePointFont(100, CString("굴림"));
			pDC->SelectObject(ff);
			ff.DeleteObject();
		}
	}
}

commands Stack::getData()
{
	commands a;
	POSITION pos = stack.GetHeadPosition();
	for (int i = 0; i < stack.GetSize(); i++)
	{
		a.data[i]=stack.GetNext(pos);
		a.size++;
	}
	return a;
}

void Stack::changeData(commands com)
{
	stack.RemoveAll();
	for (int i = 0; i < com.size; i++)
	{
		stack.AddTail(com.data[i]);
	}
}
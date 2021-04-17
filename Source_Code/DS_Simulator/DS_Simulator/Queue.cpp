#pragma once
#include "stdafx.h"
#include "Queue.h"

_flag Queue::Insert(CString data)
{
	if (!IsFull())
	{
		if (data == "") //빈칸 제외
		{
			return INVALID;
		}
		queue.AddTail(data);
		return SUCCESS;
	}
	else
	{
		return FULL;
	}
}

_flag Queue::Delete(CString data)
{
	if (!IsEmpty())
	{
		queue.RemoveHead();
		return SUCCESS;
	}
	else
	{
		return EMPTY;
	}
}
_flag Queue::Clear()
{
	queue.RemoveAll();
	return SUCCESS;
}
BOOL Queue::IsEmpty()
{
	return GetSize() == 0;
}

BOOL Queue::IsFull()
{
	return GetSize() == 30;
}

int Queue::GetSize()
{
	return (int)queue.GetSize();
}

void Queue::print(CRect * Box, CString recent)
{
	int idx = GetSize() - 1;
	POSITION pos = queue.GetTailPosition(); //끝부터 탐색하는 이유는 가장 마지막에 입력한 데이터를 빨간색 볼드체로
	//처리하려 하는데 큐에선 중복 검사를 하지 않아서 더 뒤에 있는 데이터가 더 최근에 넣은 데이터이므로 뒤부터 탐색
	CString item;
	BOOL check = FALSE; //가장 마지막에 넣은 데이터의 값과 같은 값이 있는지 체크
	if (pDC != NULL)
	{
		while (pos != NULL)
		{
			item = queue.GetAt(pos);
			if (item == recent && !check) //가장 마지막에 넣은 데이터라면 빨간색 볼드체 처리
			{
				CFont cFont;
				cFont.CreateFont(15, 10, 0, 0, FALSE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
					CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("굴림체"));
				pDC->SelectObject(cFont);
				pDC->SetTextColor(RGB(255, 0, 0));
				check = TRUE;
			}
			pDC->DrawText(CString(item), -1, &Box[idx],
				DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			queue.GetPrev(pos);
			idx--;

			pDC->SetTextColor(RGB(0, 0, 0));
			CFont cFont1;
			cFont1.CreateFont(16, 7, 0, 0, 70, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("굴림")); //박스 중앙 정렬로 데이터 출력
			pDC->SelectObject(cFont1);
		}
	}
}

commands Queue::getData()
{
	commands a;
	POSITION pos = queue.GetHeadPosition();
	for (int i = 0; i < queue.GetSize(); i++)
	{
		a.data[i]= queue.GetNext(pos);
		a.size++;
	}
	return a;
}

void Queue::changeData(commands com)
{
	queue.RemoveAll();
	for (int i = 0; i < com.size; i++)
	{
		queue.AddTail(com.data[i]);
	}
}
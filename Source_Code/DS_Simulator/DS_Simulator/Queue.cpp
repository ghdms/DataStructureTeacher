#pragma once
#include "stdafx.h"
#include "Queue.h"

_flag Queue::Insert(CString data)
{
	if (!IsFull())
	{
		if (data == "") //��ĭ ����
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
	POSITION pos = queue.GetTailPosition(); //������ Ž���ϴ� ������ ���� �������� �Է��� �����͸� ������ ����ü��
	//ó���Ϸ� �ϴµ� ť���� �ߺ� �˻縦 ���� �ʾƼ� �� �ڿ� �ִ� �����Ͱ� �� �ֱٿ� ���� �������̹Ƿ� �ں��� Ž��
	CString item;
	BOOL check = FALSE; //���� �������� ���� �������� ���� ���� ���� �ִ��� üũ
	if (pDC != NULL)
	{
		while (pos != NULL)
		{
			item = queue.GetAt(pos);
			if (item == recent && !check) //���� �������� ���� �����Ͷ�� ������ ����ü ó��
			{
				CFont cFont;
				cFont.CreateFont(15, 10, 0, 0, FALSE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
					CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("����ü"));
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
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("����")); //�ڽ� �߾� ���ķ� ������ ���
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
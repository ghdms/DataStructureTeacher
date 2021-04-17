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
	POSITION pos = stack.GetTailPosition(); //������ Ž���ϴ� ������ ���� �������� �Է��� �����͸� ������ ����ü��
	//ó���Ϸ� �ϴµ� ���ÿ��� �ߺ� �˻縦 ���� �ʾƼ� �� �ڿ� �ִ� �����Ͱ� �� �ֱٿ� ���� �������̹Ƿ� �ں��� Ž��
	CString item;
	BOOL check = FALSE; //���� �������� ���� �������� ���� ���� ���� �ִ��� üũ
	if (pDC != NULL)
	{
		while (pos != NULL)
		{
			item = stack.GetAt(pos);
			if (item == recent && !check) //���� �������� ���� �����Ͷ�� ������ ����ü ó��
			{
				CFont cFont;
				cFont.CreateFont(15, 10, 0, 0, FALSE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
					CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("����ü"));
				pDC->SelectObject(cFont);
				pDC->SetTextColor(RGB(255, 0, 0));
				check = TRUE;
			}
			pDC->DrawText(CString(item), -1, &Box[idx],
				DT_CENTER | DT_VCENTER | DT_SINGLELINE); //�ڽ� �߾� ���ķ� ������ ���
			stack.GetPrev(pos);
			idx--;

			pDC->SetTextColor(RGB(0, 0, 0));
			CFont ff;
			ff.CreatePointFont(100, CString("����"));
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
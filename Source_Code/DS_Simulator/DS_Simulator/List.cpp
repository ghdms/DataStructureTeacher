#pragma once
#include "stdafx.h"
#include "List.h"

_flag List :: Insert(CString data)
{ 
	if (!IsFull())
	{
		if (data == "") //��ĭ ����
		{
			return INVALID;
		}
		if (!isNumeric(data)) //�������� üũ (����Ʈ�� ���� ����� �����ϱ� ������ int�θ� �Է�)
		{
			return INVALID;
		}

		POSITION pos = list.GetHeadPosition();
		while (pos != NULL)
		{
			if (data == list.GetAt(pos)) //�ߺ� ����
			{
				return ALREADYEXIST;
			}
			list.GetNext(pos);
		}

		list.AddTail(data);
		return SUCCESS;
	}
	else
	{
		return FULL;
	}
}

_flag List::Delete(CString data)
{ 
	if (!IsEmpty())
	{
		CString temp;
		POSITION pos = list.GetHeadPosition();
		while (pos != NULL)
		{
			temp = list.GetAt(pos);
			if (temp == data)
			{
				list.RemoveAt(pos);
				return SUCCESS;
			}
			list.GetNext(pos);
		}

		return NOTARGET;
	}
	else
	{
		return EMPTY;
	}
}

BOOL List::IsEmpty()
{
	return GetSize() == 0;
}

BOOL List::IsFull() 
{ 
	return GetSize() == 30;
}

int List::GetSize() 
{ 
	return (int)list.GetSize();
}

void List::print(CRect * Box, CString recent)
{
	int idx = 0;
	POSITION pos = list.GetHeadPosition();
	CString item;

	if (pDC != NULL)
	{
		while (pos != NULL)
		{
			item = list.GetAt(pos);
			if (item == recent) //���� �������� ���� �����Ͷ�� ������ ����ü ó��
			{
				CFont cFont;
				cFont.CreateFont(15, 10, 0, 0, FALSE , FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
					CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("����ü"));
				pDC->SelectObject(cFont);
				pDC->SetTextColor(RGB(255, 0, 0));
			}
			pDC->DrawText(CString(item), -1, &Box[idx],
				DT_CENTER | DT_VCENTER | DT_SINGLELINE); //�ڽ� �߾� �����ؼ� ������ ���
			list.GetNext(pos);
			idx++;
			pDC->SetTextColor(RGB(0, 0, 0));
			CFont ff;
			ff.CreatePointFont(100, CString("����"));
			pDC->SelectObject(ff);
			ff.DeleteObject();
		}
	}
}

_flag List::Clear()
{
	list.RemoveAll();
	return SUCCESS;
}

_flag List::Sort()
{
	if (list.IsEmpty())
	{
		return EMPTY;
	}

	bool bChanged = true;
	
	while (bChanged) //�� �̻� �ٲ� �� ������ ����
	{
		bChanged = false;
		int idx1 = 0;
		int idx2 = 0; //���� ���� �߿� �����Ͱ� �ٲ�� �ڽ� �ε��� �ʱ�ȭ

		POSITION pos = list.GetHeadPosition();
		POSITION pos_save;

		while (pos != NULL)
		{
			pos_save = pos;
			idx1 = idx2;
			CString i1 = list.GetNext(pos);
			idx2++;
			if (pos != NULL)
			{
				CString i2 = list.GetAt(pos);

				if (i2.GetLength() < i1.GetLength() || (i2.GetLength() == i1.GetLength() && i2 < i1))
				{
					bChanged = true;

					sort1 = idx1;
					sort2 = idx2; //�����Ͱ� �ٲ�� �ڽ� �ε��� ����

					pDlg->Invalidate(FALSE);
					Wait(1000);

					list.SetAt(pos_save, i2);
					list.SetAt(pos, i1); //swap

					pDlg->Invalidate(FALSE);
					Wait(500);
				}
			}
		}
	}
	sort1 = 300;
	sort2 = 300; //������ ���� �� �ڽ� ǥ�� ���ֱ� ���� �ִ� ������ �ʰ� ������ ����
	return SUCCESS;
}

commands List::getData()
{
	commands a;
	POSITION pos = list.GetHeadPosition();
	for (int i = 0; i < list.GetSize(); i++)
	{
		a.data[i] = list.GetNext(pos);
		a.size++;
	}
	return a;
}

void List::changeData(commands com)
{
	list.RemoveAll();
	for (int i = 0; i < com.size; i++)
	{
		list.AddTail(com.data[i]);
	}
}
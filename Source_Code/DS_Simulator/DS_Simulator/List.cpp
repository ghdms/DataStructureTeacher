#pragma once
#include "stdafx.h"
#include "List.h"

_flag List :: Insert(CString data)
{ 
	if (!IsFull())
	{
		if (data == "") //빈칸 제외
		{
			return INVALID;
		}
		if (!isNumeric(data)) //숫자인지 체크 (리스트에 정렬 기능을 제공하기 때문에 int로만 입력)
		{
			return INVALID;
		}

		POSITION pos = list.GetHeadPosition();
		while (pos != NULL)
		{
			if (data == list.GetAt(pos)) //중복 제거
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
			if (item == recent) //가장 마지막에 넣은 데이터라면 빨간색 볼드체 처리
			{
				CFont cFont;
				cFont.CreateFont(15, 10, 0, 0, FALSE , FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
					CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("굴림체"));
				pDC->SelectObject(cFont);
				pDC->SetTextColor(RGB(255, 0, 0));
			}
			pDC->DrawText(CString(item), -1, &Box[idx],
				DT_CENTER | DT_VCENTER | DT_SINGLELINE); //박스 중앙 정렬해서 데이터 출력
			list.GetNext(pos);
			idx++;
			pDC->SetTextColor(RGB(0, 0, 0));
			CFont ff;
			ff.CreatePointFont(100, CString("굴림"));
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
	
	while (bChanged) //더 이상 바뀔 게 없으면 종료
	{
		bChanged = false;
		int idx1 = 0;
		int idx2 = 0; //소팅 과정 중에 데이터가 바뀌는 박스 인덱스 초기화

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
					sort2 = idx2; //데이터가 바뀌는 박스 인덱스 저장

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
	sort2 = 300; //소팅이 끝난 후 박스 표시 없애기 위해 최대 사이즈 초과 값으로 설정
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
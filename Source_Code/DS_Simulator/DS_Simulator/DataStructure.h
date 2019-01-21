#pragma once
#include "stdafx.h"
#include <cctype>

enum _flag { SUCCESS, EMPTY, FULL, NOTARGET, INVALID, ALREADYEXIST, NOSPACE }; //�� �Լ����� ���ϰ�

struct commands //undo�� ���� ����ü
{
	CString data[40];
	CPoint data2[144];
	int size;
	int size2;
	bool max;
	bool min;
	commands() { size = 0, size2 = 0, max = false, min = false; }
};

class DataStructure
{
private :

public :
	virtual _flag Insert(CString data) = 0;
	virtual _flag Delete(CString data) = 0;
	virtual _flag Clear() = 0;
	
	virtual _flag Sort() { return INVALID; } //����Ʈ�� ��Ʈ�� ���� �Լ�
	
	virtual BOOL IsEmpty() = 0;
	virtual BOOL IsFull() = 0;
	virtual int GetSize() = 0;

	BOOL max, min; //FALSE�� �ʱ�ȭ. Ʈ������ �ƽ�����ư�� ���� �Ŀ� max�� TRUE, min�� FALSE. ������ư ��� �ݴ�.
	BOOL HeapWait; //TRUE�� �ʱ�ȭ. �߽����̳� ������ư ������ FALSE�� �ǰ� ���� �� �ٽ� TRUE. TRUE�� �� ���� ������ ���δ�.
	int sort1, sort2; //���� swap �Ǵ� �����͸� ǰ�� �ִ� �ڽ��� �ε���

	CPaintDC *pDC; //���� CPaintDC�� �޾ƿͼ� ������ ���� ������ ���
	CDialogEx *pDlg; //�並 �޾ƿͼ� ������ ���� Invalidate�Լ� ȣ��
	virtual void print(CRect * Box, CString recent) {}; //������ ���

	//undo�� ���� �Լ�
	virtual commands getData() = 0; //�ֱ� �����͸� �޾ƿͼ�
	virtual void changeData(commands com) = 0; //���� �����͸� �޾ƿ� �����ͷ� ��ü

	void Wait(DWORD dwMillisecond) //Sleep ����
	{
		MSG msg;
		DWORD t0, t1, diff;

		t0 = GetTickCount();
		while (TRUE)
		{
			t1 = GetTickCount();

			if (t0 <= t1)
			{
				diff = t1 - t0;
			}
			else
			{
				diff = 0xFFFFFFFF - t0 + t1;
			}
			if (diff > dwMillisecond)
			{
				break;
			}

			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			Sleep(1);
		}
	}
	
	bool cmp(CString a, CString b) //CString �� �Լ� >=�� ����
	{
		if (a.GetLength() > b.GetLength())
		{
			return TRUE;
		}
		else if (a.GetLength() == b.GetLength())
		{
			for (int i = 0; i < a.GetLength(); i++)
			{
				if (a[i] < b[i])
				{
					return FALSE;
				}
				else if (a[i] > b[i])
				{
					return TRUE;
				}
			}
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	bool isNumeric(CString str) //�������� üũ
	{
		for (int i = 0; i<str.GetLength(); i++) 
		{
			if (!std::isdigit(str[i]))
			{
				return false;
			}
		}
		return true;
	}
};
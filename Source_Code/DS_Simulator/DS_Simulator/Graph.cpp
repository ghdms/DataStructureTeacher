#pragma once
#include "stdafx.h"
#include "Graph.h"

_flag Graph::Insert(CString data)
{ 
	if (!IsFull())
	{
		if (data == "") //��ĭ ����
		{
			return INVALID;
		}
		graph.Add(data);
		return SUCCESS;
	}
	else
	{
		return FULL;
	}
}	

_flag Graph::Delete(CString data)
{ 
	if (!IsEmpty())
	{
		for (int i = 0; i < GetSize(); i++)
		{
			if (data == graph[i])
			{
				graph.RemoveAt(i);
				for (int j = 0; j < vGetSize(); j++) 
				{
					if (i == vertex[j].x || i == vertex[j].y) //������ ������ ����� ���ؽ� ������ ���� ����
					{
						vertex.RemoveAt(j);
						j--;
					}
					else // �ε��� ������ ����
					{
						if (i < vertex[j].x)
						{
							vertex[j].x--;
						}
						if (i < vertex[j].y)
						{
							vertex[j].y--;
						}
					}
				}
				return SUCCESS;
			}
		}
		return NOTARGET;
	}
	else
	{
		return EMPTY;
	}
}

_flag Graph::Clear()
{
	vertex.RemoveAll();
	graph.RemoveAll();
	return SUCCESS;
}

_flag Graph::Add_Vertex(int start, int end)
{
	CPoint temp;
	temp.x = start;
	temp.y = end;
	CPoint temp2;
	temp2.x = end;
	temp2.y = start;
	if (start > GetSize() - 1 || end > GetSize() - 1) //���� ��
	{
		return INVALID;
	}
	for (int i = 0; i < vGetSize(); i++) 
	{
		if (temp == vertex[i] || temp2 == vertex[i]) //�ߺ� ����
		{
			return ALREADYEXIST;
		}
	}
	vertex.Add(temp);
	return SUCCESS;
}

_flag Graph::Delete_Vertex(int start, int end)
{
	CPoint temp;
	temp.x = start;
	temp.y = end;
	CPoint temp2;
	temp2.x = end;
	temp2.y = start;
	for (int i = 0; i < vertex.GetSize(); i++)
	{
		if (temp == vertex[i] || temp2 == vertex[i])
		{
			vertex.RemoveAt(i);
			return SUCCESS;
		}
	}
	return NOTARGET;
}

BOOL Graph::IsEmpty()
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

BOOL Graph::IsFull() 
{ 
	if (GetSize() == 16)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int Graph::GetSize() 
{ 
	return (int)graph.GetSize(); 
}

int Graph::vGetSize() 
{ 
	return (int)vertex.GetSize(); 
}

void Graph::print(CRect * Box, CString recent) //������ ���
{
	if (pDC != NULL)
	{
		for (int i = 0; i < GetSize(); i++)
		{
			if (graph[i] == recent) //���� �������� �Է��� �����͸� ������ ����ü ó��
			{
				CFont cFont;
				cFont.CreateFont(15, 10, 0, 0, FALSE , FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
					CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("����ü"));
				pDC->SelectObject(cFont);
				pDC->SetTextColor(RGB(255, 0, 0));
			}
			pDC->DrawText(CString(graph[i]), -1, &Box[i],
				DT_CENTER | DT_VCENTER | DT_SINGLELINE); //�ڽ� �߾� �����ؼ� ������ ���
			pDC->SetTextColor(RGB(0, 0, 0));
		}
	}
}

void Graph::printLine(CRect* Box) //���ؽ� ���
{
	int x, y;
	CRect start, end;
	POINT st, ed;
	for (int i = 0; i < vertex.GetSize(); i++)
	{
		x = vertex[i].x;
		y = vertex[i].y;

		start = Box[x]; //���� �ڽ�
		end = Box[y]; //�� �ڽ�

		st.x = start.left + 35;
		st.y = start.top + 35;
		ed.x = end.left + 35;
		ed.y = end.top + 35; //������ �߽� ��ǥ�� ����

		pDC->MoveTo(st);
		pDC->LineTo(ed); //�� ����
	}
}

commands Graph::getData()
{
	commands a;
	for (int i = 0; i < graph.GetSize(); i++)
	{
		a.data[i] = graph[i];
		a.size++;
	}
	for (int i = 0; i < vertex.GetSize(); i++)
	{
		a.data2[i] = vertex[i];
		a.size2++;
	}
	return a;
}

void Graph::changeData(commands com)
{
	graph.RemoveAll();
	vertex.RemoveAll();
	for (int i = 0; i < com.size; i++)
	{
		graph.Add(com.data[i]);
	}
	for (int i = 0; i < com.size; i++)
	{
		vertex.Add(com.data2[i]);
	}
}
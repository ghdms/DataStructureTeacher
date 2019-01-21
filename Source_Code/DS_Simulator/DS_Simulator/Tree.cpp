#pragma once
#include "stdafx.h"
#include "Tree.h"

void Tree::init()
{
	CString nul = CString("NULL");
	for (int i = 0; i < MAX_SIZE; i++)
	{
		tree.Add(nul);
	}
	size = 0;
}

bool Tree::isNull(int a)
{
	CString nul = CString("NULL");
	if (tree[a] == nul)
	{
		return true;
	}
	return false;
}

int getLeftChildIndex(int nodeIndex) 
{
	return 2 * nodeIndex + 1;
}
int getRightChildIndex(int nodeIndex)
{
	return 2 * nodeIndex + 2;
}
int getParentIndex(int nodeIndex) 
{
	return (nodeIndex - 1) / 2;
}

void Tree::MaxHeapUp(int nodeIndex, CArray<CString, CString&>& data)
{
	int parentIndex;
	CString tmp;
	if (nodeIndex != 0) 
	{
		parentIndex = getParentIndex(nodeIndex);
		if (!cmp(data[parentIndex], data[nodeIndex])) //data[nodeIndex]�� �� ũ��
		{
			sort1 = parentIndex;
			sort2 = nodeIndex; //���� ���� �߿� �����Ͱ� �ٲ�� �ڽ� �ε��� ����
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(1000);
			}
			tmp = data[parentIndex];
			data[parentIndex] = data[nodeIndex];
			data[nodeIndex] = tmp; //swap
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(500);
			}
			MaxHeapUp(parentIndex, data);
		}
	}
	sort1 = 300;
	sort2 = 300; //�ڽ� ǥ�� ���ֱ� ���� �ִ� ������ �ʰ� ������ ����
}
void Tree::MinHeapUp(int nodeIndex, CArray<CString, CString&>& data)
{
	int parentIndex;
	CString tmp;
	if (nodeIndex != 0)
	{
		parentIndex = getParentIndex(nodeIndex);
		if (cmp(data[parentIndex], data[nodeIndex])) //data[parentIndex]�� �� ũ��
		{
			sort1 = parentIndex;
			sort2 = nodeIndex; //���� ���� �߿� �����Ͱ� �ٲ�� �ڽ� �ε��� ����
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(2000);
			}
			tmp = data[parentIndex];
			data[parentIndex] = data[nodeIndex];
			data[nodeIndex] = tmp;
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(500);
			}
			MinHeapUp(parentIndex, data);
		}
	}
	sort1 = 300;
	sort2 = 300; //�ڽ� ǥ�� ���ֱ� ���� �ִ� ������ �ʰ� ������ ����
}

_flag Tree::toBST()
{
	CArray<CString, CString&> temp;
	CString nul = CString("NULL");
	for (int i = 0; i < 15; i++)
	{
		temp.Add(nul);
	}
	CString item;
	int s = 0;
	int index;
	for (int i = 0; i < GetSize(); i++)
	{
		item = tree[i];
		index = 0;
		while (index < MAX_SIZE)
		{
			if (tree[index] == "NULL")
			{
				temp[index] = item;
				s++;
				break;
			}
			if (cmp(item, tree[index])) //item > tree[index]
			{
				index++;
				index *= 2;
			}
			else //item < tree[index]
			{
				index *= 2;
				index++;
			}
		}
	}
	size = s;
	pDlg->Invalidate();
	return SUCCESS;
}

_flag Tree::Insert(CString data)
{
	CString nul = CString("NULL");

	if (!IsFull())
	{
		if (data == "") //��ĭ ����
		{
			return INVALID;
		}
		if (!isNumeric(data)) //���� �ƴ� �� (������ ���� ����� �����ϱ� ������ int��)
		{
			return INVALID;
		}
		if (isExist(data)) //�ߺ� �˻�
		{
			return ALREADYEXIST;
		}
		
		if (max) //���� �ƽ����� ���(�ƽ�����ư�� ���� ���� ���)
		{
			if (size == MAX_SIZE)
			{
				return FULL;
			}
			else 
			{
				size++;
				tree[size - 1] = data;
				MaxHeapUp(size - 1, tree);
				return SUCCESS;
			}
		}
		else if (min) //���� ������ ���(������ư�� ���� ���� ���)
		{
			if (size == MAX_SIZE)
			{
				return FULL;
			}
			else 
			{
				size++;
				tree[size - 1] = data;
				MinHeapUp(size - 1, tree);
				return SUCCESS;
			}
		}
		else //Binary Search Tree �� ���
		{
			int index = 0;
			while (index < MAX_SIZE)
			{
				if (tree[index] == nul)
				{
					tree[index] = data;
					size++;
					return SUCCESS;
				}
				if (cmp(data,tree[index])) //data > tree[index]
				{
					index++;
					index *= 2;
				} 
				else //data < tree[index]
				{
					index *= 2;
					index++;
				}
			}
			return NOSPACE;
		}
	}
	else
	{
		return FULL;
	}
}
_flag Tree::Delete(CString data)
{
	/*	if (!IsEmpty())
	{
		for (int i = 0; i < GetSize(); i++)
		{

			if (data == tree[i])
			{
				tree[i] = tree[GetSize() - 1];
				tree.RemoveAt(GetSize() - 1);
				if (max)
				{
					MaxHeapDown(i, GetSize() - 1, tree);
				}
				else if (min)
				{
					MinHeapDown(i, GetSize() - 1, tree);
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
	*/
	return INVALID;
}

_flag Tree::Clear()
{
	tree.RemoveAll();
	init();
	return SUCCESS;
}

BOOL Tree::IsEmpty()
{
	if (size)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

BOOL Tree::IsFull()
{
	if (size == MAX_SIZE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int Tree::GetSize()
{
	return size;
}

void Tree::print(CRect * Box, CString recent)
{
	if (pDC != NULL)
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (tree[i] != "NULL")
			{
				if (tree[i] == recent) //���� �������� ���� �������� ��� ������ ����ü ó��
				{
					CFont cFont;
					cFont.CreateFont(15, 10, 0, 0, FALSE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
						CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("����ü"));
					pDC->SelectObject(cFont);
					pDC->SetTextColor(RGB(255, 0, 0));
				}
				pDC->DrawText(tree[i], -1, &Box[i], DT_CENTER | DT_VCENTER | DT_SINGLELINE); //�ڽ��� �߾� ���ķ� ���
				pDC->SetTextColor(RGB(0, 0, 0));

				CFont ff;
				ff.CreatePointFont(100, CString("����"));
				pDC->SelectObject(ff);
				ff.DeleteObject();
			}
		}
	}
}

_flag Tree::MakeMaxheap() //�ƽ������� ��ȯ
{ 
	CArray<CString, CString&> temp; //�ӽ� �ƽ���
	for (int i = 0; i < 15; i++) //����������
	{
		if (tree[i] != "NULL") //�����Ͱ� ������
		{
			temp.Add(tree[i]);
			MaxHeapUp((int)temp.GetSize() - 1, temp); //�ְ� �ƽ�����
		}
	}
	for (int i = 0; i < temp.GetSize(); i++)
	{
		tree[i] = temp[i]; //������ ����
	}
	for (int i = (int)temp.GetSize(); i < 15; i++)
	{
		tree[i] = "NULL"; //�������� NULL�� �ʱ�ȭ
	}
	return SUCCESS; 
}
//
_flag Tree::MakeMinheap() //�������� ��ȯ
{
	CArray<CString, CString&> temp; //�ӽ� ����
	for (int i = 0; i < 15; i++) //����������
	{
		if (tree[i] != "NULL") //�����Ͱ� ������
		{
			temp.Add(tree[i]);
			MinHeapUp((int)temp.GetSize() - 1, temp); //�ְ� ������
		} 
	}
	for (int i = 0; i < temp.GetSize(); i++)
	{
		tree[i] = temp[i]; //������ ����
	}
	for (int i = (int)temp.GetSize(); i < 15; i++)
	{
		tree[i] = "NULL"; //�������� NULL�� �ʱ�ȭ
	}
	return SUCCESS;
}

bool Tree::isExist(CString a)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (a == tree[i])
		{
			return true;
		}
	}
	return false;
}

commands Tree::getData()
{
	commands a;
	for (int i = 0; i < tree.GetSize(); i++)
	{
		a.data[i] = tree[i];
		a.size++;
	}
	if (max)
		a.max = true;
	if (min)
		a.min = true;
	
	return a;
}
void Tree::changeData(commands com)
{

	tree.RemoveAll();
	size = 0;
	for (int i = 0; i < com.size; i++)
	{
		if (com.data[i] != "NULL")
		{
			size++;
		}
		tree.Add(com.data[i]);
	}
	max = min = false;
	if (com.max)
		max = true;
	if (com.min)
		min = true;
}
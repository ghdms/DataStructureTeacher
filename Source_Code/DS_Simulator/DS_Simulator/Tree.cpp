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
		if (!cmp(data[parentIndex], data[nodeIndex])) //data[nodeIndex]가 더 크면
		{
			sort1 = parentIndex;
			sort2 = nodeIndex; //힙업 과정 중에 데이터가 바뀌는 박스 인덱스 저장
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
	sort2 = 300; //박스 표시 없애기 위해 최대 사이즈 초과 값으로 설정
}
void Tree::MinHeapUp(int nodeIndex, CArray<CString, CString&>& data)
{
	int parentIndex;
	CString tmp;
	if (nodeIndex != 0)
	{
		parentIndex = getParentIndex(nodeIndex);
		if (cmp(data[parentIndex], data[nodeIndex])) //data[parentIndex]가 더 크면
		{
			sort1 = parentIndex;
			sort2 = nodeIndex; //힙업 과정 중에 데이터가 바뀌는 박스 인덱스 저장
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(1000);
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
	sort2 = 300; //박스 표시 없애기 위해 최대 사이즈 초과 값으로 설정
}

void Tree::MaxHeapDown(int nodeIndex, CArray<CString, CString&>& data)
{
	int leftChildIndex;
	int rightChildIndex;
	CString tmp;
	CString nul = CString("NULL");
	if (nodeIndex < GetSize())
	{
		leftChildIndex = nodeIndex * 2 + 1;
		rightChildIndex = nodeIndex * 2 + 2;
		if (leftChildIndex >= MAX_SIZE)
		{
			sort1 = 300;
			sort2 = 300;
			return;
		}
		if (data[leftChildIndex] == nul && data[rightChildIndex] == nul)
		{
			sort1 = 300;
			sort2 = 300;
			return;
		}
		if (data[leftChildIndex] != nul && data[rightChildIndex] != nul)
		{
			if (cmp(data[nodeIndex], data[leftChildIndex]) && cmp(data[nodeIndex], data[rightChildIndex]))
			{
				sort1 = 300;
				sort2 = 300;
				return;
			}

			sort1 = nodeIndex;
			if (cmp(data[leftChildIndex], data[rightChildIndex]))
			{
				sort2 = leftChildIndex;
			}
			else
			{
				sort2 = rightChildIndex;
			}
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(1000);
			}
			tmp = data[nodeIndex];
			data[nodeIndex] = data[sort2];
			data[sort2] = tmp; //swap
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(500);
			}
			MaxHeapDown(sort2, data);
			return;
		}
		else if (!cmp(data[nodeIndex], data[leftChildIndex]))
		{
			sort1 = nodeIndex;
			sort2 = leftChildIndex;
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(1000);
			}
			tmp = data[nodeIndex];
			data[nodeIndex] = data[leftChildIndex];
			data[leftChildIndex] = tmp; //swap
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(500);
			}
			MaxHeapDown(leftChildIndex, data);
			return;
		}
	}
	sort1 = 300;
	sort2 = 300; //박스 표시 없애기 위해 최대 사이즈 초과 값으로 설정
}

void Tree::MinHeapDown(int nodeIndex, CArray<CString, CString&>& data)
{
	int leftChildIndex;
	int rightChildIndex;
	CString tmp;
	CString nul = CString("NULL");
	if (nodeIndex < GetSize())
	{
		leftChildIndex = nodeIndex * 2 + 1;
		rightChildIndex = nodeIndex * 2 + 2;
		if (leftChildIndex >= MAX_SIZE)
		{
			sort1 = 300;
			sort2 = 300;
			return;
		}
		if (data[leftChildIndex] == nul && data[rightChildIndex] == nul)
		{
			sort1 = 300;
			sort2 = 300;
			return;
		}
		if (data[leftChildIndex] != nul && data[rightChildIndex] != nul)
		{
			if (!cmp(data[nodeIndex], data[leftChildIndex]) && !cmp(data[nodeIndex], data[rightChildIndex]))
			{
				sort1 = 300;
				sort2 = 300;
				return;
			}

			sort1 = nodeIndex;
			if (!cmp(data[leftChildIndex], data[rightChildIndex]))
			{
				sort2 = leftChildIndex;
			}
			else
			{
				sort2 = rightChildIndex;
			}
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(1000);
			}
			tmp = data[nodeIndex];
			data[nodeIndex] = data[sort2];
			data[sort2] = tmp; //swap
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(500);
			}
			MinHeapDown(sort2, data);
			return;
		}
		else if (cmp(data[nodeIndex], data[leftChildIndex]))
		{
			sort1 = nodeIndex;
			sort2 = leftChildIndex;
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(1000);
			}
			tmp = data[nodeIndex];
			data[nodeIndex] = data[leftChildIndex];
			data[leftChildIndex] = tmp; //swap
			if (HeapWait)
			{
				pDlg->Invalidate(FALSE);
				Wait(500);
			}
			MinHeapDown(leftChildIndex, data);
			return;
		}
	}
	sort1 = 300;
	sort2 = 300; //박스 표시 없애기 위해 최대 사이즈 초과 값으로 설정
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
	if (IsFull())
	{
		return FULL;
	}
	if (data == "") //빈칸 제외
	{
		return INVALID;
	}
	if (!isNumeric(data)) //숫자 아닐 시 (힙에서 소팅 기능을 제공하기 때문에 int만)
	{
		return INVALID;
	}
	if (isExist(data)) //중복 검사
	{
		return ALREADYEXIST;
	}

	CString nul = CString("NULL");
	if (max) //지금 맥스힙인 경우(맥스힙버튼을 누른 후인 경우)
	{
		size++;
		tree[size - 1] = data;
		MaxHeapUp(size - 1, tree);
		return SUCCESS;
	}
	else if (min) //지금 민힙인 경우(민힙버튼을 누른 후인 경우)
	{
		size++;
		tree[size - 1] = data;
		MinHeapUp(size - 1, tree);
		return SUCCESS;
	}
	else //Binary Search Tree 인 경우
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

void Tree::afterDelete(int parentIndex, int originLeftIndex, int originRightIndex)
{
	if (originLeftIndex >= MAX_SIZE) {
		return;
	}
	CString nul = CString("NULL");
	if (tree[originLeftIndex] != nul) {
		tree[parentIndex * 2 + 1] = tree[originLeftIndex];
		tree[originLeftIndex] = nul;
		afterDelete(parentIndex * 2 + 1, originLeftIndex * 2 + 1, originLeftIndex * 2 + 2);
	}
	if (tree[originRightIndex] != nul) {
		tree[parentIndex * 2 + 2] = tree[originRightIndex];
		tree[originRightIndex] = nul;
		afterDelete(parentIndex * 2 + 2, originRightIndex * 2 + 1, originRightIndex * 2 + 2);
	}
}

_flag Tree::Delete(CString data)
{
	if (IsEmpty())
	{
		return EMPTY;
	}

	CString nul = CString("NULL");
	for (int i = MAX_SIZE - 1; i >= 0; i--)
	{
		if (data == tree[i])
		{
			if (!max && !min)
			{
				int leftChildIndex = i * 2 + 1;
				int rightChildIndex = i * 2 + 2;
				if (leftChildIndex >= MAX_SIZE || (tree[leftChildIndex] == nul && tree[rightChildIndex] == nul))
				{
					tree[i] = nul;
					size--;
				}
				else if (tree[leftChildIndex] != nul && tree[rightChildIndex] != nul)
				{
					//min of rights or max of lefts
					int targetIdx = rightChildIndex;
					while (2 * targetIdx + 1 < MAX_SIZE && tree[2 * targetIdx + 1] != nul) {
						targetIdx = 2 * targetIdx + 1;
					}
					tree[i] = tree[targetIdx];
					Delete(tree[targetIdx]);
				}
				else if (tree[leftChildIndex] == nul)
				{
					//jump
					tree[i] = tree[rightChildIndex];
					tree[rightChildIndex] = nul;
					afterDelete(i, rightChildIndex * 2 + 1, rightChildIndex * 2 + 2);
					size--;
				}
				else if (tree[rightChildIndex] == nul)
				{
					//jump
					tree[i] = tree[leftChildIndex];
					tree[leftChildIndex] = nul;
					afterDelete(i, leftChildIndex * 2 + 1, leftChildIndex * 2 + 2);
					size--;
				}
				return SUCCESS;
			}

			tree[i] = tree[GetSize() - 1];
			tree[GetSize() - 1] = nul;
			size--;
			if (tree[i] != nul) {
				if (max)
				{
					MaxHeapDown(i, tree);
					MaxHeapUp(i, tree);
				}
				else if (min)
				{
					MinHeapDown(i, tree);
					MinHeapUp(i, tree);
				}
			}
			return SUCCESS;
		}
	}
	return NOTARGET;
}

_flag Tree::Clear()
{
	tree.RemoveAll();
	sort1 = -1;
	sort2 = -1;
	max = FALSE;
	min = FALSE;
	init();
	return SUCCESS;
}

BOOL Tree::IsEmpty()
{
	return size == 0;
}

BOOL Tree::IsFull()
{
	return size == MAX_SIZE;
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
				if (tree[i] == recent) //가장 마지막에 넣은 데이터이 경우 빨간색 볼드체 처리
				{
					CFont cFont;
					cFont.CreateFont(15, 10, 0, 0, FALSE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
						CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("굴림체"));
					pDC->SelectObject(cFont);
					pDC->SetTextColor(RGB(255, 0, 0));
				}
				pDC->DrawText(tree[i], -1, &Box[i], DT_CENTER | DT_VCENTER | DT_SINGLELINE); //박스에 중앙 정렬로 출력
				pDC->SetTextColor(RGB(0, 0, 0));

				CFont ff;
				ff.CreatePointFont(100, CString("굴림"));
				pDC->SelectObject(ff);
				ff.DeleteObject();
			}
		}
	}
}

_flag Tree::MakeMaxheap() //맥스힙으로 변환
{ 
	CArray<CString, CString&> temp; //임시 맥스힙
	for (int i = 0; i < 15; i++) //순차적으로
	{
		if (tree[i] != "NULL") //데이터가 있으면
		{
			temp.Add(tree[i]);
			MaxHeapUp((int)temp.GetSize() - 1, temp); //넣고 맥스힙업
		}
	}
	for (int i = 0; i < temp.GetSize(); i++)
	{
		tree[i] = temp[i]; //원본에 저장
	}
	for (int i = (int)temp.GetSize(); i < 15; i++)
	{
		tree[i] = "NULL"; //나머지는 NULL로 초기화
	}
	return SUCCESS; 
}

_flag Tree::MakeMinheap() //민힙으로 변환
{
	CArray<CString, CString&> temp; //임시 민힙
	for (int i = 0; i < 15; i++) //순차적으로
	{
		if (tree[i] != "NULL") //데이터가 있으면
		{
			temp.Add(tree[i]);
			MinHeapUp((int)temp.GetSize() - 1, temp); //넣고 민힙업
		} 
	}
	for (int i = 0; i < temp.GetSize(); i++)
	{
		tree[i] = temp[i]; //원본에 저장
	}
	for (int i = (int)temp.GetSize(); i < 15; i++)
	{
		tree[i] = "NULL"; //나머지는 NULL로 초기화
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
	else if (min)
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
	else if (com.min)
		min = true;
}
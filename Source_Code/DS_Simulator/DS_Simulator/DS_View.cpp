// DSView.cpp : 구현 파일입니다.
//
#include "stdafx.h"
#include "DS_Simulator.h"
#include "DS_View.h"
#include "afxdialogex.h"
#include "DS_Input.h"
#include "DS_Input2.h"
#include <string>
const int left = 700;
const int top = 10;
const int right = 800;
const int bottom = 36;
// DSView 대화 상자입니다.

IMPLEMENT_DYNAMIC(DSView, CDialogEx)
DSView::DSView(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_VIEW_DIALOG, pParent)
{

}
DSView::~DSView()
{
}

//우측 메뉴 button 위치 지정, str을 캡션 지정
void DSView::showbutton(CButton* button, CString str)
{
	bcount--;
	button->ShowWindow(SW_SHOW);
	button->SetWindowPos(0, 790, bcount * 50 + 150, 106, 30, 0);
	if (str != "")
	{
		button->SetWindowText(str);
	}

}

//윈도우 위치 지정, DS에 따라서 우측 메뉴 지정, 우측 상단 아이콘 지정
void DSView::makeButton()	
{
	CRect rect;
	
	this->SetWindowPos(0, 0, 0, 950, 600, SWP_NOMOVE);
	m_PictureCtrl.SetWindowPos(0, 805, 20, 80, 80, 0);
	m_cancel.SetWindowPos(0, 805, 500, 86, 30, 0);

	switch (DS)
	{
	case LIST:

		bit.LoadBitmap(IDB_LIST);
		m_PictureCtrl.SetBitmap((HBITMAP)bit);
		bit.Detach();

		bcount = 5;
		data = new List();

		showbutton(&button_sort);
		showbutton(&button_undo);
		showbutton(&button_clear);
		showbutton(&button_delete);
		showbutton(&button_insert);
		break;

	case QUEUE:

		bit.LoadBitmap(IDB_QUEUE);
		m_PictureCtrl.SetBitmap((HBITMAP)bit);
		bit.Detach();

		bcount = 4;
		data = new Queue();

		showbutton(&button_undo);
		showbutton(&button_clear);
		showbutton(&button_delete, CString("Dequeue"));
		showbutton(&button_insert, CString("Enqueue"));
		break;

	case STACK:
		bit.LoadBitmap(IDB_STACK);
		m_PictureCtrl.SetBitmap((HBITMAP)bit);
		bit.Detach();

		bcount = 4;
		data = new Stack();

		showbutton(&button_undo);
		showbutton(&button_clear);
		showbutton(&button_delete, CString("Pop"));
		showbutton(&button_insert, CString("Push"));
		break;

	case TREE:
		bit.LoadBitmap(IDB_TREE);
		m_PictureCtrl.SetBitmap((HBITMAP)bit);
		bit.Detach();
		
		bcount = 6;
		data = new Tree();

		showbutton(&button_undo);
		showbutton(&button_clear);
		//showbutton(&button_fun3,CString("To BST"));
		showbutton(&button_fun2, CString("Min Heap"));
		showbutton(&button_fun1, CString("Max Heap"));
		showbutton(&button_delete);
		showbutton(&button_insert);
		break;

	case GRAPH:
		bit.LoadBitmap(IDB_GRAPH);
		m_PictureCtrl.SetBitmap((HBITMAP)bit);
		bit.Detach();

		bcount = 6;
		data = new Graph();

		showbutton(&button_undo);
		showbutton(&button_clear);
		showbutton(&button_fun2, CString("Delete Edge"));
		showbutton(&button_fun1, CString("Add Edge"));
		showbutton(&button_delete, CString("Delete Vertex"));
		showbutton(&button_insert, CString("Add Vertex"));
		break;
	}
}

void DSView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Insert, button_insert);
	DDX_Control(pDX, IDC_Delete, button_delete);
	DDX_Control(pDX, IDC_Clear, button_clear);
	DDX_Control(pDX, IDC_Undo, button_undo);
	DDX_Control(pDX, IDC_SORT, button_sort);
	DDX_Control(pDX, IDC_PICTURE_CONTROL, m_PictureCtrl);
	DDX_Control(pDX, IDC_FUNCTION1, button_fun1);
	DDX_Control(pDX, IDC_FUNCTION2, button_fun2);
	DDX_Control(pDX, IDC_FUNCTION3, button_fun3);
	DDX_Control(pDX, IDCANCEL, m_cancel);
	DDX_Control(pDX, IDC_HEAD, m_head);
	DDX_Control(pDX, IDC_TAIl, m_tail);
	DDX_Control(pDX, IDC_EMPTY, m_empty);
}

//메세지 맵
BEGIN_MESSAGE_MAP(DSView, CDialogEx)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDCANCEL, &DSView::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_Insert, &DSView::OnBnClickedInsert)
	ON_BN_CLICKED(IDC_Delete, &DSView::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_Clear, &DSView::OnBnClickedClear)
	ON_BN_CLICKED(IDC_Undo, &DSView::OnBnClickedUndo)
	ON_BN_CLICKED(IDC_SORT, &DSView::OnBnClickedSort)
	ON_BN_CLICKED(IDC_FUNCTION1, &DSView::OnBnClickedFunction1)
	ON_BN_CLICKED(IDC_FUNCTION2, &DSView::OnBnClickedFunction2)
	ON_BN_CLICKED(IDC_FUNCTION3, &DSView::OnBnClickedFunction3)
END_MESSAGE_MAP()


// DSView 메시지 처리기입니다.

//DoModal 오버라이딩, DS 입력 받아서 초기화
INT_PTR DSView::DoModal(dsl ds)
{
	DS = ds;
	bcount = 0;
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	return CDialogEx::DoModal();
}

BOOL DSView::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	isRunning = false;
	
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	//버튼 생성
	makeButton();
	
	//상태 비트맵
	m_head.ShowWindow(SW_HIDE);
	m_tail.ShowWindow(SW_HIDE);
	m_empty.ShowWindow(SW_HIDE);
	m_empty.SetWindowPos(0, 400, 200, 200, 200, 0);

	setBox();
	//초기값
	if (DS == TREE)
		dynamic_cast<Tree*>(data)->init();

	data->HeapWait = TRUE;
	data->sort1 = -1;
	data->sort2 = -1;

	showPictrl();
	CRect rrrr(0, 0, 790, 700);
	InvalidateRect(rrrr);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

//박스 위치 초기화
void DSView::setBox()
{
	//트리나 그래프를 제외하고는 박스가 선형
	if (DS != TREE && DS != GRAPH)
	{
		for (int i = 0; i < 30; i++)
		{
			Box[i] = CRect(40 + 70 * (i % 10), (i / 10) * 140 + 70, 100 + 70 * (i % 10), (i / 10) * 140 + 130);
		}
	}
	//그래프는 원형이므로 안보이게 지정
	else if (DS == GRAPH)
	{
		for (int i = 0; i < 30; i++)
		{
			Box[i] = CRect(0, 0, 0, 0);
		}
	}
	//트리형으로 지정
	else if (DS == TREE)
	{
		int w = 40;

		int cx = 340 + 420;
		cx /= 2;

		int fy = 40;
		int h = 70;

		Box[0] = CRect(cx + 5 - w, 40, cx + 5 + w, 40 + h);

		Box[1] = CRect(cx - 170 - w, 160, cx - 170 + w, 160 + h);
		Box[2] = CRect(cx + 190 - w, 160, cx + 190 + w, 160 + h);

		for (int i = 0; i < 4; i++)
		{
			Box[3 + i] = CRect(80 + 178 * i, 280, 80 + 178 * i + 2 * w, 280 + h);
		}

		for (int i = 0; i < 8; i++)
		{
			Box[7 + i] = CRect(30 + 90 * i, 400, 30 + 90 * i + 2 * w, 400 + h);
		}

		for (int i = 15; i < 30; i++)
		{
			Box[i] = CRect(0, 0, 0, 0);
		}
	}
}

//head tail empty 메세지 출력
void DSView::showPictrl()
{
	int size = data->GetSize();
	if (size == 0)
	{
		m_head.ShowWindow(SW_HIDE);
		m_tail.ShowWindow(SW_HIDE);

		m_empty.ShowWindow(SW_SHOWNOACTIVATE);
		bit.LoadBitmap(IDB_EMPTY);
		m_empty.SetBitmap((HBITMAP)bit);
		bit.Detach();
	}
	else
	{
		m_empty.ShowWindow(SW_HIDE);
		switch (DS)
		{
		case LIST:
			m_head.SetWindowPos(0, 40, 20, 100, 20, 0);
			m_head.ShowWindow(SW_SHOWNOACTIVATE);
			bit.LoadBitmap(IDB_HEAD);
			m_head.SetBitmap((HBITMAP)bit);
			bit.Detach();

			m_tail.SetWindowPos(0, 40 + 70 * ((size - 1) % 10), ((size - 1) / 10) * 140 + 20, 100, 20, 0);
			m_tail.ShowWindow(SW_SHOWNOACTIVATE);
			bit.LoadBitmap(IDB_TAIl);
			m_tail.SetBitmap((HBITMAP)bit);
			bit.Detach();
			break;
		case STACK:
			m_head.SetWindowPos(0, 40 + 70 * ((size - 1) % 10), ((size - 1) / 10) * 140 + 20, 100, 20, 0);
			m_head.ShowWindow(SW_SHOWNOACTIVATE);
			bit.LoadBitmap(IDB_TOP);
			m_head.SetBitmap((HBITMAP)bit);
			bit.Detach();
			break;

		case QUEUE:
			m_head.SetWindowPos(0, 40, 20, 100, 20, 0);
			m_head.ShowWindow(SW_SHOWNOACTIVATE);;
			bit.LoadBitmap(IDB_HEAD);
			m_head.SetBitmap((HBITMAP)bit);
			bit.Detach();

			m_tail.SetWindowPos(0, 40 + 70 * ((size - 1) % 10), ((size - 1) / 10) * 140 + 20, 100, 20, 0);
			m_tail.ShowWindow(SW_SHOWNOACTIVATE);
			bit.LoadBitmap(IDB_TAIl);
			m_tail.SetBitmap((HBITMAP)bit);
			bit.Detach();
			break;

		case TREE:

			break;

		case GRAPH:

			break;
		}
	}
}

void DSView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	data->pDC = &dc;
	data->pDlg = this;

	CPen pen;
	pen.CreatePen(PS_DOT, 3, RGB(0, 0, 0));
	dc.SelectObject(pen);

	CFont font;
	CFont * pOld;
	font.CreatePointFont(300, CString("굴림"));
	pOld = dc.SelectObject(&font);

	int size = data->GetSize();
	float dg = (float)6.283184 / (float)size;
	
	
	CRect tempr;
	if (DS != GRAPH)
	{
		int s = size;
		if (DS == TREE)
			s = MAX_SIZE;
		for (int i = 0; i < s; i++)
		{
				for (int i = 0; i < s; i++)
				{
					if (DS==TREE)
						if (dynamic_cast<Tree*>(data)->isNull(i))
							continue;

					//테두리랑 위에 검은색
					tempr = Box[i];
					tempr.bottom = tempr.top;
					tempr.top = tempr.top - 20;
					CPen pen;
					pen.CreatePen(PS_DOT, 3, RGB(0, 0, 0));
					CPen* oldPen = dc.SelectObject(&pen);

					CBrush brush;
					brush.CreateSolidBrush(RGB(0, 0, 0));
					CBrush* oldBrush = dc.SelectObject(&brush);
					dc.Rectangle(tempr);
					dc.SelectObject(oldBrush);

					CPen temp;
					temp.CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
					CPen * pTemp = NULL;
					if (i == data->sort1 || i == data->sort2)
					{
						pTemp = dc.SelectObject(&temp);
					}
					dc.Rectangle(Box[i]);
					if(pTemp != NULL)
						dc.SelectObject(pTemp);

					CString a;
					a.Format(_T("%d"), i + 1);
					dc.SetBkColor(RGB(0, 0, 0));
					dc.SetTextColor(RGB(255, 255, 255));

					CFont Font;
					CFont* pOldFont;
					Font.CreateFont(16, 7, 0, 0, 70, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
						CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("굴림"));
					pOldFont = (CFont*)dc.SelectObject(&Font);


					dc.DrawText(a, -1, &tempr, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


					dc.SetTextColor(RGB(0, 0, 0));
					dc.SetBkColor(RGB(255, 255, 255));
				}
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			//375, 275 중심
			//375 + 100cos(dg * (i + 1)), 275 + 100sin(dg * (i + 1))
			Box[i] = CRect((int)(375 + 210 * cos(dg * (i + 1)) - 35), (int)(275 + 210 * sin(dg * (i + 1)) - 35), 
				(int)(375 + 210 * cos(dg * (i + 1)) + 35), (int)(275 + 210 * sin(dg * (i + 1)) + 35));
		}
		dynamic_cast<Graph*>(data)->printLine(Box);
		CFont font11;
		font11.CreateFont(16, 7, 0, 0, 70, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, CString("굴림"));
		dc.SelectObject(&font11);
		for (int i = 0; i < size; i++)
		{
			dc.Ellipse(Box[i]);
			CString a;
			a.Format(CString("%d"), i);
			dc.TextOut((int)(366 + 261 * cos(dg * (i + 1))), int(266 + 260 * sin(dg * (i + 1))),a);
		}
		dc.SelectObject(&font);
		font11.DeleteObject();
	}
	font.DeleteObject();
	font.CreatePointFont(100, CString("굴림"));
	dc.SelectObject(&font);
	data->print(Box, recent);
	font.DeleteObject();
}

BOOL DSView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));
	return TRUE;
	return CDialogEx::OnEraseBkgnd(pDC);
}

//종료
void DSView::OnBnClickedCancel()
{
	if (isRunning)
		return;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	prev.RemoveAll();
	CDialogEx::OnCancel();
}

//삽입
void DSView::OnBnClickedInsert()
{
	if (isRunning)
		return;
	DS_Input input;
	_flag mes;
	BOOL check = FALSE;
	if (data->IsFull())
	{
		AfxMessageBox(CString("자료구조가 가득 찼습니다."));
	}
	else
	{
		if (input.DoModal() == IDOK)
		{
			prev.AddTail(data->getData());
			mes = data->Insert(input.m_input);
			switch (mes)
			{
			//enum _flag { SUCCESS, EMPTY, FULL, NOTARGET, INVALID, ALREADYEXIST, NOSPACE };
			case INVALID:
				AfxMessageBox(CString("잘못된 입력입니다."));
				check = TRUE;
				break;
			case FULL:
				AfxMessageBox(CString("자료구조가 가득 찼습니다."));
				check = TRUE;
				break;
			case NOTARGET:
				AfxMessageBox(CString("대상이 존재하지 않습니다."));
				check = TRUE;
				break;
			case ALREADYEXIST:
				AfxMessageBox(CString("대상이 이미 존재합니다."));
				check = TRUE;
				break;
			case NOSPACE:
				AfxMessageBox(CString("대상을 삽입할 공간이 없습니다."));
				check = TRUE;
				break;
			}

			if (mes == SUCCESS)
			{
				if (!check)
					recent = input.m_input;
			}
			else
			{
				prev.RemoveTail();
			}

			showPictrl();
			CRect rrrr(0, 0, 790, 700);
			InvalidateRect(rrrr);
		}
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//삭제
void DSView::OnBnClickedDelete()
{
	if (isRunning)
		return;
	if (data->IsEmpty())
	{
		AfxMessageBox(CString("자료구조가 비어있습니다."));
	}
	else
	{
		DS_Input input;
		_flag mes;
		prev.AddTail(data->getData());
		if (DS == STACK || DS == QUEUE)
		{
			mes=data->Delete(CString("A"));
		}
		else if (input.DoModal() == IDOK)
		{
			mes = data->Delete(input.m_input);
			if (mes == NOTARGET)
			{
				AfxMessageBox(CString("대상이 존재하지 않습니다."));
			}
		}
		if (mes != SUCCESS)
		{
			prev.RemoveTail();
		}
		showPictrl();
		CRect rrrr(0, 0, 790, 700);
		InvalidateRect(rrrr);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//비우기
void DSView::OnBnClickedClear()
{
	if (isRunning)
		return;
	prev.AddTail(data->getData());
	data->Clear();
	showPictrl();
	CRect rrrr(0, 0, 790, 700);
	InvalidateRect(rrrr);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//되돌리기
void DSView::OnBnClickedUndo()
{
	if (isRunning)
		return;
	if (prev.GetSize() != 0)
	{
		data->Clear();
		data->changeData(prev.GetTail());
		prev.RemoveTail();

		showPictrl();
		CRect rrrr(0, 0, 790, 700);
		InvalidateRect(rrrr);
	}
	else
	{
		AfxMessageBox(CString("자료구조가 비어있습니다."));
	}

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//정렬
void DSView::OnBnClickedSort()
{

	if (isRunning)
		return;
	prev.AddTail(data->getData());
	isRunning = true;
	_flag mes = data->Sort();
	isRunning = false;
	if (mes == EMPTY)
	{
		AfxMessageBox(CString("자료구조가 비어있습니다."));
		prev.RemoveTail();
	}
	showPictrl();
	CRect rrrr(0, 0, 790, 700);
	InvalidateRect(rrrr);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//추가기능 1
void DSView::OnBnClickedFunction1()
{
	if (isRunning)
		return;
	prev.AddTail(data->getData());
	if (DS == TREE)
	{
		isRunning = true;
		data->max = TRUE;
		data->min = FALSE;
		data->HeapWait = FALSE;
		dynamic_cast<Tree*>(data)->MakeMaxheap();
		data->HeapWait = TRUE;
		CRect rrrr(0, 0, 790, 700);
		InvalidateRect(rrrr);
		isRunning = false;
	}
	else
	{
		if (data->GetSize() < 2)
		{
			AfxMessageBox(CString("잘못된 입력입니다."));
			prev.RemoveTail();
			return;
		}
		if (dynamic_cast<Graph*>(data)->vGetSize() == (data->GetSize() * (data->GetSize() - 1)) / 2)
		{
			AfxMessageBox(CString("자료구조가 가득 찼습니다."));
			prev.RemoveTail();
			return;
		}

		DS_Input2 input;
		if (input.DoModal() == IDOK)
		{
			if (input.input == "" || input.input2 == "")
			{
				AfxMessageBox(CString("잘못된 입력입니다."));
				prev.RemoveTail();
			}
			else
			{
				int put = _tstoi(input.input);
				int put2 = _tstoi(input.input2);
				_flag mes = dynamic_cast<Graph*> (data)->Add_Vertex(put, put2);
				switch (mes)
				{
				case ALREADYEXIST :
					AfxMessageBox(CString("대상이 이미 존재합니다."));
					prev.RemoveTail();
					break;
				case INVALID :
					AfxMessageBox(CString("잘못된 입력입니다."));
					prev.RemoveTail();
				}
				showPictrl();
				CRect rrrr(0, 0, 790, 700);
				InvalidateRect(rrrr);
			}
		}
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//추가기능 2
void DSView::OnBnClickedFunction2()
{
	if (isRunning)
		return;
	prev.AddTail(data->getData());
	if (DS == TREE)
	{
		isRunning = true;
		data->max = FALSE;
		data->min = TRUE;
		data->HeapWait = FALSE;
		dynamic_cast<Tree*>(data)->MakeMinheap();
		data->HeapWait = TRUE;
		CRect rrrr(0, 0, 790, 700);;
		InvalidateRect(rrrr);
		isRunning = false;
	}
	else
	{
		if (data->IsEmpty())
		{
			AfxMessageBox(CString("자료구조가 비어있습니다."));
			prev.RemoveTail();
			return;
		}

		if (dynamic_cast<Graph*>(data)->vGetSize() == 0)
		{
			AfxMessageBox(CString("자료구조가 비어있습니다."));
			prev.RemoveTail();
		}
		else
		{
			DS_Input2 input;
			if (input.DoModal() == IDOK)
			{
				int put = _tstoi(input.input);
				int put2 = _tstoi(input.input2);
				_flag mes = dynamic_cast<Graph*>(data)->Delete_Vertex(put, put2);

				if (mes == NOTARGET)
				{
					AfxMessageBox(CString("대상이 존재하지 않습니다."));
					prev.RemoveTail();
				}
				showPictrl();
				CRect rrrr(0, 0, 790, 700);
				InvalidateRect(rrrr);
			}
		}
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//추가기능 3
void DSView::OnBnClickedFunction3()
{
	if (isRunning)
		return;
	prev.AddTail(data->getData());
	if (DS == TREE)
	{
		data->max = FALSE;
		data->min = FALSE;
		dynamic_cast<Tree*>(data)->toBST();

		showPictrl();
		CRect rrrr(0, 0, 790, 700);
		InvalidateRect(rrrr);
	}
	// TODO: Add your control notification handler code here
}



// DS_SimulatorDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "DS_Simulator.h"
#include "DS_SimulatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDS_SimulatorDlg 대화 상자



CDS_SimulatorDlg::CDS_SimulatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DS_SIMULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	view = new DSView();
}

void CDS_SimulatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON1, mList);
	DDX_Control(pDX, IDC_BUTTON_GRAPH, m_graph_button);
	DDX_Control(pDX, IDC_BUTTON_LIST, m_list_button);
	DDX_Control(pDX, IDC_BUTTON_QUEUE, m_queue_button);
	DDX_Control(pDX, IDC_BUTTON_STACK, m_stack_button);
	DDX_Control(pDX, IDC_BUTTON_TREE, m_tree_button);
	//  DDX_Control(pDX, IDC_BUTTON_SORETEDLIST, m_sortedlist);
}

BEGIN_MESSAGE_MAP(CDS_SimulatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LIST, &CDS_SimulatorDlg::OnBnClickedButtonList)
	ON_BN_CLICKED(IDC_BUTTON_STACK, &CDS_SimulatorDlg::OnBnClickedButtonStack)
	ON_BN_CLICKED(IDC_BUTTON_QUEUE, &CDS_SimulatorDlg::OnBnClickedButtonQueue)
	ON_BN_CLICKED(IDC_BUTTON_TREE, &CDS_SimulatorDlg::OnBnClickedButtonTree)
	ON_BN_CLICKED(IDC_BUTTON_GRAPH, &CDS_SimulatorDlg::OnBnClickedButtonGraph)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CDS_SimulatorDlg 메시지 처리기

BOOL CDS_SimulatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.	

	CBitmap bit_list;
	bit_list.LoadBitmap(IDB_LIST);
	m_list_button.SetBitmap((HBITMAP)bit_list);
	bit_list.Detach();

	bit_list.LoadBitmap(IDB_GRAPH);
	m_graph_button.SetBitmap((HBITMAP)bit_list);
	bit_list.Detach();

	bit_list.LoadBitmap(IDB_TREE);
	m_tree_button.SetBitmap((HBITMAP)bit_list);
	bit_list.Detach();

	bit_list.LoadBitmap(IDB_STACK);
	m_stack_button.SetBitmap((HBITMAP)bit_list);
	bit_list.Detach();

	bit_list.LoadBitmap(IDB_QUEUE);
	m_queue_button.SetBitmap((HBITMAP)bit_list);
	bit_list.Detach();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDS_SimulatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDS_SimulatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDS_SimulatorDlg::OnBnClickedButtonList()
{
	view->DoModal(LIST);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDS_SimulatorDlg::OnBnClickedButtonStack()
{
	view->DoModal(STACK);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDS_SimulatorDlg::OnBnClickedButtonQueue()
{
	view->DoModal(QUEUE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDS_SimulatorDlg::OnBnClickedButtonTree()
{
	view->DoModal(TREE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDS_SimulatorDlg::OnBnClickedButtonGraph()
{
	view->DoModal(GRAPH);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CDS_SimulatorDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));




	return TRUE;
	return CDialogEx::OnEraseBkgnd(pDC);
}

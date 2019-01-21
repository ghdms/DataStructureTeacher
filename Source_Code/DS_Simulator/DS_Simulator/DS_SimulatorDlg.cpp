
// DS_SimulatorDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DS_Simulator.h"
#include "DS_SimulatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDS_SimulatorDlg ��ȭ ����



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


// CDS_SimulatorDlg �޽��� ó����

BOOL CDS_SimulatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.	

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
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CDS_SimulatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CDS_SimulatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDS_SimulatorDlg::OnBnClickedButtonList()
{
	view->DoModal(LIST);

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CDS_SimulatorDlg::OnBnClickedButtonStack()
{
	view->DoModal(STACK);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CDS_SimulatorDlg::OnBnClickedButtonQueue()
{
	view->DoModal(QUEUE);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CDS_SimulatorDlg::OnBnClickedButtonTree()
{
	view->DoModal(TREE);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CDS_SimulatorDlg::OnBnClickedButtonGraph()
{
	view->DoModal(GRAPH);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


BOOL CDS_SimulatorDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(255, 255, 255));




	return TRUE;
	return CDialogEx::OnEraseBkgnd(pDC);
}

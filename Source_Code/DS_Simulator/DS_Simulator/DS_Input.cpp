// DS_Input.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DS_Simulator.h"
#include "DS_Input.h"
#include "afxdialogex.h"


// DS_Input ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(DS_Input, CDialogEx)

DS_Input::DS_Input(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INPUT_DIALOG, pParent)
	, m_input(_T(""))
{
}

DS_Input::~DS_Input()
{
}

void DS_Input::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_input);
	DDV_MaxChars(pDX, m_input, 10);
}


BEGIN_MESSAGE_MAP(DS_Input, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DS_Input::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT1, &DS_Input::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &DS_Input::OnBnClickedOk)
END_MESSAGE_MAP()


// DS_Input �޽��� ó�����Դϴ�.


//void DS_Input::OnEnChangeEdit1()
//{
//	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
//	// CDialogEx::OnInitDialog() �Լ��� ������ 
//	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
//	// �� �˸� �޽����� ������ �ʽ��ϴ�.
//
//	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//}


void DS_Input::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void DS_Input::OnBnClickedOk()
{

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}


BOOL DS_Input::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
	return FALSE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

// DS_Input2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DS_Simulator.h"
#include "DS_Input2.h"
#include "afxdialogex.h"


// DS_Input2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(DS_Input2, CDialogEx)

DS_Input2::DS_Input2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INPUT2_DIALOG, pParent)
	, input(_T(""))
	, input2(_T(""))
{

}

DS_Input2::~DS_Input2()
{
}

void DS_Input2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, input);
	DDX_Text(pDX, IDC_EDIT2, input2);
}


BEGIN_MESSAGE_MAP(DS_Input2, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DS_Input2::OnEnChangeEdit1)
END_MESSAGE_MAP()


// DS_Input2 �޽��� ó�����Դϴ�.


void DS_Input2::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


BOOL DS_Input2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
	return FALSE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

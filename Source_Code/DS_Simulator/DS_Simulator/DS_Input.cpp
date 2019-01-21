// DS_Input.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DS_Simulator.h"
#include "DS_Input.h"
#include "afxdialogex.h"


// DS_Input 대화 상자입니다.

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


// DS_Input 메시지 처리기입니다.


//void DS_Input::OnEnChangeEdit1()
//{
//	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
//	// CDialogEx::OnInitDialog() 함수를 재지정 
//	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
//	// 이 알림 메시지를 보내지 않습니다.
//
//	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}


void DS_Input::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DS_Input::OnBnClickedOk()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


BOOL DS_Input::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

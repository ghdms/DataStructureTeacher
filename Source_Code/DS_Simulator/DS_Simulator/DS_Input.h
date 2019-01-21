#pragma once


// DS_Input 대화 상자입니다.

class DS_Input : public CDialogEx
{
	DECLARE_DYNAMIC(DS_Input)

public:
	DS_Input(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DS_Input();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnEnChangeEdit1();
	CString m_input;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};

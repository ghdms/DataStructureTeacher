#pragma once


// DS_Input2 대화 상자입니다.

class DS_Input2 : public CDialogEx
{
	DECLARE_DYNAMIC(DS_Input2)

public:
	DS_Input2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DS_Input2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUT2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString input;
	CString input2;
	virtual BOOL OnInitDialog();
};

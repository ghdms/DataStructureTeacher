#pragma once


// DS_Input ��ȭ �����Դϴ�.

class DS_Input : public CDialogEx
{
	DECLARE_DYNAMIC(DS_Input)

public:
	DS_Input(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DS_Input();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnEnChangeEdit1();
	CString m_input;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};

#pragma once


// DS_Input2 ��ȭ �����Դϴ�.

class DS_Input2 : public CDialogEx
{
	DECLARE_DYNAMIC(DS_Input2)

public:
	DS_Input2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DS_Input2();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUT2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString input;
	CString input2;
	virtual BOOL OnInitDialog();
};

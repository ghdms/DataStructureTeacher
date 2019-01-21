
// DS_SimulatorDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "DS_View.h"

// CDS_SimulatorDlg ��ȭ ����
class CDS_SimulatorDlg : public CDialogEx
{
// �����Դϴ�.
public:

	CDS_SimulatorDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DS_SIMULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;
	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	
public:
//	CButton mList;
//	afx_msg void OnBnClickedButton1();
	DSView *view;
	afx_msg void OnBnClickedButtonList();
	afx_msg void OnBnClickedButtonStack();
	afx_msg void OnBnClickedButtonQueue();
	afx_msg void OnBnClickedButtonTree();
	afx_msg void OnBnClickedButtonGraph();
	CButton m_graph_button;
	CButton m_list_button;
	CButton m_queue_button;
	CButton m_stack_button;
	CButton m_tree_button;

	
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

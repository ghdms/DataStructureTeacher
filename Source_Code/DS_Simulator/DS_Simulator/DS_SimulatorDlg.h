
// DS_SimulatorDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "DS_View.h"

// CDS_SimulatorDlg 대화 상자
class CDS_SimulatorDlg : public CDialogEx
{
// 생성입니다.
public:

	CDS_SimulatorDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DS_SIMULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	// 생성된 메시지 맵 함수
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

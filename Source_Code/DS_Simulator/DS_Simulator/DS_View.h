#pragma once
#include "DataStructure.h"
#include "List.h"
#include "SortedList.h"
#include "Queue.h"
#include "Stack.h"
#include "Tree.h"
#include "Graph.h"
#include "afxwin.h"
// DSView 대화 상자입니다.
enum dsl{ LIST , SORTEDLIST, QUEUE, STACK, TREE, GRAPH};

class DSView : public CDialogEx
{
	DECLARE_DYNAMIC(DSView)

public:
	DSView(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DSView();

// 버튼 만드는 쪽
	void makeButton();
	void showPictrl();
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEW_DIALOG };
#endif

protected:
	dsl DS;
	DataStructure *data;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


	DECLARE_MESSAGE_MAP()
public:
	virtual INT_PTR DoModal(dsl ds);
	virtual BOOL OnInitDialog();

		
	//버튼
	
	CButton button_insert;//삽입
	CButton button_delete;//삭제
	CButton button_clear;//클리어
	CButton button_undo;//언두
	CButton button_sort;//소트
	CButton button_fun1;//추가기능1
	CButton button_fun2;//추가기능2
	CButton button_fun3;//추가기능3
	CStatic m_PictureCtrl;//우측 상단 아이콘

	//버튼 출력
	void showbutton(CButton* button, CString = CString(""));
	//박스 위치 초기화
	void setBox();
	//메세지 함수
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedInsert();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedUndo();
	afx_msg void OnBnClickedSort();
	afx_msg void OnBnClickedFunction1();
	afx_msg void OnBnClickedFunction2();
	afx_msg void OnBnClickedFunction3();


	CButton m_cancel;//종료
	CStatic m_head;//head message 표시
	CStatic m_tail;//tail message 표시
	CStatic m_empty;//empty message 표시
	CString recent;//가장 최근 변경한 것

	bool isRunning;

	int bcount; //버튼 갯수
	CBitmap bit; //비트맵
	CRect Box[30]; //박스 위치
	CList<commands> prev; //이전 명령어

};

#pragma once
#include "DataStructure.h"
#include "List.h"
#include "SortedList.h"
#include "Queue.h"
#include "Stack.h"
#include "Tree.h"
#include "Graph.h"
#include "afxwin.h"
// DSView ��ȭ �����Դϴ�.
enum dsl{ LIST , SORTEDLIST, QUEUE, STACK, TREE, GRAPH};

class DSView : public CDialogEx
{
	DECLARE_DYNAMIC(DSView)

public:
	DSView(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DSView();

// ��ư ����� ��
	void makeButton();
	void showPictrl();
// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEW_DIALOG };
#endif

protected:
	dsl DS;
	DataStructure *data;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.


	DECLARE_MESSAGE_MAP()
public:
	virtual INT_PTR DoModal(dsl ds);
	virtual BOOL OnInitDialog();

		
	//��ư
	
	CButton button_insert;//����
	CButton button_delete;//����
	CButton button_clear;//Ŭ����
	CButton button_undo;//���
	CButton button_sort;//��Ʈ
	CButton button_fun1;//�߰����1
	CButton button_fun2;//�߰����2
	CButton button_fun3;//�߰����3
	CStatic m_PictureCtrl;//���� ��� ������

	//��ư ���
	void showbutton(CButton* button, CString = CString(""));
	//�ڽ� ��ġ �ʱ�ȭ
	void setBox();
	//�޼��� �Լ�
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


	CButton m_cancel;//����
	CStatic m_head;//head message ǥ��
	CStatic m_tail;//tail message ǥ��
	CStatic m_empty;//empty message ǥ��
	CString recent;//���� �ֱ� ������ ��

	bool isRunning;

	int bcount; //��ư ����
	CBitmap bit; //��Ʈ��
	CRect Box[30]; //�ڽ� ��ġ
	CList<commands> prev; //���� ��ɾ�

};

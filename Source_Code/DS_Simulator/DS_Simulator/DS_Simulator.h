
// DS_Simulator.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CDS_SimulatorApp:
// �� Ŭ������ ������ ���ؼ��� DS_Simulator.cpp�� �����Ͻʽÿ�.
//

class CDS_SimulatorApp : public CWinApp
{
public:
	CDS_SimulatorApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CDS_SimulatorApp theApp;
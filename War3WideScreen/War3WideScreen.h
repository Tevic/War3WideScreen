
// War3WideScreen.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWar3WideScreenApp:
// �йش����ʵ�֣������ War3WideScreen.cpp
//

class CWar3WideScreenApp : public CWinApp
{
public:
	CWar3WideScreenApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWar3WideScreenApp theApp;

// Calculator_1.1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCalculator11App:
// See Calculator_1.1.cpp for the implementation of this class
//

class CCalculator11App : public CWinApp
{
public:
	CCalculator11App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCalculator11App theApp;

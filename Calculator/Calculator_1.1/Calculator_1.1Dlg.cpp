
// Calculator_1.1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator_1.1.h"
#include "Calculator_1.1Dlg.h"
#include "afxdialogex.h"
#include<math.h>
#include<cstring>
#include <iostream>
#include <string>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <format>


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:



};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)


END_MESSAGE_MAP()


// CCalculator11Dlg dialog



CCalculator11Dlg::CCalculator11Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_11_DIALOG, pParent)
	, function(_T(""))
	, Result(_T(""))

{
	num1 = num2 = num0 = 0;
	str1 = _T(" ");
	str2 = _T(" ");
	str3 += _T(" ");
	detect = true;
	Operator = 0;

}

void CCalculator11Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, function);
	DDX_Text(pDX, IDC_EDIT1, Result);
}

BEGIN_MESSAGE_MAP(CCalculator11Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_B0, &CCalculator11Dlg::OnBnClickedB0)
	ON_BN_CLICKED(IDC_B1, &CCalculator11Dlg::OnBnClickedB1)
	ON_BN_CLICKED(IDC_B2, &CCalculator11Dlg::OnBnClickedB2)
	ON_BN_CLICKED(IDC_B3, &CCalculator11Dlg::OnBnClickedB3)
	ON_BN_CLICKED(IDC_B4, &CCalculator11Dlg::OnBnClickedB4)
	ON_BN_CLICKED(IDC_B5, &CCalculator11Dlg::OnBnClickedB5)
	ON_BN_CLICKED(IDC_B6, &CCalculator11Dlg::OnBnClickedB6)
	ON_BN_CLICKED(IDC_B7, &CCalculator11Dlg::OnBnClickedB7)
	ON_BN_CLICKED(IDC_B8, &CCalculator11Dlg::OnBnClickedB8)
	ON_BN_CLICKED(IDC_B9, &CCalculator11Dlg::OnBnClickedB9)
	ON_BN_CLICKED(IDC_B_point, &CCalculator11Dlg::OnBnClickedBpoint)
	ON_BN_CLICKED(IDC_B_Plus, &CCalculator11Dlg::OnBnClickedBPlus)
	ON_BN_CLICKED(IDC_B_Minus, &CCalculator11Dlg::OnBnClickedBMinus)
	ON_BN_CLICKED(IDC_B_Multi, &CCalculator11Dlg::OnBnClickedBMulti)
	ON_BN_CLICKED(IDC_B_Division, &CCalculator11Dlg::OnBnClickedBDivision)
	ON_BN_CLICKED(IDC_B_Power, &CCalculator11Dlg::OnBnClickedBPower)
	ON_BN_CLICKED(IDC_B_Remainder, &CCalculator11Dlg::OnBnClickedBRemainder)
	ON_BN_CLICKED(IDC_BEqua, &CCalculator11Dlg::OnBnClickedBequa)
	ON_BN_CLICKED(IDC_B_Clear, &CCalculator11Dlg::OnBnClickedBClear)
	
	ON_BN_CLICKED(IDC_BAbout, &CCalculator11Dlg::OnBnClickedBabout)
END_MESSAGE_MAP()


// CCalculator11Dlg message handlers

BOOL CCalculator11Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculator11Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculator11Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculator11Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculator11Dlg::OnBnClickedB0()
{
	if (detect == true)
	{
		str1 += _T("0");
		Result = str1;
	}
	else
	{
		str2 += _T("0");
		Result = str2;
	}
	str3 += _T("0");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedB1()
{
	if (detect == true)
	{
		str1 += _T("1");
		Result = str1;
	}
	else
	{
		str2 += _T("1");
		Result = str2;
	}
	str3 += _T("1");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedB2()
{
	if (detect == true)
	{
		str1 += _T("2");
		Result = str1;
	}
	else
	{
		str2 += _T("2");
		Result = str2;
	}
	str3 += _T("2");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedB3()
{
	if (detect == true)
	{
		str1 += _T("3");
		Result = str1;
	}
	else
	{
		str2 += _T("3");
		Result = str2;
	}
	str3 += _T("3");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedB4()
{
	if (detect == true)
	{
		str1 += _T("4");
		Result = str1;
	}
	else
	{
		str2 += _T("4");
		Result = str2;
	}
	str3 += _T("4");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedB5()
{
	if (detect == true)
	{
		str1 += _T("5");
		Result = str1;
	}
	else
	{
		str2 += _T("5");
		Result = str2;
	}
	str3 += _T("5");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedB6()
{
	if (detect == true)
	{
		str1 += _T("6");
		Result = str1;
	}
	else
	{
		str2 += _T("6");
		Result = str2;
	}
	str3 += _T("6");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedB7()
{
	if (detect == true)
	{
		str1 += _T("7");
		Result = str1;
	}
	else
	{
		str2 += _T("7");
		Result = str2;
	}
	str3 += _T("7");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedB8()
{
	if (detect == true)
	{
		str1 += _T("8");
		Result = str1;
	}
	else
	{
		str2 += _T("8");
		Result = str2;
	}
	str3 += _T("8");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedB9()
{
	if (detect == true)
	{
		str1 += _T("9");
		Result = str1;
	}
	else
	{
		str2 += _T("9");
		Result = str2;
	}
	str3 += _T("9");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedBpoint()
{
	if (detect == true)
	{
		str1 += _T(".");
		Result = str1;
	}
	else
	{
		str2 += _T(".");
		Result = str2;
	}
	str3 += _T(".");
	function = str3;
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedBPlus()
{
	if (Result != _T(" "))
	{
		num1 = _ttof(Result);
		detect = !detect;
		Result = _T(" ");
		Operator = 1;
		num5 = _ttof(function);
		str3 += _T(" + ");
		function = str3;
		str1 = _T(" ");
		str2 = _T(" ");

	}
	UpdateData(FALSE);

}


void CCalculator11Dlg::OnBnClickedBMinus()
{
	if (Result != _T(" "))
	{
		num1 = _ttof(Result);
		detect = !detect;
		Result = _T(" ");
		Operator = 2;
		num5 = _ttof(function);
		str3 += _T(" - ");
		function = str3;
		str1 = _T(" ");
		str2 = _T(" ");
	}
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedBMulti()
{
	if (Result != _T(" "))
	{
		num1 = _ttof(Result);
		detect = !detect;
		Result = _T(" ");
		Operator = 3;
		num5 = _ttof(function);
		str3 += _T(" X ");
		function = str3;
		str1 = _T(" ");
		str2 = _T(" ");
	}
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedBDivision()
{
	if (Result != _T(" "))
	{
		num1 = _ttof(Result);
		detect = !detect;
		Result = _T(" ");
		Operator = 4;
		num5 = _ttof(function);
		str3 += _T(" / ");
		function = str3;
		str1 = _T(" ");
		str2 = _T(" ");
	}
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedBPower()
{
	if (Result != _T(" "))
	{
		num1 = _ttof(Result);
		detect = !detect;
		Result = _T(" ");
		Operator = 5;
		num5 = _ttof(function);
		str3 += _T(" ^ ");
		function = str3;
		str1 = _T(" ");
		str2 = _T(" ");
	}
	UpdateData(FALSE);
}


void CCalculator11Dlg::OnBnClickedBRemainder()
{
	if (Result != _T(" "))
	{
		num3 = _ttoi(Result);
		detect = !detect;
		Result = _T(" ");
		Operator = 6;

		str3 += _T(" % ");
		function = str3;
		str1 = _T(" ");
		str2 = _T(" ");
	}
	UpdateData(FALSE);
}

void CCalculator11Dlg::OnBnClickedBClear()
{
	Result = _T(" ");
	num1 = num2 = num3 = num4 = 0;
	str3 = _T(" ");
	function = str3;
	UpdateData(FALSE);
}



void CCalculator11Dlg::OnBnClickedBequa()
{
	if (Result != _T(" "))
	{
		num2 = _ttof(Result);
		num4 = _ttoi(Result);
		detect = !detect;
		Result = _T(" ");


		if (Operator == 1)
		{
			num0 = num1 + num2;
		}
		if (Operator == 2)
		{
			num0 = num1 - num2;
		}
		if (Operator == 3)
		{
			num0 = num1 * num2;
		}
		if (Operator == 4)
		{
			num0 = num1 / num2;
		}
		if (Operator == 5)
		{
			num0 = pow(num1, num2);
		}
		if (Operator == 6)
		{
			num0 = num3 % num4;
		}
	}

	function = str3;

	Result.Format(_T("%.3f "), num0);
	UpdateData(FALSE);
	str1 = _T(" ");
	str2 = _T(" ");
}






void CCalculator11Dlg::OnBnClickedBabout()
{
	MessageBox(_T("Wijesinghe K.A.S.S - 20/ENG/168\nParanawithana T.D. - 20/ENG/094\nSubhasinghe S.A.V.I. - 20/ENG/136\nWaththegama K.S. - 20/ENG/157"));
}

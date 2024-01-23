
// Calculator_1.1Dlg.h : header file
//

#pragma once


// CCalculator11Dlg dialog
class CCalculator11Dlg : public CDialogEx
{
// Construction
public:
	CCalculator11Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_11_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	bool detect;
	int Operator,num3,num4;
	double num1, num2, num0, num5;
	CString str1, str2, str3, str4, str5;
	afx_msg void OnBnClickedB0();
	afx_msg void OnBnClickedB1();
	afx_msg void OnBnClickedB2();
	afx_msg void OnBnClickedB3();
	afx_msg void OnBnClickedB4();
	afx_msg void OnBnClickedB5();
	afx_msg void OnBnClickedB6();
	afx_msg void OnBnClickedB7();
	afx_msg void OnBnClickedB8();
	afx_msg void OnBnClickedB9();
	afx_msg void OnBnClickedBpoint();
	afx_msg void OnBnClickedBPlus();
	afx_msg void OnBnClickedBMinus();
	afx_msg void OnBnClickedBMulti();
	afx_msg void OnBnClickedBDivision();
	afx_msg void OnBnClickedBPower();
	afx_msg void OnBnClickedBRemainder();
	afx_msg void OnBnClickedBequa();
	CString function;
	CString Result;
	afx_msg void OnBnClickedBClear();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBabout();
};

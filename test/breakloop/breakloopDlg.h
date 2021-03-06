// breakloopDlg.h : header file
//

#if !defined(AFX_BREAKLOOPDLG_H__C02743A7_8362_4067_AF50_065034834DBC__INCLUDED_)
#define AFX_BREAKLOOPDLG_H__C02743A7_8362_4067_AF50_065034834DBC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <pcap.h>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CBreakloopDlg dialog

class CBreakloopDlg : public CDialog
{
// Construction
public:
	CBreakloopDlg(CWnd* pParent = NULL);	// standard constructor
	~CBreakloopDlg();

// Dialog Data
	//{{AFX_DATA(CBreakloopDlg)
	enum { IDD = IDD_BREAKLOOP_DIALOG };
	CListBox	m_InfoList;
	CComboBox	m_DevList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBreakloopDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	vector<pcap_if_t *> devArray;// 设备列表转换过来的数组
	pcap_t *cur_pcap_t;
	HICON m_hIcon;

	void initWinPcap();
	void OnTCatch(const struct pcap_pkthdr *header, const u_char *pkt_data);
	void OnTExit(int exitNum);

	// Generated message map functions
	//{{AFX_MSG(CBreakloopDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BREAKLOOPDLG_H__C02743A7_8362_4067_AF50_065034834DBC__INCLUDED_)


// War3WideScreenDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "War3WideScreen.h"
#include "War3WideScreenDlg.h"
#include "afxdialogex.h"
#include "atlbase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWar3WideScreenDlg 对话框




CWar3WideScreenDlg::CWar3WideScreenDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWar3WideScreenDlg::IDD, pParent)
	, m_ResStr(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//获取屏幕分辨率
	m_Wide = GetSystemMetrics(SM_CXSCREEN);
	m_Height = GetSystemMetrics(SM_CYSCREEN);
}

void CWar3WideScreenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_WIDE, m_Wide);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_Height);
}

BEGIN_MESSAGE_MAP(CWar3WideScreenDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, &CWar3WideScreenDlg::OnBnClickedButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_SET, &CWar3WideScreenDlg::OnBnClickedButtonSet)
	ON_BN_CLICKED(IDC_RADIO1, &CWar3WideScreenDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CWar3WideScreenDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CWar3WideScreenDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CWar3WideScreenDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CWar3WideScreenDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CWar3WideScreenDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &CWar3WideScreenDlg::OnBnClickedRadio7)
END_MESSAGE_MAP()


// CWar3WideScreenDlg 消息处理程序

BOOL CWar3WideScreenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWar3WideScreenDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWar3WideScreenDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CWar3WideScreenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWar3WideScreenDlg::OnBnClickedButtonAbout()
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CWar3WideScreenDlg::OnBnClickedButtonSet()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//UpdateData(FALSE);
	CString m_W,m_H;
	m_W.Format(_T("%d"),m_Wide);
	m_H.Format(_T("%d"),m_Height);
	m_ResStr=m_W+_T("×")+m_H;
	if (m_Wide<=3000 && m_Wide>=1000 && m_Height<=2000 && m_Height>=700)
	{
		if(MessageBox(_T("确定要设置魔兽分辨率为 ")+m_ResStr,_T("魔兽争霸分辨率设置"),1+32+256)==IDOK)
		{
			CRegKey resKey;
			resKey.Open(HKEY_CURRENT_USER,_T("Software\\Blizzard Entertainment\\Warcraft III\\Video"),KEY_ALL_ACCESS);
			resKey.SetDWORDValue(_T("resheight"),m_Height);
			resKey.SetDWORDValue(_T("reswidth"),m_Wide);
			resKey.Close();
			MessageBox(_T("魔兽分辨率已设置为 ")+m_ResStr,_T("魔兽争霸分辨率设置"),48);
		}
	}
	else 
	{
		MessageBox(_T("分辨率宽度应在1000到3000之间，高度应在700到2000之间！"),_T("魔兽争霸分辨率设置"),48);
		//获取屏幕分辨率
		m_Wide = GetSystemMetrics(SM_CXSCREEN);
		m_Height = GetSystemMetrics(SM_CYSCREEN);
		UpdateData(FALSE);
	}
}


void CWar3WideScreenDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Height=1080;
	m_Wide=1920;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Height=900;
	m_Wide=1600;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Height=768;
	m_Wide=1366;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Height=1200;
	m_Wide=1920;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Height=1050;
	m_Wide=1680;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Height=900;
	m_Wide=1440;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio7()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Height=800;
	m_Wide=1280;
	UpdateData(FALSE);
}

void CWar3WideScreenDlg::OnOK()
{
	if (GetFocus()->GetNextWindow()!=nullptr)
	{
		GetFocus()->GetNextWindow()->SetFocus();
	}
}
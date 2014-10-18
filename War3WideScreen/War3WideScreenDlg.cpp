
// War3WideScreenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "War3WideScreen.h"
#include "War3WideScreenDlg.h"
#include "afxdialogex.h"
#include "atlbase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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


// CWar3WideScreenDlg �Ի���




CWar3WideScreenDlg::CWar3WideScreenDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWar3WideScreenDlg::IDD, pParent)
	, m_ResStr(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//��ȡ��Ļ�ֱ���
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


// CWar3WideScreenDlg ��Ϣ�������

BOOL CWar3WideScreenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CWar3WideScreenDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CWar3WideScreenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWar3WideScreenDlg::OnBnClickedButtonAbout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CWar3WideScreenDlg::OnBnClickedButtonSet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	//UpdateData(FALSE);
	CString m_W,m_H;
	m_W.Format(_T("%d"),m_Wide);
	m_H.Format(_T("%d"),m_Height);
	m_ResStr=m_W+_T("��")+m_H;
	if (m_Wide<=3000 && m_Wide>=1000 && m_Height<=2000 && m_Height>=700)
	{
		if(MessageBox(_T("ȷ��Ҫ����ħ�޷ֱ���Ϊ ")+m_ResStr,_T("ħ�����Էֱ�������"),1+32+256)==IDOK)
		{
			CRegKey resKey;
			resKey.Open(HKEY_CURRENT_USER,_T("Software\\Blizzard Entertainment\\Warcraft III\\Video"),KEY_ALL_ACCESS);
			resKey.SetDWORDValue(_T("resheight"),m_Height);
			resKey.SetDWORDValue(_T("reswidth"),m_Wide);
			resKey.Close();
			MessageBox(_T("ħ�޷ֱ���������Ϊ ")+m_ResStr,_T("ħ�����Էֱ�������"),48);
		}
	}
	else 
	{
		MessageBox(_T("�ֱ��ʿ��Ӧ��1000��3000֮�䣬�߶�Ӧ��700��2000֮�䣡"),_T("ħ�����Էֱ�������"),48);
		//��ȡ��Ļ�ֱ���
		m_Wide = GetSystemMetrics(SM_CXSCREEN);
		m_Height = GetSystemMetrics(SM_CYSCREEN);
		UpdateData(FALSE);
	}
}


void CWar3WideScreenDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Height=1080;
	m_Wide=1920;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Height=900;
	m_Wide=1600;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Height=768;
	m_Wide=1366;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Height=1200;
	m_Wide=1920;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Height=1050;
	m_Wide=1680;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Height=900;
	m_Wide=1440;
	UpdateData(FALSE);
}


void CWar3WideScreenDlg::OnBnClickedRadio7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
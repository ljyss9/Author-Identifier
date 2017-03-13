// asdfghjkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "asdfghjk.h"
#include "asdfghjkDlg.h"
#include <string.h>
#include <math.h>
#include <Python.h>
#include "Para1.h"
#include "Para2.h"
#include "Para3.h"
#include "Para4.h"
#include "xunlian.h"
#include "Mdonwload.h"


#include "include\\NLPIR.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef OS_LINUX
#pragma comment(lib, "lib\\NLPIR.lib")
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


char adress[50];

int Judge(char a[][10], char b[][10], int m,int s)
{
	int start = 0;
	for(int i = 0; i < s; i++)
	{
		int flat = 0;
		for(int j = start; j < m; j++)
		{
			if(strcmp(a[j],b[i])==0)
			{
				flat = 1;
				start = j+1;
				break;
			}
		}
		if(flat==0) return 0;
	}
	return 1;
}

double* bj(double a[],int t)
{
    double y;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<t-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                y=a[j+1];
                a[j+1]=a[j];
                a[j]=y;
            }
        }
    }
    return a;
}

int get(int x,int a[])
{
	FILE *fu,*f;
	double d[20];
        char z[7]=".txt";
            char s[20]="r\\ba\\";
            char pe[5]="0000";
            itoa(x+1,pe,10);
            strcat(s,pe);
            strcat(s,z);
        for(int j=1;j<=20;j++)
        {

        double l[]={1,1,1,1,1};
         double min[5];
         for (int t=(j-1)*60+1;t<=j*60;t++)
         {
             int yt;
			 yt = a[t-1];
             if(yt==1){
            fu=fopen(s,"r");
            if(!fu)
            {
            printf("can't open file\n");
            exit(1);
            }
             char s2[20]="r\\ba\\";
             char u[5]="0000";
             itoa(t,u,10);
             strcat(s2,u);
            strcat(s2,z);
           f=fopen(s2,"r");
            if(!f)
            {
            printf("can't open file2\n");
            exit(1);
            }
            double len=0;
            double e1,e2;
            double lk;
			double last;
			int fn = 0;
            while(fscanf(f,"%lf",&e1)!=EOF)
            {
                fscanf(fu,"%lf",&e2);
                if(fn<=44)
				{
                     len+=(e1-e2)*(e1-e2);
				}
				else if(fn>44&&fn<=48)
				{
                    len+=0.00001*(e1-e2)*(e1-e2);					
				}
				else
					len+=(e1-e2)*(e1-e2);
                lk=e1;
				last = (e1-e2)*(e1-e2);
            }
			len-=last;
			fclose(f);
			fclose(fu);

            if((t-(j-1)*60-1)<5)
            {
                min[t-(j-1)*60-1]=len;
            }
            else if((t-(j-1)*60-1)==5)         
				for(int ii = 0; ii < 5; ii++)
				{
                   min[ii]=bj(min,5)[ii];
				}
            else
            {
                if(len<min[0])
                {
                    for(int i=4;i>0;i--)
                     {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
                     }
                    min[0]=len;
                    l[0]=lk;
                }
                else if(len<min[1])
                {
                    for(int i=4;i>1;i--)
                      {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
                     }
                    min[1]=len;
                    l[1]=lk;
                }
                else if(len<min[2])
                {
                    for(int i=4;i>2;i--)
                       {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
					}
                    min[2]=len;
                    l[2]=lk;
                }
                else if(len<min[3])
                {
                    for(int i=4;i>3;i--)
                       {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
                     }
                    min[3]=len;
                    l[3]=lk;
                }
                else if(len<min[4])
                {
                    min[4]=len;
                    l[4]=lk;
                }
            }
           }
         }
		  d[j-1]=(l[0]*min[0]+l[1]*min[1]+l[2]*min[2]+l[3]*min[3]+l[4]*min[4])/(l[0]+l[1]+l[2]+l[3]+l[4]);
        }
        double vc1=1000000;
		int vc2=1;
        for(int po=0;po<20;po++)
        {
            if(d[po]<vc1)
			{
                vc1=d[po];
            vc2=po;
			}
        }
     return vc2;
	}
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsdfghjkDlg dialog

CAsdfghjkDlg::CAsdfghjkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAsdfghjkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAsdfghjkDlg)
	m_len = _T("");
	m_w1 = 0.0;
	m_w2 = 0.0;
	m_w3 = 0.0;
	m_w4 = 0.0;
	m_rate = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAsdfghjkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsdfghjkDlg)
	DDX_Control(pDX, IDC_RADIO6, m_radio13);
	DDX_Control(pDX, IDC_RADIO5, m_radio12);
	DDX_Control(pDX, IDC_RADIO4, m_radio11);
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Control(pDX, IDC_RADIO3, m_radio3);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_PROGRESS8, m_pro8);
	DDX_Control(pDX, IDC_PROGRESS7, m_pro7);
	DDX_Control(pDX, IDC_PROGRESS6, m_pro6);
	DDX_Control(pDX, IDC_PROGRESS1, m_pro1);
	DDX_Control(pDX, IDC_PROGRESS5, m_pro5);
	DDX_Control(pDX, IDC_PROGRESS4, m_pro4);
	DDX_Control(pDX, IDC_PROGRESS3, m_pro3);
	DDX_Control(pDX, IDC_PROGRESS2, m_pro2);
	DDX_Text(pDX, IDC_EDIT4, m_R);
	DDX_Text(pDX, IDC_EDIT6, m_w1);
	DDX_Text(pDX, IDC_EDIT7, m_w2);
	DDX_Text(pDX, IDC_EDIT8, m_w3);
	DDX_Text(pDX, IDC_EDIT9, m_w4);
	DDX_Text(pDX, IDC_EDIT10, m_rate);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAsdfghjkDlg, CDialog)
	//{{AFX_MSG_MAP(CAsdfghjkDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCRESOURCE, OnCresource)
	ON_BN_CLICKED(IDRESULT, OnResult)
	ON_BN_CLICKED(IDPART, OnPart)
	ON_BN_CLICKED(IDC_AL, OnAl)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsdfghjkDlg message handlers

BOOL CAsdfghjkDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	::SetWindowPos(this->m_hWnd,HWND_BOTTOM,50,50,900,650,SWP_NOZORDER);
	CenterWindow();
	SetWindowText("L4-基于行文特征的互联网作者识别工具");
	// Add "About..." menu item to system menu.

	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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


    m_tab.InsertItem(0,"获取原文结果");  //添加参数一选项卡 
    m_tab.InsertItem(1,"分词结果");  //添加参数二选项卡 
    m_tab.InsertItem(2,"特征分析结果");    //添加结果选项卡
	m_tab.InsertItem(3,"作者分析");

    
	para1.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB2)); 
	para2.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB2)); 
	para3.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB2)); 
	para4.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB2)); 
	CRect rs; 
    m_tab.GetClientRect(&rs); 
	rs.top+=14; 
    rs.bottom-=1; 
    rs.left-=10; 
    rs.right-=2; 
	para1.MoveWindow(&rs);
	para2.MoveWindow(&rs);
	para3.MoveWindow(&rs);
	para4.MoveWindow(&rs);



	para1.ShowWindow(true); 
	para2.ShowWindow(false); 
	para3.ShowWindow(false); 
	para4.ShowWindow(false); 
	m_tab.SetCurSel(0);



	m_radio2.SetCheck(true);
	m_radio11.SetCheck(true);
	m_w1 = m_w2 = m_w3 = m_w4 = 1.0;

	UpdateData(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAsdfghjkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAsdfghjkDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		MoveWindow(300,600,600,300,TRUE);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialog::OnPaint();
		 CPaintDC   dc(this);   
           CRect   rect;   
           GetClientRect(&rect);   
           CDC   dcMem;   
           dcMem.CreateCompatibleDC(&dc);   
           CBitmap   bmpBackground;   
           //bmpBackground.LoadBitmap(IDB_BITMAP7);   //IDB_BITMAP是你自己的图对应的ID   ，由于我刚刚加入的位图资源 
                                                                             //被我命名成了IDB_Bg，因而我这句就是bmpBackground.LoadBitmap(IDB_Bg);  
                  
           BITMAP   bitmap;   
           bmpBackground.GetBitmap(&bitmap);   
		   CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
           dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
           bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  

	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAsdfghjkDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAsdfghjkDlg::OnCresource() 
{
	UpdateData(true);
	para4.m_len = ""; 
	UpdateData(false);
	CFileDialog dlg(true,NULL,NULL,OFN_NOCHANGEDIR);
	dlg.DoModal ();
	strcpy(adress,(LPCTSTR)dlg.GetPathName());
	//DLG dlg;
	//dlg.DoModal ();	
	//strcpy(adress,dlg.m_adress);
	//MessageBox(adress,"提示",MB_OK);
	FILE *fp;
	fp=fopen(adress,"r");
	int len = strlen(adress);
	if(!fp && len>0)
    {
		MessageBox("获取文章失败!","提示",MB_OK);
    }
	else if(len>0)
	{
		fclose(fp);
	   CFile   file1(adress,CFile::modeRead); 
       char   *pBuf; 
       int   iLen=file1.GetLength(); 
       pBuf   =new   char[iLen+1]; 
       file1.Read(pBuf,iLen); 
       pBuf[iLen]=0; 
       file1.Close(); 
       //SetDlgItemText(IDC_EDIT1,pBuf);
	   	para1.SetDlgItemText(IDC_EDIT1,pBuf);
		m_tab.SetCurSel(0);
		para1.ShowWindow(true); 
	    para2.ShowWindow(false); 
	    para3.ShowWindow(false); 
	    para4.ShowWindow(false); 
	}	
	// TODO: Add your control notification handler code here	
}

void CAsdfghjkDlg::OnResult() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	UpdateData(false);
	
    
	int kind = 0;
	int bl1 = 0;
	int bl2 = 0;
	FILE *fu,*f;
	double d[20]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char z[5]=".txt";		
	int v=1;
	int flat = 0;
	char author[20][20] = {"蔡澜","大动妈","韩寒","鸿水","李银河","马末都","毛丹青","徐静蕾","冯骥才","郭雪波","黄国荣","雷颐","刘墉","麦家","毛佩琦","宁财神","饶雪漫","沈思源","石康","张颐武"};
	int passage = 0;

    if(m_radio11.GetCheck()==TRUE)
	{
		kind = 1;
	}
	else if(m_radio12.GetCheck()==TRUE)
	{
		kind = 2;
	}
	else
	{
		kind = 3;
	}

	if(m_radio1.GetCheck()==TRUE)
	{
		passage = 20;
	}
	else if(m_radio2.GetCheck()==TRUE)
	{
		passage = 30;
	}
	else
	{
		passage = 40;
	}

	if(kind==1)
	{
    for(int j=1;j<=20;j++)
    { 
		double min[5]; 
		double l[]={1,1,1,1,1};
        for (int t=(v-1)*30+1;t<=(v-1)*30+passage;t++)
        {			 
			fu=fopen("result.txt","r");		  
			if(!fu)       
			{			
				MessageBox("未找到特征分析结果!","提示",MB_OK);			
				SetDlgItemText(IDC_EDIT4,"");				
				j = 21;
				flat = 1;
				break;       
			}		             
				char s2[20]="r\\ba\\";             
				char u[5]="0000";             
				itoa(t,u,10);            
				strcat(s2,u);            
				strcat(s2,z);            
				f = fopen(s2,"r");            
				if(!f)           
				{				
					MessageBox("未找到特征库!","提示",MB_OK);				
					j = 21;
					flat = 1;
					break;           
				}							
					int yr = 0;                
					double len=0;               
					double e1,e2; 
					double lk;
			        double last;
					while(fscanf(f,"%lf",&e1)!=EOF)           				
					{				
						yr++;                
						fscanf(fu,"%lf",&e2);
						if(yr<=32)
						{
							len+=m_w1*m_w1*(e1-e2)*(e1-e2);
						}
						else if(yr<=44)				
						{                     
							len+=m_w2*m_w2*(e1-e2)*(e1-e2);				
						}				
						else if(yr>44&&yr<=48)				
						{                    
							len+=m_w3*m_w3*0.00001*(e1-e2)*(e1-e2);									
						}				
						else					
							len+=m_w4*m_w4*(e1-e2)*(e1-e2);  				
					   lk=e1;
				       last = (e1-e2)*(e1-e2);
					}
					len-=last;
					CString str,str1;
					str.Format("%f", len);
					if(t%60!=passage)
					str1.Format("%d", t%passage);
					else
					str1.Format("%d",passage);
					para4.m_len=para4.m_len+"本文与训练文章"+"“"+author[j-1]+ str1 +"”"+"的距离"+str+"\r\n"; 


					fclose(f);			           
					if((t-(j-1)*60-1)<5)          
					{               
						min[t-(j-1)*60-1]=len;
            
					}
            
					else if((t-(j-1)*60-1)==5)
			
					{
                
						for(int ii = 0; ii < 5; ii++)
				
						{
                   
							min[ii]=bj(min,5)[ii];
				
						}
			
					}
            
					else
            {
                if(len<min[0])
                {
                    for(int i=4;i>0;i--)
                     {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
                     }
                    min[0]=len;
                    l[0]=lk;
                }
                else if(len<min[1])
                {
                    for(int i=4;i>1;i--)
                      {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
                     }
                    min[1]=len;
                    l[1]=lk;
                }
                else if(len<min[2])
                {
                    for(int i=4;i>2;i--)
                       {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
					}
                    min[2]=len;
                    l[2]=lk;
                }
                else if(len<min[3])
                {
                    for(int i=4;i>3;i--)
                       {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
                     }
                    min[3]=len;
                    l[3]=lk;
                }
                else if(len<min[4])
                {
                    min[4]=len;
                    l[4]=lk;
                }
            }
			
					fclose(fu);					 			
			}
			d[j-1]=(l[0]*min[0]+l[1]*min[1]+l[2]*min[2]+l[3]*min[3]+l[4]*min[4])/(l[0]+l[1]+l[2]+l[3]+l[4]);
			CString str2,str3;
			str2.Format("%f", d[j-1]);
			str3.Format("%d", j);
			if(flat==0)
			para4.m_len = para4.m_len+"\r\n"  + str3 +"."+ "本文与"+"“"+author[j-1]+"”"+"所有的比较文章的距离"+":"+str2+"\r\n"+"\r\n"; 
			v=v+2;						
		} 

		}
		else if(kind == 2)
		{
			double keep[60][300];
    double aver[20][300];
	for(int a1 = 0; a1 < 60; a1++)
		for(int a2 = 0; a2 < 300; a2++)
			keep[a1][a2] = 0;
		for(int a11 = 0; a11 < 20; a11++)
		for(int a21 = 0; a21 < 300; a21++)
			aver[a11][a21] = 0;
			int pa;
	        char z[5]=".txt";
	       for(int i1=0;i1<20;i1++)//根据现在作者人数进行更改	
		   {
		for(int i=i1*60+1;i<=60*i1+passage;i++)//根据每个作者的篇数进行更改
		
		{
			char s2[20]="r\\ba\\";
             char u[5]="0000";
	             itoa(i,u,10);
             strcat(s2,u);
            strcat(s2,z);
           f=fopen(s2,"r");
            if(!f)           
				{				
					MessageBox("未找到特征库!","提示",MB_OK);				
					i1 = 21;
					flat = 1;
					break;           
				}	
			double e;
			 pa=0;
			while(fscanf(f,"%lf",&e)!=EOF)
			{
				keep[i%10-1][pa]=e;
				pa++;
			}
			fclose(f);
		}
		
		for(int j1=0;j1<pa;j1++)
        {
            double result=0;
            for(int j2=0;j2<passage;j2++)
                result+=keep[j2][j1];
            aver[i1][j1]=result*1.0/passage;//最后聚类的结果，每个作者的平均向量。
			
        }
	}
            	  

			for(int j = 0; j < 20; j++)
			{
				    int yr = 0;                
					double len=0;               
					double e1,e2;
					fu=fopen("result.txt","r");	
								if(!fu)       			
								{							
									MessageBox("未找到特征分析结果!","提示",MB_OK);							
									SetDlgItemText(IDC_EDIT4,"");								
									j = 21;				
									flat = 1;				
									break; 				      			
								}
					while(fscanf(fu,"%lf",&e1)!=EOF)           				
					{																									
						yr++; 
						e2 = aver[j][yr-1];
						
						if(yr<=32)
						{
							len+=m_w1*m_w1*(e1-e2)*(e1-e2);
						}
						else if(yr<=44)				
						{                     
							len+=m_w2*m_w2*(e1-e2)*(e1-e2);				
						}				
						else if(yr>44&&yr<=48)				
						{                    
							len+=m_w3*m_w3*0.00001*(e1-e2)*(e1-e2);									
						}				
						else					
							len+=m_w4*m_w4*(e1-e2)*(e1-e2); 
					}
					d[j] = len;
				
					CString str2,str3;
			        str2.Format("%f", d[j]);
			        str3.Format("%d", j+1);
					if(flat==0)
			        para4.m_len = para4.m_len+"\r\n"  + str3 +"."+ "本文与"+"“"+author[j]+"”"+"所有的比较文章的距离"+":"+str2+"\r\n"+"\r\n"; 
					fclose(fu);
			}
						
		}
		
		else if(kind==3)
		{
			double keep[60][300];
    double aver[20][300];
	for(int a1 = 0; a1 < 60; a1++)
		for(int a2 = 0; a2 < 300; a2++)
			keep[a1][a2] = 0;
		for(int a11 = 0; a11 < 20; a11++)
		for(int a21 = 0; a21 < 300; a21++)
			aver[a11][a21] = 0;
	int pa;
	char z[]=".txt";
	for(int i1=0;i1<20;i1++)//根据作者数修改
	{
		for(int i=i1*60+1;i<=60*i1+passage;i++)//根据作者篇数修改
		{
			char s2[20]="r\\ba\\";
             char u[5]="0000";
	             itoa(i,u,10);
             strcat(s2,u);
            strcat(s2,z);
           f=fopen(s2,"r");
            if(!f)
            {
           MessageBox("未找到特征库!","提示",MB_OK);				 
            i1 = 21;
					flat = 1;
					break; 
            }
			double e;
			 pa=0;
			while(fscanf(f,"%lf",&e)!=EOF)
			{
				keep[i%passage-1][pa]=e;//根据每个作者篇数修改
				pa++;
			}
			fclose(f);
		}
		double min=1000;
		int mark=0;
		for(int j1=0;j1<10;j1++)
        {
            double result=0;
            for(int j2=0;j2<10;j2++)
            {
                if(j2!=j1)
                for(int j3=0;j3<pa;j3++)
                    result+=(keep[j2][j3]-keep[j1][j3])*(keep[j2][j3]-keep[j1][j3]);
            }
            if(result<min)
            {
                min=result;
                mark=j1;
            }
        }
        for(int j3=0;j3<pa;j3++)
        aver[i1][j3]=keep[mark][j3];
	}
	for(int j = 0; j < 20; j++)
			{
				    int yr = 0;                
					double len=0;               
					double e1,e2;
					fu=fopen("result.txt","r");	
								if(!fu)       			
								{							
									MessageBox("未找到特征分析结果!","提示",MB_OK);			
				SetDlgItemText(IDC_EDIT4,"");				
				j = 21;
				flat = 1;
				break; 			      			
								}
					while(fscanf(fu,"%lf",&e1)!=EOF)           				
					{																									
						yr++; 
						e2 = aver[j][yr-1];
						
						if(yr<=32)
						{
							len+=m_w1*m_w1*(e1-e2)*(e1-e2);
						}
						else if(yr<=44)				
						{                     
							len+=m_w2*m_w2*(e1-e2)*(e1-e2);				
						}				
						else if(yr>44&&yr<=48)				
						{                    
							len+=m_w3*m_w3*0.00001*(e1-e2)*(e1-e2);									
						}				
						else					
							len+=m_w4*m_w4*(e1-e2)*(e1-e2); 
					}
					d[j] = len;
					CString str2,str3;
			        str2.Format("%f", d[j]);
			        str3.Format("%d", j+1);
					if(flat==0)
			        para4.m_len = para4.m_len+"\r\n"  + str3 +"."+ "本文与"+"“"+author[j]+"”"+"所有的比较文章的距离"+":"+str2+"\r\n"+"\r\n"; 					
					fclose(fu);
			}
		}

		m_tab.SetCurSel(3);
		para4.UpdateData(false);
		para1.ShowWindow(false); 
	    para2.ShowWindow(false); 
	    para3.ShowWindow(false); 
	    para4.ShowWindow(true); 
		
		if(flat == 0)
		{
			int mark[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
			double ti[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			for(int u = 0; u < 20; u++)
			{
				if(d[u]==0)
				{
						
				}
				mark[u] = u;
				ti[u] = d[u];
			}

			
					

			int m=0;
			double t=0;
			for(int i = 0; i < 20; i++)
			{
				for(int j=0;j<20-1-i;j++)
					if(ti[j]>ti[j+1])
					{
						m = mark[j];
						mark[j] = mark[j+1];
						mark[j+1] = m;
						t = ti[j];
						ti[j] = ti[j+1];
						ti[j+1] = t;
					}
			}

		

			double tsum = 0;
			for(int i1 = 0; i1 < 20; i1++)
			{
				tsum+=1/ti[i1];
			}
			        
						
			
        int pr1 = (int)(((1/ti[0])/tsum)*100);			
		int pr2 = (int)(((1/ti[1])/tsum)*100);
		int pr3 = (int)(((1/ti[2])/tsum)*100);
		int pr4 = (int)(((1/ti[3])/tsum)*100);
		int pr5 = (int)(((1/ti[4])/tsum)*100);
		int pr6 = (int)(((1/ti[5])/tsum)*100);
		int pr7 = (int)(((1/ti[6])/tsum)*100);
		int pr8 = (int)(((1/ti[7])/tsum)*100);
        
		
		
		m_pro1.SetPos(pr1);			
		m_pro2.SetPos(pr2);
		m_pro3.SetPos(pr3);
		m_pro4.SetPos(pr4);
		m_pro5.SetPos(pr5);
		m_pro6.SetPos(pr6);
		m_pro7.SetPos(pr7);
		m_pro8.SetPos(pr8);
		 			
		char result[100] = "文章最可能的作者（按可能性排序）：\r\n";
		strcat(result,"  \r\n1.");	
		strcat(result,author[mark[0]]);			
		strcat(result,"  \r\n2.");           
		strcat(result,author[mark[1]]);	
		strcat(result,"  \r\n3.");           
		strcat(result,author[mark[2]]);	
		strcat(result,"  \r\n4.");           
		strcat(result,author[mark[3]]);	
		strcat(result,"  \r\n5.");           
		strcat(result,author[mark[4]]);	
		strcat(result,"  \r\n6.");           
		strcat(result,author[mark[5]]);	
		strcat(result,"  \r\n7.");           
		strcat(result,author[mark[6]]);	
		strcat(result,"  \r\n8.");           
		strcat(result,author[mark[7]]);	
		
		
       
        m_R = result;
	    SetDlgItemText(IDC_STATIC10,"作者分析结果");
		SetDlgItemText(IDC_STATIC1,author[mark[0]]);			
		SetDlgItemText(IDC_STATIC2,author[mark[1]]);
		SetDlgItemText(IDC_STATIC3,author[mark[2]]);			
		SetDlgItemText(IDC_STATIC4,author[mark[3]]);
		SetDlgItemText(IDC_STATIC5,author[mark[4]]);			
		SetDlgItemText(IDC_STATIC6,author[mark[5]]);
		SetDlgItemText(IDC_STATIC7,author[mark[6]]);			
		SetDlgItemText(IDC_STATIC8,author[mark[7]]);
			
		
		
		UpdateData(false);
		DeleteFile("result.txt");
		}
}

void CAsdfghjkDlg::OnPart() 
{
	
	UpdateData(true);
	// TODO: Add your control notification handler code here
	int adl = strlen(adress);
	FILE *fp;
	fp=fopen(adress,"r");
	if(adl<=4 || !fp )
        MessageBox("未找到原文章!","提示",MB_OK);		
	else
	{
		fclose(fp);
		char ad2[100];
	strncpy(ad2,adress,adl-4);
	ad2[adl-4]='\0';
	strcat(ad2,"_cla.txt");
	FILE *fp1;
	fp1 = fopen(ad2,"r");
	
	if(!fp1)
	{}
	else
	{
		fclose(fp1);
        DeleteFile(ad2);
	}
	//ShellExecute(NULL,"open","ICTCLAS-release\\ICTCLAS_Win.exe",NULL,NULL,SW_SHOWNORMAL);		
	//system("ICTCLAS-release\\ICTCLAS_Win.exe");
	
	int nCode = GBK_CODE;
 
	if(!NLPIR_Init("..",nCode))//数据在当前路径下，默认为GBK编码的分词
	{
		MessageBox("hs","提示",MB_OK);
	}
	NLPIR_FileProcess(adress,ad2);
    NLPIR_Exit();

    
	CFile   file1(ad2,CFile::modeRead); 
    char   *pBuf; 
    int   iLen=file1.GetLength(); 
    pBuf   =new   char[iLen+1]; 
    file1.Read(pBuf,iLen); 
    pBuf[iLen]=0; 
    file1.Close(); 
    para2.SetDlgItemText(IDC_EDIT1,pBuf);
	m_tab.SetCurSel(1);
	
	para1.ShowWindow(false); 
	para2.ShowWindow(true); 
	para3.ShowWindow(false); 
	para4.ShowWindow(false); 
	}

}
void CAsdfghjkDlg::OnAl() 
{
	UpdateData(true);
	// TODO: Add your control notification handler code here
	int adl = strlen(adress);
	if(adl == 0)
	{
		MessageBox("特征分析失败!","提示",MB_OK);
	}
		else
		{
	char ad1[50];
	strncpy(ad1,adress,adl-4);
	ad1[adl-4]='\0';
	strcat(ad1,"_cla.txt");
    char c[2024][40];
	char c1[2024][40];
	char c2[2024][40];			
	FILE *fp;	
	fp =  fopen(ad1,"r");
	if(!fp)
      MessageBox("特征分析失败!","提示",MB_OK);
    else
	{
	int i = 0;
	char *delim = "/";
	while(fscanf(fp,"%s",c[i])!=EOF && i<2024)
	{
		if(strchr(c[i],'/')!=NULL)
		{
		strcpy(c1[i],strtok(c[i],delim));
		strcpy(c2[i],strtok(NULL,delim));
		i++;
		}
	}
	fclose(fp);

    FILE *fp2;
	fp2 =  fopen("result.txt","w");
	
    	
	int j,k;
	double num[10];
	char all[10]={'n','v','a','m','q','r','d','p','c','u'};
	for(j = 0; j < 10; j++)
		num[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <10; k++)
			if(c2[j][0] == all[k])
				num[k]++;
	for(j = 0; j < 10; j++)
		fprintf(fp2,"%lf ",num[j]/i);

	int dn =  30;
	double dnum[50];
	char d[50][20] = {"很","颇","极","十分","就","都","居然","重新","不断","乃","不","也","其","几","却","何","可","只","在","即","既","多少","又","反","得","还","太","连","才","的"};
	for(j = 0; j < dn; j++)
		dnum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <dn; k++)
			if(strcmp(c1[j],d[k])==0)
				dnum[k]++;	
			for(k = 0; k <dn; k++)
			if(k==4||k==29)
			fprintf(fp2,"%lf ",dnum[k]/i);
	/*
	int pn =  21;
	double pnum[50];
	char p[50][20] = {"与","到","于","从","似","当","去","让","及","往","对","如","把","替","比","至","同","凭","跟","被","给"};
	for(j = 0; j < dn; j++)
		pnum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <pn; k++)
			if(strcmp(c1[j],p[k])==0)
				pnum[k]++;	
			for(k = 0; k <pn; k++)
			fprintf(fp1,"%s\t(%lf)\n",p[k],pnum[k]/i);
			*/
	int un =  13;
	double unum[50];
	char u[50][20] = {"么","了","之","为","着","以","向","来","如","是","每","等","将"};
	for(j = 0; j < un; j++)
		unum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <un; k++)
			if(strcmp(c1[j],u[k])==0)
				unum[k]++;	
			for(k = 0; k <un; k++)
			if(k==1||k==4||k==9)
			fprintf(fp2,"%lf ",unum[k]/i);
	int yn =  17;
	double ynum[50];
	char y[50][20] = {"吧","罢","呗","啦","了","吗","嘛","么","麽","呢","呐","呵","哈","哉","大概","可能","一定"};
	for(j = 0; j < yn; j++)
		ynum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <yn; k++)
			if(strcmp(c1[j],y[k])==0)
				ynum[k]++;	
			for(k = 0; k <yn; k++)
			fprintf(fp2,"%lf ",ynum[k]/i);

			int bn =  12;
	double bnum[50];
	double bnnum =0;
	char b[50][20] = {"。","？","！","，","、","；","：","“","──","「","《","…"};
	for(j = 0; j < bn; j++)
		bnum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <bn; k++)
			if(strcmp(c1[j],b[k])==0)
			{
				bnum[k]++;
				bnnum++;
			}
			for(k = 0; k <bn; k++)
			{
			//printf("%s\t(%lf)\n",b[k],bnum[k]/bnnum);
			fprintf(fp2,"%lf ",bnum[k]/bnnum);
			}
			/*
	fprintf(fp1,"特殊时间词词频\n",NULL);
	int tn =  6;
	double tnum[50];
	char t[50][20] = {"今天","明天","昨天","当前","以后","未来"};
	for(j = 0; j < tn; j++)
		tnum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <tn; k++)
			if(strcmp(c1[j],t[k])==0)
				tnum[k]++;	
			for(k = 0; k <tn; k++)
			fprintf(fp1,"%s\t(%lf)\n",t[k],tnum[k]/i);
*/


			char sentence[200][100][10];
	int sth = 0;
	int snum = 0;
	int ssnum = 0;
	int slength[1024];
	int wordnum = 0;
    for(j = 0; j < i; j++)
	{
		if(c2[j][0]=='w')
		{
			ssnum++;
		}
		if(strcmp(c1[j],"。")!=0 && strcmp(c1[j],"？")!=0 && strcmp(c1[j],"！")!=0)
		{
			if(c2[j][0] != 'w')
			{
				wordnum++;
			    strcpy(sentence[snum][sth],c2[j]);
			    sth++;
			}
		}
		else
		{
			if(c2[j-1][0]!='w')
			{
			   slength[snum] = sth;
			  
               snum++;
			   sth = 0;
			}
		}

	}


    FILE *fp1;
	fp1 =  fopen("r\\jushi.txt","r");
	char s[100];
	char str[300][100][10];
	int jsnum[1000] = {0};
	int jnum = 0;
	int jssentencelength[300];
	for(int k1 = 0; k1 < 300; k1++)
          jssentencelength[k1] = 0;
	int count1 = 0;
    while(fscanf(fp1,"%s",s)!=EOF)
	{
		//printf("%s ",s);
		char delims[] = "+";
		char *result = NULL;
		result = strtok( s, delims );
		int count2 = 0;
		while( result != NULL )
		{
			jssentencelength[count1]++;
			strcpy(str[count1][count2],result);
			//printf( "%s ", result );
			result = strtok( NULL, delims );
			count2++;
		}
		//printf("\n");
		count1++;
	}

	int px[300];
	for(int k2 = 0; k2 < 300; k2++)
          px[k2] = 0;
	for(int i2 = 0; i2 < snum; i2++)
	{
		for(int j2 = 0; j2 < count1; j2++)
		  if(Judge(sentence[i2],str[j2],slength[i2],jssentencelength[j2])==1)
		  {
			  px[j2]++;
			  jnum++;
		  }
	}
	
    //printf("本文共%d句\n",snum);
	fprintf(fp2,"%lf ",snum*1.0);
    //printf("平均句长%d\n",wordnum/snum);
	fprintf(fp2,"%lf ",wordnum/snum*1.0);
	//printf("本文共%d短句\n",ssnum);
	fprintf(fp2,"%lf ",ssnum*1.0);
    //printf("平均每句中的短句数%d\n",ssnum/snum);
	fprintf(fp2,"%lf ",ssnum/snum*1.0);

	for(int k3 = 0; k3 < count1; k3++)
	{
		double e=px[k3]*1.0/jnum;
		fprintf(fp2,"%lf ",e);
	}
	fclose(fp1);
	fclose(fp2);
	}
	CFile   file1("result.txt",CFile::modeRead); 
    char   *pBuf; 
    int   iLen=file1.GetLength(); 
    pBuf   =new   char[iLen+1]; 
    file1.Read(pBuf,iLen); 
    pBuf[iLen]=0; 
    file1.Close(); 
    para3.SetDlgItemText(IDC_EDIT1,pBuf);
	m_tab.SetCurSel(2);
	para1.ShowWindow(false); 
	para2.ShowWindow(false); 
	para3.ShowWindow(true); 
	para4.ShowWindow(false); 
	}
}

void CAsdfghjkDlg::OnButton1() 
{
	//Py_Initialize(); 
	//PyRun_SimpleString("execfile('test1.py')");  
    //Py_Finalize( );

	UpdateData(true);
	// TODO: Add your control notification handler code here
	MessageBox("使用说明:\n\n\n1.请按 ( 训练，原文章 , 分词 , 特征分析 , 结果 ) 的顺序进行操作。\n\n\n2.下载的文章保存在所选路径下的download.txt文件里。\n\n\n3.点击 ‘原文章’ 按钮后请选择要处理文章。\n\n\n4.“正确率分析”为当前参数下的正确率测试。","欢迎使用L4-基于行文特征的互联网作者识别工具 ！",MB_OK);
}



//DEL void CAsdfghjkDlg::OnOutofmemoryProgress1(NMHDR* pNMHDR, LRESULT* pResult) 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	skinppSetNoSkinHwd(hwnd,TRUE);
//DEL 	*pResult = 0;
//DEL }

void CAsdfghjkDlg::OnButton2() 
{
	UpdateData(true);
	// TODO: Add your control notification handler code here
	exit(1);
}

void CAsdfghjkDlg::OnButton3() 
{
	UpdateData(true);
	// TODO: Add your control notification handler code here
	para1.SetDlgItemText(IDC_EDIT1,"");
	para2.SetDlgItemText(IDC_EDIT1,"");
	para3.SetDlgItemText(IDC_EDIT1,"");
	para4.SetDlgItemText(IDC_EDIT1,"");
	SetDlgItemText(IDC_EDIT4,"");
	SetDlgItemText(IDC_EDIT10,"");
	m_len = "";
	m_rate = "";
	m_R = "";
	SetDlgItemText(IDC_STATIC0,"");
	SetDlgItemText(IDC_STATIC1,"作者1");
	SetDlgItemText(IDC_STATIC2,"作者2");
	SetDlgItemText(IDC_STATIC3,"作者3");
	SetDlgItemText(IDC_STATIC4,"作者4");
	SetDlgItemText(IDC_STATIC5,"作者5");
	SetDlgItemText(IDC_STATIC6,"作者6");
	SetDlgItemText(IDC_STATIC7,"作者7");
	SetDlgItemText(IDC_STATIC8,"作者8");
	m_pro1.SetPos(0);
    m_pro2.SetPos(0);
	m_pro3.SetPos(0);
    m_pro4.SetPos(0);
	m_pro5.SetPos(0);
    m_pro6.SetPos(0);
	m_pro7.SetPos(0);
    m_pro8.SetPos(0);

	m_radio1.SetCheck(false);
	m_radio2.SetCheck(TRUE);
	m_radio3.SetCheck(false);
	m_w1 = m_w2 = m_w3 = m_w4 = 1.0;
	m_R = "";
	UpdateData(false);
}

void CAsdfghjkDlg::OnButton4() 
{
	UpdateData(true);
	// TODO: Add your control notification handler code here
	CAboutDlg dlg;
	dlg.DoModal ();
}

void CAsdfghjkDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_radio1.SetCheck(true);
	m_radio2.SetCheck(false);
	m_radio3.SetCheck(false);
}

void CAsdfghjkDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_radio1.SetCheck(false);
	m_radio2.SetCheck(true);
	m_radio3.SetCheck(false);
}

void CAsdfghjkDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	m_radio1.SetCheck(false);
	m_radio2.SetCheck(false);
	m_radio3.SetCheck(true);
}

void CAsdfghjkDlg::OnButton5() 
{
	SetDlgItemText(IDC_STATIC0,"测试中,请稍等...");
	SetDlgItemText(IDC_EDIT10,"");
	m_rate = "";
	UpdateData(true);
	 dlg.Create(IDD_DIALOG7,NULL);
	 dlg.ShowWindow(SW_SHOW);
	 dlg.MoveWindow(500,200,400,250);
	 dlg.SetDlgItemText(IDC_STATIC70,"正确率测试中，请稍等...");
	 dlg.m_xpro.SetRange(0, 460 );//设置进度条范围   
	 dlg.m_xpro.SetStep(1);//步长
    
	// TODO: Add your control notification handler code here
    int passage = 0;
	 if(m_radio1.GetCheck()==TRUE)
	{
		passage = 20;
	}
	else if(m_radio2.GetCheck()==TRUE)
	{
		passage = 30;
	}
	else
	{
		passage = 40;
	}
	 int kind = 0;
	 if(m_radio11.GetCheck()==TRUE)
	{
		kind = 1;
	}
	else if(m_radio12.GetCheck()==TRUE)
	{
		kind = 2;
	}
	else
	{
		kind = 3;
	}
	int bl1[460];
	int bl2[460];
	 FILE  *fu,*f;
	double d[460][20];
	for(int i=0;i<460;i++)
	{
		dlg.m_xpro.StepIt(); 
		//dlg.m_xpro.SetPos((int)(i*0.22));
		//m_pro1.SetPos((int)(i*0.22));
		if(kind==1)
		{
		int v=1;
        for(int j=1;j<=20;j++)
        {
            //printf("asdasdasdasda   %d\n",j);
			double min[5];
			double l[]={1,1,1,1,1};
            //printf("%d\n",(v-1)*30+1);
			//j=8;
         for (int t=(v-1)*30+1;t<=(v-1)*30+passage;t++)  
		 {
			 //t=v*30+1;
			 char z[5]=".txt";
		char s[20]="r\\text\\un";
		char pe[4]="000";
		itoa(i+1,pe,10);
		strcat(s,pe);
		strcat(s,z);
		fu=fopen(s,"r");
		if(!fu)
        {
		    //printf("can't open file\n");
		    exit(1);
        }
			
             //printf("%d\n",t);
			 int yr=0;
             char s2[20]="r\\ba\\";
             char u[5]="0000";
			 z[0]='.';
			 z[1]='t';
			 z[2]='x';
			 z[3]='t';
		//	 t = 75;
             itoa(t,u,10);
             strcat(s2,u);
            strcat(s2,z);
           f=fopen(s2,"r");
            if(!f)
            {
                 exit(1);
            }
            double len=0;
            double e1 ,e2;
			double lk;
			double last;
            while(fscanf(f,"%lf",&e1)!=EOF)
            {
				yr++;
                fscanf(fu,"%lf",&e2);
				//printf("%lf ",e2);
				if(yr<=32)
						{
							len+=m_w1*m_w1*(e1-e2)*(e1-e2);
						}
						else if(yr<=44)				
						{                     
							len+=m_w2*m_w2*(e1-e2)*(e1-e2);				
						}				
						else if(yr>44&&yr<=48)				
						{                    
							len+=m_w3*m_w3*0.00001*(e1-e2)*(e1-e2);									
						}				
						else					
							len+=m_w4*m_w4*(e1-e2)*(e1-e2); 
				lk=e1;
				last = (e1-e2)*(e1-e2);
            }
			//printf("%lf\n",len);
			len-=last;
			fclose(f);
            if((t-(j-1)*60-1)<5 )
            {
                min[t-(j-1)*60-1]=len;
            }
            else 
			if((t-(j-1)*60-1)==5)
			{
				for(int ii = 0; ii < 5; ii++)
				{
                   min[ii]=bj(min,5)[ii];
				}
			}
            else
            {
                if(len<min[0])
                {
                    for(int i=4;i>0;i--)
                     {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
                     }
                    min[0]=len;
                    l[0]=lk;
                }
                else if(len<min[1])
                {
                    for(int i=4;i>1;i--)
                      {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
                     }
                    min[1]=len;
                    l[1]=lk;
                }
                else if(len<min[2])
                {
                    for(int i=4;i>2;i--)
                       {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
					}
                    min[2]=len;
                    l[2]=lk;
                }
                else if(len<min[3])
                {
                    for(int i=4;i>3;i--)
                       {
                         min[i]=min[i-1];
                         l[i]=l[i-1];
                     }
                    min[3]=len;
                    l[3]=lk;
                }
                else if(len<min[4])
                {
                    min[4]=len;
                    l[4]=lk;
                }
            }
         fclose(fu);
		 }		
		  d[i][j-1]=(l[0]*min[0]+l[1]*min[1]+l[2]*min[2]+l[3]*min[3]+l[4]*min[4])/(l[0]+l[1]+l[2]+l[3]+l[4]);
		  //printf("%lf  %lf  %lf  %lf  %lf   %lf\n",min[0],min[1],min[2],min[3],min[4],d[i][j-1]);
		  v=v+2;		  
        }
		}
		else if(kind==2)
		{
			char z[5]=".txt";
		char s[20]="r\\text\\un";
		char pe[4]="000";
		itoa(i+1,pe,10);
		strcat(s,pe);
		strcat(s,z);
		double keep[60][300];
    double aver[20][300];
	for(int a1 = 0; a1 < 60; a1++)
		for(int a2 = 0; a2 < 300; a2++)
			keep[a1][a2] = 0;
		for(int a11 = 0; a11 < 20; a11++)
		for(int a21 = 0; a21 < 300; a21++)
			aver[a11][a21] = 0;
			int pa;
	       for(int i1=0;i1<20;i1++)//根据现在作者人数进行更改	
		   {
		for(int t=i1*60+1;t<=60*i1+passage;t++)//根据每个作者的篇数进行更改
		
		{
			char s2[20]="r\\ba\\";
             char u[5]="0000";
	             itoa(t,u,10);
             strcat(s2,u);
            strcat(s2,z);
           f=fopen(s2,"r");
            if(!f)           
				{				
					MessageBox("未找到特征库!","提示",MB_OK);				
					break;           
				}	
			double e;
			 pa=0;
			while(fscanf(f,"%lf",&e)!=EOF)
			{
				keep[t%10-1][pa]=e;
				pa++;
			}
			fclose(f);
		}
		
		for(int j1=0;j1<pa;j1++)
        {
            double result=0;
            for(int j2=0;j2<passage;j2++)
                result+=keep[j2][j1];
            aver[i1][j1]=result*1.0/passage;//最后聚类的结果，每个作者的平均向量。
			
        }
	}
            	  

			for(int j = 0; j < 20; j++)
			{
				    int yr = 0;                
					double len=0;               
					double e1,e2;
					fu=fopen(s,"r");
		            if(!fu)       			
								{							
									MessageBox("未找到特征分析结果!","提示",MB_OK);							
									SetDlgItemText(IDC_EDIT4,"");				      			
								}
					while(fscanf(fu,"%lf",&e1)!=EOF)           				
					{																									
						yr++; 
						e2 = aver[j][yr-1];
						
						if(yr<=32)
						{
							len+=m_w1*m_w1*(e1-e2)*(e1-e2);
						}
						else if(yr<=44)				
						{                     
							len+=m_w2*m_w2*(e1-e2)*(e1-e2);				
						}				
						else if(yr>44&&yr<=48)				
						{                    
							len+=m_w3*m_w3*0.00001*(e1-e2)*(e1-e2);									
						}				
						else					
							len+=m_w4*m_w4*(e1-e2)*(e1-e2); 
					}					
					d[i][j] = len;
					fclose(fu);
			}
			
		}
		else
		{
			char z[5]=".txt";
		char s[20]="r\\text\\un";
		char pe[4]="000";
		itoa(i+1,pe,10);
		strcat(s,pe);
		strcat(s,z);
		double keep[60][300];
    double aver[20][300];
	for(int a1 = 0; a1 < 60; a1++)
		for(int a2 = 0; a2 < 300; a2++)
			keep[a1][a2] = 0;
		for(int a11 = 0; a11 < 20; a11++)
		for(int a21 = 0; a21 < 300; a21++)
			aver[a11][a21] = 0;
	int pa;
	for(int i1=0;i1<20;i1++)//根据作者数修改
	{
		for(int t=i1*60+1;t<=60*i1+passage;t++)//根据作者篇数修改
		{
			char s2[20]="r\\ba\\";
             char u[5]="0000";
	             itoa(t,u,10);
             strcat(s2,u);
            strcat(s2,z);
           f=fopen(s2,"r");
            if(!f)
            {
           MessageBox("未找到特征库!","提示",MB_OK);				 
            exit(1);
            }
			double e;
			 pa=0;
			while(fscanf(f,"%lf",&e)!=EOF)
			{
				keep[i%passage-1][pa]=e;//根据每个作者篇数修改
				pa++;
			}
			fclose(f);
		}
		double min=1000;
		int mark=0;
		for(int j1=0;j1<10;j1++)
        {
            double result=0;
            for(int j2=0;j2<10;j2++)
            {
                if(j2!=j1)
                for(int j3=0;j3<pa;j3++)
                    result+=(keep[j2][j3]-keep[j1][j3])*(keep[j2][j3]-keep[j1][j3]);
            }
            if(result<min)
            {
                min=result;
                mark=j1;
            }
        }
        for(int j3=0;j3<pa;j3++)
        aver[i1][j3]=keep[mark][j3];
	}
	for(int j = 0; j < 20; j++)
			{
				    int yr = 0;                
					double len=0;               
					double e1,e2;
					fu=fopen(s,"r");
		            if(!fu)       			
								{							
									MessageBox("未找到特征分析结果!","提示",MB_OK);							
									SetDlgItemText(IDC_EDIT4,"");				      			
								}
					while(fscanf(fu,"%lf",&e1)!=EOF)           				
					{																									
						yr++; 
						e2 = aver[j][yr-1];
						
						if(yr<=32)
						{
							len+=m_w1*m_w1*(e1-e2)*(e1-e2);
						}
						else if(yr<=44)				
						{                     
							len+=m_w2*m_w2*(e1-e2)*(e1-e2);				
						}				
						else if(yr>44&&yr<=48)				
						{                    
							len+=m_w3*m_w3*0.00001*(e1-e2)*(e1-e2);									
						}				
						else					
							len+=m_w4*m_w4*(e1-e2)*(e1-e2); 
					}
					d[i][j] = len;
					fclose(fu);
			}
			
		}
		
	}
	    int bi;
		int right[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	    FILE *fb;
        fb=fopen("r\\bz.txt","r");
        for(int ds=0;ds<460;ds++)
        {
			fscanf(fb,"%d",&bi);
			//printf("%lf\n",d[ds][0]);
			//printf("%lf\n",d[ds][1]);
            int mark[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
			double ti[20];
			for(int u = 0; u < 20; u++)
			{
				mark[u] = u;
				ti[u] = d[ds][u];
			}
			int m;
			double t;
			for(int i = 0; i < 20; i++)
			{
				for(int j=0;j<20-1-i;j++)
					if(ti[j]>ti[j+1])
					{
						m = mark[j];
						mark[j] = mark[j+1];
						mark[j+1] = m;
						t = ti[j];
						ti[j] = ti[j+1];
						ti[j+1] = t;
					}
			}
			if(mark[0]+1==bi )
                right[0]++;
			if(mark[0]+1==bi || mark[1]+1==bi )
                right[1]++;
			if(mark[0]+1==bi|| mark[1]+1==bi || mark[2]+1==bi)
                right[2]++;
			if(mark[0]+1==bi|| mark[1]+1==bi || mark[2]+1==bi || mark[3]+1==bi)
                right[3]++;
			if(mark[0]+1==bi|| mark[1]+1==bi || mark[2]+1==bi || mark[3]+1==bi || mark[4]+1==bi)
                right[4]++;
			if(mark[0]+1==bi|| mark[1]+1==bi || mark[2]+1==bi || mark[3]+1==bi || mark[4]+1==bi || mark[5]+1==bi)
                right[5]++;
			if(mark[0]+1==bi|| mark[1]+1==bi || mark[2]+1==bi || mark[3]+1==bi || mark[4]+1==bi || mark[5]+1==bi || mark[6]+1==bi)
                right[6]++;
			if(mark[0]+1==bi|| mark[1]+1==bi || mark[2]+1==bi || mark[3]+1==bi || mark[4]+1==bi || mark[5]+1==bi || mark[6]+1==bi || mark[7]+1==bi)
                right[7]++;
			//printf("文章%d最可能是作者%d写的，其次是作者%d写的\n",ds+1,mark[0]+1,mark[1]+1);
        }
		CString str;
	    str.Format("%.2f", 100*right[0]*1.0/460);
		m_rate = m_rate +"范围为1人准确率为"+str+"%";
		str.Format("%.2f", 100*right[1]*1.0/460);
		m_rate = m_rate +"\r\n"+"范围为2人准确率为"+str+"%";
		str.Format("%.2f", 100*right[2]*1.0/460);
		m_rate = m_rate +"\r\n"+"范围为3人准确率为"+str+"%";
		str.Format("%.2f", 100*right[3]*1.0/460);
		m_rate = m_rate +"\r\n"+"范围为4人准确率为"+str+"%";
		str.Format("%.2f", 100*right[4]*1.0/460);
		m_rate = m_rate +"\r\n"+"范围为5人准确率为"+str+"%";
		str.Format("%.2f", 100*right[5]*1.0/460);
		m_rate = m_rate +"\r\n"+"范围为6人准确率为"+str+"%";
		str.Format("%.2f", 100*right[6]*1.0/460);
		m_rate = m_rate +"\r\n"+"范围为7人准确率为"+str+"%";
		str.Format("%.2f", 100*right[7]*1.0/460);
		m_rate = m_rate +"\r\n"+"范围为8人准确率为"+str+"%";
		UpdateData(false);
        //printf("范围为1人准确率为%lf%\n",right[0]*1.0/184);
	//	printf("范围为2人准确率为%lf\n",right[1]*1.0/184);
		//printf("范围为3人准确率为%lf\n",right[2]*1.0/184);
		//printf("范围为4人准确率为%lf\n",right[3]*1.0/184);
		//printf("范围为5人准确率为%lf\n",right[4]*1.0/184);
		//printf("范围为6人准确率为%lf\n",right[5]*1.0/184);
		//printf("范围为7人准确率为%lf\n",right[6]*1.0/184);
		//printf("范围为8人准确率为%lf\n",right[7]*1.0/184);
		SetDlgItemText(IDC_STATIC0,"测试结果");
		dlg.SetDlgItemText(IDC_STATIC70,"完成！");
}

void CAsdfghjkDlg::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
int cursel = m_tab.GetCurSel();
switch(cursel)
 {
 case 0:
  para1.ShowWindow(true);
  para2.ShowWindow(false);
  para3.ShowWindow(false);
  para4.ShowWindow(false);
  break;
 case 1:
  para1.ShowWindow(false);
  para2.ShowWindow(true);
  para3.ShowWindow(false);
  para4.ShowWindow(false);
  break;
 case 2:
  para1.ShowWindow(false);
  para2.ShowWindow(false);
  para3.ShowWindow(true);
  para4.ShowWindow(false);
  break;
 case 3:
  para1.ShowWindow(false);
  para2.ShowWindow(false);
  para3.ShowWindow(false);
  para4.ShowWindow(true);
  break;
 default:;
 }
	*pResult = 0;
}

void CAsdfghjkDlg::OnButton6() 
{
     //Cxunlian dlg;  
	 dlg.Create(IDD_DIALOG7,NULL);
	 dlg.ShowWindow(SW_SHOW);
	 dlg.MoveWindow(500,200,400,250);
	 dlg.SetDlgItemText(IDC_STATIC70,"特征提取中，请稍等...");
	// TODO: Add your control notification handler code here
	char name[20][10] = {"c","d","h","ho","l","m","mao","x","f","g","hg","lei","liu","mai","maop","n","r","shen","shi","z"};
for(int b = 0; b < 20; b++)
{
	dlg.m_xpro.SetPos((int)(b*5+5));
	char c[4024][40];
	char c1[4024][40];
	char c2[4024][40];
	FILE *fp,*fp2;
	for(int qw=1;qw<=60;qw++){
	char z[10]=")_cla.txt";
	char s2[40]="r\\2\\";
	strcat(s2,name[b]);
	strcat(s2,"\\");
	strcat(s2,name[b]);
	strcat(s2," (");
	char pe[4];
	pe[0]='0';
	pe[1]='0';
	pe[2]='0';
	pe[3]='0';
    itoa(qw,pe,10);
	strcat(s2,pe);
	strcat(s2,z);
	fp =  fopen(s2,"r");
	if(!fp)
	{
		MessageBox("训练失败!","提示",MB_OK);
		//printf("can't open file\n");
		//printf("%s\n",s2);
		exit(1);
	}

    int i = 0;
	char *delim = "/";
	while(fscanf(fp,"%s",c[i])!=EOF)
	{
		if(strchr(c[i],'/')!=NULL)
		{
		strcpy(c1[i],strtok(c[i],delim));
		strcpy(c2[i],strtok(NULL,delim));
		i++;
		}
	}
	fclose(fp);

	int j,k;
	char s1[100]="r\\ba\\";
	itoa(qw+60*b,pe,10);
	char zx[10]=".txt";
	strcat(s1,pe);
	strcat(s1,zx);
	fp2=fopen(s1,"w");
	if(!fp2)
	{
		MessageBox("训练失败!","提示",MB_OK);
		//printf("can't open file\n");
		exit(1);
	}
	//printf("词频向量p（名词，动词，形容词，数词，量词，代词，副词，介词，连词，助词）\n");
	double num[10];
	char all[10]={'n','v','a','m','q','r','d','p','c','u'};
	for(j = 0; j < 10; j++)
		num[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <10; k++)
			if(c2[j][0] == all[k])
				num[k]++;
	//printf("p(");
	for(j = 0; j < 9; j++)
	{
		//printf("%lf,",num[j]/i);
		fprintf(fp2,"%lf ",num[j]/i);
	}
	//printf("%lf)\n",num[9]/i);
	fprintf(fp2,"%lf ",num[9]/i);
    //printf("特殊副词词频\n");
	int dn =  30;
	double dnum[50];
	char d[50][20] = {"很","颇","极","十分","就","都","居然","重新","不断","乃","不","也","其","几","却","何","可","只","在","即","既","多少","又","反","得","还","太","连","才","的"};
	for(j = 0; j < dn; j++)
		dnum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <dn; k++)
			if(strcmp(c1[j],d[k])==0)
				dnum[k]++;
			for(k = 0; k <dn; k++){
			//printf("%s\t(%lf)\n",d[k],dnum[k]/i);
			if(k==4||k==29)
			fprintf(fp2,"%lf ",dnum[k]/i);
			}
	//printf("特殊介词词频\n");
	int pn =  21;
	double pnum[50];
	char p[50][20] = {"与","到","于","从","似","当","去","让","及","往","对","如","把","替","比","至","同","凭","跟","被","给"};
	for(j = 0; j < dn; j++)
		pnum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <pn; k++)
			if(strcmp(c1[j],p[k])==0)
				pnum[k]++;
			for(k = 0; k <pn; k++){
			//printf("%s\t(%lf)\n",p[k],pnum[k]/i);
		/*	fprintf(fp2,"%lf ",pnum[k]/i);*/
			}
	//printf("特殊助词词频\n");
	int un =  13;
	double unum[50];
	char u[50][20] = {"么","了","之","为","着","以","向","来","如","是","每","等","将"};
	for(j = 0; j < un; j++)
		unum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <un; k++)
			if(strcmp(c1[j],u[k])==0)
				unum[k]++;
			for(k = 0; k <un; k++){
			//printf("%s\t(%lf)\n",u[k],unum[k]/i);
			if(k==1||k==4||k==9)
			fprintf(fp2,"%lf ",unum[k]/i);
			}
	//printf("特殊语气词词频\n");
	int yn =  17;
	double ynum[50];
	char y[50][20] = {"吧","罢","呗","啦","了","吗","嘛","么","麽","呢","呐","呵","哈","哉","大概","可能","一定"};
	for(j = 0; j < yn; j++)
		ynum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <yn; k++)
			if(strcmp(c1[j],y[k])==0)
				ynum[k]++;
			for(k = 0; k <yn; k++){
			//printf("%s\t(%lf)\n",y[k],ynum[k]/i);
			fprintf(fp2,"%lf ",ynum[k]/i);
			}
	int bn =  12;
	double bnum[50];
	double bnnum =0;
	char b[50][20] = {"。","？","！","，","、","；","：","“","──","「","《","…"};
	for(j = 0; j < bn; j++)
		bnum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <bn; k++)
			if(strcmp(c1[j],b[k])==0)
			{
				bnum[k]++;
				bnnum++;
			}
			for(k = 0; k <bn; k++)
			{
			//printf("%s\t(%lf)\n",b[k],bnum[k]/bnnum);
			fprintf(fp2,"%lf ",bnum[k]/bnnum);
			}
/*	printf("特殊时间词词频\n");
	int tn =  6;
	double tnum[50];
	char t[50][20] = {"今天","明天","昨天","当前","以后","未来"};
	for(j = 0; j < tn; j++)
		tnum[j] = 0;
	for(j = 0; j < i; j++)
		for(k = 0; k <tn; k++)
			if(strcmp(c1[j],t[k])==0)
				tnum[k]++;
			for(k = 0; k <tn; k++)
			printf("%s\t(%lf)\n",t[k],tnum[k]/i);

*/
	char sentence[200][100][10];
	int sth = 0;
	int snum = 0;
	int ssnum = 0;
	int slength[1024];
	int wordnum = 0;
    for(j = 0; j < i; j++)
	{
		if(c2[j][0]=='w')
		{
			ssnum++;
		}
		if(strcmp(c1[j],"。")!=0 && strcmp(c1[j],"？")!=0 && strcmp(c1[j],"！")!=0)
		{
			if(c2[j][0] != 'w')
			{
				wordnum++;
			    strcpy(sentence[snum][sth],c2[j]);
			    sth++;
			}
		}
		else
		{
			if(c2[j-1][0]!='w')
			{
			   slength[snum] = sth;
			  
               snum++;
			   sth = 0;
			}
		}

	}


    FILE *fp1;
	fp1 =  fopen("r\\jushi.txt","r");
	char s[100];
	char str[300][100][10];
	int jsnum[1000];
	int jnum = 0;
	int jssentencelength[300];
	for(int k1 = 0; k1 < 300; k1++)
          jssentencelength[k1] = 0;
	int count1 = 0;
    while(fscanf(fp1,"%s",s)!=EOF)
	{
		//printf("%s ",s);
		char delims[] = "+";
		char *result = NULL;
		result = strtok( s, delims );
		int count2 = 0;
		while( result != NULL )
		{
			jssentencelength[count1]++;
			strcpy(str[count1][count2],result);
			//printf( "%s ", result );
			result = strtok( NULL, delims );
			count2++;
		}
		//printf("\n");
		count1++;
	}

	int px[300];
	for(int k2 = 0; k2 < 300; k2++)
          px[k2] = 0;
	for(int i2 = 0; i2 < snum; i2++)
	{
		for(int j2 = 0; j2 < count1; j2++)
		  if(Judge(sentence[i2],str[j2],slength[i2],jssentencelength[j2])==1)
		  {
			  px[j2]++;
			  jnum++;
		  }
	}
	
    //printf("本文共%d句\n",snum);
	fprintf(fp2,"%lf ",snum*1.0);
    //printf("平均句长%d\n",wordnum/snum);
	fprintf(fp2,"%lf ",wordnum/snum*1.0);
	//printf("本文共%d短句\n",ssnum);
	fprintf(fp2,"%lf ",ssnum*1.0);
    //printf("平均每句中的短句数%d\n",ssnum/snum);
	fprintf(fp2,"%lf ",ssnum/snum*1.0);


	//printf("句式向量：");
	//printf("%d",count1);
	//printf("px(");
	for(int k3 = 0; k3 < count1; k3++)
	{
		double e=px[k3]*1.0/jnum;
		//printf("%lf,",e);
		fprintf(fp2,"%lf ",e);
	}
	fprintf(fp2,"%lf ",1.0);
	//printf(")\n");
	fclose(fp1);
	fclose(fp2);
	}
}
     dlg.SetDlgItemText(IDC_STATIC70,"特征提取完成！赋予文章权重中...请稍等");
	 dlg.m_xpro.SetRange(0, 3600 );//设置进度条范围   
	 dlg.m_xpro.SetStep(1);//步长
	 dlg.m_xpro.SetPos(0);
	int a[1200];
	int v=1;
    for(int i=0;i<20;i++)
    {
        for(int j=i*60;j<i*60+20;j++)
            a[j]=1;
        for(j=i*60+20;j<i*60+60;j++)
            a[j]=0;
    }
    int k;
    //for(i=0;i<20;i++)
        //m[i]=20;
	int kk=1;
    while(1){
            int mk=1;
			v++;
    for(int i=0;i<1200;i++)
    {
		dlg.m_xpro.StepIt();
        if(a[i]==0)
        {
            mk=0;
           k=get(i,a);
        if(k==(int)i/60)
        {
			//printf("%d.....%d\n",k,(i+1)%60);
            a[i]=1;
            //m[k]++;
        }
        else
            {
                FILE *f;
                char z[7]=".txt";
            char s[20]="r\\ba\\";
            char pe[5]="0000";
            itoa(i+1,pe,10);
            strcat(s,pe);
            strcat(s,z);
            f=fopen(s,"r+");
            	double e;
        fseek(f,-9,SEEK_END);
        fscanf(f,"%lf",&e);
        fseek(f,-9,SEEK_END);
        fprintf(f," %lf",e/1.2);
		fclose(f);
            }
        }
    }
	kk++;
    if(mk==1)
        break;
	if(v>3)
		break;
	}
	 dlg.SetDlgItemText(IDC_STATIC70,"训练完成！");
}

void CAsdfghjkDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	m_radio11.SetCheck(true);
	m_radio12.SetCheck(false);
	m_radio13.SetCheck(false);
}

void CAsdfghjkDlg::OnRadio5() 
{
	// TODO: Add your control notification handler code here
	m_radio11.SetCheck(false);
	m_radio12.SetCheck(true);
	m_radio13.SetCheck(false);
}

void CAsdfghjkDlg::OnRadio6() 
{
	// TODO: Add your control notification handler code here
	m_radio11.SetCheck(false);
	m_radio12.SetCheck(false);
	m_radio13.SetCheck(true);
}

void CAsdfghjkDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	ddlg.DoModal();
}

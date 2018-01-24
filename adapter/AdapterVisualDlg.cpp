#include "AdapterVisual.h"
#include "AdapterVisualDlg.h"
#include "afxdialogex.h"
#include <memory>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

std::vector<std::shared_ptr<VectorObject>> vectorObjects
{
  make_shared<VectorRectangle>(10,10,100,100),
    make_shared<VectorRectangle>(30,30,60,60)
    };

struct LineToPointCachingAdapter
{
  typedef vector<Point> Points;

  LineToPointCachingAdapter(Line& line) //constructor
  {
    boost::hash<Line> hash;
    line_hash = hash(line);
    if(cache.fine(line_hash) != cache.end())
      {
	return;
      }
   
    static int count = 0;
    cout << "generating points for line\n" << count++ << endl;

    Point points;
    
    int left = min(line.start.x, line.end.x);
    int right = max(line.start.x, line.end.x);
    int top = min(line.start.y, line.end.y);
    int bottom = max(line.start.y, line.end.y);
    int dx = right - left;
    int dy = line.end.y - line.start.y;

    if(dx == 0)
      {
	//vertical
	for(int y = top;  y <= bottom; y++)
	  {
	    points.emplace_back(Point{left, y});
	  }
      }
    else if(dy ==0)
      {
	for(int x = left; x <= right; x++)
	  {
	    points.emplace_back(Point{x,top});
	  }
      }

    cache[line_hash] = points;
  }
  virtual Points::iterator begin() {return cache[line_hash].begin();}
  virtual Points::iterator end() {return cache[line_hash].end();}
private:
  size_t line_hash;
  static map<size_t, vector<Point>> cache;
};

map<size_t, vector<Point>> LineToPointCachingadapter::cache;
//ABoutDlg dialog used for app about

class CAbout Dlg : public CDialogEx
{
 public:
  CAboutDlg();

  //Dialog Data
#ifdef AFX_DESIGN_TIME


 protected:
  HICON mHIcon;

  void DrawPoints(CPaintDC& dc, std::vector<Point>::iterator begin, std::vector<Point>::iterator end)
  {
  for(auto i = begin; i != end; i++)
    {
  dc.SetPixel(i->x, i->y, 0);
}
}

  //Generated message map functions
  virtual BOOL OnInitDialog();
  afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
  afx_msg void OnPaint();
  afx_msg HCURSOR OnQueryDragIcon();
  DECLARE_MESSAGE_MAP()
    };

 CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
 {}

 void CAboutDlg::DoDataExchange(CDataExchange* pDX)
 {
  CDialogEx::DoDataExchange(pDX);
}

 BEGIN_MESSAGE_MAP(CAboutDlg,CDialogEx)
   ON_WM_SYSCOMMAND()
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   END_MESSAGE_MAP()

   //CAdapterVisualDlg message handlers

   BOOL CAdapterVisualDlg::OnInitDialog()
   {
  CDialogEx::OnInitDialog();

  //Add "About..." menu item to system menu.
  //IDM_ABOUTBOX must be inm the system command range.
  ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
  ASSERT(IDM_ABOUTBOX < 0xF000);

  CMenu* pSysMenu = GetSystemMenu(FALSE);
  if(pSysMenu != NULL)
    {
  BOOL bNameValid;
  CString strAboutMenu;
  bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
  ASSERT(bNameValid);
  if(!strAboutMenu.IsEmpty())
    {
  pSysMenu->AppendMenu(MF_SEPARATOR);
  pSysMenu->AppendMenu(MF_STRING< IDM_ABOUTBOX, strAboutMenu);
  
}
}

  //Set the icon for this dialog.  The framework does this automatically when the application's main window is not a dialog.
  SetIcon(m_hIcon, TRUE); //sets big icon
  SetIcon(m_hIcon, FALSE); //sets small icon

  //TODO: Add extra initialization here

  return TRUE; //return true unless you set the focus to a control.
}

 void CAdapterVisualDlg::OnSysCommand(UINT nID, LPARAM lParam)
 {
  if((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
  CAboutDlg dlgAbout;
  dlgAbout.DoModal();
}
  else
    {
  CDialogEx::OnSysCommand(nID,lParam);
}
}

 //If you add a minimize button to your dialog, you will need the code below to draw the icon.  For MFC applications using the document/view model, this is automatically done for you by the framework.

 void CAdapterVisualDlg::OnPain()
 {
  if(IsIconic())
    {
  CPaintDC dc(this); //device context for painting
  SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()),)

    //Center icon in client rectangle

    int cxIcon = GetSystemMetrics(SM_CXICON);
  int cyICON = Ge5SystemMetrics(SM_CYICON);
  CRect rectl
    GetClientRect(&rect);
  int x = (rect.Width() - cxIcon + 1) / 2;
  int y = (rect.Height() - cyIcon + 1) / 2;

  //Draw the icon
  dc.DrawIcon(x, y, m_hIcon);
}
  else
    {
  for(auto& o : vectorObjects)
    {
  for(auto& l : *o)
    {
  LineToPointCachingAdapter lpo{l};
  DrawPoints(dc, lpo.begin(), lpo.end();)
    }
}
  CDialogEx::OnPaint();
  
}
  
}
 //The system calls this function to obtain the cursor to display while the u the minimized window.

 HCURSOR CAdapterVisualDlg::OnQueryDragIcon()
 {
  return static_cast<HCURSOR>(m_hIcon);
}
  
}

   

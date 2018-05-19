// PointToDark.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "PointToDark.h"
#include <stdio.h>

#define MAX_LOADSTRING 100
//#define x 1682
//#define y 881
int x=1682,y=881;

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	WNDCLASS wc = {0};
    wc.lpszClassName = L"wndclass";
    wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpfnWndProc = WndProc;
    RegisterClass(&wc);

    HWND hWnd = CreateWindowExW(WS_EX_LAYERED|WS_EX_TOOLWINDOW, L"wndclass", L"Window", WS_POPUP|WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, 0, 0, hInstance, 0);
    if (hWnd == NULL)
        return 1;
	//SetTimer(hWnd,1,1000,NULL);

    SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA); // Tomato
	MSG msg = {0};
    while (GetMessage(&msg, 0, 0, 0))
    {
        DispatchMessage(&msg);
    }

	
    return 0;
	//
	//MSG msg;
	//HACCEL hAccelTable;

	//// 初始化全局字符串
	//LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	//LoadString(hInstance, IDC_POINTTODARK, szWindowClass, MAX_LOADSTRING);
	//MyRegisterClass(hInstance);

	//// 执行应用程序初始化:
	//if (!InitInstance (hInstance, nCmdShow))
	//{
	//	return FALSE;
	//}

	//hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_POINTTODARK));

	//// 主消息循环:
	//while (GetMessage(&msg, NULL, 0, 0))
	//{
	//	if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
	//	{
	//		TranslateMessage(&msg);
	//		DispatchMessage(&msg);
	//	}
	//}

	//return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
//  注释:
//
//    仅当希望
//    此代码与添加到 Windows 95 中的“RegisterClassEx”
//    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
//    这样应用程序就可以获得关联的
//    “格式正确的”小图标。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_POINTTODARK));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_POINTTODARK);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//int wmId, wmEvent;
	//PAINTSTRUCT ps;
	//HDC hdc;

	//switch (message)
	//{
	//case WM_COMMAND:
	//	wmId    = LOWORD(wParam);
	//	wmEvent = HIWORD(wParam);
	//	// 分析菜单选择:
	//	switch (wmId)
	//	{
	//	case IDM_ABOUT:
	//		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
	//		break;
	//	case IDM_EXIT:
	//		DestroyWindow(hWnd);
	//		break;
	//	default:
	//		return DefWindowProc(hWnd, message, wParam, lParam);
	//	}
	//	break;
	//case WM_PAINT:
	//	hdc = BeginPaint(hWnd, &ps);
	//	// TODO: 在此添加任意绘图代码...
	//	EndPaint(hWnd, &ps);
	//	break;
	//case WM_DESTROY:
	//	PostQuitMessage(0);
	//	break;
	//default:
	//	return DefWindowProc(hWnd, message, wParam, lParam);
	//}
	//return 0;
	////////////////////////////////////////////////
	static HDC hDC = GetWindowDC(hWnd);
    //static HRGN hRgn = CreateRectRgn(120, 70, 280, 230);

    switch(message)
    {
    case WM_ERASEBKGND:
        {
            DefWindowProc(hWnd, message, wParam, lParam);
            //FillRgn(hDC, hRgn, CreateSolidBrush(RGB(255, 165, 0))); // Orange
            //SelectObject(hDC, hRgn);
            return 0;
        }

    case WM_CREATE:
        {
			//int x=1682,y=881;
			FILE *fp;
			fp = fopen("coordinate.ini","r");
			if(fp != NULL)
			{
				fscanf(fp,"%d %d",&x,&y);
				HRGN hRgn1 = CreateRectRgn(0,0,5,5);//CreateEllipticRgn(0, 0, 400, 300);
				HRGN hRgn2 = CreateRectRgn(1,0,5,5);//CreateEllipticRgn(150, 100, 250, 200);
				HRGN hRgn3 = CreateRectRgn(0,1,5,5);//
				CombineRgn(hRgn1, hRgn1, hRgn2, RGN_XOR);//异或方式
				CombineRgn(hRgn1, hRgn1, hRgn3, RGN_DIFF);//
				SetWindowRgn(hWnd, hRgn1, TRUE);
				SetWindowPos(hWnd,HWND_TOPMOST,x,y,5,5,SWP_NOSIZE|SWP_SHOWWINDOW);
				DeleteObject(hRgn1);
				 DeleteObject(hRgn2); 
				 DeleteObject(hRgn3);

				 SetTimer(hWnd,1,1000,NULL);
				 break;
				 fclose(fp);
			}
         }
 
    case WM_LBUTTONDOWN:
         {
            //SendMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);
            break;
        }

    case WM_DESTROY:
        {
            //DeleteObject(hRgn);
            ReleaseDC(hWnd, hDC);
            PostQuitMessage(0);
			
			KillTimer(hWnd,1);
            break;
         }
	case WM_TIMER: 
		{
			//HWND foreHwnd = GetForegroundWindow();
			//HWND foreHwnd2 = GetActiveWindow();
			//HWND foreHwnd2 = GetWindow(NULL,GW_HWNDFIRST);
			//HWND foreHwnd2 = GetTopWindow(NULL);
			//if(foreHwnd2 != hWnd)
				SetWindowPos(hWnd,HWND_TOPMOST,x,y,5,5,SWP_NOSIZE|SWP_SHOWWINDOW);
			break;
		}
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

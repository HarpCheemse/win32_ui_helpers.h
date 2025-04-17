#include <windows.h>
#include <commctrl.h> 
#include <stdio.h>

HFONT createUIFont_Default(int size, int spread, int nEscapement, int nOrientation,
    int weight, int italic, int underline, int strikeout, LPCSTR font) 
{
    return CreateFont(
        size, spread, nEscapement, nOrientation,
        weight, italic, underline, strikeout,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font
    );
}
HFONT createUIFont(int size, int weight, LPCSTR font) 
{
    return CreateFont(
        size, 0, 0, 0,
        weight, FALSE, FALSE, FALSE,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font
    );
}
HFONT createUIFont_90(int size, int weight, LPCSTR font) 
{
    return CreateFont(
        size, 0, 900, 900,
        weight, FALSE, FALSE, FALSE,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font
    );
}
HFONT createUIFont_Rotate(int size, int nEscapment, int nOrientation, int weight, LPCSTR font) 
{
    return CreateFont(
        size, 0, nEscapment, nOrientation,
        weight, FALSE, FALSE, FALSE,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font
    );
}
HFONT createUIFont_Spread(int size, int spread, int weight, LPCSTR font) 
{
    return CreateFont(
        size, spread , 0, 0,
        weight, FALSE, FALSE, FALSE,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font
    );
}
HFONT createUIFont_Italic(int size, int weight, LPCSTR font)
{
    return CreateFont(
        size, 0 , 0, 0,
        weight, TRUE, FALSE, FALSE,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font
    );
}
HFONT createUIFont_Underline(int size, int weight, LPCSTR font)
{
    return CreateFont(
        size, 0 , 0, 0,
        weight, FALSE, TRUE, FALSE,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font
    );
}
HFONT createUIFont_Strikeout(int size, int weight, LPCSTR font)
{
    return CreateFont(
        size, 0 , 0, 0,
        weight, FALSE, FALSE, TRUE,
        ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, font
    );
}

HWND createLabel_Default(HWND parent, const char* text, DWORD style, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndLabel = CreateWindow("STATIC", text,
        WS_VISIBLE | WS_CHILD | style,
        x, y, w, h,
        parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndLabel, WM_SETFONT, (WPARAM)font, TRUE);
    return hwndLabel;
}
HWND createLabel(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndLabel = CreateWindow("STATIC", text,
        WS_VISIBLE | WS_CHILD,
        x, y, w, h,
        parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndLabel, WM_SETFONT, (WPARAM)font, TRUE);
    return hwndLabel;
}
HWND createLabel_Box(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndLabel = CreateWindow("STATIC", text,
        WS_CHILD | WS_BORDER | SS_CENTER | SS_CENTERIMAGE,
        x, y, w, h,
        parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndLabel, WM_SETFONT, (WPARAM)font, TRUE);
    return hwndLabel;
}
HWND createLabel_Button(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndLabel = CreateWindow("STATIC", text,
        WS_VISIBLE | WS_CHILD | SS_NOTIFY,
        x, y, w, h,
        parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndLabel, WM_SETFONT, (WPARAM)font, TRUE);
    return hwndLabel;
}

HWND createEdit_Default(HWND parent, const char* text, DWORD style, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndEdit = CreateWindow("EDIT", text,
    WS_VISIBLE | WS_CHILD | style,
    x, y, w, h,
    parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndEdit, WM_SETFONT, (WPARAM)font, TRUE);
    return hwndEdit;
}
HWND createEdit(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndEdit = CreateWindow("EDIT", text,
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
    x, y, w, h,
    parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndEdit, WM_SETFONT, (WPARAM)font, TRUE);
    return hwndEdit;
}
HWND createEdit_PassWord(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndEdit = CreateWindow("EDIT", text,
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD | ES_AUTOHSCROLL,
    x, y, w, h,
    parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndEdit, WM_SETFONT, (WPARAM)font, TRUE);
    return hwndEdit;
}
HWND createEdit_Single_Number(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndEdit = CreateWindow("EDIT", text,
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER | ES_AUTOHSCROLL,
    x, y, w, h,
    parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndEdit, WM_SETFONT, (WPARAM)font, TRUE);
    return hwndEdit;
}
HWND createEdit_Multiple_Number(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndEdit = CreateWindow("EDIT", text,
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
    x, y, w, h,
    parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndEdit, WM_SETFONT, (WPARAM)font, TRUE);
    return hwndEdit;
}
HWND createEdit_Single_Number_Limit(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font, int limit)
{
    HWND hwndEdit = CreateWindow("EDIT", text,
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER | ES_AUTOHSCROLL,
    x, y, w, h,
    parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndEdit, WM_SETFONT, (WPARAM)font, TRUE);
    SendMessage(hwndEdit, EM_LIMITTEXT, limit, 0);
    return hwndEdit;
}
HWND createEdit_Multiple_Number_Limit(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font, int limit)
{
    HWND hwndEdit = CreateWindow("EDIT", text,
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
    x, y, w, h,
    parent, (HMENU)(intptr_t)id, NULL, NULL);
    SendMessage(hwndEdit, WM_SETFONT, (WPARAM)font, TRUE);
    SendMessage(hwndEdit, EM_LIMITTEXT, limit, 0);
    return hwndEdit;
}

HWND createSlider_defalt(HWND parent, const char* text, int x, int y, int w, int h, DWORD style, int id, int start, int end, int pos)
{
     HWND hwndSlide = CreateWindowEx(0, TRACKBAR_CLASS, text,
     WS_VISIBLE | WS_CHILD | style,
     x, y, w, h,
     parent, (HMENU)(intptr_t)id, NULL, NULL);
     SendMessage(hwndSlide, TBM_SETRANGE, TRUE, MAKELPARAM(start, end));
     SendMessage(hwndSlide, TBM_SETPOS, TRUE, pos);
     return hwndSlide;
}
HWND createSlider(HWND parent, const char* text, int x, int y, int w, int h, int id, int start, int end, int pos)
{
     HWND hwndSlide = CreateWindowEx(0, TRACKBAR_CLASS, text,
     WS_VISIBLE | WS_CHILD | TBS_AUTOTICKS,
     x, y, w, h,
     parent, (HMENU)(intptr_t)id, NULL, NULL);
     SendMessage(hwndSlide, TBM_SETRANGE, TRUE, MAKELPARAM(start, end));
     SendMessage(hwndSlide, TBM_SETPOS, TRUE, pos);
     return hwndSlide;
}
int calculateJump(HWND hwndSlide)
{
    RECT rect;
    GetClientRect(hwndSlide, &rect);
    int width = rect.right - rect.left;
    int start = (int)SendMessage(hwndSlide, TBM_GETRANGEMIN, 0, 0);
    int end = (int)SendMessage(hwndSlide, TBM_GETRANGEMAX, 0, 0);
    int jump = width / (end - start);
    return jump;
}
void createSliderNumber(HWND parent, int x, int y, int w, int h, HFONT font, HWND hwndSlider)
{
    int jump = calculateJump(hwndSlider);
    int start = (int)SendMessage(hwndSlider, TBM_GETRANGEMIN, 0, 0);
    int end   = (int)SendMessage(hwndSlider, TBM_GETRANGEMAX, 0, 0);
    for (int i = start; i <= end; i++) 
    {
          char buffer[50];
          sprintf(buffer, "%d", i);
          int temp = x + (i - start) * jump;
          HWND hLabel_100 = CreateWindow("STATIC", buffer,
              WS_VISIBLE | WS_CHILD,
              temp, y, w, h,
              parent, NULL, NULL, NULL);
              SendMessage(hLabel_100, WM_SETFONT, (WPARAM)font, TRUE); 
     }
}


HWND createButton_Default(HWND parent, const char* text, DWORD style, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndButton = CreateWindow("BUTTON", text,
        WS_VISIBLE | WS_CHILD | style,
        x, y, w, h,
        parent, (HMENU)(intptr_t)id, NULL, NULL);
        SendMessage(hwndButton, WM_SETFONT, (WPARAM)font, TRUE);
        return hwndButton;
}
HWND createButton_Flat(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndButton = CreateWindow("BUTTON", text,
        WS_VISIBLE | WS_CHILD | BS_FLAT,
        x, y, w, h,
        parent, (HMENU)(intptr_t)id, NULL, NULL);
        SendMessage(hwndButton, WM_SETFONT, (WPARAM)font, TRUE);
        return hwndButton;
}
HWND createButton_GroupBox(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font)
{
    HWND hwndButton = CreateWindow("BUTTON", text,
        WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
        x, y, w, h,
        parent, (HMENU)(intptr_t)id, NULL, NULL);
        SendMessage(hwndButton, WM_SETFONT, (WPARAM)font, TRUE);
        return hwndButton;
}

int getCentered_Width(int width)
{
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    return (screen_width - width)/2;
}
int getCentered_Height(int height)
{
    int screen_height = GetSystemMetrics(SM_CYSCREEN);
    return (screen_height-height)/2;
}
void intSliderHelper()
{
    INITCOMMONCONTROLSEX icex = { sizeof(icex), ICC_BAR_CLASSES };
    InitCommonControlsEx(&icex); 
}

BOOL InitWindowClassEx(HINSTANCE hInst, const char* class_name, WNDPROC wndProc, WNDCLASSEX* wc)
{
    wc->cbSize = sizeof(WNDCLASSEX);
    wc->style = CS_HREDRAW | CS_VREDRAW;
    wc->hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc->hInstance = hInst;
    wc->lpszClassName = class_name;
    wc->lpfnWndProc = wndProc;
    wc->hCursor = LoadCursor(NULL, IDC_ARROW);
    wc->hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc->hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    
    return RegisterClassEx(wc);
}

void displayIcon_Big(int ID, WNDCLASSEX* wc)
{
    wc->hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(ID));
}
void displayIcon_Small(int ID, WNDCLASSEX* wc)
{
    wc->hIconSm = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(ID));
}
    
HWND createUIWindow(HINSTANCE hInst,  const char* class_name, const char* gui_name, DWORD style,int init_x_cord, int init_y_cord, int width,  int height)
{
    HWND hwnd = CreateWindow(class_name, gui_name,
    WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | style, 
    init_x_cord, init_y_cord, width, height,
    NULL, NULL, hInst, NULL);
    return hwnd;
}

void runWindowGUI()
{
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
void hideUnuseParams(HINSTANCE hPrevInst, LPSTR lpCmdLine)
{
    (void)hPrevInst;
    (void)lpCmdLine;
}
void openSite(HWND parent, const char* url)
{
    ShellExecute(parent, "open", url, NULL, NULL, SW_SHOWNORMAL);
}



#include <windows.h>
#include "include/win32_ui_helpers.h"

#define NONE 0
#define ID_YOUTUBE 100
#define ID_REDDIT 101

HBRUSH hWhiteBrush;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
    switch (msg) 
    {
        case WM_CREATE:

            hWhiteBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
            HFONT hfont13_NORMAL = createUIFont(12, FW_NORMAL, "Segeo UI");
            createButton_Flat(hwnd, "Youtube", 20, 200, 150, 60, ID_YOUTUBE, hfont13_NORMAL);
            createButton_Flat(hwnd, "REDDIT", 200, 200, 150, 60, ID_REDDIT, hfont13_NORMAL);
    
            break;
        case WM_COMMAND:

            if(LOWORD(wParam) == ID_YOUTUBE) openSite(hwnd, "http://youtube.com");
            if(LOWORD(wParam) == ID_REDDIT) openSite(hwnd, "http://reddit.com");
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CTLCOLORSTATIC:
            HDC hdc = (HDC)wParam;

            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, RGB(10,10,10));
            return (INT_PTR)hWhiteBrush;


        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int nCmdShow)
{
    hideUnuseParams(hPrevInst, args);
    
    int width = 400;
    int height = 450;

    WNDCLASSEX wc = {0};
    InitWindowClassEx(hInst, "Test", WndProc,  &wc);

    HWND hwnd = createUIWindow(hInst, "Test", "Big Test", NONE, getCentered_Width(width), getCentered_Height(height), width, height);
    ShowWindow(hwnd, nCmdShow);

    runWindowGUI();
    return 0;
}

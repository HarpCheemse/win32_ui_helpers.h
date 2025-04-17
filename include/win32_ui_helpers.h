#ifndef WIN32_GUI_HELPERS_H
#define WIN32_GUI_HELPERS_H

#include <windows.h>
#include <commctrl.h> 
#include <stdio.h>

// Font Creation Functions
HFONT createUIFont_Default(int size, int spread, int nEscapement, int nOrientation,
                           int weight, int italic, int underline, int strikeout, LPCSTR font);
HFONT createUIFont(int size, int weight, LPCSTR font);
HFONT createUIFont_90(int size, int weight, LPCSTR font);
HFONT createUIFont_Rotate(int size, int nEscapment, int nOrientation, int weight, LPCSTR font);
HFONT createUIFont_Spread(int size, int spread, int weight, LPCSTR font);
HFONT createUIFont_Italic(int size, int weight, LPCSTR font);
HFONT createUIFont_Underline(int size, int weight, LPCSTR font);
HFONT createUIFont_Strikeout(int size, int weight, LPCSTR font);

// UI Label Functions
HWND createLabel_Default(HWND parent, const char* text, DWORD style, int x, int y, int w, int h, int id, HFONT font);
HWND createLabel(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font);
HWND createLabel_Box(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font);
HWND createLabel_Button(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font);

// UI Edit Functions
HWND createEdit_Default(HWND parent, const char* text, DWORD style, int x, int y, int w, int h, int id, HFONT font);
HWND createEdit(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font);
HWND createEdit_PassWord(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font);
HWND createEdit_Single_Number(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font);

// UI Edit Functions
HWND createEdit_Multiple_Number(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font);
HWND createEdit_Single_Number_Limit(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font, int limit);
HWND createEdit_Multiple_Number_Limit(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font, int limit);

// UI Slider Functions
HWND createSlider_defalt(HWND parent, const char* text, int x, int y, int w, int h, DWORD style, int id, int start, int end, int pos);
HWND createSlider(HWND parent, const char* text, int x, int y, int w, int h, int id, int start, int end, int pos);
void createSliderNumber(HWND parent, int x, int y, int w, int h, HFONT font, HWND hwndSlider);

// UI Button Functions
HWND createButton_Default(HWND parent, const char* text, DWORD style, int x, int y, int w, int h, int id, HFONT font);
HWND createButton_Flat(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font);
HWND createButton_GroupBox(HWND parent, const char* text, int x, int y, int w, int h, int id, HFONT font);

// Helper Functions
int calculateJump(HWND hwndSlide);
int getCentered_Width(int width);
int getCentered_Height(int height);
void intSliderHelper();

// Main Functions
BOOL InitWindowClassEx(HINSTANCE hInst, const char* class_name, WNDPROC wndProc, WNDCLASSEX* wc);
void displayIcon_Big(int ID, WNDCLASSEX* wc);
void displayIcon_Small(int ID, WNDCLASSEX* wc);
HWND createUIWindow(HINSTANCE hInst, const char* class_name, const char* gui_name, DWORD style, int init_x_cord, int init_y_cord, int width, int height);
void runWindowGUI();

void hideUnuseParams(HINSTANCE hPrevInst, LPSTR lpCmdLine);

void openSite(HWND parent, const char* url);
HBRUSH createUIBrush(HWND parent, int R, int G, int B);
#endif

#pragma once
#include <windows.h>

class Window
{
public:
    Window(HINSTANCE hInstance, int nCmdShow);
    int run();

private:
    static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    void initializeWindow();

    HINSTANCE m_hInstance;
    HWND m_hwnd;
    int m_nCmdShow;
};

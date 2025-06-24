#pragma once

#include <windows.h>

#include "apm_tracker.h"

class Window
{
public:
    Window(HINSTANCE hInstance, int nCmdShow, ApmTracker* tracker);
    ~Window();
    int run();

private:
    static LRESULT CALLBACK wndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    void initializeWindow();

    HINSTANCE m_hInstance;
    HWND m_hwnd;
    int m_nCmdShow;

    ApmTracker* m_tracker;
};

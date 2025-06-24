#include "window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    Window window(hInstance, nCmdShow);
    window.run();
    return 0;
}

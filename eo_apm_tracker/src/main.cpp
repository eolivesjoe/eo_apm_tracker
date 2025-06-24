#include "window.h"
#include "apm_tracker.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    ApmTracker tracker;
    tracker.Start();

    Window window(hInstance, nCmdShow, &tracker);
    window.run();

    tracker.Stop();
    return 0;
}

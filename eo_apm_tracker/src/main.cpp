#include "window.h"
#include "apm_tracker.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    tracker::ApmTracker tracker;
    tracker.start();

    window::Window window(hInstance, nCmdShow, &tracker);
    window.run();

    tracker.stop();
    return 0;
}

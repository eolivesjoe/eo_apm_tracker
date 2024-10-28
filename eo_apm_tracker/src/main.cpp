#include <wx/wx.h>
#include <wx/evtloop.h>
#include "app/app.h"

App* g_app = nullptr;

int Run(int argc, char** argv);

int main(int argc, char** argv)
{
	return Run(argc, argv);
}

int Run(int argc, char** argv)
{
    g_app = new App();

    if (!wxEntryStart(argc, argv))
    {
        return EXIT_FAILURE;
    }

    if (!g_app->OnInit())
    {
        return EXIT_FAILURE;
    }

    wxEventLoopBase* loop = wxEventLoopBase::GetActive();
    if (!loop)
    {
        loop = new wxEventLoop();
        wxEventLoopBase::SetActive(loop);
    }

    while (!g_app->IsMainLoopStopped())
    {
        if (loop->Pending())
        {
            loop->Dispatch();
        }
        else
        {
            loop->Yield();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    wxEntryCleanup();

    delete g_app;
    return EXIT_SUCCESS;
}
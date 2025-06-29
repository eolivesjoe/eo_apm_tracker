#include "app/app.h"
#include "logger/logger.h"

int main(int argc, char* argv[])
{
    logger::init();

    app::App app;
    logger::info("starting tracker...");
    app.run();

    return 0;
}

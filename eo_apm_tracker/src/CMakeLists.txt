set(SOURCES
    main.cpp
    tracker/apm_tracker.cpp
    window/window.cpp
	logger/logger.cpp
	app/app.cpp
)

set(HEADERS
    tracker/apm_tracker.h
    window/window.h
	app/app.h
	logger/logger.h
	constants.h
)

add_executable(apm_tracker ${SOURCES} ${HEADERS})

target_link_libraries(apm_tracker
    user32
    gdi32
    kernel32
)

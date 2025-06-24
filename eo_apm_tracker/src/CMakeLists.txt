# List sources
set(SOURCES
    main.cpp
    apm_tracker.cpp
    window.cpp
)

set(HEADERS
    apm_tracker.h
    window.h
	constants.h
)

add_executable(apm_tracker ${SOURCES} ${HEADERS})

# Tell linker this is a Windows GUI app with WinMain
set_target_properties(apm_tracker PROPERTIES WIN32_EXECUTABLE TRUE)

# Link Windows libs
target_link_libraries(apm_tracker
    user32
    gdi32
    kernel32
)

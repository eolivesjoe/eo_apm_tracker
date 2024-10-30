cmake_minimum_required(VERSION 3.15)

project(eo_apm_tracker VERSION 1.0 LANGUAGES CXX)

if(NOT DEFINED ENV{WXWIN})
    message(FATAL_ERROR "Environment variable WXWIN is not set. Please set it to the root of your wxWidgets installation.")
endif()

set(wxWidgets_ROOT_DIR "$ENV{WXWIN}")
set(wxWidgets_LIB_DIR "${wxWidgets_ROOT_DIR}/lib/gcc_lib")
set(wxWidgets_INCLUDE_DIRS "${wxWidgets_ROOT_DIR}/include")

set(wxWidgets_USE_LIBS core base png tiff jpeg zlib regex expat)
find_package(wxWidgets REQUIRED COMPONENTS ${wxWidgets_USE_LIBS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(${wxWidgets_USE_FILE})

set(SRC_FILES
    ${CMAKE_SOURCE_DIR}/eo_apm_tracker/src/main.cpp
	${CMAKE_SOURCE_DIR}/eo_apm_tracker/src/apm_tracker.h
    ${CMAKE_SOURCE_DIR}/eo_apm_tracker/src/apm_tracker.cpp
	${CMAKE_SOURCE_DIR}/eo_apm_tracker/src/app.h
    ${CMAKE_SOURCE_DIR}/eo_apm_tracker/src/app.cpp
    ${CMAKE_SOURCE_DIR}/eo_apm_tracker/src/mainframe.h
    ${CMAKE_SOURCE_DIR}/eo_apm_tracker/src/mainframe.cpp
)

set(HEADER_FILES
)

include_directories(${CMAKE_SOURCE_DIR}/eo_apm_tracker/include ${wxWidgets_INCLUDE_DIRS})

add_executable(eo_apm_tracker ${SRC_FILES} ${HEADER_FILES})

target_link_libraries(eo_apm_tracker ${wxWidgets_LIBRARIES})
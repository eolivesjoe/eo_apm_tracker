# APM Tracker

## Overview

The **APM Tracker** is a C++ tool designed to measure the actions per minute (APM) of users. APM is a key performance indicator for individuals engaged in activities requiring high precision and efficiency, such as gaming or productivity software. This tracker calculates APM by using low-level hooks to monitor keyboard and mouse inputs.

## Features

- **Multi-threading**: Utilizes threads to ensure non-blocking performance, allowing the tracker to run in the background.
- **Mutex**: Implements mutexes to ensure thread-safe operations.
- **Low-level hooks**: Leverages hooks to capture user input without interrupting the user experience.

## Technologies

- **C++**: Core programming language.
- **WinAPI**: For capturing input events via low-level hooks.
- **Threading**: Used to calculate APM in real-time while maintaining low CPU usage.
- **wxWidgets**: A library for creating a graphical user interface (GUI).

## How to Use

1. Clone the repository.
2. **Set Up wxWidgets**:
   - **Install wxWidgets**:
     - Download and install `wxWidgets.zip` from the official [wxWidgets website](https://www.wxwidgets.org/downloads/).
   - **Configure Your IDE**:
     - **For Visual Studio**:
       - Select the latest wx_vc.sln in the `\build\msw` folder and build.
       - Set `WXWIN` as a path variable to point to your `wxWidgets` installation directory for easier access.
       - Under **Linker** → **General**, add the path to the `wxWidgets` lib directory (e.g., `$(WXWIN)\lib\vc_x64_lib`) to **Additional Include Directories**.
       - Under **C/C++** → **General**, add the path to the `wxWidgets` include directory and the msvc subfolder (e.g., `$(WXWIN)\include;$(WXWIN)\include\msvc`) to **Additional Include Directories**.
3. Build the project using your IDE.
4. Run the program, and it will begin calculating APM based on your system’s input.

## Future Improvements

- Adding a graphical user interface (GUI) for better user interaction.
- Improving the accuracy of mouse input detection.
- Improve usability
- Cross-platform support.

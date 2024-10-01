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
     - Download and install `wxWidgets` from the official [wxWidgets website](https://www.wxwidgets.org/downloads/).
   - **Configure Your IDE**:
     - **For Visual Studio**:
       - Right-click on your project in the Solution Explorer and select **Properties**.
       - Under **C/C++** → **General**, add the path to the `wxWidgets` include directory (e.g., `C:\wxWidgets-<version>\include`) to **Additional Include Directories**.
       - Under **Linker** → **General**, add the path to the `lib` directory of your `wxWidgets` installation (e.g., `C:\wxWidgets-<version>\lib\vc_lib`) to **Additional Library Directories**.
       - Under **Linker** → **Input**, add necessary wxWidgets libraries (e.g., `wxbase31u.lib`, `wxmsw31u.lib`, etc.) to **Additional Dependencies**.
   - **Set Environment Variables** (optional):
     - Set `WXWIN` to point to your `wxWidgets` installation directory for easier access.
3. Build the project using your C++-compatible IDE.
4. Run the program, and it will begin calculating APM based on your system’s input.

## Future Improvements

- Adding a graphical user interface (GUI) for better user interaction.
- Improving the accuracy of mouse input detection.
- Cross-platform support.

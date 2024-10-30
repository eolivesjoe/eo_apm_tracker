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

## Prerequisites

- **CMake**: Ensure you have CMake installed on your system. You can download it from the [official CMake website](https://cmake.org/download/).
- **wxWidgets**: Download and install wxWidgets from the official [wxWidgets website](https://www.wxwidgets.org/downloads/).

## How to Use

1. Clone this repository:
    ```bash
    git clone https://github.com/yourusername/eo_apm_tracker.git
    cd eo_apm_tracker
    ```

2. Set up the `WXWIN` environment variable to point to your wxWidgets installation:
    - Add it to your environment variables (e.g., `C:\path\to\wxWidgets`).

3. Build the project with CMake:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

4. Run the APM Tracker:
    ```bash
    ./eo_apm_tracker
    ```

## Future Improvements

- **Graphical User Interface**: Expanding the GUI to offer more controls and better user interaction.
- **Effective Actions Per Minute (EAPM)**: Adding EAPM calculations for more accurate performance tracking in StarCraft: Brood War.
- **Usability Enhancements**: Simplifying setup and adding more intuitive controls.
- **Cross-Platform Support**: Extending compatibility beyond Windows.
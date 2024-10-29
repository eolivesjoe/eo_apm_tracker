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

# TODO

## Future Improvements
- Adding a proper graphical user interface (GUI) for better user interaction.
- Adding EAPM calculation for StarCraft Brood War
- Improve usability
- Cross-platform support.
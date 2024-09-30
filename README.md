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

## How to Use

1. Clone the repository.
2. Build the project using any C++-compatible IDE (such as Visual Studio or CLion).
3. Run the program, and it will begin calculating APM based on your system’s input.

## Future Improvements

- Adding a graphical user interface (GUI) for better user interaction.
- Improving the accuracy of mouse input detection.
- Cross-platform support.

## License

This project is licensed under the MIT License.

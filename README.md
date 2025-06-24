# APM Tracker

## Overview

**APM Tracker** is a modern C++ tool designed to measure the Actions Per Minute of users in real-time by monitoring keyboard and mouse inputs. It uses low-level Windows hooks and multi-threading to provide accurate, low-latency tracking of user actions, with a minimalistic always-on-top window display showing the current APM.

## Features

- **Real-time APM calculation**: Tracks actions per minute over a rolling window with updates every second.
- **Low-level hooks**: Uses Windows low-level keyboard and mouse hooks to capture user input events.
- **Multi-threading**: Runs APM calculations on a dedicated thread to ensure responsiveness and low CPU usage.
- **Thread safety**: Protects shared data with mutexes to avoid race conditions.
- **Lightweight overlay window**: Displays the current APM in a transparent, always-on-top, non-activating window using native WinAPI.

## Usage

1. Clone the repository.
2. Build the project using your preferred IDE or build system.
3. Run the executable. The small overlay window will appear near the bottom-right of your primary screen, showing your current APM.

## Code Structure

- `apm_tracker.h/cpp`: Core tracking logic, managing hooks, action counts, and APM calculations.
- `window.h/cpp`: Handles window creation, painting the APM value, and message loop.
- `constants.h`: Defines constants like window size, timer intervals, etc.

## Future Improvements

- Add user controls for customizing window appearance and position.
- Provide a GUI with richer statistics and history visualisation.


Feel free to contribute or file issues if you encounter bugs or have feature requests!
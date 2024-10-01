#include "hotkey_reader.h"
#include <fstream>
#include <iostream>

HotkeyReader::HotkeyReader(const std::string& settings_file)
    : settings_file(settings_file) {}

void HotkeyReader::ReadHotkeys() {
    std::ifstream file(settings_file);
    if (!file.is_open()) {
        std::cerr << "Could not open the settings file: " << settings_file << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t delimiter_pos = line.find('=');
        if (delimiter_pos != std::string::npos) {
            std::string key = line.substr(0, delimiter_pos);
            std::string value = line.substr(delimiter_pos + 1);
            hotkeys[key] = value;
        }
    }

    file.close();
}

const std::unordered_map<std::string, std::string>& HotkeyReader::GetHotkeys() const {
    return hotkeys_;
}

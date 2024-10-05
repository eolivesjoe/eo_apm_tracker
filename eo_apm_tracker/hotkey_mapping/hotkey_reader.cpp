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


    file.close();
}

const std::unordered_map<std::string, std::string>& HotkeyReader::GetHotkeys() const {
    return hotkeys;
}

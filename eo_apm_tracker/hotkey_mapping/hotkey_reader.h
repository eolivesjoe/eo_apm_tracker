#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class HotkeyReader {
public:
    HotkeyReader(const std::string& settings_file);
    ~HotkeyReader() = default;

    void ReadHotkeys();
    const std::unordered_map<std::string, std::string>& GetHotkeys() const;

private:
    std::string settings_file;
    std::unordered_map<std::string, std::string> hotkeys;
};

#pragma once

#include <unordered_map>
#include <string>
#include <vector>

class HotkeyMapper {
public:
    void MapHotkeys(const std::unordered_map<std::string, std::string>& hotkeys);
    const std::unordered_map<std::string, std::vector<std::string>>& GetTerranActions() const;
    const std::unordered_map<std::string, std::vector<std::string>>& GetProtossActions() const;
    const std::unordered_map<std::string, std::vector<std::string>>& GetZergActions() const;
    const std::unordered_map<std::string, std::vector<std::string>>& GetEffectiveActions() const;
    const std::unordered_map<std::string, std::vector<std::string>>& GetNonEffectiveActions() const;

private:
    void InitializeMappings();

    std::unordered_map<std::string, std::vector<std::string>> terran_actions;
    std::unordered_map<std::string, std::vector<std::string>> protoss_actions;
    std::unordered_map<std::string, std::vector<std::string>> zerg_actions;
    std::unordered_map<std::string, std::vector<std::string>> effective_actions;
    std::unordered_map<std::string, std::vector<std::string>> non_effective_actions;
};

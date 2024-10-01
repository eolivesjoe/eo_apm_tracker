#include "hotkey_mapper.h"

void HotkeyMapper::MapHotkeys(const std::unordered_map<std::string, std::string>& hotkeys) {
    InitializeMappings();

    for (const auto& [key, value] : hotkeys) {
        if (value == "Terran") {
            terran_actions["Build"] = { key };
        }
        else if (value == "Protoss") {
            protoss_actions["Build"] = { key };
        }
        else if (value == "Zerg") {
            zerg_actions["Build"] = { key };
        }

        effective_actions["Action"] = { key };
    }
}

const std::unordered_map<std::string, std::vector<std::string>>& HotkeyMapper::GetTerranActions() const {
    return terran_actions;
}

const std::unordered_map<std::string, std::vector<std::string>>& HotkeyMapper::GetProtossActions() const {
    return protoss_actions;
}

const std::unordered_map<std::string, std::vector<std::string>>& HotkeyMapper::GetZergActions() const {
    return zerg_actions;
}

const std::unordered_map<std::string, std::vector<std::string>>& HotkeyMapper::GetEffectiveActions() const {
    return effective_actions;
}

const std::unordered_map<std::string, std::vector<std::string>>& HotkeyMapper::GetNonEffectiveActions() const {
    return non_effective_actions;
}

void HotkeyMapper::InitializeMappings() {
    // Initialize action mappings if necessary.
}

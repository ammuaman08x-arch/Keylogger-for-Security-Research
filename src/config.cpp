#include "config.h"
#include "utils.h"

#include <fstream>
#include <sstream>
#include <iostream>

namespace SecurityResearch {

ConfigManager::ConfigManager()
    : m_configPath("config.ini") {
    LoadDefaults();
}

ConfigManager::ConfigManager(const std::string& configFilePath)
    : m_configPath(configFilePath) {
    LoadDefaults();
}

void ConfigManager::LoadDefaults() {
    m_settings["AppName"] = "Keylogger for Security Research";
    m_settings["Version"] = "1.0.0";
    m_settings["Author"] = "B.Tech Cybersecurity Intern";
    m_settings["Environment"] = "Educational / Lab Research";
    m_settings["LogLevel"] = "INFO";
    m_settings["LogFilePath"] = "app_events.log";
    m_settings["ReportOutputDir"] = "reports";
    m_settings["EnforceDefensiveModeOnly"] = "true";
    m_settings["KeystrokeLoggingEnabled"] = "false"; // HARDCODED DEFENSIVE GUARANTEE
}

bool ConfigManager::LoadConfig() {
    if (!Utils::FileExists(m_configPath)) {
        Utils::PrintWarning("Configuration file not found (" + m_configPath + "). Creating default configuration.");
        return SaveConfig();
    }

    std::ifstream inFile(m_configPath);
    if (!inFile.is_open()) {
        Utils::PrintWarning("Unable to open configuration file. Falling back to defaults.");
        return false;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        line = Utils::Trim(line);
        if (line.empty() || line[0] == '#' || line[0] == ';') {
            continue; // Skip comments and empty lines
        }

        size_t delimPos = line.find('=');
        if (delimPos != std::string::npos) {
            std::string key = Utils::Trim(line.substr(0, delimPos));
            std::string value = Utils::Trim(line.substr(delimPos + 1));
            
            // Hardcoded guardrail enforcement
            if (key == "KeystrokeLoggingEnabled") {
                value = "false";
            }
            m_settings[key] = value;
        }
    }

    inFile.close();
    Utils::PrintSuccess("Configuration loaded successfully from " + m_configPath);
    return true;
}

bool ConfigManager::SaveConfig() {
    std::ofstream outFile(m_configPath);
    if (!outFile.is_open()) {
        Utils::PrintWarning("Failed to write config file: " + m_configPath);
        return false;
    }

    outFile << "# Keylogger Security Research - Configuration File\n";
    outFile << "# Created for Academic B.Tech Cybersecurity Internship\n\n";

    for (const auto& [key, val] : m_settings) {
        outFile << key << " = " << val << "\n";
    }

    outFile.close();
    return true;
}

std::string ConfigManager::GetSetting(const std::string& key, const std::string& defaultValue) const {
    auto it = m_settings.find(key);
    if (it != m_settings.end()) {
        return it->second;
    }
    return defaultValue;
}

void ConfigManager::SetSetting(const std::string& key, const std::string& value) {
    if (key == "KeystrokeLoggingEnabled" && value != "false") {
        Utils::PrintWarning("Security Override: Keystroke logging cannot be enabled in this defensive research application.");
        m_settings[key] = "false";
        return;
    }
    m_settings[key] = value;
}

void ConfigManager::PrintConfig() const {
    Utils::PrintSubHeader("Current Application Configuration");
    for (const auto& [key, val] : m_settings) {
        std::cout << "  " << key << " : " << val << "\n";
    }
}

} // namespace SecurityResearch

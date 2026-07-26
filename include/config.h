#ifndef KEYLOGGER_SECURITY_RESEARCH_CONFIG_H
#define KEYLOGGER_SECURITY_RESEARCH_CONFIG_H

#include <string>
#include <map>

namespace SecurityResearch {

class ConfigManager {
public:
    ConfigManager();
    explicit ConfigManager(const std::string& configFilePath);

    bool LoadConfig();
    bool SaveConfig();

    std::string GetSetting(const std::string& key, const std::string& defaultValue = "") const;
    void SetSetting(const std::string& key, const std::string& value);

    const std::string& GetConfigPath() const { return m_configPath; }
    void PrintConfig() const;

private:
    void LoadDefaults();

    std::string m_configPath;
    std::map<std::string, std::string> m_settings;
};

} // namespace SecurityResearch

#endif // KEYLOGGER_SECURITY_RESEARCH_CONFIG_H

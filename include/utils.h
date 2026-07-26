#ifndef KEYLOGGER_SECURITY_RESEARCH_UTILS_H
#define KEYLOGGER_SECURITY_RESEARCH_UTILS_H

#include <string>
#include <vector>
#include <iostream>

namespace SecurityResearch {
namespace Utils {

    // Console styling enum
    enum class Color {
        Default,
        Red,
        Green,
        Yellow,
        Blue,
        Cyan,
        White
    };

    // Output formatted & colored text to stdout
    void PrintColor(const std::string& text, Color color = Color::Default);
    void PrintHeader(const std::string& title);
    void PrintSubHeader(const std::string& title);
    void PrintSuccess(const std::string& message);
    void PrintWarning(const std::string& message);
    void PrintInfo(const std::string& message);

    // Date and time utilities
    std::string GetCurrentTimestamp();
    std::string GetFormattedDate();

    // File I/O helpers
    bool FileExists(const std::string& filepath);
    bool CreateDirectoryIfNotExist(const std::string& dirPath);

    // String formatting helper
    std::string Trim(const std::string& str);

} // namespace Utils
} // namespace SecurityResearch

#endif // KEYLOGGER_SECURITY_RESEARCH_UTILS_H

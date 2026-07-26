#include "utils.h"

#include <chrono>
#include <iomanip>
#include <sstream>
#include <filesystem>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace SecurityResearch {
namespace Utils {

    void PrintColor(const std::string& text, Color color) {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        WORD attribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; // Default white/gray

        switch (color) {
            case Color::Red:
                attribute = FOREGROUND_RED | FOREGROUND_INTENSITY;
                break;
            case Color::Green:
                attribute = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
                break;
            case Color::Yellow:
                attribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
                break;
            case Color::Blue:
                attribute = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
                break;
            case Color::Cyan:
                attribute = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
                break;
            case Color::White:
                attribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
                break;
            case Color::Default:
            default:
                attribute = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
                break;
        }

        SetConsoleTextAttribute(hConsole, attribute);
        std::cout << text;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
        std::cout << text;
#endif
    }

    void PrintHeader(const std::string& title) {
        std::string line(60, '=');
        PrintColor("\n" + line + "\n", Color::Cyan);
        PrintColor(" " + title + "\n", Color::White);
        PrintColor(line + "\n", Color::Cyan);
    }

    void PrintSubHeader(const std::string& title) {
        std::string line(50, '-');
        PrintColor("\n" + title + "\n", Color::Yellow);
        PrintColor(line + "\n", Color::Yellow);
    }

    void PrintSuccess(const std::string& message) {
        PrintColor("[+] SUCCESS: ", Color::Green);
        std::cout << message << "\n";
    }

    void PrintWarning(const std::string& message) {
        PrintColor("[!] WARNING: ", Color::Yellow);
        std::cout << message << "\n";
    }

    void PrintInfo(const std::string& message) {
        PrintColor("[*] INFO: ", Color::Cyan);
        std::cout << message << "\n";
    }

    std::string GetCurrentTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto time_t_now = std::chrono::system_clock::to_time_t(now);
        std::tm tm_buf;
#ifdef _WIN32
        localtime_s(&tm_buf, &time_t_now);
#else
        localtime_r(&time_t_now, &tm_buf);
#endif
        std::ostringstream ss;
        ss << std::put_time(&tm_buf, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

    std::string GetFormattedDate() {
        auto now = std::chrono::system_clock::now();
        auto time_t_now = std::chrono::system_clock::to_time_t(now);
        std::tm tm_buf;
#ifdef _WIN32
        localtime_s(&tm_buf, &time_t_now);
#else
        localtime_r(&time_t_now, &tm_buf);
#endif
        std::ostringstream ss;
        ss << std::put_time(&tm_buf, "%B %d, %Y");
        return ss.str();
    }

    bool FileExists(const std::string& filepath) {
        return std::filesystem::exists(filepath);
    }

    bool CreateDirectoryIfNotExist(const std::string& dirPath) {
        if (!std::filesystem::exists(dirPath)) {
            return std::filesystem::create_directories(dirPath);
        }
        return true;
    }

    std::string Trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        if (std::string::npos == first) {
            return str;
        }
        size_t last = str.find_last_not_of(" \t\n\r");
        return str.substr(first, (last - first + 1));
    }

} // namespace Utils
} // namespace SecurityResearch

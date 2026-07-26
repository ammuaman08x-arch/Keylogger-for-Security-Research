#ifndef KEYLOGGER_SECURITY_RESEARCH_APPLICATION_H
#define KEYLOGGER_SECURITY_RESEARCH_APPLICATION_H

#include <memory>
#include <fstream>
#include <string>

#include "config.h"
#include "analyzer.h"
#include "detector.h"
#include "report.h"

namespace SecurityResearch {

class Application {
public:
    Application();
    ~Application();

    bool Initialize();
    void Run();
    void Shutdown();

private:
    void RenderMenu() const;
    void HandleMenuSelection(int choice);

    // Menu handlers
    void ShowProjectOverview() const;
    void ShowWhatIsKeylogger() const;
    void ShowTypesOfKeyloggers() const;
    void ShowWindowsInputArchitecture() const;
    void ShowResearchNotes() const;
    void ShowDetectionTechniques() const;
    void ShowSecurityRecommendations() const;
    void GenerateReport();

    // Internal event logging (Application lifecycle events only)
    void LogEvent(const std::string& eventMessage);

    bool m_isRunning;
    std::unique_ptr<ConfigManager> m_config;
    std::unique_ptr<ThreatAnalyzer> m_analyzer;
    std::unique_ptr<DetectionEngine> m_detector;
    std::unique_ptr<ReportGenerator> m_reportGenerator;
    std::ofstream m_logFile;
};

} // namespace SecurityResearch

#endif // KEYLOGGER_SECURITY_RESEARCH_APPLICATION_H

#ifndef KEYLOGGER_SECURITY_RESEARCH_REPORT_H
#define KEYLOGGER_SECURITY_RESEARCH_REPORT_H

#include <string>

namespace SecurityResearch {

class ReportGenerator {
public:
    ReportGenerator();

    bool GenerateReport(const std::string& outputDirectory = "reports") const;
    std::string BuildReportString() const;

private:
    std::string m_projectName;
    std::string m_version;
    std::string m_author;
};

} // namespace SecurityResearch

#endif // KEYLOGGER_SECURITY_RESEARCH_REPORT_H

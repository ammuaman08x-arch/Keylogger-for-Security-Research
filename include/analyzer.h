#ifndef KEYLOGGER_SECURITY_RESEARCH_ANALYZER_H
#define KEYLOGGER_SECURITY_RESEARCH_ANALYZER_H

#include <string>
#include <vector>

namespace SecurityResearch {

struct ThreatCategory {
    std::string categoryName;
    std::string mechanism;
    std::string targetVector;
    std::string historicalExamples;
    std::string defensiveCountermeasures;
};

class ThreatAnalyzer {
public:
    ThreatAnalyzer();

    void DisplaySoftwareKeyloggersOverview() const;
    void DisplayHardwareKeyloggersOverview() const;
    void DisplayKernelKeyloggersOverview() const;
    void DisplayUserModeKeyloggersOverview() const;
    void DisplayBrowserCredentialTheftOverview() const;
    void DisplayHistoricalExamples() const;
    void DisplayDefensiveCountermeasures() const;

    void DisplayCompleteResearchNotes() const;
    const std::vector<ThreatCategory>& GetCategories() const { return m_categories; }

private:
    std::vector<ThreatCategory> m_categories;
    void InitializeThreatTaxonomy();
};

} // namespace SecurityResearch

#endif // KEYLOGGER_SECURITY_RESEARCH_ANALYZER_H

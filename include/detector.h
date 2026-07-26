#ifndef KEYLOGGER_SECURITY_RESEARCH_DETECTOR_H
#define KEYLOGGER_SECURITY_RESEARCH_DETECTOR_H

#include <string>
#include <vector>

namespace SecurityResearch {

struct DetectionConcept {
    std::string name;
    std::string description;
    std::string researchDetails;
    std::string implementationNotes;
};

class DetectionEngine {
public:
    DetectionEngine();

    void DisplayProcessInspectionConcept() const;
    void DisplayBehaviorMonitoringConcept() const;
    void DisplayIntegrityVerificationConcept() const;
    void DisplayAutorunInspectionConcept() const;
    void DisplayRegistryPersistenceConcept() const;
    void DisplayDigitalSignatureConcept() const;
    void DisplayMemoryAnalysisConcept() const;

    void DisplayAllDetectionTechniques() const;

private:
    std::vector<DetectionConcept> m_concepts;
    void InitializeConcepts();
};

} // namespace SecurityResearch

#endif // KEYLOGGER_SECURITY_RESEARCH_DETECTOR_H

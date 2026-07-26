#include "detector.h"
#include "utils.h"

#include <iostream>

namespace SecurityResearch {

DetectionEngine::DetectionEngine() {
    InitializeConcepts();
}

void DetectionEngine::InitializeConcepts() {
    m_concepts = {
        {
            "Process Inspection & Binary Auditing",
            "Scans active process metadata to flag unverified or suspicious executables running without valid digital signatures.",
            "EDR systems query EnumProcesses() / QueryFullProcessImageName() and calculate SHA-256 hashes of running binaries to cross-reference against Threat Intelligence databases (VirusTotal/ReversingLabs).",
            "// TODO [Defensive Research Placeholder]: Integrate Win32 EnumProcesses() API with WinVerifyTrust() to validate digital signatures of active processes."
        },
        {
            "Behavioral Monitoring & Telemetry",
            "Monitors API usage patterns (such as continuous high-frequency polling of GetAsyncKeyState or Win32 message hook registrations).",
            "Modern Windows Security leverages Event Tracing for Windows (ETW) and Microsoft Defender Endpoint API hooks to detect illegal user-space thread injections or unauthorized SetWindowsHookEx calls.",
            "// TODO [Defensive Research Placeholder]: Subscribe to ETW provider 'Microsoft-Windows-Kernel-Process' to log real-time process thread creation events."
        },
        {
            "Integrity Verification & HVCI",
            "Ensures kernel memory integrity and verifies driver digital signatures before allowing module execution.",
            "Hypervisor-Protected Code Integrity (HVCI) uses virtualization-based security (VBS) to prevent unsigned kernel filter drivers (e.g. malicious kbdclass filter drivers) from loading into ring 0.",
            "// TODO [Defensive Research Placeholder]: Query VBS status via WMI / Win32 API GetSystemFirmwareTable() to confirm HVCI policy enforcement."
        },
        {
            "Autorun Inspection & Persistence Auditing",
            "Audits auto-start extensibility points (ASEPs) where persistence mechanisms are commonly established.",
            "Keyloggers often establish autostart persistence via Registry Run keys (HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run) or Scheduled Tasks.",
            "// TODO [Defensive Research Placeholder]: Inspect Registry ASEPs using RegOpenKeyExW() and compare binary signatures against trusted baselines."
        },
        {
            "Registry Persistence Checks",
            "Monitors real-time changes to critical Windows Registry hives associated with startup and Winlogon notify drivers.",
            "Defensive monitoring tools register RegNotifyChangeKeyValue() to trigger alerts whenever autostart hives are modified by unrecognized processes.",
            "// TODO [Defensive Research Placeholder]: Implement RegNotifyChangeKeyValue() listener thread to log key creation in HKCU/HKLM autostart paths."
        },
        {
            "Digital Signature & Authenticode Verification",
            "Validates Microsoft Authenticode PKI signatures on all loaded DLLs and system executables.",
            "Prevents DLL side-loading attacks where legitimate applications are hijacked to execute malicious input monitoring code.",
            "// TODO [Defensive Research Placeholder]: Utilize WinVerifyTrust() API with WINTRUST_ACTION_GENERIC_VERIFY_V2 to audit executable digital signatures."
        },
        {
            "Memory Analysis & Memory Pattern Matching",
            "Inspects process memory regions for injected code, hook trampolines, or unbacked executable memory regions.",
            "Advanced EDR tools perform VirtualQueryEx() scans to identify executable memory pages (PAGE_EXECUTE_READWRITE) that lack a corresponding image file backing on disk.",
            "// TODO [Defensive Research Placeholder]: Implement memory region scanner using VirtualQueryEx() to audit process page protection flags."
        }
    };
}

void DetectionEngine::DisplayProcessInspectionConcept() const {
    Utils::PrintSubHeader(m_concepts[0].name);
    std::cout << "Description:\n  " << m_concepts[0].description << "\n\n";
    std::cout << "Security Research Telemetry:\n  " << m_concepts[0].researchDetails << "\n\n";
    Utils::PrintColor("Implementation Blueprint:\n  " + m_concepts[0].implementationNotes + "\n", Utils::Color::Cyan);
}

void DetectionEngine::DisplayBehaviorMonitoringConcept() const {
    Utils::PrintSubHeader(m_concepts[1].name);
    std::cout << "Description:\n  " << m_concepts[1].description << "\n\n";
    std::cout << "Security Research Telemetry:\n  " << m_concepts[1].researchDetails << "\n\n";
    Utils::PrintColor("Implementation Blueprint:\n  " + m_concepts[1].implementationNotes + "\n", Utils::Color::Cyan);
}

void DetectionEngine::DisplayIntegrityVerificationConcept() const {
    Utils::PrintSubHeader(m_concepts[2].name);
    std::cout << "Description:\n  " << m_concepts[2].description << "\n\n";
    std::cout << "Security Research Telemetry:\n  " << m_concepts[2].researchDetails << "\n\n";
    Utils::PrintColor("Implementation Blueprint:\n  " + m_concepts[2].implementationNotes + "\n", Utils::Color::Cyan);
}

void DetectionEngine::DisplayAutorunInspectionConcept() const {
    Utils::PrintSubHeader(m_concepts[3].name);
    std::cout << "Description:\n  " << m_concepts[3].description << "\n\n";
    std::cout << "Security Research Telemetry:\n  " << m_concepts[3].researchDetails << "\n\n";
    Utils::PrintColor("Implementation Blueprint:\n  " + m_concepts[3].implementationNotes + "\n", Utils::Color::Cyan);
}

void DetectionEngine::DisplayRegistryPersistenceConcept() const {
    Utils::PrintSubHeader(m_concepts[4].name);
    std::cout << "Description:\n  " << m_concepts[4].description << "\n\n";
    std::cout << "Security Research Telemetry:\n  " << m_concepts[4].researchDetails << "\n\n";
    Utils::PrintColor("Implementation Blueprint:\n  " + m_concepts[4].implementationNotes + "\n", Utils::Color::Cyan);
}

void DetectionEngine::DisplayDigitalSignatureConcept() const {
    Utils::PrintSubHeader(m_concepts[5].name);
    std::cout << "Description:\n  " << m_concepts[5].description << "\n\n";
    std::cout << "Security Research Telemetry:\n  " << m_concepts[5].researchDetails << "\n\n";
    Utils::PrintColor("Implementation Blueprint:\n  " + m_concepts[5].implementationNotes + "\n", Utils::Color::Cyan);
}

void DetectionEngine::DisplayMemoryAnalysisConcept() const {
    Utils::PrintSubHeader(m_concepts[6].name);
    std::cout << "Description:\n  " << m_concepts[6].description << "\n\n";
    std::cout << "Security Research Telemetry:\n  " << m_concepts[6].researchDetails << "\n\n";
    Utils::PrintColor("Implementation Blueprint:\n  " + m_concepts[6].implementationNotes + "\n", Utils::Color::Cyan);
}

void DetectionEngine::DisplayAllDetectionTechniques() const {
    Utils::PrintHeader("Defensive Detection Research & Technical Blueprints");
    Utils::PrintInfo("The following detection modules represent theoretical frameworks and technical blueprints");
    Utils::PrintInfo("used in modern Endpoint Detection & Response (EDR) software.\n");

    for (const auto& conceptItem : m_concepts) {
        Utils::PrintSubHeader(conceptItem.name);
        std::cout << "Description:\n  " << conceptItem.description << "\n\n";
        std::cout << "Research Telemetry:\n  " << conceptItem.researchDetails << "\n\n";
        Utils::PrintColor("Implementation Blueprint:\n  " + conceptItem.implementationNotes + "\n\n", Utils::Color::Cyan);
        std::cout << std::string(60, '-') << "\n";
    }
}

} // namespace SecurityResearch

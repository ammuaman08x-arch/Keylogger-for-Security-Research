#include "report.h"
#include "utils.h"

#include <fstream>
#include <sstream>
#include <iostream>

namespace SecurityResearch {

ReportGenerator::ReportGenerator()
    : m_projectName("Keylogger for Security Research"),
      m_version("1.0.0"),
      m_author("B.Tech Cybersecurity Intern") {}

std::string ReportGenerator::BuildReportString() const {
    std::ostringstream ss;

    std::string banner(70, '=');
    std::string sectionDivider(70, '-');

    ss << banner << "\n";
    ss << "          KEYLOGGER SECURITY RESEARCH - ACADEMIC REPORT          \n";
    ss << banner << "\n\n";

    ss << "PROJECT INFORMATION:\n";
    ss << "  Project Title:    " << m_projectName << "\n";
    ss << "  Version:          " << m_version << "\n";
    ss << "  Author/Role:      " << m_author << "\n";
    ss << "  Date Generated:   " << Utils::GetCurrentTimestamp() << "\n";
    ss << "  Environment:      Windows 10/11 Defensive Security Lab\n\n";

    ss << sectionDivider << "\n";
    ss << "1. EXECUTIVE RESEARCH SUMMARY\n";
    ss << sectionDivider << "\n";
    ss << "This research project investigates the architectural mechanisms of input observation\n";
    ss << "and interception in Windows operating systems. Grounded strictly in defensive cyber\n";
    ss << "security research principles, this study analyzes user-mode Win32 hooks, kernel-mode\n";
    ss << "driver filter stacks, hardware passthrough implants, and browser DOM event interception.\n";
    ss << "Crucially, this project operates under a strict ethical framework: NO keystroke capture\n";
    ss << "or input eavesdropping functionality is implemented.\n\n";

    ss << sectionDivider << "\n";
    ss << "2. KEYLOGGER THREAT TAXONOMIES\n";
    ss << sectionDivider << "\n";
    ss << "A. User-Mode Software Keyloggers:\n";
    ss << "   - Mechanism: Win32 SetWindowsHookEx (WH_KEYBOARD_LL) or GetAsyncKeyState polling.\n";
    ss << "   - Target Vector: Desktop user application message loops.\n";
    ss << "   - Countermeasure: Process memory integrity auditing, User Interface Privilege Isolation (UIPI).\n\n";

    ss << "B. Kernel-Mode Drivers & Rootkits:\n";
    ss << "   - Mechanism: kbdclass.sys lower/upper filter driver attachment or IRP dispatch patching.\n";
    ss << "   - Target Vector: Global Windows Kernel Input Subsystem.\n";
    ss << "   - Countermeasure: Hypervisor-Protected Code Integrity (HVCI), Secure Boot, Driver Signing.\n\n";

    ss << "C. Hardware Interception Devices:\n";
    ss << "   - Mechanism: Inline USB hardware passthrough dongles, keyloggers on physical PS/2 ports.\n";
    ss << "   - Target Vector: Physical bus between keyboard hardware and motherboard.\n";
    ss << "   - Countermeasure: Physical port locks, USB vendor ID whitelisting, endpoint device control.\n\n";

    ss << "D. Browser-Based Credential Theft:\n";
    ss << "   - Mechanism: Malicious JavaScript event listeners or unauthorized web extensions.\n";
    ss << "   - Target Vector: HTML DOM input forms and web password fields.\n";
    ss << "   - Countermeasure: Content Security Policy (CSP), extension permission auditing.\n\n";

    ss << sectionDivider << "\n";
    ss << "3. DEFENSIVE DETECTION METHODS & TECHNICAL BLUEPRINTS\n";
    ss << sectionDivider << "\n";
    ss << "1. Process Inspection & Binary Auditing:\n";
    ss << "   - Auditing running processes via EnumProcesses() and computing cryptographic SHA-256 hashes.\n";
    ss << "2. Event Tracing for Windows (ETW) Behavioral Monitoring:\n";
    ss << "   - Subscribing to kernel process events to detect unauthorized thread injection or hook installation.\n";
    ss << "3. Hypervisor-Protected Code Integrity (HVCI):\n";
    ss << "   - Utilizing VBS to enforce driver digital signature verification before loading Ring 0 code.\n";
    ss << "4. Registry Autostart Persistence Inspection:\n";
    ss << "   - Auditing HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run for unauthorized binaries.\n";
    ss << "5. Authenticode Digital Signature Verification:\n";
    ss << "   - Programmatic validation of Microsoft PKI signatures using WinVerifyTrust() API.\n\n";

    ss << sectionDivider << "\n";
    ss << "4. STRATEGIC SECURITY RECOMMENDATIONS\n";
    ss << sectionDivider << "\n";
    ss << "[1] Enforce Endpoint Security Controls: Enable HVCI (Memory Integrity) and Secure Boot.\n";
    ss << "[2] Least Privilege Access: Restrict user accounts from executing with Administrative privileges.\n";
    ss << "[3] Deploy Multi-Factor Authentication (MFA): Mitigate stolen static password credentials.\n";
    ss << "[4] Implement Device Control Policies: Restrict unauthorized USB mass storage & HID devices.\n";
    ss << "[5] Continuous Telemetry Auditing: Monitor autostart registry hives via EDR agent tools.\n\n";

    ss << sectionDivider << "\n";
    ss << "5. ETHICAL COMPLIANCE & SAFETY STATEMENT\n";
    ss << sectionDivider << "\n";
    ss << "This document and its underlying software application were constructed in total compliance\n";
    ss << "with academic integrity and ethical security research guidelines. The project contains zero\n";
    ss << "keystroke recording code, keyboard hooks, or telemetry harvesting routines.\n";
    ss << banner << "\n";

    return ss.str();
}

bool ReportGenerator::GenerateReport(const std::string& outputDirectory) const {
    Utils::CreateDirectoryIfNotExist(outputDirectory);

    std::string filename = outputDirectory + "/Security_Research_Report_" + std::to_string(std::time(nullptr)) + ".txt";
    std::ofstream reportFile(filename);

    if (!reportFile.is_open()) {
        Utils::PrintWarning("Failed to create report file at " + filename);
        return false;
    }

    std::string content = BuildReportString();
    reportFile << content;
    reportFile.close();

    Utils::PrintSuccess("Research Report successfully generated and saved locally:");
    Utils::PrintColor("  -> " + filename + "\n", Utils::Color::Green);
    return true;
}

} // namespace SecurityResearch

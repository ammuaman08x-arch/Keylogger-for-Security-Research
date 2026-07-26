#include "analyzer.h"
#include "utils.h"

#include <iostream>

namespace SecurityResearch {

ThreatAnalyzer::ThreatAnalyzer() {
    InitializeThreatTaxonomy();
}

void ThreatAnalyzer::InitializeThreatTaxonomy() {
    m_categories = {
        {
            "User-Mode Software Keyloggers",
            "Win32 API Hooking (SetWindowsHookEx) or Continuous Key-State Polling (GetAsyncKeyState).",
            "User Applications, Web Browsers, Password Fields.",
            "Olympic Vision, Agent Tesla, Hawkeye Infostealers.",
            "Process memory integrity scanning, UIPI (User Interface Privilege Isolation), Anti-Hooking hooks."
        },
        {
            "Kernel-Mode Keyloggers",
            "Kernel Filter Drivers (kbdclass.sys lower/upper filters) or IRP Dispatch Table Patching.",
            "Global OS Input Subsystem (all processes and secure desktops).",
            "ZeroAccess rootkit, TDSS/TDL4 driver rootkits.",
            "Hypervisor-Protected Code Integrity (HVCI), Secure Boot, Driver Signature Enforcement (DSE)."
        },
        {
            "Hardware Keyloggers",
            "Physical USB passthrough dongles, inline PS/2 hardware modules, acoustic/electromagnetic emission sniffing.",
            "Physical Hardware Interface between Keyboard and Host Computer.",
            "Keystroke Ninja, KeyGrabber USB hardware implants.",
            "Physical port locks, USB Vendor/Product ID whitelisting, Endpoint Device Control policies."
        },
        {
            "Browser-Based Credential Theft (Formjacking)",
            "Malicious JavaScript DOM event listeners, malicious web extensions, Man-in-the-Browser (MitB).",
            "Web Application Forms, HTML Input Elements, Online Banking Interfaces.",
            "Magecart web attacks, compromised Chrome/Edge extensions.",
            "Content Security Policy (CSP), Subresource Integrity (SRI), Web Extension permission auditing."
        }
    };
}

void ThreatAnalyzer::DisplaySoftwareKeyloggersOverview() const {
    Utils::PrintSubHeader("Research Overview: Software Keyloggers");
    std::cout << "Software keyloggers are executable programs operating within the guest operating system.\n";
    std::cout << "They capture keystrokes via application-level hooks, polling APIs, or memory inspection.\n\n";
    std::cout << "Key Architecture Characteristics:\n";
    std::cout << "  - Operates under standard user or administrative process privileges.\n";
    std::cout << "  - Utilizes Windows message loop mechanisms (`SetWindowsHookEx` with `WH_KEYBOARD_LL`).\n";
    std::cout << "  - Requires local process execution and autostart registry persistence.\n";
}

void ThreatAnalyzer::DisplayHardwareKeyloggersOverview() const {
    Utils::PrintSubHeader("Research Overview: Hardware Keyloggers");
    std::cout << "Hardware keyloggers are physical electronic devices installed between the keyboard and host.\n";
    std::cout << "They operate completely independent of the target operating system and host software.\n\n";
    std::cout << "Key Architecture Characteristics:\n";
    std::cout << "  - Completely invisible to software-only anti-virus or process auditing tools.\n";
    std::cout << "  - Contains internal flash memory or Wi-Fi microcontrollers for data logging/exfiltration.\n";
    std::cout << "  - Mitigated through physical security controls, endpoint device control policies, and USB encryption.\n";
}

void ThreatAnalyzer::DisplayKernelKeyloggersOverview() const {
    Utils::PrintSubHeader("Research Overview: Kernel-Level Keyloggers");
    std::cout << "Kernel-level keyloggers execute in Ring 0 with full system privileges.\n";
    std::cout << "They intercept raw keyboard packets by attaching filter drivers to `kbdclass.sys`.\n\n";
    std::cout << "Key Architecture Characteristics:\n";
    std::cout << "  - Intercepts input before user-mode security software or password fields receive keystrokes.\n";
    std::cout << "  - Historically used by rootkits to hide process presence from Task Manager.\n";
    std::cout << "  - Modern 64-bit Windows effectively neutralizes this via Secure Boot and HVCI driver signing.\n";
}

void ThreatAnalyzer::DisplayUserModeKeyloggersOverview() const {
    Utils::PrintSubHeader("Research Overview: User-Mode Keyloggers");
    std::cout << "User-mode keyloggers run in Ring 3 and rely on Win32 user subsystem APIs.\n";
    std::cout << "They are constrained by privilege boundaries (e.g. standard user vs. elevated admin).\n\n";
    std::cout << "Key Architecture Characteristics:\n";
    std::cout << "  - Standard User-mode processes cannot hook elevated (Admin) processes due to UIPI.\n";
    std::cout << "  - Easily detected by Endpoint Detection & Response (EDR) process telemetry.\n";
}

void ThreatAnalyzer::DisplayBrowserCredentialTheftOverview() const {
    Utils::PrintSubHeader("Research Overview: Browser-Based Credential Theft");
    std::cout << "Modern credential theft frequently targets the browser layer rather than the OS kernel.\n";
    std::cout << "Attacks leverage DOM event listeners (`addEventListener('keydown')`) or malicious browser extensions.\n\n";
    std::cout << "Key Architecture Characteristics:\n";
    std::cout << "  - Bypasses traditional operating system process scanning tools.\n";
    std::cout << "  - Focuses specifically on high-value sensitive input forms (login forms, payment gateways).\n";
    std::cout << "  - Defensive controls require browser-level Content Security Policies (CSP) and extension auditing.\n";
}

void ThreatAnalyzer::DisplayHistoricalExamples() const {
    Utils::PrintSubHeader("Historical Case Studies & Cybersecurity Threat Intelligence");
    std::cout << "1. Olympic Vision Infostealer:\n";
    std::cout << "   - Targeted commercial enterprises via spear-phishing emails containing malicious attachments.\n";
    std::cout << "   - Utilized basic user-mode polling to log keystrokes and exfiltrate credentials over SMTP.\n\n";
    std::cout << "2. Agent Tesla:\n";
    std::cout << "   - Advanced spyware malware active since 2014, leveraging user-mode API hooking and clipboard monitoring.\n";
    std::cout << "   - Demonstrates the necessity of behavioral process auditing and memory integrity checks.\n\n";
    std::cout << "3. ZeroAccess Rootkit:\n";
    std::cout << "   - Sophisticated kernel-mode rootkit that modified kernel structures and system driver stacks.\n";
    std::cout << "   - Motivated the development of Kernel Patch Protection (PatchGuard) and modern VBS controls.\n";
}

void ThreatAnalyzer::DisplayDefensiveCountermeasures() const {
    Utils::PrintHeader("Comprehensive Defensive Countermeasures Matrix");
    for (const auto& cat : m_categories) {
        Utils::PrintSubHeader(cat.categoryName);
        std::cout << "  Mechanism:              " << cat.mechanism << "\n";
        std::cout << "  Target Vector:          " << cat.targetVector << "\n";
        std::cout << "  Historical Examples:    " << cat.historicalExamples << "\n";
        Utils::PrintColor("  Defensive Countermeasure: " + cat.defensiveCountermeasures + "\n\n", Utils::Color::Green);
    }
}

void ThreatAnalyzer::DisplayCompleteResearchNotes() const {
    Utils::PrintHeader("Comprehensive Keylogger Research Notes");
    DisplaySoftwareKeyloggersOverview();
    DisplayKernelKeyloggersOverview();
    DisplayHardwareKeyloggersOverview();
    DisplayBrowserCredentialTheftOverview();
    DisplayHistoricalExamples();
}

} // namespace SecurityResearch

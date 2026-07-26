#include "application.h"
#include "utils.h"

#include <iostream>
#include <limits>

namespace SecurityResearch {

Application::Application()
    : m_isRunning(false) {}

Application::~Application() {
    Shutdown();
}

bool Application::Initialize() {
    // 1. Initialize configuration manager
    m_config = std::make_unique<ConfigManager>("config.ini");
    m_config->LoadConfig();

    // 2. Open application event log file
    std::string logPath = m_config->GetSetting("LogFilePath", "app_events.log");
    m_logFile.open(logPath, std::ios::app);
    if (!m_logFile.is_open()) {
        Utils::PrintWarning("Unable to open log file: " + logPath);
    }

    LogEvent("Program Started - Application initialized successfully.");

    // 3. Initialize research & detection engines
    m_analyzer = std::make_unique<ThreatAnalyzer>();
    m_detector = std::make_unique<DetectionEngine>();
    m_reportGenerator = std::make_unique<ReportGenerator>();

    m_isRunning = true;
    return true;
}

void Application::LogEvent(const std::string& eventMessage) {
    std::string timestamp = Utils::GetCurrentTimestamp();
    std::string entry = "[" + timestamp + "] " + eventMessage + "\n";
    if (m_logFile.is_open()) {
        m_logFile << entry;
        m_logFile.flush();
    }
}

void Application::Shutdown() {
    if (m_isRunning) {
        LogEvent("Program Closed - Normal shutdown.");
        if (m_logFile.is_open()) {
            m_logFile.close();
        }
        m_isRunning = false;
    }
}

void Application::RenderMenu() const {
    Utils::PrintHeader("Keylogger for Security Research - Main Menu");
    std::cout << "1. Project Overview\n";
    std::cout << "2. What is a Keylogger?\n";
    std::cout << "3. Types of Keyloggers\n";
    std::cout << "4. Windows Keyboard Input Architecture (Conceptual)\n";
    std::cout << "5. Research Notes & Threat Intelligence\n";
    std::cout << "6. Defensive Detection Techniques & Blueprints\n";
    std::cout << "7. Security Recommendations\n";
    std::cout << "8. Generate Research Report (.txt)\n";
    std::cout << "9. Exit\n";
    std::cout << std::string(60, '-') << "\n";
    Utils::PrintColor("Select an option [1-9]: ", Utils::Color::Yellow);
}

void Application::Run() {
    while (m_isRunning) {
        RenderMenu();

        int choice = 0;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            Utils::PrintWarning("Invalid input. Please enter a number between 1 and 9.");
            continue;
        }

        HandleMenuSelection(choice);
    }
}

void Application::HandleMenuSelection(int choice) {
    LogEvent("Menu Selected: Choice " + std::to_string(choice));

    switch (choice) {
        case 1:
            ShowProjectOverview();
            break;
        case 2:
            ShowWhatIsKeylogger();
            break;
        case 3:
            ShowTypesOfKeyloggers();
            break;
        case 4:
            ShowWindowsInputArchitecture();
            break;
        case 5:
            ShowResearchNotes();
            break;
        case 6:
            ShowDetectionTechniques();
            break;
        case 7:
            ShowSecurityRecommendations();
            break;
        case 8:
            GenerateReport();
            break;
        case 9:
            Utils::PrintInfo("Exiting program. Thank you for using Keylogger Security Research Tool.");
            m_isRunning = false;
            break;
        default:
            Utils::PrintWarning("Invalid choice. Please select an option between 1 and 9.");
            break;
    }

    if (m_isRunning && choice >= 1 && choice <= 8) {
        std::cout << "\nPress Enter to return to the main menu...";
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        std::cin.get();
    }
}

void Application::ShowProjectOverview() const {
    Utils::PrintHeader("Project Overview: Keylogger for Security Research");
    std::cout << "Academic Project Title:  Keylogger for Security Research\n";
    std::cout << "Target Purpose:          B.Tech Cybersecurity Internship Project\n";
    std::cout << "Focus:                   Defensive Security Research & Academic Education\n\n";

    Utils::PrintColor("Ethical Principles & Safeguards:\n", Utils::Color::Green);
    std::cout << "  - Zero Keystroke Recording: Strictly no keylogging APIs or hooking mechanisms.\n";
    std::cout << "  - Educational Focus: Explains threat architectures and modern defensive blueprints.\n";
    std::cout << "  - Modern C++17 Standard: Clean, modular architecture with zero offensive capabilities.\n";
}

void Application::ShowWhatIsKeylogger() const {
    Utils::PrintHeader("What is a Keylogger? (Conceptual Overview)");
    std::cout << "A keylogger (keystroke logger) is a surveillance technology used to monitor and record\n";
    std::cout << "keystrokes typed on a computer keyboard.\n\n";
    std::cout << "Dual-Use Context:\n";
    std::cout << "  - Malicious Use: Credential theft, banking fraud, unauthorized corporate espionage.\n";
    std::cout << "  - Legitimate Use: Authorized system troubleshooting, parent/employee monitoring (with consent).\n";
    std::cout << "  - Defensive Focus: Understanding interception points to build effective EDR telemetry.\n";
}

void Application::ShowTypesOfKeyloggers() const {
    m_analyzer->DisplayDefensiveCountermeasures();
}

void Application::ShowWindowsInputArchitecture() const {
    Utils::PrintHeader("Windows Keyboard Input Subsystem Architecture");
    std::cout << "Data Flow Breakdown:\n";
    std::cout << "  1. Physical Keyboard  -> Generates Hardware Interrupt (IRQ 1 / USB HID)\n";
    std::cout << "  2. i8042prt / kbdhid  -> Port Drivers process raw scancodes into KEYBOARD_INPUT_DATA\n";
    std::cout << "  3. kbdclass.sys       -> Keyboard Class Driver aggregates input packets\n";
    std::cout << "  4. win32k.sys         -> Translates packets into Windows Messages (WM_KEYDOWN/UP)\n";
    std::cout << "  5. USER32.dll / App   -> Target process receives input in its Message Queue\n\n";

    Utils::PrintColor("Security Interception Points:\n", Utils::Color::Yellow);
    std::cout << "  - Kernel-mode driver hooks (kbdclass filter drivers)\n";
    std::cout << "  - User-mode Win32 hooks (SetWindowsHookEx)\n";
    std::cout << "  - Polling APIs (GetAsyncKeyState)\n";
}

void Application::ShowResearchNotes() const {
    m_analyzer->DisplayCompleteResearchNotes();
}

void Application::ShowDetectionTechniques() const {
    m_detector->DisplayAllDetectionTechniques();
}

void Application::ShowSecurityRecommendations() const {
    Utils::PrintHeader("Strategic Defensive Security Recommendations");
    std::cout << "[1] Hypervisor-Protected Code Integrity (HVCI):\n";
    std::cout << "    Enforce VBS to block unsigned kernel driver filter implants.\n\n";
    std::cout << "[2] User Interface Privilege Isolation (UIPI):\n";
    std::cout << "    Prevent un-elevated user-mode binaries from injecting hooks into elevated processes.\n\n";
    std::cout << "[3] Multi-Factor Authentication (MFA):\n";
    std::cout << "    Deploy FIDO2/Hardware keys to render stolen static passwords useless.\n\n";
    std::cout << "[4] Endpoint Detection and Response (EDR):\n";
    std::cout << "    Utilize ETW process monitoring to detect autostart registry persistence and unbacked memory pages.\n";
}

void Application::GenerateReport() {
    LogEvent("Report Generated - User initiated report export.");
    std::string reportDir = m_config->GetSetting("ReportOutputDir", "reports");
    m_reportGenerator->GenerateReport(reportDir);
}

} // namespace SecurityResearch

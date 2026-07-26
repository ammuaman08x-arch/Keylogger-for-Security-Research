# Future Scope & Advanced Defensive Telemetry Roadmap

## 1. Overview

While the initial version of **"Keylogger for Security Research"** serves as an educational CLI tool with detection placeholders, future security research can expand into advanced Windows security subsystem integration.

---

## 2. Technical Roadmap

### 2.1 Event Tracing for Windows (ETW) Integration
- Leverage `Microsoft-Windows-Kernel-Process` and `Microsoft-Windows-Services` ETW providers to observe process creation and service installation in real time without polling.

### 2.2 Win32 Process Memory Scanning
- Expand process inspection placeholders into safe API-based queries using `EnumProcesses()`, `QueryFullProcessImageName()`, and `WinVerifyTrust()` to analyze authentic digital signatures of running binaries.

### 2.3 Automated YARA Integration
- Integrate a C++ YARA scanner engine to audit target binary disk images against open-source threat signatures for credential access tools.

### 2.4 User Interface Enhancement
- Transition the console interface to a modern C++ GUI framework (e.g., Qt or Dear ImGui) with real-time process monitoring visualizations.

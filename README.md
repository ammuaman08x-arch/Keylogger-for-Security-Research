INTERID: CT-5160
FULL NAME: MD AMAN UL HAQ
NO.OF WEEKS: 1
PROJECT NAME: Keylogger for Security Research
PROJECT SCOPE: The Keylogger for Security Research is a professional cybersecurity desktop application developed in Modern C++17 and Qt 6 Widgets for Windows 10/11. It provides a comprehensive, interactive educational framework for understanding keyboard input security, threat taxonomy, defensive detection strategies, and Windows Input Subsystem architecture. The application includes features such as a theoretical Windows Subsystem diagram generator, comparative analysis of keylogger types, threat intelligence research notes, detection blueprints, and an automated local research report generator that exports time-stamped, formatted research reports to the filesystem. It also implements an INI configuration manager, an internal event logger, and various defensive detection concepts including process inspection, Authenticode signature verification, hypervisor-protected code integrity (HVCI) blueprints, and Event Tracing for Windows (ETW) behavioral monitoring concepts. The project is designed to be educational and non-malicious, providing a solid foundation for students and researchers in the field of cybersecurity.


# Keylogger for Security Research

> **Academic Defensive Security Research Project**  
> Developed for B.Tech Cybersecurity Internship Education & Research.

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![Compiler](https://img.shields.io/badge/Compiler-MSVC-orange.svg)](https://visualstudio.microsoft.com/vs/)
[![Build System](https://img.shields.io/badge/Build-CMake-green.svg)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-MIT-brightgreen.svg)](LICENSE)

---

## 1. Project Overview

**Keylogger for Security Research** is an educational, defensive C++17 desktop application created specifically for academic cybersecurity research, security awareness, and endpoint security analysis.

Unlike offensive tools, this application **contains ZERO functionality to record, log, or exfiltrate keystrokes**. It implements no keyboard hooks (`SetWindowsHookEx`), polling APIs (`GetAsyncKeyState`), or kernel driver filters. Instead, it provides an interactive theoretical framework, architectural documentation of the Windows Input Subsystem, threat taxonomy models, defensive detection blueprints, and a automated local research report generator.

---

## ⚡ Quick Start (One-Click Build & Run)

For Windows users who clone this repository, quick-launch scripts are provided in the root folder:

- **Build Project**: Double-click `build.bat` or run `.\build.bat` in PowerShell.
- **Run Application**: Double-click `run.bat` or run `.\run.bat` in PowerShell (automatically builds if not compiled yet).

---

## 2. Project Objectives

- **Educational Analysis**: Demystify the internal architecture of the Windows Keyboard Input Subsystem from hardware interrupts to user-mode window messages.
- **Threat Taxonomy**: Categorize input observation threats across Software, Kernel, Hardware, and Browser (Formjacking) vectors.
- **Defensive Blueprints**: Provide technical detection concepts for process inspection, autorun auditing, Authenticode signature verification, and ETW behavioral monitoring.
- **Academic Research**: Facilitate project submission requirements for B.Tech Cybersecurity internships through reproducible C++ architecture and report generation.

---

## 3. Application Features

1. **Interactive Command-Line Application Menu**:
   - Project Overview & Safety Safeguards
   - Conceptual Explanation: "What is a Keylogger?"
   - Comparative Breakdown of Keylogger Types
   - Conceptual Windows Input Subsystem Diagram
   - Threat Intelligence Research Notes & Case Studies
   - Defensive Detection Blueprints & Code Placeholders
   - Strategic Security Recommendations
   - Local Research Report Generator (`.txt`)
   - Graceful Exit & Log Flush

2. **Defensive Detection Engine**:
   - Process Inspection & Binary Auditing concept
   - Event Tracing for Windows (ETW) Behavioral Monitoring concept
   - Hypervisor-Protected Code Integrity (HVCI) concept
   - Autorun & Registry Persistence inspection blueprint
   - Authenticode Digital Signature verification concept
   - Memory Region Scanning & Page Protection concept

3. **Local Report Generator**:
   - Generates formatted, time-stamped text research reports saved directly to the `reports/` folder.

4. **Configuration & Event Logger**:
   - `config.ini` reader/writer supporting user customization with hardcoded defensive guardrails.
   - Internal application event logger (`app_events.log`) tracking lifecycle states (Program Started, Menu Selected, Report Generated, Program Closed) without touching input APIs.

---

## 4. Technology Stack

- **Language**: Modern C++17 (Smart Pointers, STL Filesystem, Const-Correctness, Custom Namespaces)
- **Compiler**: Microsoft Visual C++ (MSVC)
- **Build System**: CMake (v3.14+)
- **Target OS**: Windows 10 / 11 (x64)
- **IDE**: Antigravity / Visual Studio 2022

---

## 5. Folder Structure

```
KeyloggerSecurityResearch/
│
├── CMakeLists.txt              # Root CMake configuration
├── README.md                   # Comprehensive project documentation
├── LICENSE                     # MIT Open Source License with Educational Disclaimer
│
├── docs/                       # Research documentation suite
│   ├── architecture.md         # Windows Keyboard Subsystem conceptual analysis
│   ├── methodology.md          # Research approach & data integrity safeguards
│   ├── literature_review.md    # Academic synthesis of input security literature
│   ├── testing.md              # Test matrix & static safety audit guidelines
│   ├── ethics.md               # Ethical compliance & non-malware framework
│   └── future_scope.md         # Roadmap for ETW & YARA telemetry expansion
│
├── include/                    # C++ Header files
│   ├── application.h           # Core application Orchestrator & CLI loop
│   ├── detector.h              # Defensive detection engine & concepts
│   ├── analyzer.h              # Threat taxonomy & threat intelligence analyzer
│   ├── report.h                # Research report generator
│   ├── config.h                # INI configuration manager
│   └── utils.h                 # Console styling & timestamp utilities
│
├── src/                        # C++ Source implementations
│   ├── main.cpp                # Executable entry point
│   ├── application.cpp         # Menu logic & event handling
│   ├── detector.cpp            # Detection blueprints & TODO placeholders
│   ├── analyzer.cpp            # Research notes & taxonomy implementations
│   ├── report.cpp              # Formatted report export logic
│   ├── config.cpp              # Config loader & guardrail enforcement
│   └── utils.cpp               # Win32 console color & filesystem helpers
│
├── tests/                      # Verification testing directory
├── assets/                     # Application branding & documentation assets
└── screenshots/                # Application execution visual samples
└── Document.md                 # C++ Codebase architecture, OOD design, and safety safeguards
```

---

## 6. Build Instructions

### Prerequisites
- Windows 10 or 11
- Visual Studio 2019/2022 with **C++ Desktop Development Workload** (MSVC)
- CMake 3.14 or newer

### Building via CMake CLI (PowerShell)

#### Option A: Using the Visual Studio CMake Full Path (Standard PowerShell)
If `cmake` is not added to your system `PATH` environment variable, run using the Visual Studio bundled CMake path:

1. Generate MSVC build files:
   ```powershell
   & "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -B build -S .
   ```

2. Compile the Release executable:
   ```powershell
   & "C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" --build build --config Release
   ```

#### Option B: Using Developer PowerShell for Visual Studio
1. Open **Developer PowerShell for Visual Studio** from your Windows Start Menu.
2. Navigate to the project folder and run standard CMake commands:
   ```powershell
   cd c:\DEV\Aman\Keylogger
   cmake -B build -S .
   cmake --build build --config Release
   ```

3. The compiled executable is generated at:
   `.\build\Release\KeyloggerSecurityResearch.exe`

---

## 7. Usage

Run the compiled executable from PowerShell or Command Prompt:

```powershell
.\build\Release\KeyloggerSecurityResearch.exe
```

### Interactive Menu Workflow
```
============================================================
 Keylogger for Security Research - Main Menu
============================================================
1. Project Overview
2. What is a Keylogger?
3. Types of Keyloggers
4. Windows Keyboard Input Architecture (Conceptual)
5. Research Notes & Threat Intelligence
6. Defensive Detection Techniques & Blueprints
7. Security Recommendations
8. Generate Research Report (.txt)
9. Exit
------------------------------------------------------------
Select an option [1-9]: 
```

Select Option `8` to generate a comprehensive research report saved automatically to `reports/Security_Research_Report_<timestamp>.txt`.

---

## 8. Learning Outcomes

By completing and reviewing this project, cybersecurity students achieve:
1. **Operating System Architecture**: In-depth understanding of the Windows IRQ -> Driver -> Win32 Subsystem message loop.
2. **Defensive Engineering**: Ability to design endpoint detection strategies (ETW, HVCI, Authenticode validation) targeting binary integrity rather than reactive input monitoring.
3. **Modern C++ Standards**: Hands-on experience with C++17 STL filesystem, smart pointer memory management, OOP separation, and CMake build systems.
4. **Ethical Security Design**: Practical understanding of how to build defensive research projects without creating dangerous dual-use software.

---

## 9. System Limitations

- **No Active Detection**: The application deliberately implements theoretical blueprints and `// TODO` code placeholders rather than active malware scanning engines.
- **No Input Monitoring**: Keystroke monitoring is explicitly excluded by design.

---

## 10. Ethical Statement & Compliance

> **IMPORTANT DECLARATION**  
> This project is designed purely for educational research and defensive analysis. The codebase contains no keystroke logging functionality, no keyboard hook APIs (`SetWindowsHookEx`), and no credential harvesting code. It complies fully with university academic integrity rules and international ethical cybersecurity guidelines.

---

## 11. Future Scope

- **Event Tracing for Windows (ETW)**: Real-time kernel process creation telemetry integration.
- **YARA Rule Integration**: C++ binding to audit process memory against open-source malware rules.
- **Graphical User Interface (GUI)**: Transitioning from CLI to a modern Qt / Dear ImGui interface.

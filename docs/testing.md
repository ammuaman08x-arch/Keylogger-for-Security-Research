# Testing Framework & Defensive Verification Protocol

## 1. Overview

This document describes the testing strategy for the "Keylogger for Security Research" C++ application, ensuring robust execution, modern C++17 memory safety, and complete adherence to ethical guidelines.

---

## 2. Test Matrix

| Test Suite | Purpose | Execution Method | Expected Result |
| :--- | :--- | :--- | :--- |
| **Static Code Analysis** | Ensure code quality, zero warning compilation | MSVC `/W4 /permissive-` | Clean compilation, 0 warnings |
| **Configuration Engine Test** | Verify parsing and writing of `config.ini` | Automated run | Successful load & default creation |
| **Report Generator Test** | Validate output report formatting | Application execution | Formatted `.txt` file created in `reports/` |
| **Detection Engine Mock** | Verify theoretical inspection placeholder execution | Console menu option 6 | Informative educational output displayed |
| **Safety Audit** | Ensure zero usage of `SetWindowsHookEx`, `GetAsyncKeyState`, or input APIs | Code inspection & grep | No keyboard monitoring functions present |

---

## 3. Automated Code Audit Verification Command

```powershell
# Verify no usage of Windows keyboard hook APIs in codebase
Select-String -Path "src\*", "include\*" -Pattern "SetWindowsHookEx", "GetAsyncKeyState", "GetKeyState", "WH_KEYBOARD"
```
*Expected Result:* Zero matches across all files.

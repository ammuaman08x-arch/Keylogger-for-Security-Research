# Ethical Guidelines & Responsible Research Declaration

## 1. Ethical Framework Statement

Academic cybersecurity research relies on rigorous ethical standards. This project, **"Keylogger for Security Research"**, was designed from inception as a defensive, educational tool intended exclusively for academic evaluation, security awareness, and defensive technical training.

---

## 2. Strict Technical Constraints

To guarantee that this project cannot be misused or classified as dual-use software:

1. **NO Keystroke Capture**: The codebase contains no calls to `SetWindowsHookEx`, `GetAsyncKeyState`, `GetKeyState`, `RegisterRawInputDevices`, or low-level keyboard drivers.
2. **NO Persistence Mechanisms**: The application does not write to autostart registry keys, startup folders, or scheduled tasks.
3. **NO Hidden Execution**: The application runs transparently in a foreground console window with explicit user menus.
4. **NO Data Exfiltration**: The application contains no network sockets, web requests, or remote data transmission capabilities.

---

## 3. Academic Integrity Compliance

This project complies fully with university and industry ethical guidelines:
- **Association for Computing Machinery (ACM) Code of Ethics**
- **IEEE Ethical Guidelines for Cybersecurity Research**
- **Responsible Disclosure Principles**

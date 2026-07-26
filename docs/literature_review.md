# Literature Review: Input Security & Malware Detection Dynamics

## 1. Introduction

Input security is a critical subfield of endpoint cyber defense. Keylogging represents one of the oldest forms of credential harvesting, evolving alongside changes in operating system security boundaries.

---

## 2. Academic & Industry Literature Synthesis

### 2.1 Evolution of User-Mode Interception
Historical research by Vasudevan et al. (2006) highlighted the vulnerability of standard Win32 API message loops to user-mode hooks (`SetWindowsHookEx`). Early counter-measures focused on Hook Chain inspection. Modern operating systems mitigate global hooks across privilege levels using User Interface Privilege Isolation (UIPI).

### 2.2 Kernel-Mode Rootkits and Driver Filters
With the introduction of x64 64-bit Windows, Microsoft introduced Kernel Patch Protection (PatchGuard) and Hypervisor-Protected Code Integrity (HVCI). Industry research from Microsoft Security Response Center (MSRC) demonstrates that enforcing signed kernel drivers effectively neutralized legacy kernel-mode keyloggers.

### 2.3 Web & Formjacking Threats
As application architecture shifted toward browser-based workflows, threat actors transitioned toward JavaScript-based DOM event listeners (Formjacking) and malicious browser extensions. Defense-in-depth measures such as Content Security Policy (CSP) and extension manifest v3 restrictions have become primary defensive standards.

---

## 3. Comparative Taxonomy of Defensive Strategies

| Defensive Strategy | Primary Focus | Effectiveness | Implementation Complexity |
| :--- | :--- | :--- | :--- |
| **Authenticode Signature Enforcement** | Binary Validation | High | Low |
| **Behavioral Telemetry (ETW)** | Process Activity | High | Medium |
| **Out-of-Band Hardware Encryption** | Input Data Protection | Very High | High |
| **Static Heuristic Inspection** | Process & File Analysis | Medium | Low |

---

## 4. Key Takeaways for Defensive Engineering

- Keylogger prevention requires layered defense: binary verification, driver signing, privilege isolation, and behavioral monitoring.
- Defensive research tools must prioritize visibility into autostart locations and unsigned running binaries rather than reacting to active input interception.

# Windows Keyboard Input & Keylogger Architecture (Conceptual Analysis)

## 1. Executive Summary

Understanding keyboard input processing in Windows OS is foundational to modern endpoint detection and response (EDR). This document details the architectural stack from hardware interrupts down to user-mode window messages, analyzing where unauthorized input interception points historically occur and how defensive systems audit these paths.

---

## 2. Windows Keyboard Input Subsystem Hierarchy

The keyboard input pipeline flows from lower kernel drivers up to active desktop application windows:

```
[ Physical Keyboard / Hardware ]
               │
               ▼
   [ Port Driver (i8042prt.sys / kbdhid.sys) ]
               │
               ▼
   [ Keyboard Class Driver (kbdclass.sys) ]
               │
               ▼
   [ Win32k.sys / User Subsystem (USER32.dll) ]
               │
               ▼
 [ Thread Message Queue (WM_KEYDOWN / WM_KEYUP) ]
               │
               ▼
      [ Target Window Proc ]
```

### 2.1 Hardware and Interrupt Service Routines (ISRs)
- Physical keystrokes generate Hardware Interrupt Request (IRQ 1 for PS/2 or USB HID Interrupt Endpoints).
- The Kernel Interrupt Service Routine (ISR) acknowledges the hardware event and schedules a Deferred Procedure Call (DPC).

### 2.2 Kernel-Mode Drivers
- **Port Driver (`i8042prt.sys` / `kbdhid.sys`)**: Converts physical scancodes into structured data (`KEYBOARD_INPUT_DATA`).
- **Keyboard Class Driver (`kbdclass.sys`)**: Aggregates input packets across input devices and feeds them up to `win32k.sys`.
- **Upper/Lower Filter Drivers**: Kernel drivers can register filters attached to `kbdclass.sys`. Modern OS integrity enforcement (Hypervisor-Protected Code Integrity / HVCI) strictly limits unauthorized filter driver loading.

### 2.3 User-Mode Input Processing
- **Win32k Subsystem**: Translates raw input packets into Windows Messages (`WM_KEYDOWN`, `WM_KEYUP`, `WM_CHAR`).
- **Raw Input API**: Applications can register via `RegisterRawInputDevices()` to receive `WM_INPUT` messages directly without global hooks.

---

## 3. Input Interception Taxonomies & Defensive Auditing

| Interception Layer | Mechanism / Vector | Detection Vector | Defensive Countermeasure |
| :--- | :--- | :--- | :--- |
| **Hardware** | Inline USB passthrough dongles | USB device VID/PID whitelist logging | Port security, physical locks |
| **Kernel Mode** | Filter Driver / IRP Hooking | Driver digital signature checks (`ci.dll`), HVCI | Kernel Patch Protection (KPP / PatchGuard) |
| **User Mode (Hooks)** | `SetWindowsHookEx` (`WH_KEYBOARD_LL`) | DLL Injection detection, API Hook scanning | Process memory integrity checks, EDR API hooks |
| **User Mode (Polling)**| `GetAsyncKeyState` / `GetKeyState` | Continuous thread polling behavior, high CPU usage | Behavioral heuristical analysis |
| **Browser Extensions**| DOM Event Listener Interception | Content Security Policy (CSP), Web Extension auditing | Browser integrity controls |

---

## 4. Defensive Research Principles

1. **Non-Intrusive Auditing**: Defensive tools monitor process integrity and driver signatures rather than hooking input pathways.
2. **Behavioral Telemetry**: Leveraging ETW (Event Tracing for Windows) provides transparent system-level logging without kernel modification.
3. **Zero Input Collection**: Modern endpoint defense verifies binary integrity rather than monitoring keystrokes.

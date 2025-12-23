# 🚀 VirtuOS Industrial Simulator
### **Embedded Multi-Process System for ARM VExpress**

![Language](https://img.shields.io/badge/language-C-blue.svg) 
![Platform](https://img.shields.io/badge/platform-ARM%20VExpress-orange.svg) 
![OS](https://img.shields.io/badge/OS-Buildroot%20Linux-red.svg)
![Status](https://img.shields.io/badge/status-Functional-success.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

---

## 📖 Project Overview
VirtuOS Industrial Simulator is a specialized **Embedded Linux** application designed to simulate an industrial control environment. It demonstrates the ability to manage **asynchronous processes**, handle **Inter-Process Communication (IPC)**, and automate system tasks within a custom-built Linux kernel.

---

## 🧩 System Architecture
The project follows a **Producer-Consumer** design pattern. The logic is decoupled to ensure that sensor data collection remains independent of the user interface.



```mermaid
graph TD
    subgraph "Linux Kernel Space (/proc)"
        A[Uptime Data] --> C
        B[Load Average] --> C
    end

    subgraph "Background Layer (Producer)"
        C[sensor_hub] -- "Writes simulated data" --> D((RAMFS /tmp))
    end

    subgraph "Interface Layer (Consumer)"
        D -- "Reads status" --> E[controller_dash]
        E --> F{Real-time Display}
    end

    F -- "Load > 0.10" --> G[ALERT: RED LED]
    F -- "Load < 0.10" --> H[STATUS: GREEN LED]

## 📺 Live Simulation Preview

### 🟢 System Normal
```bash
[VirtuOS]: Scanning Sensors...
[TEMP: 38.4 C] [LOAD: 0.08] | STATUS: SYSTEM NOMINAL

[VirtuOS]: WARNING - Threshold Exceeded!
[TEMP: 52.1 C] [LOAD: 0.55] | STATUS: !! OVERHEAT/OVERLOAD !!

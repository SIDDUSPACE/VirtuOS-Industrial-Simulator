# VirtuOS Industrial Simulator
An ARM-based embedded system that simulates an industrial control environment.

## 🏗️ Architecture
The system uses a **decoupled multi-process architecture**:
- **`sensor_hub`**: A background service that gathers system metrics and simulates temperature data.
- **`controller`**: A real-time dashboard that consumes sensor data and manages system alerts.

## 🛠️ Built With
- **OS**: Custom Linux via Buildroot
- **Kernel**: 5.x LTS
- **Architecture**: ARMv7 (QEMU vexpress-a9)
- **Language**: C (Standard Library)

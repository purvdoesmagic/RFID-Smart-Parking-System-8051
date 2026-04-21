# 🚗 RFID Smart Parking System (8051)

<p align="center">
  <b>Smart Parking System using 8051 Microcontroller • Keil µVision • Proteus Simulation</b>
</p>

---

## 📌 Overview

This project implements a **Smart Parking System using the AT89C51 (8051) microcontroller**, designed to efficiently manage parking slots through **RFID-based authentication and real-time tracking**.

The system dynamically allocates parking slots, tracks vehicle entry and exit, and prevents over-parking using optimized embedded system logic. The complete system is simulated in **Proteus** and programmed using **Embedded C in Keil µVision**.

---

## 🚀 Key Features

- 🔐 **RFID-based User Authentication**
- 🚗 **Dynamic Slot Allocation (5 Slots)**
- 🔄 **Automatic Slot Reuse after Exit**
- 🚫 **Parking Full Detection**
- ❌ **Invalid User Handling**
- 📟 **Real-time LCD Display**
- 💻 **UART-based Virtual Terminal Input**
- ⚙️ **Motor-Controlled Gate Simulation (L293D Driver)**

---

## 🛠️ Tech Stack

| Component       | Technology              |
|----------------|------------------------|
| Microcontroller| AT89C51 (8051)         |
| Language       | Embedded C             |
| IDE            | Keil µVision           |
| Simulation     | Proteus ISIS           |
| Communication  | UART (Virtual Terminal)|

---

## ⚙️ System Workflow

1. System initializes LCD and UART modules
2. User enters RFID ID via Virtual Terminal
3. Microcontroller validates the ID

### ✅ Valid User
- First scan → Parking slot assigned
- Second scan → Vehicle exit and slot freed

### ❌ Invalid User
- Access denied with appropriate display message

### 🚫 Parking Full Condition
- Displays **PARKING FULL** when all slots are occupied

### 📟 Display Output
- User identification
- Assigned slot number
- System status messages

---

## 🎬 Demo Flow

- Enter valid RFID → Slot assigned
- Re-enter same RFID → Exit processed
- Fill all slots → Parking Full triggered
- Enter unknown RFID → Invalid User detected

---

## 📸 Project Demonstration

### 🔌 Circuit Diagram
<p align="center">
  <img src="Circuit.png" width="700"/>
</p>

### 💻 Output (Virtual Terminal)
<p align="center">
  <img src="output.png" width="700"/>
</p>

---

## ▶️ How to Run

1. Open the Proteus project file
2. Load the provided `.hex` file into the microcontroller
3. Run the simulation
4. Enter RFID IDs via the Virtual Terminal

---

## 🧪 Sample Inputs

### ✔ Valid RFID IDs

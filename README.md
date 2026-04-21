# 🚗 RFID Smart Parking System (8051)

<p align="center">
  <b>Smart Parking using 8051 Microcontroller • Keil µVision • Proteus Simulation</b>
</p>

---

## 📌 Overview

This project presents a **Smart Parking System using the AT89C51 (8051) microcontroller** that dynamically manages parking slots in real time.

It assigns slots to authorized users, tracks entry and exit, and prevents over-parking using efficient embedded system logic.

The system is fully simulated in **Proteus** and implemented using **Embedded C in Keil µVision**.

---

## 🚀 Key Features

* 🔹 Dynamic slot allocation (5 parking slots)
* 🔹 Entry & exit tracking using RFID IDs
* 🔹 Automatic slot reuse after exit
* 🔹 Parking full detection
* 🔹 Invalid user detection
* 🔹 Real-time LCD display
* 🔹 UART-based Virtual Terminal input
* 🔹 Motor-controlled gate simulation (L293D)

---

## 🛠️ Tech Stack

| Component       | Technology              |
| --------------- | ----------------------- |
| Microcontroller | AT89C51 (8051)          |
| Language        | Embedded C              |
| IDE             | Keil µVision            |
| Simulation      | Proteus ISIS            |
| Communication   | UART (Virtual Terminal) |

---

## ⚙️ System Working

1. System initializes LCD and UART
2. User enters RFID ID via Virtual Terminal
3. Microcontroller validates the ID

### ✅ Valid User

* First scan → Assign slot
* Second scan → Exit + slot freed

### ❌ Invalid User

* Access denied

### 🚫 Full Parking

* Displays **PARKING FULL** when no slots are available

### 📟 Display Output

* User name
* Slot number

---

## 🎬 Demo Flow

* Enter valid RFID → Slot assigned
* Re-enter same RFID → Exit
* Fill all slots → Parking Full
* Enter unknown ID → Invalid User

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
2. Load the `.hex` file into the microcontroller
3. Run the simulation
4. Enter RFID IDs in the Virtual Terminal

---

## 🧪 Sample Inputs

### ✔ Valid Users

```
16014024013
16014024014
16014024015
16014024016
16014024017
16014024018
```

### ❌ Invalid Input

```
12345678901
```

---

## 💯 Output Behavior

* Assigns slots from 1 to 5
* Reuses slots after exit
* Displays **PARKING FULL** when capacity is reached
* Displays **INVALID USER** for unknown IDs

---

## 🎯 Applications

* Smart parking systems
* Residential parking automation
* Office & campus parking management
* RFID-based access control

---

## ⭐ Highlights

* Efficient slot management using arrays
* Real-time embedded system simulation
* UART-based RFID emulation
* Clean and optimized 8051 implementation

---

## 🔍 Keywords

RFID • 8051 • Embedded Systems • Smart Parking • Keil • Proteus • UART

---

## 🔮 Future Improvements

* Real RFID hardware integration
* IR sensors for automatic vehicle detection
* Mobile app for slot tracking
* Database logging system

---

## 👨‍💻 Author

**Purv Doshi**

---

---

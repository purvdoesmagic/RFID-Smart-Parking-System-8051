# 🚗 RFID Smart Parking System (8051 + Proteus)

A smart parking system built using **8051 microcontroller** and **RFID technology**, designed to automate vehicle entry/exit and manage parking slots efficiently. The system is simulated using **Proteus** and demonstrates real-world embedded system integration.

---

## 📌 Features

- 🔐 **RFID-based Vehicle Authentication**
- 🚧 **Automated Entry and Exit Control**
- 📊 **Real-time Parking Slot Monitoring**
- 🖥️ **LCD Display for Status Updates**
- ⚡ **Efficient Parking Flow Management**
- 🧠 **Embedded System Logic using 8051**

---

## 🛠️ Tech Stack

- **Microcontroller:** 8051  
- **Simulation Tool:** Proteus  
- **Programming:** Embedded C  
- **Hardware Components:**  
  - RFID Module  
  - LCD Display  
  - Microcontroller (AT89C51 / equivalent)

---

## ⚙️ How It Works

1. Vehicle arrives at the parking entry.
2. RFID tag is scanned using the reader.
3. System verifies the tag:
   - ✅ Valid → Gate opens  
   - ❌ Invalid → Access denied  
4. Parking slot availability is checked.
5. LCD displays:
   - Available slots  
   - Parking full status  
6. On exit, RFID is scanned again to update system.

---

## 📂 Project Structure

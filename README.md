# 🚂 Railway Reservation System

A console-based application in **C** for managing a basic railway ticket booking system. This project demonstrates core programming concepts, including data structures, modular design, and file handling.

---

## 💻 Project Overview

The Railway Reservation System automates the ticket booking process, providing a simple yet effective interface for passengers and administrators. Users can view train schedules, book or cancel tickets, and retrieve booking details, while administrators can manage train information. The project is ideal as an academic demonstration of structured programming and C fundamentals.

---

## ✨ Features

* **User-Friendly Interface**: Menu-driven console application for easy navigation.
* **Train Schedule**: View all available trains, routes, and seat availability.
* **Ticket Booking**: Book a seat on any available train.
* **Ticket Cancellation**: Cancel bookings using the unique PNR number.
* **Booking Management**: Retrieve and view ticket details.
* **Admin Access**: Admin login to manage trains and review all bookings.
* **Data Persistence**: All data is stored in binary files, preserving information across sessions.

---

## 🛠 Tech Stack

* **Programming Language**: C
* **Libraries**:

  * `stdio.h` – Standard Input/Output
  * `stdlib.h` – Standard Library
  * `string.h` – String Manipulation
  * `ctype.h` – Character Handling

---

## 💾 Data Storage

The system uses binary files for persistent storage:

* `trains.dat` – Stores train details
* `bookings.dat` – Stores passenger and ticket information

---

## 🚀 Getting Started

Follow these steps to compile and run the project locally.

### Prerequisites

* C Compiler (GCC, MinGW, or similar)

### Installation

1. Clone the repository or download the source code.
2. Save the main file as `main.c`.
3. Open a terminal or command prompt and navigate to the project directory.

### Compile and Run

```bash
gcc main.c -o railway_reservation
```

Run the executable:

* **Windows**:

```bash
.\railway_reservation.exe
```

* **macOS/Linux**:

```bash
./railway_reservation
```

---

## 📋 Usage Guide

Upon running, the application presents a main menu allowing access to both **User** and **Admin** functionalities.

### Admin Credentials

* **Username**: `admin`
* **Password**: `admin123`

> Note: Admin authentication is hardcoded for demonstration purposes.

---

## 👨‍💻 Author

**Vishant Chaudhary**

* [LinkedIn](https://www.linkedin.com/in/vishant-chaudhary-c-s)
* Email: [vishantkumar3105@gmail.com](mailto:vishantkumar3105@gmail.com)

---

## 📄 License

This project is licensed under the **MIT License**. See the LICENSE file for details.

---

> ⚡ "The Railway Reservation System not only manages tickets but also showcases structured programming, problem-solving, and data management in C."

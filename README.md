🚂 Railway Reservation System
A console-based application for managing a simple railway ticket booking system, built entirely in C.

💻 Project Overview
This project is a straightforward and efficient solution for automating the process of railway ticket reservations. Developed in C, it serves as a robust academic project that demonstrates fundamental programming concepts such as data structures, modular function design, and file handling for data persistence. The system allows users to view train schedules, book and cancel tickets, and retrieve booking details. It also features a basic administrator interface for managing train information.

📸 Console Screenshot
Here is a preview of the application's console interface in action:

✨ Features
User-Friendly Interface: A clear, menu-driven console application.

Train Schedule: Displays a list of all available trains, their routes, and available seats.

Ticket Booking: Allows passengers to book a seat on a selected train.

Ticket Cancellation: Enables the cancellation of an existing booking using its unique PNR number.

Booking Management: Users can retrieve and view their ticket details by PNR.

Admin Access: A dedicated admin login to manage trains and view all bookings in the system.

Data Persistence: All data is saved to binary files, ensuring that information is preserved across program executions.

🛠 Tech Stack
Programming Language:

C

Libraries:

stdio.h (Standard Input/Output)

stdlib.h (Standard Library)

string.h (String Manipulation)

ctype.h (Character Handling)

💾 Data Storage
This project uses binary file handling for data persistence.

trains.dat: Stores all train details in a binary format.

bookings.dat: Stores all booking records, including passenger and ticket information.

🚀 Getting Started
Follow these steps to compile and run the project on your local machine.

Prerequisites
A C compiler (e.g., GCC, MinGW).

Installation
Clone the repository or download the source code.

Save the code as main.c.

Open your terminal or command prompt and navigate to the project directory.

Compile and Run
To compile the source code, use the following command:

gcc main.c -o railway_reservation

To run the compiled executable:

# On Windows
.\railway_reservation.exe

# On macOS or Linux
./railway_reservation

📋 Usage Guide
The application will present a main menu upon startup. You can navigate between the User and Admin menus.

Admin Credentials
The admin login is a basic hardcoded authentication for demonstration purposes.

Username: admin

Password: admin123

👨‍💻 Author
Name: Vishant Chaudhary

LinkedIn: www.linkedin.com/in/vishant-chaudhary-c-s
Email: vishantkumar3105@gmail.com

📄 License
This project is licensed under the MIT License. See the LICENSE file for details.

⚡ "This Railway Reservation System doesn't just manage tickets — it demonstrates the power of structured programming and problem-solving in C."

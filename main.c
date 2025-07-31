#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>   
#include <ctype.h>    

// --- Constants and Macros ---
#define MAX_TRAINS 5        
#define MAX_BOOKINGS 100    
#define MAX_NAME_LEN 50     
#define MAX_LOC_LEN 30      
#define TRAIN_FILE "trains.dat"     
#define BOOKING_FILE "bookings.dat"

// --- Structure Definitions ---

// Structure to hold train details
typedef struct {
    int train_no;           
    char name[MAX_NAME_LEN]; 
    char source[MAX_LOC_LEN]; 
    char destination[MAX_LOC_LEN]; 
    float fare;             
    int total_seats;        
    int available_seats;    
} Train;

// Structure to hold passenger details for a booking
typedef struct {
    char passenger_name[MAX_NAME_LEN]; 
    int age;             
    char gender;            
} Passenger;

// Structure to hold booking details
typedef struct {
    int pnr_no;             
    int train_no;           
    Passenger passenger;    
    int seat_no;            
    int is_cancelled;       
} Booking;

// --- Global Variables ---
Train trains[MAX_TRAINS];     
int num_trains = 0;            

Booking bookings[MAX_BOOKINGS]; 
int num_bookings = 0;          
int next_pnr = 1001;            

// --- Function Prototypes ---
void admin_menu();
void user_menu();
void display_train_schedule();
void book_ticket();
void cancel_ticket();
void view_booked_tickets();
void load_data();
void save_data();
void add_train();
void display_all_bookings_admin();

// --- Main Function ---
int main() {
    
    load_data();

    int choice;
    do {
        printf("\n===== RAILWAY RESERVATION SYSTEM =====");
        printf("\n1. Admin Login");
        printf("\n2. User Menu");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                admin_menu(); 
                break;
            case 2:
                user_menu();  
                break;
            case 3:
                printf("\nExiting the system. Thank you!\n");
                save_data(); 
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3); 

    return 0; 
}

// --- Admin Functions ---

// Function for admin login
void admin_menu() {
    char username[20];
    char password[20];

    printf("\n--- Admin Login ---");
    printf("\nEnter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    // Hardcoded admin credentials for simplicity
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf("\nAdmin Login Successful!\n");
        int choice;
        do {
            printf("\n--- Admin Menu ---");
            printf("\n1. Add New Train");
            printf("\n2. View All Bookings"); 
            printf("\n3. Back to Main Menu");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    add_train(); 
                    break;
                case 2:
                    display_all_bookings_admin(); 
                    break;
                case 3:
                    printf("\nLogging out from Admin.\n");
                    break;
                default:
                    printf("\nInvalid choice. Please try again.\n");
            }
        } while (choice != 3);
    } else {
        printf("\nInvalid Username or Password. Access Denied.\n");
    }
}

// Function to add a new train to the system
void add_train() {
    if (num_trains >= MAX_TRAINS) {
        printf("\nMaximum number of trains reached. Cannot add more.\n");
        return;
    }

    printf("\n--- Add New Train ---");
    printf("\nEnter Train Number: ");
    scanf("%d", &trains[num_trains].train_no);

    // Check if train number already exists
    for (int i = 0; i < num_trains; i++) {
        if (trains[i].train_no == trains[num_trains].train_no) {
            printf("Error: Train with this number already exists. Please use a unique number.\n");
            return;
        }
    }

    printf("Enter Train Name: ");
    getchar(); 
    fgets(trains[num_trains].name, MAX_NAME_LEN, stdin);
    trains[num_trains].name[strcspn(trains[num_trains].name, "\n")] = 0; 

    printf("Enter Source Station: ");
    fgets(trains[num_trains].source, MAX_LOC_LEN, stdin);
    trains[num_trains].source[strcspn(trains[num_trains].source, "\n")] = 0;

    printf("Enter Destination Station: ");
    fgets(trains[num_trains].destination, MAX_LOC_LEN, stdin);
    trains[num_trains].destination[strcspn(trains[num_trains].destination, "\n")] = 0;

    printf("Enter Fare: ");
    scanf("%f", &trains[num_trains].fare);

    printf("Enter Total Seats: ");
    scanf("%d", &trains[num_trains].total_seats);
    trains[num_trains].available_seats = trains[num_trains].total_seats; 

    num_trains++; 
    printf("\nTrain added successfully!\n");
    save_data(); 
}

// Function for admin to view all active and cancelled bookings
void display_all_bookings_admin() {
    printf("\n--- All Bookings (Admin View) ---\n");
    if (num_bookings == 0) {
        printf("No bookings found in the system.\n");
        return;
    }

    printf("%-10s %-10s %-20s %-5s %-7s %-10s %-10s\n",
           "PNR", "Train No", "Passenger Name", "Age", "Gender", "Seat No", "Status");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_bookings; i++) {
        printf("%-10d %-10d %-20s %-5d %-7c %-10d %-10s\n",
               bookings[i].pnr_no,
               bookings[i].train_no,
               bookings[i].passenger.passenger_name,
               bookings[i].passenger.age,
               toupper(bookings[i].passenger.gender), 
               bookings[i].seat_no,
               bookings[i].is_cancelled ? "CANCELLED" : "ACTIVE");
    }
    printf("--------------------------------------------------------------------------------\n");
}


// --- User Functions ---

// Function for user menu
void user_menu() {
    int choice;
    do {
        printf("\n--- User Menu ---");
        printf("\n1. Display Train Schedule");
        printf("\n2. Book Ticket");
        printf("\n3. Cancel Ticket");
        printf("\n4. View Booked Tickets (by PNR)");
        printf("\n5. Back to Main Menu");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_train_schedule(); 
                break;
            case 2:
                book_ticket(); // 
                break;
            case 3:
                cancel_ticket(); 
                break;
            case 4:
                view_booked_tickets(); 
                break;
            case 5:
                printf("\nReturning to Main Menu.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

// Function to display the available train schedule
void display_train_schedule() {
    printf("\n--- Train Schedule ---\n");
    if (num_trains == 0) {
        printf("No trains available in the schedule. Please ask admin to add trains.\n");
        return;
    }

    printf("%-10s %-20s %-15s %-15s %-10s %-10s\n",
           "Train No", "Train Name", "Source", "Destination", "Fare", "Available");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_trains; i++) {
        printf("%-10d %-20s %-15s %-15s %-10.2f %-10d\n",
               trains[i].train_no,
               trains[i].name,
               trains[i].source,
               trains[i].destination,
               trains[i].fare,
               trains[i].available_seats);
    }
    printf("--------------------------------------------------------------------------------\n");
}

// Function to book a new ticket
void book_ticket() {
    if (num_trains == 0) {
        printf("\nNo trains available to book. Please check the schedule later.\n");
        return;
    }
    if (num_bookings >= MAX_BOOKINGS) {
        printf("\nMaximum number of bookings reached. Cannot make more bookings.\n");
        return;
    }

    display_train_schedule(); 

    int desired_train_no;
    printf("\n--- Book Ticket ---");
    printf("\nEnter Train Number you wish to book: ");
    scanf("%d", &desired_train_no);

    int train_idx = -1; 
    for (int i = 0; i < num_trains; i++) {
        if (trains[i].train_no == desired_train_no) {
            train_idx = i;
            break;
        }
    }

    if (train_idx == -1) {
        printf("\nTrain with number %d not found.\n", desired_train_no);
        return;
    }

    if (trains[train_idx].available_seats <= 0) {
        printf("\nSorry, no seats available on Train %d (%s).\n",
               trains[train_idx].train_no, trains[train_idx].name);
        return;
    }

    // Collect passenger details
    printf("\nEnter Passenger Name: ");
    getchar(); // Consume newline
    fgets(bookings[num_bookings].passenger.passenger_name, MAX_NAME_LEN, stdin);
    bookings[num_bookings].passenger.passenger_name[strcspn(bookings[num_bookings].passenger.passenger_name, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &bookings[num_bookings].passenger.age);
    if (bookings[num_bookings].passenger.age <= 0 || bookings[num_bookings].passenger.age > 120) {
        printf("Invalid age. Booking failed.\n");
        return;
    }

    printf("Enter Gender (M/F/O): ");
    getchar(); 
    scanf("%c", &bookings[num_bookings].passenger.gender);
    bookings[num_bookings].passenger.gender = toupper(bookings[num_bookings].passenger.gender);
    if (bookings[num_bookings].passenger.gender != 'M' &&
        bookings[num_bookings].passenger.gender != 'F' &&
        bookings[num_bookings].passenger.gender != 'O') {
        printf("Invalid gender. Please enter M, F, or O. Booking failed.\n");
        return;
    }

    // Assign PNR, train number, and seat
    bookings[num_bookings].pnr_no = next_pnr++;
    bookings[num_bookings].train_no = desired_train_no;
    bookings[num_bookings].seat_no = trains[train_idx].total_seats - trains[train_idx].available_seats + 1; // Simple seat assignment
    bookings[num_bookings].is_cancelled = 0; // Not cancelled

    trains[train_idx].available_seats--; 

    printf("\nTicket booked successfully!");
    printf("\nYour PNR Number: %d", bookings[num_bookings].pnr_no);
    printf("\nTrain: %s (Train No: %d)", trains[train_idx].name, trains[train_idx].train_no);
    printf("\nPassenger: %s", bookings[num_bookings].passenger.passenger_name);
    printf("\nSeat Number: %d", bookings[num_bookings].seat_no);
    printf("\nFare: %.2f\n", trains[train_idx].fare);

    num_bookings++; // Increment the count of bookings
    save_data(); // Save data immediately after booking
}

// Function to cancel an existing ticket
void cancel_ticket() {
    if (num_bookings == 0) {
        printf("\nNo tickets have been booked yet.\n");
        return;
    }

    int pnr_to_cancel;
    printf("\n--- Cancel Ticket ---");
    printf("\nEnter PNR Number to cancel: ");
    scanf("%d", &pnr_to_cancel);

    int booking_idx = -1;
    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].pnr_no == pnr_to_cancel && bookings[i].is_cancelled == 0) {
            booking_idx = i;
            break;
        }
    }

    if (booking_idx == -1) {
        printf("\nBooking with PNR %d not found or already cancelled.\n", pnr_to_cancel);
        return;
    }

    // Mark as cancelled
    bookings[booking_idx].is_cancelled = 1;

    // Increment available seats for the corresponding train
    int train_idx = -1;
    for (int i = 0; i < num_trains; i++) {
        if (trains[i].train_no == bookings[booking_idx].train_no) {
            train_idx = i;
            break;
        }
    }

    if (train_idx != -1) {
        trains[train_idx].available_seats++;
    } else {
        printf("Warning: Associated train not found for PNR %d. Seat count not updated.\n", pnr_to_cancel);
    }

    printf("\nTicket with PNR %d cancelled successfully!\n", pnr_to_cancel);
    save_data(); // Save data immediately after cancellation
}

// Function to view a booked ticket by PNR number
void view_booked_tickets() {
    if (num_bookings == 0) {
        printf("\nNo tickets have been booked yet.\n");
        return;
    }

    int pnr_to_view;
    printf("\n--- View Booked Ticket ---");
    printf("\nEnter PNR Number to view: ");
    scanf("%d", &pnr_to_view);

    int found = 0;
    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].pnr_no == pnr_to_view) {
            found = 1;
            printf("\n--- Ticket Details for PNR %d ---\n", pnr_to_view);
            printf("Train Number: %d\n", bookings[i].train_no);

            // Find train name
            char train_name[MAX_NAME_LEN] = "N/A";
            for (int j = 0; j < num_trains; j++) {
                if (trains[j].train_no == bookings[i].train_no) {
                    strcpy(train_name, trains[j].name);
                    break;
                }
            }
            printf("Train Name: %s\n", train_name);
            printf("Passenger Name: %s\n", bookings[i].passenger.passenger_name);
            printf("Age: %d\n", bookings[i].passenger.age);
            printf("Gender: %c\n", toupper(bookings[i].passenger.gender));
            printf("Seat Number: %d\n", bookings[i].seat_no);
            printf("Status: %s\n", bookings[i].is_cancelled ? "CANCELLED" : "ACTIVE");
            printf("--------------------------------------\n");
            break;
        }
    }

    if (!found) {
        printf("\nBooking with PNR %d not found.\n", pnr_to_view);
    }
}

// --- File Handling Functions ---

// Function to load train and booking data from files
void load_data() {
    FILE *train_fp = fopen(TRAIN_FILE, "rb"); 
    if (train_fp == NULL) {
        printf("No existing train data found. Starting fresh.\n");
    } else {
        // Read the number of trains first
        fread(&num_trains, sizeof(int), 1, train_fp);
        // Read train data into the array
        fread(trains, sizeof(Train), num_trains, train_fp);
        fclose(train_fp);
        printf("Train data loaded successfully.\n");
    }

    FILE *booking_fp = fopen(BOOKING_FILE, "rb"); 
    if (booking_fp == NULL) {
        printf("No existing booking data found. Starting fresh.\n");
    } else {
        // Read the number of bookings first
        fread(&num_bookings, sizeof(int), 1, booking_fp);
        // Read booking data into the array
        fread(bookings, sizeof(Booking), num_bookings, booking_fp);
        // Find the next available PNR number based on loaded bookings
        for (int i = 0; i < num_bookings; i++) {
            if (bookings[i].pnr_no >= next_pnr) {
                next_pnr = bookings[i].pnr_no + 1;
            }
        }
        fclose(booking_fp);
        printf("Booking data loaded successfully.\n");
    }
}

// Function to save train and booking data to files
void save_data() {
    FILE *train_fp = fopen(TRAIN_FILE, "wb"); 
    if (train_fp == NULL) {
        printf("Error: Could not open train data file for writing.\n");
        return;
    }
    // Write the number of trains first
    fwrite(&num_trains, sizeof(int), 1, train_fp);
    // Write train data from the array
    fwrite(trains, sizeof(Train), num_trains, train_fp);
    fclose(train_fp);
    printf("Train data saved successfully.\n");

    FILE *booking_fp = fopen(BOOKING_FILE, "wb"); 
    if (booking_fp == NULL) {
        printf("Error: Could not open booking data file for writing.\n");
        return;
    }
    // Write the number of bookings first
    fwrite(&num_bookings, sizeof(int), 1, booking_fp);
    // Write booking data from the array
    fwrite(bookings, sizeof(Booking), num_bookings, booking_fp);
    fclose(booking_fp);
    printf("Booking data saved successfully.\n");
}

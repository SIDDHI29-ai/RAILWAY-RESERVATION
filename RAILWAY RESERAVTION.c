#include <stdio.h>
#include <string.h>

// Global variables
char trainName[50];
int trainNumber;
char source[50];
char destination[50];
int availableSeats = 100;
int passengerCount = 0;
char passengerNames[100][50];
int passengerAges[100];
char passengerGenders[100][10];
int bookedTrainNumber[100];

void mainMenu();
void addTrain();
void bookTicket();
void cancelTicket();
void displayTrains();
void displayPassengers();

int main() {
    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;
    while (1) {
        printf("Railway Reservation System\n");
        printf("1. Add Train\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Display Trains\n");
        printf("5. Display Passengers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            addTrain();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                displayTrains();
                break;
            case 5:
                displayPassengers();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addTrain() {
    printf("Enter train name: ");
    scanf("%s", trainName);
    printf("Enter train number: ");
    scanf("%d", &trainNumber);
    printf("Enter source: ");
    scanf("%s", source);
    printf("Enter destination: ");
    scanf("%s", destination);
    printf("Train added successfully!\n");
}
void bookTicket() {
    int enteredTrainNumber;
    printf("Enter train number: ");
    scanf("%d", &enteredTrainNumber);

    if (enteredTrainNumber == trainNumber) {
        if (availableSeats > 0) {
            printf("Enter passenger name: ");
            scanf("%s", passengerNames[passengerCount]);
            printf("Enter age: ");
            scanf("%d", &passengerAges[passengerCount]);
            printf("Enter gender: ");
            scanf("%s", passengerGenders[passengerCount]);
            bookedTrainNumber[passengerCount] = enteredTrainNumber;
            availableSeats--;
            passengerCount++;
            printf("Ticket booked successfully!\n");
        } else {
            printf("No available seats.\n");
        }
    } else {
        printf("Train not found.\n");
    }
}
void cancelTicket() {
    char passengerName[50];
    int age;
    printf("Enter passenger name: ");
    scanf("%s", passengerName);
    printf("Enter age: ");
    scanf("%d", &age);

    for (int i = 0; i < passengerCount; i++) {
        if (strcmp(passengerNames[i], passengerName) == 0 && passengerAges[i] == age) {
            availableSeats++;
            printf("Ticket cancelled successfully!\n");
            // Shift remaining passengers to fill the gap
            for (int j = i; j < passengerCount - 1; j++) {
                strcpy(passengerNames[j], passengerNames[j + 1]);
                passengerAges[j] = passengerAges[j + 1];
                strcpy(passengerGenders[j], passengerGenders[j + 1]);
                bookedTrainNumber[j] = bookedTrainNumber[j + 1];
            }
            passengerCount--;
            return;
        }
    }
    printf("Ticket not found.\n");
}
void displayTrains() {
    printf("Train Name: %s\n", trainName);
    printf("Train Number: %d\n", trainNumber);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    printf("Available Seats: %d\n", availableSeats);
}

void displayPassengers() {
    for (int i = 0; i < passengerCount; i++) {
        printf("Passenger Name: %s\n", passengerNames[i]);
        printf("Age: %d\n", passengerAges[i]);
        printf("Gender: %s\n", passengerGenders[i]);
        printf("Train Number: %d\n\n", bookedTrainNumber[i]);
    }
}
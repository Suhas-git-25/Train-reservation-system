
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a reservation node
struct node {
    int reservation_id;
    char name[50];
    int seat_number;
    struct node* prev;
    struct node* next;
};

// Function to create a new node
struct node* createNode() {
    int reservation_id, seat_number;
    char name[50];

    printf("Enter Reservation ID: ");
    scanf("%d", &reservation_id);

    printf("Enter Name: ");
    scanf("%s", name);

    printf("Enter Seat Number: ");
    scanf("%d", &seat_number);

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->reservation_id = reservation_id;
    strcpy(new_node->name, name);
    new_node->seat_number = seat_number;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

// Add a new reservation at a specific position
struct node* addReservation(struct node* head) {
    struct node* new_node = createNode();
    int position;

    printf("Enter position to insert reservation: ");
    scanf("%d", &position);

    if (head == NULL) {
        return new_node;
    }

    struct node* temp = head;

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        struct node* last = head;
        while (last->next != NULL) last = last->next;
        last->next = new_node;
        new_node->prev = last;
    } else {
        new_node->next = temp;
        new_node->prev = temp->prev;
        if (temp->prev != NULL) temp->prev->next = new_node;
        temp->prev = new_node;
        if (position == 1) head = new_node;
    }

    return head;
}

// Cancel a reservation given the reservation ID
struct node* cancelReservation(struct node* head) {
    int reservation_id;

    printf("Enter Reservation ID to cancel: ");
    scanf("%d", &reservation_id);

    struct node* temp = head;

    while (temp != NULL && temp->reservation_id != reservation_id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Reservation ID %d not found.
", reservation_id);
        return head;
    }

    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp == head) head = temp->next;

    free(temp);
    printf("Reservation ID %d cancelled.
", reservation_id);

    return head;
}

// Move a reservation from one seat to another
void moveReservation(struct node* head) {
    int reservation_id, new_seat_number;

    printf("Enter Reservation ID to move: ");
    scanf("%d", &reservation_id);

    printf("Enter new Seat Number: ");
    scanf("%d", &new_seat_number);

    struct node* temp = head;

    while (temp != NULL && temp->reservation_id != reservation_id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Reservation ID %d not found.
", reservation_id);
        return;
    }

    temp->seat_number = new_seat_number;
    printf("Reservation ID %d moved to seat number %d.
", reservation_id, new_seat_number);
}

// Display the list of reservations in forward direction
void displayForward(struct node* head) {
    struct node* temp = head;
    printf("Reservations (Forward):\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Seat: %d\n", temp->reservation_id, temp->name, temp->seat_number);
        temp = temp->next;
    }
}

// Display the list of reservations in backward direction
void displayBackward(struct node* head) {
    struct node* temp = head;
    if (temp == NULL) return;

    while (temp->next != NULL) temp = temp->next;

    printf("Reservations (Backward):\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Seat: %d\n", temp->reservation_id, temp->name, temp->seat_number);
        temp = temp->prev;
    }
}

// Split the list into two lists based on odd/even seat numbers
void splitBySeatNumber(struct node* head, struct node** oddList, struct node** evenList) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->seat_number % 2 == 0) {
            *evenList = addReservation(*evenList);
        } else {
            *oddList = addReservation(*oddList);
        }
        temp = temp->next;
    }
}

// Main function to test the train reservation system
int main() {
    struct node* reservationList = NULL;
    struct node* oddList = NULL;
    struct node* evenList = NULL;

    int choice;

    do {
        printf("\nTrain Reservation System\n");
        printf("1. Add Reservation\n");
        printf("2. Cancel Reservation\n");
        printf("3. Move Reservation\n");
        printf("4. Display Reservations Forward\n");
        printf("5. Display Reservations Backward\n");
        printf("6. Split by Seat Numbers (Odd/Even)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reservationList = addReservation(reservationList);
                break;
            case 2:
                reservationList = cancelReservation(reservationList);
                break;
            case 3:
                moveReservation(reservationList);
                break;
            case 4:
                displayForward(reservationList);
                break;
            case 5:
                displayBackward(reservationList);
                break;
            case 6:
                splitBySeatNumber(reservationList, &oddList, &evenList);
                printf("Odd Seat Numbers:\n");
                displayForward(oddList);
                printf("Even Seat Numbers:\n");
                displayForward(evenList);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}

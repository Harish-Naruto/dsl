#include <iostream>
using namespace std;

// Node structure for circular doubly linked list
struct Node {
    int seatNumber;
    bool isBooked;
    string userID;
    Node* next;
    Node* prev;
    
    Node(int num) {
        seatNumber = num;
        isBooked = false;
        userID = "";
        next = nullptr;
        prev = nullptr;
    }
};

class Theater {
private:
    Node* head;
    static const int ROWS = 10;
    static const int SEATS_PER_ROW = 7;

    // Initialize the circular doubly linked list
    void createTheater() {
        head = new Node(1);
        Node* current = head;
        
        // Create remaining nodes
        for (int i = 2; i <= ROWS * SEATS_PER_ROW; i++) {
            Node* newNode = new Node(i);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        
        // Make it circular
        current->next = head;
        head->prev = current;
    }

public:
    Theater() {
        head = nullptr;
        createTheater();
    }

    // Destructor to free memory
    ~Theater() {
        if (head == nullptr) return;
        
        Node* current = head->next;
        while (current != head) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        delete head;
    }

    void displaySeats() {
        if (!head) return;
        
        cout << "\n------------------- SCREEN THIS WAY -------------------\n\n";
        Node* current = head;
        int count = 0;

        do {
            // Print seat number with leading zero for single digits
            if (current->seatNumber < 10)
                cout << "S0" << current->seatNumber << ":";
            else
                cout << "S" << current->seatNumber << ":";

            // Show booking status
            cout << (current->isBooked ? "[X]" : "[ ]") << " ";
            count++;

            // New line after each row
            if (count % SEATS_PER_ROW == 0)
                cout << endl;

            current = current->next;
        } while (current != head);
        
        cout << endl;
    }

    void bookSeat() {
        int seatNum;
        string id;

        cout << "\nEnter seat number (1-70): ";
        cin >> seatNum;

        if (seatNum < 1 || seatNum > ROWS * SEATS_PER_ROW) {
            cout << "Invalid seat number!\n";
            return;
        }

        // Find the seat
        Node* current = head;
        do {
            if (current->seatNumber == seatNum) {
                if (current->isBooked) {
                    cout << "Seat already booked!\n";
                    return;
                }

                cout << "Enter your ID: ";
                cin >> id;

                current->isBooked = true;
                current->userID = id;
                cout << "Seat " << seatNum << " booked successfully!\n";
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void cancelBooking() {
        int seatNum;
        string id;

        cout << "\nEnter seat number to cancel (1-70): ";
        cin >> seatNum;

        if (seatNum < 1 || seatNum > ROWS * SEATS_PER_ROW) {
            cout << "Invalid seat number!\n";
            return;
        }

        // Find the seat
        Node* current = head;
        do {
            if (current->seatNumber == seatNum) {
                if (!current->isBooked) {
                    cout << "Seat not booked!\n";
                    return;
                }

                cout << "Enter your ID: ";
                cin >> id;

                if (current->userID != id) {
                    cout << "Wrong ID! Cannot cancel booking.\n";
                    return;
                }

                current->isBooked = false;
                current->userID = "";
                cout << "Booking cancelled successfully!\n";
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void showAvailable() {
        if (!head) return;

        cout << "\n-------- Available Seats --------\n";
        Node* current = head;
        int count = 0;

        do {
            if (!current->isBooked) {
                if (current->seatNumber < 10)
                    cout << "S0" << current->seatNumber << " ";
                else
                    cout << "S" << current->seatNumber << " ";
                count++;
                if (count % SEATS_PER_ROW == 0)
                    cout << endl;
            }
            current = current->next;
        } while (current != head);
        
        cout << endl;
    }
};

int main() {
    Theater theater;
    char choice;

    do {
        cout << "\n=== MOVIE THEATER BOOKING SYSTEM ===\n";
        cout << "1. View All Seats\n";
        cout << "2. View Available Seats\n";
        cout << "3. Book Seat\n";
        cout << "4. Cancel Booking\n";
        cout << "5. Exit\n";
        cout << "Enter choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case '1':
                theater.displaySeats();
                break;
            case '2':
                theater.showAvailable();
                break;
            case '3':
                theater.bookSeat();
                break;
            case '4':
                theater.cancelBooking();
                break;
            case '5':
                cout << "Thank you for using our system!\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    } while (true);

    return 0;
}
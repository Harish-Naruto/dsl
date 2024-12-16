#include <iostream>
#include <iomanip>
using namespace std;

// Time class to handle time operations
class Time {
public:
    int hours;
    int minutes;
    
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}
    
    bool operator<(const Time& other) const {
        return (hours * 60 + minutes) < (other.hours * 60 + other.minutes);
    }
    
    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes;
    }
    
    // Convert time to minutes for easy comparison
    int toMinutes() const {
        return hours * 60 + minutes;
    }
    
    // Add minutes to time
    Time addMinutes(int mins) const {
        int totalMins = hours * 60 + minutes + mins;
        return Time(totalMins / 60, totalMins % 60);
    }
    
    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes;
    }
};

// Appointment node structure
struct Appointment {
    Time startTime;
    Time endTime;
    string patientName;
    Appointment* next;
    
    Appointment(Time start, Time end, string name)
        : startTime(start), endTime(end), patientName(name), next(nullptr) {}
};

class AppointmentScheduler {
private:
    Appointment* head;
    Time dayStart;
    Time dayEnd;
    int minDuration;
    int maxDuration;
    
public:
    AppointmentScheduler(Time start, Time end, int minDur, int maxDur)
        : head(nullptr), dayStart(start), dayEnd(end),
          minDuration(minDur), maxDuration(maxDur) {}
    
    // Display all free time slots
    void displayFreeSlots() {
        cout << "\nAvailable Time Slots:\n";
        Time current = dayStart;
        Appointment* temp = head;
        
        while (current < dayEnd) {
            // If no more appointments or current time is before next appointment
            if (temp == nullptr || current < temp->startTime) {
                Time slotEnd = (temp == nullptr) ? dayEnd : temp->startTime;
                int duration = slotEnd.toMinutes() - current.toMinutes();
                
                if (duration >= minDuration) {
                    current.display();
                    cout << " - ";
                    slotEnd.display();
                    cout << " (Duration: " << duration << " minutes)\n";
                }
                
                if (temp == nullptr) break;
                current = temp->endTime;
            } else {
                current = temp->endTime;
                temp = temp->next;
            }
        }
    }
    
    // Book a new appointment
    bool bookAppointment(Time start, int duration, string name) {
        // Validate time bounds
        if (start < dayStart || start.addMinutes(duration) > dayEnd) {
            cout << "Appointment time out of working hours!\n";
            return false;
        }
        
        // Validate duration
        if (duration < minDuration || duration > maxDuration) {
            cout << "Invalid appointment duration!\n";
            return false;
        }
        
        Time end = start.addMinutes(duration);
        
        // Check for conflicts
        Appointment* current = head;
        Appointment* prev = nullptr;
        
        while (current != nullptr && current->startTime < end) {
            if (!(end <= current->startTime || start >= current->endTime)) {
                cout << "Time slot not available!\n";
                return false;
            }
            if (current->startTime < start) {
                prev = current;
                current = current->next;
            } else {
                break;
            }
        }
        
        // Create new appointment
        Appointment* newAppointment = new Appointment(start, end, name);
        
        // Insert in sorted position
        if (prev == nullptr) {
            newAppointment->next = head;
            head = newAppointment;
        } else {
            newAppointment->next = prev->next;
            prev->next = newAppointment;
        }
        
        cout << "Appointment booked successfully!\n";
        return true;
    }
    
    // Cancel an appointment
    bool cancelAppointment(string name, Time start) {
        Appointment* current = head;
        Appointment* prev = nullptr;
        
        while (current != nullptr) {
            if (current->patientName == name && current->startTime == start) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Appointment cancelled successfully!\n";
                return true;
            }
            prev = current;
            current = current->next;
        }
        
        cout << "Appointment not found!\n";
        return false;
    }
    
    // Sort appointments based on time (using pointer manipulation)
    void sortAppointments() {
        if (head == nullptr || head->next == nullptr) return;
        
        bool swapped;
        Appointment* ptr1;
        Appointment* lptr = nullptr;
        
        do {
            swapped = false;
            ptr1 = head;
            
            while (ptr1->next != lptr) {
                if (ptr1->startTime < ptr1->next->startTime) {
                    // Swap nodes
                    Time tempStart = ptr1->startTime;
                    Time tempEnd = ptr1->endTime;
                    string tempName = ptr1->patientName;
                    
                    ptr1->startTime = ptr1->next->startTime;
                    ptr1->endTime = ptr1->next->endTime;
                    ptr1->patientName = ptr1->next->patientName;
                    
                    ptr1->next->startTime = tempStart;
                    ptr1->next->endTime = tempEnd;
                    ptr1->next->patientName = tempName;
                    
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
    
    // Display all appointments
    void displayAppointments() {
        cout << "\nCurrent Appointments:\n";
        Appointment* temp = head;
        while (temp != nullptr) {
            temp->startTime.display();
            cout << " - ";
            temp->endTime.display();
            cout << " : " << temp->patientName << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Initialize scheduler (9 AM to 5 PM, min 15 mins, max 60 mins)
    AppointmentScheduler scheduler(Time(9,0), Time(17,0), 15, 60);
    
    int choice;
    do {
        cout << "\n=== Appointment Scheduler ===\n";
        cout << "1. Display Free Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Display All Appointments\n";
        cout << "5. Sort Appointments\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                scheduler.displayFreeSlots();
                break;
                
            case 2: {
                int h, m, duration;
                string name;
                cout << "Enter appointment time (hours minutes): ";
                cin >> h >> m;
                cout << "Enter duration (minutes): ";
                cin >> duration;
                cout << "Enter patient name: ";
                cin >> name;
                scheduler.bookAppointment(Time(h,m), duration, name);
                break;
            }
                
            case 3: {
                string name;
                int h, m;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter appointment time (hours minutes): ";
                cin >> h >> m;
                scheduler.cancelAppointment(name, Time(h,m));
                break;
            }
                
            case 4:
                scheduler.displayAppointments();
                break;
                
            case 5:
                scheduler.sortAppointments();
                cout << "Appointments sorted!\n";
                break;
                
            case 6:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    
    return 0;
}
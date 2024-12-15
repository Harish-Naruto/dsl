#include <iostream>
using namespace std;

class JobQueue {
private:
    static const int MAX_SIZE = 10;
    int queue[MAX_SIZE];
    int front, rear;

public:
    JobQueue() {
        front = rear = -1;  // Initialize empty queue
    }

    // Add a job to queue
    void addJob(int jobId) {
        if (rear >= MAX_SIZE - 1) {
            cout << "Queue is full! Cannot add more jobs.\n";
            return;
        }

        if (front == -1) {  // If queue is empty
            front = 0;
        }

        queue[++rear] = jobId;
        cout << "Job " << jobId << " added to queue.\n";
    }

    // Remove a job from queue
    void removeJob() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty! No jobs to remove.\n";
            return;
        }

        cout << "Job " << queue[front] << " removed from queue.\n";
        front++;

        // Reset queue if empty
        if (front > rear) {
            front = rear = -1;
        }
    }

    // Display all jobs
    void displayJobs() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty! No jobs to display.\n";
            return;
        }

        cout << "Current jobs in queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    JobQueue jobs;
    int choice, jobId;

    do {
        cout << "\n=== Job Queue System ===";
        cout << "\n1. Add Job";
        cout << "\n2. Remove Job";
        cout << "\n3. Display Jobs";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> jobId;
                jobs.addJob(jobId);
                break;

            case 2:
                jobs.removeJob();
                break;

            case 3:
                jobs.displayJobs();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
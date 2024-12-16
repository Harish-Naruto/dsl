#include<iostream>
#include<string>

using namespace std;

struct node{
    int seatnumber;
    bool isbooked;
    string id;
    node *next;
    node *prev;
    node(int x){
        seatnumber = x;
        isbooked = false;
        id = "";
        next = nullptr;
        prev = nullptr;
    }

};

class theater{
    node *head;
    int row = 10;
    int col = 7;

    public:

    theater(){
        head = nullptr;
        createlist();
    }
     ~theater() {
        if (head == nullptr) return;
        
        node* current = head->next;
        while (current != head) {
            node* next = current->next;
            delete current;
            current = next;
        }
        delete head;
    }

    void createlist(){
        head = new node(1);
        node *current = head;
        for(int i = 2; i<=70 ; i++){
            node *newnode = new node(i);
            current->next = newnode;
            newnode->prev = current;
            current = current->next;
        }
        current->next = head;
        head->prev = current;
    }

    void display(){
        if(!head){
            return;
        }

        cout<<"\n---------------------screen------------------\n";
        node *current = head;
        int count = 0;

        do{
            if(current->isbooked){
                cout<<"S"<<current->seatnumber<<":[X] ";
            }else{
                cout<<"S"<<current->seatnumber<<":[ ] ";
            }
            count++;
            if(count%7==0){
                cout<<endl;
            }
            current = current->next;
        }while(current!=head);
        cout<<endl;
    }

    void bookseat(){
        int x;
        string temp;
        node *current = head;
        cout<<"Enter the seat number (1-70) : ";
        cin>>x;

        if(x<1 || x>70){
            cout<<"enter valid seat number!!";
            return;
        }

        do{
            if(current->seatnumber == x){
                if(current->isbooked){
                    cout<<"seat is already booked"<<endl;
                    return;
                }else{
                    cout<<"enter name: ";
                    cin>>temp;
                    current->id = temp;
                    current->isbooked=true;
                    cout<<"seat "<<x<<" is booked"<<endl;
                    return;
                }
            }
            current = current->next;
        }while(current!=head);
    }

    void cancel(){
        int x;
        string tempid;
        node *current = head;
        cout<<"enter the seat number: ";
        cin>>x;

        if(x<1 || x>70){
            cout<<"enter valid seat number"<<endl;
            return;
        }

        do{
            if(current->seatnumber == x){
                cout<<"enter your name: ";
                cin>>tempid;
                if(tempid != current->id){
                    cout<<"Wrong id cannot cancle booking"<<endl;
                    return;
                }
                current->isbooked=false;
                current->id = "";
                cout<<"booking is cancelled successfully"<<endl;
                return;
            }
           current = current->next;
        }while(current!=head);
    }

    void available(){
        node *current = head;
        int count = 0;
        do{
            if(!(current->isbooked)){
                cout<<"S"<<current->seatnumber<<" ";
            }
            count++;
            if(count%7 == 0){
                cout<<endl;
            }
            current = current->next;
        }while(current!=head);
        
    }

};

int main(){
    theater th;
    int choice;
    do{
        cout << "\n=== MOVIE THEATER BOOKING SYSTEM ===\n";
        cout << "1. View All Seats\n";
        cout << "2. View Available Seats\n";
        cout << "3. Book Seat\n";
        cout << "4. Cancel Booking\n";
        cout << "5. Exit\n";
        cout << "Enter choice (1-5): ";
        cin>>choice;
        switch(choice){
            case 1:
                th.display();
                break;
            case 2:
                th.available();
                break;
            case 3:
                th.bookseat();
                break;
            case 4:
                th.cancel();
                break;
            case 5:
                return 0;
            default:
                cout<<"Invalid choice!!\n";
        }
    }while(choice!=5);
    return 0;
}

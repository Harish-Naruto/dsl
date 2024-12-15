#include<iostream>
using namespace std;

#define max 10

class jobqueue{
    private:
    int queue[max];
    int front,rare;
    public:
	
    jobqueue(){
        front = -1;
        rare = -1;
    }

    bool isfull(){
        if(rare >= max-1 ){
            return true;
        }
        return false;
    }
    
    bool isempty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    void insert(int x){
        if(isfull()){
          cout<<"stack is full"<<endl;  
          return;
        }
        if(isempty()){
            front = 0;
        }
        rare++;
        queue[rare]=x;
        cout<<"it is inserted inside the queue"<<endl;

    }

    void reomve(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        front++;
        cout<<"element is deleted from the queue"<<endl;
    }

    void display(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        for(int i  = front; i<=rare ; i++){
            cout<<queue[i]<<" ";
        }
    }

    
};

int main(){
    jobqueue q;
    int choice;
    int x;

    do{
		cout << "\n 1.Insert Job\n 2.Delete Job\n 3.Display\n 4.Exit\n Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"enter the element you want to insert: ";
                cin>>x;
                q.insert(x);
                break;
            case 2: q.reomve();
                break;
            case 3: q.display();
                break;
            case 4: 
            cout<<"\nexisting from program";
        }        
    }while(choice!=4);
    return 0;
}
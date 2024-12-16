#include<iostream>
#include<string>
using namespace std;

#define max 100

class stack{
    private:
    char st[max];
    int top;
    public:
    stack(){
        top = -1;
    }

    bool isempty(){
        if(top == -1){
            return true;
        }
        return false;
    }
    
    bool isfull(){
        if(top >= max){
            return true;
        }
        return false;
    }

    void push(char x){
        if(isfull()){
            cout<<"stack is full"<<endl;
            return;
        }
        top++;
        st[top]=x;

    }

    void pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        top--;
    }
    char top_st(){
        return st[top];
    }


};

int main(){
    string s;
    stack stk;
    cout<<"Enter the expression to check: ";
    cin>>s;
    if(s[0]==')' || s[0]=='}' || s[0]==']'){
        cout<<"\n Invalid Expression..."<<endl;
        return 0;
    }
    
    for(int i = 0 ; i < s.size(); i++){
        if(stk.isempty() || s[i] == '(' || s[i] == '{' || s[i] == '['){
            stk.push(s[i]);
        }else if((stk.top_st()=='{' && s[i]=='}') || (stk.top_st()=='(' && s[i]==')') || (stk.top_st()=='[' && s[i]==']')){
            stk.pop();
        }else{
            cout<<"\n Invalid Expression..."<<endl;
            return 0;
        }
    }

    if(stk.isempty()){
        cout<<"\n Valid expression.."<<endl;
        return 0;
    }
    cout<<"\n Invalid Expression..."<<endl;
    return 0;
    
}
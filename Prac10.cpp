#include<iostream>
#include<cctype>
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

    void push(char c){
        if(top >= max){
            cout<<"stack is full"<<endl;
            return;
        }
        top++;
        st[top] = c;
    }

    char pop(){
        char c = st[top];
        top--;
        return c;
    }

    string reverse(){
        string temp = "";
        while(top>=0){
            temp = temp + pop();
        }
        return temp;
    }



};

string convert(string s){
    string temp = "";
    for(int i = 0; i < s.size() ; i++){
        if(isalnum(s[i])){
            char c = tolower(s[i]);
            temp = temp + c;
        }
    }
    return temp;
}
 int main(){
    stack stk;
    string s;
    cout<<"Enter the string to be reversed ans check it for palindrome : ";
    getline(cin,s);
    s = convert(s);
    cout<<"the converted string is : "<<s<<endl;
    for(int i = 0 ; i < s.size() ; i++){
        stk.push(s[i]);
    }
    string rev = stk.reverse();
    if(rev == s){
        cout<<"striing is palindrom"<<endl;
        return 0;
    }
    cout<<"string is not plaindrom"<<endl;
    return 0;
 }
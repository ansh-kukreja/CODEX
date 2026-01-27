#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int top;
        int *arr;

    Stack(int s){
        size = s;
        arr = new int[s];
        top = -1;
    }
    
    void push(int element){
        if(top+1 >= size){
            cout<<"Stack OverFlowed"<<endl;
        }
        else{
            top++;
            arr[top] = element;
        }
    }

    void pop(){
        if(top == -1){
            cout<<"Stack is empty broo!"<<endl;
        }
        else{
            top--;
        }
    }

    void peek(){
        if(top == -1){
            cout<<"Stack is empty broo!"<<endl;
        }
        else{
            cout<<arr[top]<<endl;
        }
    }

    void isEmpty(){
        bool x = top == -1 ? true : false;
        cout<<x<<endl;
    }

    void printStack(){
        for(int i=top; i>=0; i--){
            cout<<"| "<<arr[i]<<" |"<<endl;
        }
        cout<<"\\____/"<<endl;
    }
        
};

int main(){
    Stack sx(4);

    sx.push(47);
    sx.push(94);
    sx.push(65);
    sx.push(96);

    sx.printStack();

    // sx.peek();
    // sx.pop();
    // sx.isEmpty();
    // sx.printStack();
}
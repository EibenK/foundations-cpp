#include<iostream>
#include<cstring>
using namespace std;

/*
Creates a stack implementation in C++

Notes for code review:
    - Add try and catch next steps
    - Use pointers/references instead of passing by value
    - include git tagging (semantic versions)
    - make use of header files
    - abstraction/virtual functions for similiar datastructures(dequeues, circular, tailend,...)
    - operator overloading
    - comments explaining each function
*/

class Stack{
    private:
        int length;
        int capacity;
        int* stackData;

        void resize(){
            int newCapacity = capacity * 2;
            int* newStackData = new int[newCapacity];

            for(int i = 0; i < length; ++i){
                newStackData[i] = stackData[i];
            }

            delete[] stackData;
            stackData = newStackData;    
        };
    public:
        Stack(){
            capacity = 2;
            length = 0;
            stackData = new int[capacity];
        };

        ~Stack(){ delete[] stackData; };

        void push(int value){
            if(length >= capacity) resize();

            for(int i = length; i >= 0; --i)
            {   
                stackData[i] = stackData[i - 1];
            }
            stackData[0] = value;
            ++length;
        };

        void pop(){
            if(length == 0) return;

            // remove from the top of the stack(a.k.a. front of array)
            int* newStackData = new int[capacity];
            memcpy(newStackData, stackData + 1, sizeof(int) * (length - 1));
            delete[] stackData;
            stackData = newStackData; //I want to include the range to be after the first one
            --length;
        };

        bool isEmpty() const { return length == 0; };

        void clear(){
            while(!isEmpty()){
                pop();
            };
        };

        void display() {
            cout << "Data: ";
            for(int i = 0; i < length; ++i){
                cout << " " << stackData[i];
            }
            cout << endl;
        };
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display(); // 30 20 10
    s.pop();
    s.display(); // 20 10
    return 0;
    
};
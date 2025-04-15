#include<iostream>

using namespace std;

/*
Creates a queue(FIFO) implementation in C++

Notes for code review:
    - Add try and catch next steps
    - Use pointers/references instead of passing by value
    - include git tagging (semantic versions)
    - make use of header files
    - abstraction/virtual functions for similiar datastructures(dequeues, circular, tailend,...)
    - operator overloading
    - comments explaining each function
    - testing architecture
*/


class Queue{
    private:
        int length;
        int capacity;
        int* data;

        void resize(){
            int newCapacity = capacity*2;
            int* newData = new int[newCapacity];

            for(int i = 0; i < length; ++i){
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
            capacity = newCapacity;
        };

    public:

        Queue(){
            capacity = 2;
            length = 0;
            data = new int[capacity];
        };
        
        ~Queue(){
            delete[] data;
        };

        bool empty(){
            return (length == 0);
        };

        int size() const {
            return length;
        };

        int front(){
            // if nothing is in the queue, display nothing and then return -1
            if(empty()) { 
                cout << "Nothing in Queue" << endl;
                return -1; 
            }

            // return the front of the queue; back of the array.
            return data[0]; 
        };

        int back(){
            // if nothing is in the queue, display nothing and then return -1
            if(empty()){
                cout << "Nothing in Queue" << endl;
                return -1;
            }
            //return last element stored in the queue; first element in the array.
            return data[length - 1];
        };

        void push(int value){
            if(length >= capacity) resize();

            // pushing into the queue; pushing from the front of the array
            data[length++] = value;
        };

        void pop(){
            //if empty, edge case, return nothing
            if(empty()){
                return;
            }
            for(int i = 0; i < length; ++i){
                data[i - 1] = data[i];
            }
            
            length--;
        };

        void display(){
            cout << "Data: ";
            for(int i = 0; i < length; ++i){
                cout << " " << *(data + i);
            }
            cout << "\n";
        };
};



int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element in the queue: " << q.front() << endl;
    cout << "Size of the queue: " << q.size() << endl;
    q.display();
    q.pop();
    q.display();

};
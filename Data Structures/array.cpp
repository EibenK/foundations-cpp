#include<iostream>
using namespace std;

/*
Creates a resizable array in C++

Notes for code review:
    - Add try and catch next steps
    - Add additional different types of resizable member functions
    - Use pointers/references instead of passing by value

*/

class Array{
    private:
        int* data;
        int length;
        int capacity;
    
        void resize(){
            int newCapacity = capacity * 2;
            int* newData = new int[newCapacity];

            for(int i = 0; i < length; ++i){
                newData[i] = data[i];
            }
            
            delete[] data;
            data = newData;
            capacity = newCapacity;
        };

    public:

        Array(){
            length = 0;
            capacity = 2;
            data = new int[capacity];
        };

        ~Array(){
            delete[] data;
        };

        void push_back(int value){
            if(length == capacity) resize();
            data[length++] = value;
        };
        
        void pop_back(){
            if(length > 0) length--;
        };

        int size(){
            return length;
        };

        void display(){
            cout << "Data:\t";
            for(int i = 0; i < length; ++i){
                cout << data[i] << "\t"; 
            }
            cout << endl;
        };
};


int main(){
    Array a;
    
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.display();
    cout << "Size of array is: " << a.size() << endl;
    a.pop_back();
    a.display();

    return 0;
};
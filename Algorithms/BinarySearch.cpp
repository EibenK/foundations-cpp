/*
Creates binary search algorithm in C++

Notes for code review:
    - Add try and catch next steps
    - Use pointers/references instead of passing by value
    - include git tagging (semantic versions)
    - make use of header files
    - abstraction/virtual functions for similiar algorithms(Maybe?)
    - comments explaining each function
    - Edge cases
    - Test cases for different types of binary searches
*/

#include<iostream>
using namespace std;


class BinarySearch{
    private:
    public:
        // included for purpose, not needed in a only a binary search algorithm
        BinarySearch(){};
        ~BinarySearch(){};
        
        // Binary Search algorithm implementation
        bool search(const int* data, int* length, int* key){
            int left = 0, right = *length - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (data[mid] == *key) return true;
                else if (data[mid] < *key) left = mid + 1;
                else right = mid - 1;
            }
            return false;
        }

};


int main(){
    // created an array and a length for testing
    int data[8] = {1,2,3,4,5,6,7}; //sorted linear array for testing binary search
    int length = 8, key = 10;

    // create object for testing
    BinarySearch bs;
    bool result = bs.search(data, &length, &key);
    if(result) cout << "Key exists within the array.";
    else cout << "Key does not exist within the array.";


};
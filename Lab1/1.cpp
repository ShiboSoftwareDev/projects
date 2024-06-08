#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int *nums = new int[size];
    cout << "Fill in array: " << endl;
    for(int *pointer = nums; pointer < nums + size; pointer++) {
        cout << ">";
        cin >> *pointer;
    }

    int *max = nums;
    for(int *pointer = nums; pointer < nums + size; pointer++) {
        if(*pointer > *max)
            max = pointer;
    }
    cout << "Max value is " << *max << endl;
}

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

    int search;
    bool found = false;
    cout << "Enter number to search: ";
    cin >> search;

    for(int *pointer = nums; pointer < nums + size; pointer++) {
        if(*pointer == search)
            found = true;
    }
    if(found)
    cout << "Number found" << endl;
    else
    cout << "Number not found" << endl;
}

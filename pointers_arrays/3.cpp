#include <iostream>
using namespace std;

int *createIndexArray(int number) {
    int *array = new int[number];
    for(int i = 0; i < number; i++){
        array[i] = i;
    }
    return array;
}

int main() {
    cout << "Enter size of array: ";
    int size;
    cin >> size;
    int *array = createIndexArray(size);
    cout << "Your array: ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

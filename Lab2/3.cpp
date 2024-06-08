#include <iostream>
using namespace std;

struct Employee{
    int id;
    string name;
    int age;
};

int findEmployee(Employee *employees, int size, string name){
    bool found = false;
    for(int i = 0; i < size; i++){
        if(employees[i].name == name)
            return employees[i].id;
    }
    return -1;
}

int main(){
    Employee *employees = new Employee[10];
    cout << "Fill in employee information" << endl;
    for(int i = 0; i < 10; i++){
        cout << "Employee " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> employees[i].id;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Age: ";
        cin >> employees[i].age;
    }
    for(int i = 0; i < 10; i++) {
        cout << "Employee " << i + 1 << ": ID: " << employees[i].id << ", name: " << employees[i].name << ", age: " << employees[i].age << endl;
    }
    string name;
    cout << "Enter employee name: ";
    cin >> name;
    int result = findEmployee(employees, 10, name);
    if(result == -1)
        cout << "Employee not found" << endl;
    else
        cout << "Employee has id: " << result << endl;
}

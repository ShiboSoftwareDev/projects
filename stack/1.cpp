#include <iostream>
using namespace std;

struct Stack
{
    int *array;
    int capacity;
    int size = 0;
};

Stack *create(int capacity)
{
    Stack *newStack = new Stack;
    newStack -> capacity = capacity;
    newStack -> array = new int[capacity];

    return newStack;
}

void printStack(Stack *stack)
{
    int i = stack -> size -1;
    if(stack -> size == 0)
    {
        cout << "NULL" << endl;
        return;
    }
    while(i >= 0)
    {
        cout << stack -> array[i--];
    }
}

bool isEmpty(Stack *stack)
{
    if(stack -> size == 0)
        return true;
    else
        return false;
}

bool isFull(Stack *stack)
{
    return stack -> size == stack -> capacity;
}

void push(Stack *stack, int number)
{
    if(isFull(stack))
        return;
    stack -> array[ stack -> size++] = number; 
}

int pop(Stack *stack)
{
    if(!isEmpty(stack))
    return stack -> array[--stack -> size];
}

int decimalToBinary(int number)
{
    int i = number;
    int size = 0;
    while(i > 0)
    {
        i /= 2;
        size ++;
    }
    Stack *stack = create(size);
    i = number;
    while(i > 0)
    {
        if(i % 2 == 0)
            push(stack, 0);
        else
            push(stack, 1);
        i /= 2;
    }
    printStack(stack);
    return 1;
}

int main()
{
    int number;
    cout << "Enter number to convert: ";
    cin >> number;
    cout << number << " in binary is: "; 
    decimalToBinary(number);
    cout << endl;

    return 0;
}

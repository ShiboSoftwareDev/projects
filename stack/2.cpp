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
    int i = 0;
    if(stack -> size == 0)
    {
        cout << "NULL" << endl;
        return;
    }
    while(i < stack -> size)
    {
        cout << stack -> array[i++];
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

void removeDuplicate(Stack *stack)
{
    if(!(stack -> size < 1))
    for(int i = stack -> size - 1; i >= 1; i--)
    {
        
        for(int j = i - 1; j >= 0; j--)
        {
            if(stack -> array[i] == stack -> array[j])
            {
                Stack *temp = create(stack -> size - j - 1);
                for(int k = 0; k < temp -> capacity; k++)
                    push(temp, pop(stack));
                pop(stack);
                for(int k = 0; k < temp -> capacity; k++)
                    push(stack, pop(temp));
                break;
            }
        }
    }
}


int main()
{
    int input;
    Stack *stack = create(5);
    cout << "Fill in stack with number:" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "> ";
        cin >> input; 
        push(stack, input);
    }
    cout << "Your stack is: ";
    printStack(stack);
    cout << endl;
    removeDuplicate(stack);
    cout << "Your stack with no duplicated is: ";
    printStack(stack);
    cout << endl;
    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

struct Stack
{
    char *array;
    int capacity;
    int size = 0;
};

Stack *create(int capacity)
{
    Stack *newStack = new Stack;
    newStack -> capacity = capacity;
    newStack -> array = new char[capacity];

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

char pop(Stack *stack)
{
    if(!isEmpty(stack))
    return stack -> array[--stack -> size];
}

int traversal(string text)
{
    Stack *stack = create(text.length());
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == '[' || text[i] == '{' || text[i] == '(')
        {
            push(stack, text[i]);
        }
        else if(text[i] == ']' || text[i] == '}' || text[i] == ')')
        {
            if((stack -> array[stack -> size -1] == '[' && text[i] == ']') || (stack -> array[stack -> size -1] == '{' && text[i] == '}') || (stack -> array[stack -> size -1] == '(' && text[i] == ')'))
            {
                pop(stack);
            }
            else
            {
                return i + 1;
            }
        }
        
    }
    if(stack -> size != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
        
}


int main()
{   
    string filename;
    cout << "Enter file name to traverse: ";
    cin >> filename;
    ifstream file(filename);
    string str;
    while(getline(file, str))
    {
        cout << str << endl;
        int position = traversal(str);
        for(int i = 0; i < position - 1; i++)
        {
            cout << ' ';
        }
        if(position != 0)
            cout << "^" << endl << "Traversal failed" << endl;
        else
            cout << "Traversal successful" << endl;
    }
}

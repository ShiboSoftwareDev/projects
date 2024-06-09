#include <iostream>
using namespace std;

struct Data
{
    string name;
    int age;
};

struct Node
{
    Data node;
    Node *next;
    Node *prev;
};

Node *head = NULL;

void insert(Node *node)
{
   if(head == NULL)
       head = node;
   else
   {
       head -> prev = node;
       node -> next = head;
       head = node; 
   }
   cout << "Inserted" << endl;
}

void insertBefore(Node *node, string name)
{
    Node *cursor = head;
    bool found = false;
    while(cursor != NULL)
    {
        if(cursor -> node.name == name)
        {
            found = true;
            node -> next = cursor;
            node -> prev = cursor -> prev;
            
            if(cursor -> prev != NULL)
                cursor -> prev -> next = node;
            else
                head = node;
            cursor -> prev = node;
            cout << "Inserted" << endl;
            return;
        }
        cursor = cursor -> next;
    }
    if(!found)
        cout << "Node not found" << endl;
}

Node *create(string name, int age)
{
    Node *newNode = new Node;
    newNode -> node.name = name;
    newNode -> node.age = age;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void display()
{
    bool found = false;
    Node *cursor = head;
    while(cursor != NULL)
    {
        found = true;
        cout << "Name: " << cursor -> node.name << ", age: " << cursor -> node.age << endl;
        cursor = cursor -> next;
    }
    if(!found)
        cout << "Empty" << endl;
}

void deleteFirst()
{
    Node *cursor = head;
    if(head != NULL)
    {
        head = cursor -> next;
        delete cursor;
        cout << "Deleted first" << endl;
    }

}

void destroy()
{
    if(head != NULL)
    {
    while(head -> next != NULL)
    {
       head = head -> next;
       delete head -> prev;
    }
    if(head != NULL)
    {
        Node *cursor = head;
        head = NULL;
        delete cursor;
        cout << "Destroyed" << endl;
        return;
    }
    }
    cout << "Empty" << endl;
}

int main()
{
    display();
    cout << endl;
    insert(create("Ahmed", 22)); 
    insert(create("Moad", 33)); 
    insert(create("Anas", 12)); 
    insert(create("Abse", 21)); 
    display();
    cout << endl;
    insertBefore(create("Rafiq", 15), "Moad");
    insertBefore(create("Bro",23), "Bro");
    display();
    cout << endl;
    deleteFirst();
    deleteFirst();
    display();
    cout << endl;
    destroy();
    destroy();
    display();
    cout << endl;
    return 0;
}

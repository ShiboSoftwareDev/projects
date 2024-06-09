#include <iostream>
using namespace std;

struct Library
{
    string title;
    string category;
    bool isBorrowed;
};

struct Book
{
    Library data;
    Book *next;
};

Book *CreateBook(string name, string category)
{
    Book *newBook = new Book;
    newBook -> data.title = name;
    newBook -> data.category = category;
    newBook -> data.isBorrowed = false;
    newBook -> next = NULL;
    return newBook;
}

void Add (Book *&head, Book *node)
{
    node -> next = head;
    head = node;
    cout << "Added" << endl;
    return;
}

void FindByTitle(Book *&head, string title)
{
    Book *cursor = head;
    while(cursor != NULL)
    {
        if(cursor -> data.title == title)
        {
            cout << cursor -> data.title << " / ";
            cout << cursor -> data.category << " / ";
            if(cursor -> data.isBorrowed == 1)
                cout << "The book is borrowed" << endl;
            else
                cout << "The book is available" << endl;
            return;
        }
        cursor = cursor -> next;
    }
    cout << "Book not found" << endl;
}

void FindByCategory(Book *&head, string category)
{
    bool found = false;
    Book *cursor = head;
    while(cursor != NULL)
    {
        if(cursor -> data.category == category)
        {
            found = true;
            cout << cursor -> data.title << " / ";
            cout << cursor -> data.category << " / ";
            if(cursor -> data.isBorrowed == 1)
                cout << "The book is borrowed" << endl;
            else
                cout << "The book is available" << endl;
        }
        cursor = cursor -> next;
    }
    if(!found)
        cout << "Book not found" << endl;
}

void Like(Book *&head, string name)
{
    Book *cursor = head;
    bool found = false;
    while(cursor != NULL)
    {
        string &title = cursor -> data.title;
        for(int i = 0; i < title.length(); i++)
        {
            int j = 0;
            if(title[i] == name[j])
            {
                bool same = true;
                for(; j < name.length(); j++)
                {
                    if(!(title[i + j] == name[j]))
                    {
                        same = false;
                    }
                }
                if(same)
                {
                        cout << cursor -> data.title << " / ";
                        cout << cursor -> data.category << " / ";
                        if(cursor -> data.isBorrowed == 1)
                            cout << "The book is borrowed" << endl;
                        else
                            cout << "The book is available" << endl;
                  found = true;
                }
            }
        }
    cursor = cursor -> next;
    }
    if(!found)
        cout << "Book not found" << endl;
}

void Borrow(Book *&head, string name)
{
    Book *cursor = head;
    bool found = false;
    while(cursor != NULL)
    {
        if(cursor -> data.title == name)
        {
            found = true;
            if(cursor -> data.isBorrowed == 0)
            {
                cursor -> data.isBorrowed = 1;
                cout << "Borrowed" << endl;
            }
            else
                cout << "Book is already borrowed" << endl;
            break;
        }
        cursor = cursor -> next;
    }
    if(!found)
        cout << "The book was not found" << endl;
}

void Return(Book *&head, string name)
{
    bool found = false;
    Book *cursor = head;
    while(cursor != NULL)
    {
        if(cursor -> data.title == name)
        {
            found = true;
            if(cursor -> data.isBorrowed == 0)
                cout << "The book is already in the library" << endl;
            else
            {
                cursor -> data.isBorrowed = 0;
                cout << "Book returned" << endl;
            }
        }
        cursor = cursor -> next;
    }
    if(!found)
        cout << "The book was not found" << endl;
}

void Modify(Book *&head, string title)
    {
        cout << "Modifying" << endl;
        Book *cursor = head;
        while(cursor != NULL)
        {
            if(cursor -> data.title == title)
            {
                cout << "Enter new title: ";
                cin >> cursor -> data.title;
                cout << "Enter new category: ";
                cin >> cursor -> data.category;
            
                cout << "Modified" << endl;
                return;
            }
            cursor = cursor -> next;
        }
        cout << "No book was found" << endl;
    }

void Delete(Book *&head, string title)
{
    Book *cursor = head;
    Book *back = NULL;
    bool found = false;

    while(cursor != NULL)
    {
        if(cursor -> data.title == title)
        {
            found = true;
            if(back == NULL)
            {
                head = cursor -> next;
                delete cursor;
                cursor = head;
                cout << "Deleted" << endl;
            }
            else
            {
            back -> next = cursor -> next;
            delete cursor;
            cout << "Deleted" << endl;
            }
        }
        else
        {
            back = cursor;
            cursor = cursor -> next;
        }
    }
    if(!found)
        cout << "Book not found" << endl;
}

void Destroy(Book *&head)
{
    bool found = false;
    Book *current = head;
    Book *next;
    while(current != NULL)
        {
            found = true;
            next = current -> next;
            delete current;
            current = next;
        }
    head = NULL;
    if(found)
        cout << "Library destroyed" << endl;
    else
        cout << "Library already empty" << endl;
}

void Display(Book *&head)
{
    Book *cursor = head;
    bool found = false;
    while(cursor != NULL)
    {
        found = true;
        cout << cursor -> data.title << " / ";
        cout << cursor -> data.category << " / ";
        if(cursor -> data.isBorrowed == 1)
            cout << "The book is borrowed" << endl;
        else
            cout << "The book is available" << endl;
        cursor = cursor -> next;
    }
    if(!found)
        cout << "Library is empty" << endl;
}

string *Split(string text, char delimiter)
{
    int size = 1;
    for(int i = 0; i < text.length(); i++)
        if(text[i] == delimiter)
            size ++;
    if(size < 3)
        size = 3;
    string *array = new string[size];
    for(int i = 0; i < size; i++)
        array[i] = "";
    for(int i = 0, j = 0; i < text.length(); i++)
    {
        if(text[i] == delimiter){
            j++;
        }
        else
        {
            array[j] += text[i]; 
        }
    }
    return array;
}

void Excute(Book *&head, string command, string first, string second)
{
    if(command == "add")
        Add(head, CreateBook(first,second));
    else if(command == "display")
        Display(head);
    else if(command == "find" && first == "title")
        FindByTitle(head, second);
    else if(command == "find" && first == "category")
        FindByCategory(head, second);
    else if(command == "like")
        Like(head, first);
    else if(command == "borrow")
        Borrow(head, first);
    else if(command == "return")
        Return(head, first);
    else if(command == "delete")
        Delete(head, first);
    else if(command == "destroy")
        Destroy(head);
    else if(command == "modify")
        Modify(head, first);
    else if(command == "help")
    {
        cout << ">add [title] [category]:   adds a new book." << endl;
        cout << ">find title [title]:       finds a book with the exact title." << endl;
        cout << ">find category [category]: finds books with the exact category." << endl;
        cout << ">like [title]:             finds books with a similar title." << endl;
        cout << ">borrow [title]:           borrows a book." << endl;
        cout << ">return [title]:           returns a book." << endl;
        cout << ">delete [title]:           deletes a book." << endl;
        cout << ">modify [title]:           modifies a book." << endl;
        cout << ">destroy:                  deletes all books." << endl;
        cout << ">display:                  displays all books." << endl;
    }
}
    
int main()
{
    string input = "";
    string *commands;
    string command = "";
    string first = "";
    string second = "";

    Book *head = NULL;

    cout << "Enter (help) for list of commands" << endl;
    do
    {
        cout << "Enter command: ";
        getline(cin, input);
        commands = Split(input, ' ');
        command = commands[0];
        first = commands[1];
        second = commands[2];
        delete[] commands;
        Excute(head, command, first, second);

    } while(command != "exit");






    return 0;
}










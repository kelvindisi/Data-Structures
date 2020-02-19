#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *previous;
};

class List
{
private:
    struct Node *first, *last;

public:
    void print();
    void addItem(int);
    void insertItem(int, int);
    void deleteItem(int);
    void printBackward();
    bool isEmpty();
    bool isFull();
    List();
};

List::List()
{
    first = NULL;
    last = NULL;
}
void List::print()
{
    struct Node *current = NULL;

    if(first==NULL)
    {
        cout<<"Sorry the list is empty"<<endl;

    }else
    {
        current = first;
        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
}
void List::printBackward()
{

}
void List::insertItem(int val, int after)
{
    Node *new_node = new Node;
    new_node->data = val;
    new_node->next=NULL;
    Node *current = NULL;
    bool found = false;
    current = first;
    while (current != NULL && !found)
    {
        if (current->data == after)
            found = true;
        else
            current = current->next;
    }
    if (found == true)
    {
        new_node->next = current->next;
        current->next = new_node;
    }else
    {
        cout<<"Unable to find point of insertion"<<endl;
    }
}
void List::addItem(int val)
{
    struct Node *current = new Node;
    current->data = val;
    current->next = NULL;
    current->previous = NULL;

    if (first == NULL)
    {
        first=current;
        last=current;
    }else
    {
        current->previous = last;
        last->next = current;
        last = current;
    }
}
bool List::isEmpty()
{
    return (first==NULL);
}

bool List::isFull()
{
    return false;
}

void List::deleteItem(int val)
{
    struct Node *previous = NULL;
    struct Node *current = NULL;
    struct Node *temp = NULL;
    bool found;
    if (first == NULL)
    {
        cout<<"Sorry the list is empty"<<endl;
    }else if (first->data==val)
    {
        if (first == last)
        {
            current = first;
            first = NULL;
            delete current;
        }else
        {
            current = first;
            first = first->next;
            delete current;
        }
    }else{
        previous = first;
        current = first->next;
        found = false;

        while(current != NULL && !found)
        {
            if (current->data == val){
                found = true;
            }
            else{
                previous = current;
                current = current->next;
            }
        }
        if (found == false)
        {
            cout<<"The data item has not been found"<<endl;
        }else
        {
            if (current == last)
            {
                temp = last;
                last = previous;
                delete temp;
            }
            else
            {
                temp = current;
                previous->next = current->next;
                delete temp;
            }
        }

    }
}

int main(void)
{
    int input, choice;
    List myList;
    do{
        cout<<"1. Add Item\n2. Add Between \n3. Print \n4. Delete Item"
                "\n5. IsEmpty \n6. isFull\n7. Exit"
                "\nMake your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter data item: ";
            cin>>input;
            myList.addItem(input);
            break;
        case 2:
            int temp;
            cout<<"Enter the value to insert: ";
            cin>>input;
            cout<<"Value to be inserted after: ";
            cin>>temp;
            myList.insertItem(input, temp);
            break;
        case 3:
            myList.print();
            break;
        case 4:
            cout<<"Enter value to delete: ";
            cin>>input;
            myList.deleteItem(input);
            break;
        case 5:
            if (myList.isEmpty())
                cout<<"The list is empty"<<endl;
            else
                cout<<"The list is not empty"<<endl;
        case 6:
            if (myList.isFull())
                cout<<"The list is full"<<endl;
            else
                cout<<"The list is not full"<<endl;
        default:
            cout<<"You selected an invalid choice"<<endl;
        }
    }while(choice != 7);

    cout<<"*****Program terminated*****"<<endl;

    return 0;
}

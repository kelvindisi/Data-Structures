#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};


class List
{
private:
    Node *first;
public:
    List();
    void setFirst(Node *node);
    bool addItem(int);
    void print();
    Node *getFirst();
};
List::List()
{
    first = NULL;
}
bool List::addItem(int val)
{
    Node *newNode = new Node;
    if (newNode != NULL)
    {
        newNode->val = val;
        newNode->next = NULL;
        Node *current = first;

        //check if list is empty
        if (first == NULL)
        {
            first = newNode;
            return true; // created first new node
        } else
        {
            while (current->next != NULL)
                current = current->next;
            current->next = newNode;
            return true; // new node linked
        }
    }
    // new node not created
    return false;
}

void List::print()
{
    // check list if empty
    Node *current = first;
    cout<<"\n\n***********RESULT***********"<<endl;

    if (current == NULL)
    {
        cout<<"No item to print"<<endl;
    } else
    {
        while (current != NULL)
        {
            cout<<current->val<<endl;
            current = current->next;
        }

    }
    cout<<"*********END RESULT*********\n\n";
}
Node *List::getFirst()
{
    return first;
}
void List::setFirst(Node *node)
{
    if (first == NULL)
        first = node;
}


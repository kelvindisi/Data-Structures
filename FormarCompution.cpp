#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

struct Link
{
    char value;
    Link *next;
};

class Infix
{
private:
    Link *first;
public:
    Infix();
    void addItem(char);
    void print();
};

int main(void)
{
    Infix act;
    bool condit = true;
    char val;
    while(condit)
    {
        cout<<"Enter character: ";
        cin>>val;
        act.addItem(val);
        if (val == '=')
            condit = false;
    }
    act.print();

    return 0;
}


Infix::Infix()
{
    first = NULL;
}
void Infix::addItem(char val)
{
    Link *newNode = new Link();
    newNode->value= val;
    newNode->next = NULL;

    if (first == NULL)
    {
        first = newNode;
    }else
    {
        newNode->next = first;
        first = newNode;
    }
}
void Infix::print()
{
    Link *current;
    current = first;
    if (current != NULL)
    {
        do{
            cout<<current->value<< " ";
            current = current->next;
        }while(current->next != NULL);
    }
}


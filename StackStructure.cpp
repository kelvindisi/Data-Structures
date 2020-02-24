#include <iostream>

using namespace std;

struct Link
{
    char value;
    Link *next;
};

// class to handle both stack and expression
// use of list instead of array as they have limit
class Stack
{
private:
    Link *top;
public:
    Stack();
    void push(char);
    char pop();
    void addInfix(char);
    void print();
};
void captureInfix(Stack *infix)
{
    char val;
    bool exit = false;
    do
    {
        cout<<"Enter expression character: ";
        cin>>val;
        infix->addInfix(val);
        if (val == '=')
            exit = true;
    }while(!exit);
}
int main(void)
{
    Stack *_stack, *infix, *postfix = new Stack();
    //there is a logical error in line 55 -69 cant find it

    return 0;

}

Stack::Stack()
{
    top = NULL;
}
void Stack::addInfix(char val)
{
    Link *newNode = new Link();
    newNode->value = val;
    newNode->next = NULL;

    Link *current;
    current = top;

    if (current == NULL)
    {
        current  = newNode;
    }else{
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
void Stack::push(char val)
{
    //Creating a new node
    Link *current = new Link();
    if (current == NULL)
    {
        //no memory created to store value exit program
        cout<<"Memory was not created to store values"<<endl;
    }else{
        current->value = val;
        current->next = NULL;

        if (top == NULL)
        {
            top = current;
            //add first and the top node to the list
        }
        else
        {
            // join the new node with the existing list
            // current node to point to top existing node on stack
            current->next = top;
            // top node to be the current node
            top = current;
        }
    }
}

char Stack::pop()
{
    // select the item on top of stack and remove while returning it
    Link *current;
    current = top;
    char val;

    if (current != NULL)
    {
        top = current->next;
        val = current->value;
        delete current;
    }
    return val;
}

void Stack::print()
{
    //print all values in stack/list for testing
    Link *current = top;
    if (current == NULL)
    {
        cout<<"Nothing to display"<<endl;
    }else{
        bool exit = false;

        do
        {
            cout<<current->value;
            if (current->next == NULL)
                exit = true;
            else
                current = current->next;
        }while(!exit);
    }
}











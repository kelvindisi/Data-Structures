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
    void enqueue(char);
    void print();
    int createPostfix(Stack *, Stack *, Stack *);
    int addByPriority(char, Stack *);
};

void captureInfix(Stack *infix)
{
    char val;
    do
    {
        cout<<"Enter character: ";
        cin>>val;
        infix->enqueue(val);
    }while(val != '=');
}
int Stack::addByPriority(char oper, Stack *output)
{
    char _oper;
    switch(oper)
    {
    case '(':
        push(oper);
        break;
    case '*':
        push(oper);
        break;
    case '/':
        _oper = top->value;
        if (_oper == '*')
        {
            output->enqueue(_oper);
            pop();
            push(oper);
        }
        break;
    case ')':
        _oper = top->value;
        if (_oper == '*' || _oper == '+' || _oper == '/' || _oper == '-')
        {
            output->enqueue(_oper);
            pop();
            if (top->value == '(')
                pop();
            else
                return 1;
        }else if (_oper == '(')
        {
            pop();
        }
        break;
    case '+':
        _oper = top->value;
        if (_oper == '*' || _oper == '/')
        {
            output->enqueue(_oper);
            pop();
            push(oper);
        }else
        {
            push(oper);
        }
        break;
    case '-':
        _oper = top->value;
        if (_oper == '*' || _oper == '/' || _oper == '+')
        {
            output->enqueue(_oper);
            pop();
        }else
        {
            push(oper);
        }
        output->enqueue(oper);
        break;
    }
    return 0;
}
int Stack::createPostfix(Stack *infix, Stack *stack_, Stack *output)
{
    Link *current = infix->top;
    if (current == NULL)
    {
        cout<<"List is empty";
        return 1;
    }else
    {
        while(current->value != '=')
        {
            char val = current->value;
            if (isdigit(val))
            {
                output->enqueue(val);
            }else //value is not a digit
            {
                if (top == NULL) //no other operator in stack push
                {
                    push(val);
                }else
                {
                    //shortening this function

                    if (addByPriority(val, output)) //return zero if no problem
                    {
                        cout<<"There is an error with your expression"<<endl;
                    }
                }
            }
            current = current->next;
        } // end while loop
        // check for signs remaining in stack and display
        char oper;
        while (top != NULL)
        {
            oper = top->value;
            if (oper != '(')
                output->enqueue(oper);
            pop();
        }
        return 0;
    }
}
int main(void)
{
    Stack *infix = new Stack();
    Stack *stack_ = new Stack();
    Stack *output = new Stack();
    //unchecked memory error that may occur

    captureInfix(infix);
    stack_->createPostfix(infix, stack_, output);

    cout<<"postfix expression"<<endl;
    output->print();
}

Stack::Stack()
{
    top = NULL;
}
void Stack::enqueue(char val)
{
    Link *newNode = new Link();
    newNode->value = val;
    newNode->next = NULL;

    Link *current;
    current = top;

    if (newNode == NULL)
    {
        //memory not created exit program
        cout<<"Unable to store value"<<endl;
    }else
    {
        if (current == NULL)
        {
            top = newNode;
        }else
        {
            while(current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
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











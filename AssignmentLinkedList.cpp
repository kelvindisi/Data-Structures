#include <iostream>
#include "List.cpp"

using namespace std;

void chooseAction(int choice, List *list1, List *list2);
void appendList(List *list1, List *list2);

int main(void)
{
    List *list1 = new List;
    List *list2 = new List;
    int choice;
    do {
        cout<<"Add Item: \n1. List 1 \n2. List 2 \n"
            <<"Print Items: \n3. List 1 \n4. List 2 \n"
            <<"5. Compare List \n6. Append List 2 to List 1 \n"
            <<"7. Exit \n";
        cin>>choice;

        chooseAction(choice, list1, list2);
    }while(choice != 7);


    return 0;
}
int getInput()
{
    int input;
    cout<<"Enter value to store: ";
    cin>>input;
    cout<<endl;
    return input;
}
bool storeValue(int val, List *storeList)
{
    return storeList->addItem(val);
}
void printMessage(string message)
{
    cout<<message<<endl;
}
bool checkContinuity(Node *node1, Node *node2)
{
    if (node1 == NULL || node2 == NULL)
    {
        return false;
    }
    return true;
}
bool validateEquality(Node *node1, Node *node2)
{
    bool val_equal = true;
    Node *cur_one = node1;
    Node *cur_two = node2;

    while(cur_one != NULL && cur_two != NULL)
    {
        cout<<cur_one->val<<"\t\t"<<cur_two->val<<"\t\t";
        if (cur_one->val == cur_two->val)
            cout<<"Equal"<<endl;
        else {
            cout<<"Not Equal"<<endl;
            val_equal = false;
        }
        cur_one = cur_one->next;
        cur_two = cur_two->next;
    }
    // if both list were traversed to the end
    if (cur_one != NULL || cur_two != NULL)
    {
        printMessage("One List contains more item than the other");
        val_equal = false;
    }

    return val_equal;

}
void compareList(List *list1, List *list2)
{
    Node *list1Current = list1->getFirst();
    Node *list2Current = list2->getFirst();
    bool continueCheck = true;
    printMessage("\n***************COMPARISON RESULT***************");
    if (list1Current == NULL && list2Current == NULL)
    {
        printMessage("Nothing to compare, both lists are empty");
        continueCheck = false;
    } else if (list1Current == NULL || list2Current == NULL)
    {
        printMessage("List are not equal, one list is empty");
        continueCheck = false;
    }
    if (continueCheck)
    {
        printMessage("List 1\t\tList 2\t\tMessage");
        if (validateEquality(list1Current, list2Current))
            cout<<"Both list are equal"<<endl;
        else
            cout<<"The list are not equal"<<endl;
    }
    printMessage("***************END OF COMPARISON***************\n");
}
void chooseAction(int choice, List *list1, List *list2)
{
    switch(choice)
    {
    case 1:
        storeValue(getInput(), list1);
        break;
    case 2:
        storeValue(getInput(), list2);
        break;
    case 3:
        list1->print();
        break;
    case 4:
        list2->print();
        break;
    case 5: //comparing list
        compareList(list1, list2);
        break;
    case 6:
        //to implement this, append list 2 to 1 and remove items in list 2
        appendList(list1, list2);
        break;
    case 7:
        cout<<"********BYE BYE********"<<endl;
        break;
    default:
        cout<<"Invalid choice, try again..."<<endl;
    }
}
void appendList(List *list1, List *list2)
{
    Node *cur_one = list1->getFirst();
    Node *cur_two = list2->getFirst();

    if (cur_two != NULL)
    {
        if (cur_one == NULL)
        {
            cur_one = cur_two;
            cur_two = NULL;
        }
        return;
    }
    printMessage("List two has no items that can be appended on list 1");
}

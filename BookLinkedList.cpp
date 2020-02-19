#include<iostream>
#include<string.h>

using namespace std;

struct Book
{
    char *author, *title;
    float price;
    Book *next, *previous;
};

class BookList
{
private:
    Book *first, *last;

public:
    void print();
    void addItem(char *, char *);
    //void deleteItem(int);
    bool isEmpty();
    bool isFull();
    BookList();
};

BookList::BookList()
{
    first = NULL;
    last = NULL;
}
bool BookList::isFull()
{
    return false;
}
bool BookList::isEmpty()
{
    return (first == NULL);
}
void BookList::print()
{
    struct Book *current;
    if (first == NULL)
        cout<<"There is no book to display"<<endl;
    else
    {
        current = first;
        while (current->next != NULL)
        {
            cout<<"Title: "<<current->title
                <<"Author: "<<current->author<<endl;
            current = current->next;
        }
    }
}
void BookList::addItem(char *auth, char *tit)
{
    struct Book *current = new Book;
    strcpy(current->author, auth);
    strcpy(current->title, tit);

    if (first == NULL)
    {
        first = current;
        last = current;
    }else
    {
        last->next = current;
        last = current;
    }
}

int main(void)
{
    char *author, *title;
    int choice;
    BookList records;

    do{
        cout<<"1. Print \n2. Add Book \n3. isEmpty \n4. isFull \n5. Exit"<<endl;
        cin>>choice;

        switch (choice)
        {
            case 1:
                records.print();
                break;
            case 2:
                cout<<"Enter Book title: ";
                cin>>title;
                cout<<"Enter the Book Author: ";
                cin>>author;
                records.addItem(author, title);
                break;
            case 3:
                if (records.isEmpty())
                    cout<<"The list is not empty"<<endl;
                else
                    cout<<"The List is empty"<<endl;
                break;
            case 4:
                cout<<"The List is not full"<<endl;
                break;
            default:
                cout<<"You entered an invalid choice"<<endl;
        }//end switch
    }while(choice != 5);//end while
    return 0;
}


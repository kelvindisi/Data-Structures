#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    char* name;

    cout<<"Enter name: ";
    getline(cin, name);

    cout<<"Your name is "<<name<<endl;
}

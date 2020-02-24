#include <iostream>

using namespace std;

struct Store
{
    char value;
    Store *next;
};

class Infix
{
    Store first = malloc(Store);

public:
    Infix();
};
Infix::Infix()
{
    first = NULL;
}

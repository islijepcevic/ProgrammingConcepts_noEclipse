#include <iostream>

class AbstractPerson
{
public:
    virtual ~AbstractPerson() {}
    virtual void Print()=0;
};

class Mother : public AbstractPerson
{
public:
    void Print() { std::cout << "Mother\n"; }
};

class Daughter : public AbstractPerson
{
public:
    void Print() { std::cout << "Daughter\n"; }
};

int main(int agrc, char* argv[])
{
    AbstractPerson* p_abstract = new AbstractPerson;

    p_abstract->Print();

    delete p_abstract;

    return 0;
}

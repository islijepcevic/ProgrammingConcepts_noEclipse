#include <iostream>

class AbstractPerson
{
public:
    virtual ~AbstractPerson() {}
    virtual void Print() {std::cerr << "Never instantiate\n";}
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
    AbstractPerson* p_mother = new Mother;
    AbstractPerson* p_daughter = new Daughter;

    p_mother->Print();
    p_daughter->Print();

    delete p_mother;
    delete p_daughter;

    return 0;
}

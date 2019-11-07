#include "Registrar.h"

using namespace std;

Registrar::Registrar()
{
    Windows = new Window*[1];
    maxWindowIdle = 0;
    for(int i = 0; i < 1; ++i)
    {
        Windows[i] = new Window();
    }
    line = new GenQueue<Student>();
    size = 0;
}

Registrar::Registrar(int numWindows)
{
    cout << "Num Windows called " << numWindows << endl;
    size = numWindows;
    Windows = new Window*[size];
    for(int i = 0; i < size; ++i)
    {
        //iterate through the array of windows instantiating all of them
        Windows[i] = new Window();
    }
    line = new GenQueue<Student>();
}

Registrar::~Registrar()
{
    delete Windows;
    delete line;
}

void Registrar::update()
{
    cout << "Update called" << endl;
    for(int i = 0; i<size; ++i)
    {
        if(Windows[i]->isIdle)
        {
            if(!line->isEmpty())
            {
                Student temp = line->remove();
                Windows[i]->helpStudent(&temp);;
            }
        }
        Windows[i]->checkCustomerFinished();
    }
}

bool Registrar::checkAllWindows()//if all the windows are empty return true
{
    cout << "called size: " << size << endl;
    bool val = true;
    for(int i = 0; i<size; ++i)
    {
        if(!Windows[i]->isIdle)
        {
            val = false;
        }
        if(Windows[i]->MaxIdle > maxWindowIdle)
        {
            maxWindowIdle = Windows[i]->MaxIdle;
            cout << "max idle " << maxWindowIdle << endl;
        }
    }
    cout << "check all windows fini" << endl;
    return val;
}
#include "Window.h"
#include <iostream>


using namespace std;


Window::Window()
{
    customer = NULL;
    isIdle = true;
    idleTime = 0;
    MaxIdle = 0;
}

Window::~Window()
{

}

bool Window::checkCustomerFinished()
{
    if(customer == NULL)
    {
        isIdle = true;
        idleTime = idleTime + 1;
        cout << "idle Time " << idleTime <<endl;
        if(idleTime>MaxIdle)
        {
            MaxIdle = idleTime;
        }
        return true;
    }
    customer->waitTime = customer->waitTime-1;
    cout <<customer->waitTime << " Customer wait time" << endl;
    if(customer->waitTime == 0)
    {
        //the student has finished being helped
        customer = NULL;
        isIdle = true;
        return true;
    }
    return false;
}

bool Window::helpStudent(Student* s)
{
    if(customer != NULL)//there is a student paired to this window
    {
        return false;
    }
    else{
        customer = s;
        cout<< s->waitTime << " Customer Wait time when assigned" << endl;
        isIdle = false;
        idleTime = 0;
    }
    return true;
}
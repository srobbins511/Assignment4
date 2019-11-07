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
        idleTime = idleTime + 1;
        cout << "idle Time " << idleTime <<endl;
        if(idleTime>MaxIdle)
        {
            MaxIdle = idleTime;
        }
        return true;
    }
    customer->waitTime = customer->waitTime-1;
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
        isIdle = false;
        idleTime = 0;
    }
    return true;
}
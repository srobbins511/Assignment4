#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include "Student.h"

class Window
{
    public:
        Student* customer;
        bool isIdle;
        int MaxIdle;
        unsigned int idleTime;

        Window();
        ~Window();
        bool checkCustomerFinished(); //increments the student waiting and checks to see if they are done
        bool helpStudent(Student* s);
};

#endif
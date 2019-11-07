#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>


class Student
{
    public:
        int id;
        unsigned int waitTime;
        unsigned int timeWaiting;
        unsigned int timeArrival;

        //Methods
        Student();
        Student(int id, unsigned int waitTime, unsigned int timeArrival);
        ~Student();
};

#endif
#include "Student.h"

Student::Student()
{
    timeWaiting = 0;
    id = 0;
    timeArrival = 0;
    waitTime = 0;
}

Student::Student(int i, unsigned int wt, unsigned int ta)
{
    timeWaiting = 0;
    id = i;
    waitTime = wt;
    timeArrival = ta;
}

Student::~Student()
{
    
}
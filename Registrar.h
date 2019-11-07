
#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <iostream>
#include "Window.h"
#include "GenQueue.h"


using namespace std;

class Registrar
{
    public:
        Window** Windows; // a pointer to an array of Window objects
        GenQueue<Student>* line; //a pointer to a queue of students
        int size; //the number of windows that the registrar has
        int meanStuWait;
        int maxStuWait;
        int totalWait;
        int medianStuWait;
        int *waitTimes;
        int maxWindowIdle;
        Student* buffer;

        Registrar();
        Registrar(int numWindows);
        ~Registrar();
        void update();//method that will go through the array of windows and update values
        bool checkAllWindows();
};

#endif
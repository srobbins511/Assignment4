#ifndef SIMULATEDAY_H
#define SIMULATEDAY_H

#include <iostream>
#include "Registrar.h"
#include "FileIn.h"
#include "GenStack.h"

class SimulateDay
{
    public: 
        Registrar *reg;
        FileIn *myFile;
        std::string fname;
        int *plan;
        Student **students;
        int numStudents;
        GenStack<Student> *Arrivals;
        int time;

        SimulateDay(std::string fname);
        ~SimulateDay();

        void simulate();
};

#endif
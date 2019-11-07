#include "SimulateDay.h"
#include <iostream>

using namespace std;

SimulateDay::SimulateDay(std::string fname)
{
    int time =0;
    int numStudentsCreated = 0;
    int arrivalTimeCount = 0;
    myFile = new FileIn(fname);
    myFile->Format();
    plan = myFile->getContent();
    students = new Student*[myFile->size];
    numStudents = myFile->size;
    Arrivals = new GenStack<Student>(numStudents);
    int stuIndex = 0;
    Student** tempStu;
    int size = 0;
    int timeArrival = 0;
    int state = 0;
    for(int i = 0; i< myFile->size; ++i)
    {
        switch(state)
        {
            case 0:
                reg = new Registrar(plan[i]);
                state = 1;
                break;
            case 1:
                timeArrival = plan[i];
                state = 2;
                break;
            case 2:
                size = plan[i];
                tempStu = new Student*[size];
                for(int j = 0; j < size; ++j)
                {
                    tempStu[j] = new Student(++numStudentsCreated,0,timeArrival);
                }
                state = 3;
                break;
            case 3:
                tempStu[arrivalTimeCount++]->waitTime = plan[i];
                if(arrivalTimeCount == size)
                {
                    arrivalTimeCount = 0;
                    for(int j = 0; j < size; ++j)
                    {
                        students[stuIndex++] = tempStu[j];
                    }
                    delete tempStu;
                    state = 1;
                }
                break;      
        }
        
    }
    for(int i = (numStudentsCreated-1); i>=0; --i)
    {
        Arrivals->push(*students[i]);
        cout << "Push posiition: " << i << endl;
    }
}

SimulateDay::~SimulateDay()
{
    delete reg;
    delete plan;
    delete myFile;
    delete students;
}

void SimulateDay::simulate()
{
    while((!Arrivals->isEmpty()) || !reg->checkAllWindows() || !reg->line->isEmpty())
    {
        ++time;
        Student temp;
        if(!Arrivals->isEmpty())
        {
            while(Arrivals->peek().timeArrival <= time)
            {
                temp = Arrivals->pop();
                cout << "Pop an Arrival" << endl;
                reg->line->insert(temp.id, temp);
                cout << "Line Size: " << reg->line->getSize() << endl;
                if(Arrivals->isEmpty())
                {
                    break;
                }
            }
        }
        reg->update();
        cout << "Time: " << time << endl;
        cout<< "Arrivals status: " << Arrivals->isEmpty() << endl;
    }
    cout<< "Max Window Idle Time:" << reg->maxWindowIdle << endl;
}
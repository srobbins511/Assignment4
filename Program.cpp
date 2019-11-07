#include <iostream>
#include "SimulateDay.h"


using namespace std;

int main(int argc, char** argv)
{
    
    std::string fname;
    if(argc == 1)
    {
        cout <<"No Argument Given for file to read from" << endl;
    }
    else
    {
        fname = argv[1];   
    }
    SimulateDay* prgm = new SimulateDay(fname);
    prgm->simulate();
    return 0;
}
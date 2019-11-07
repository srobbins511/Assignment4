#ifndef FILEIN_H
#define FILEIN_H

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
class FileIn
{
    public:
        //variables
        std::string content;
        int* values;
        bool success;
        int size;

        //constructor
        FileIn(std::string fname);
        
        //methods
        int* getContent();
        void Format();
        int atoi(std::string num);
};

#endif
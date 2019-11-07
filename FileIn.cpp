#include "FileIn.h"
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

//file to read from a user given file
FileIn::FileIn(std::string fname)
{
    size = 0;
    ifstream myFile(fname);
    std::string line = "";
    if(myFile.is_open())
    {
        while(myFile)
            {
                myFile >> line;
                content += line + "|";
                ++size;
            }
            myFile.close();
    }
    else
    {
        //set the flag bool variable to false
        success = false;
    }
    values = new int[size];
    success = true;
}

//parse an int value to determine dimensions of the grid defined by the user
int FileIn::atoi(std::string num)
{
    int number = 0;
    for(char c : num)
    {
        number*=10;
        if(c == '9')
        {
            number+=9;
        }
        else if(c == '8')
        {
            number+=8;
        }
        else if(c == '7')
        {
            number+=7;
        }
        else if(c == '6')
        {
            number+=6;
        }
        else if(c == '5')
        {
            number+=5;
        }
        else if(c == '4')
        {
            number+=4;
        }
        else if(c == '3')
        {
            number+=3;
        }
        else if(c == '2')
        {
            number+=2;
        }
        else if(c == '1')
        {
            number+=1;
        }
        else if(c == '0')
        {
            number+=0;
        }
    }
    return number;
}

//fill an array with all the values given by the file
void FileIn::Format()
{
    int count = 0;
    std::string temp = "";
    for(char c : content)
    {
        if(c=='|')
        {
            values[count++] = atoi(temp);
            temp = "";
            continue;
        }
        else{
            temp += c;
        }
    }
}

//return the formatted string that represents all the values in the graph
int* FileIn::getContent()
{
    return values;
}
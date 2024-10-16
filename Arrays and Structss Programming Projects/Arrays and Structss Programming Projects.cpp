// Arrays and Structss Programming Projects.cpp : This file contains Project 1: Marathon Runners with Parallel Arrays.
// This project will take a file with the name of runners and their distance ran for a week, this program will take their data and using parallel arrays to find their total miles ran, average, and display the miles ran every day for each runner. 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Global constants

const int maxmiles = 10;        //This is the maximum entries of miles ran per person
const int runneramount = 20;    //This is the maximum number of runners

    //Prototype Functions



int fileRead(string names[], double array[][maxmiles], string file);  //This function reads the input file and outputs the data to the parallel arrays


int main()
{
    //Variables
    
    string file = "runners.txt";
    
    string myrunners[runneramount];

    double miles[runneramount][maxmiles];
    
    int numrecords;
    
    numrecords = fileRead(myrunners, miles, file);
    if (numrecords == -1)
    {
        cout << "Too many runners in the file" << endl;
        exit;
    }
    

    //debug
    cout << "data from file" << endl;
    for (int row = 0; row < numrecords; row++)
    {
        cout << myrunners[row] << " ";
        for (int col = 0; col < maxmiles; col++)
            cout << miles[row][col] << " ";
        cout << endl;
    }
}

int fileRead(string names[], double array[][maxmiles], string file)
{
    int numrecords = 0;
    ifstream runnerfile(file);
    if (!runnerfile)
    {
        cout << "File will not open" << endl;
        exit;
    }

    while (runnerfile >> names[numrecords])
    {
       if (numrecords < runneramount)
       {
        for (int A = 0; A < maxmiles; A++)
            runnerfile >> array[numrecords][A];
        numrecords++;
       }
        
       else
       {
           return -1;
       }
   
    }

    runnerfile.close();

    return numrecords;
}
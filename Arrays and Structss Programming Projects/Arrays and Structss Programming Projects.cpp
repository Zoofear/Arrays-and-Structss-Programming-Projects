// Arrays and Structss Programming Projects.cpp : This file contains Project 1: Marathon Runners with Parallel Arrays.
// This project will take a file with the name of runners and their distance ran for a week, this program will take their data and using parallel arrays to find their total miles ran, average, and display the miles ran every day for each runner. 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

    //Global constants

    //The scope of each array
const int maxentries = 7;        //This is the maximum entries of miles ran per person
const int runneramount = 20;    //This is the maximum number of runners

    //Prototype Functions

int runnerFileData(string names[], double array[][maxentries], string file);  //This function reads the input file and outputs the data to the parallel arrays

void runnerAvgTotal(const double array[][maxentries], double avg[], double total[], int numrecords);  //This function takes the inputted miles and calculates the average and total miles each runner has ran

void milesOutput(const string names[], const double array[][maxentries], const double avg[], const double total[], int numrecords);     //This function takes all the data and calculations and outputs it to be read by the user

    //Main

int main()
{
    //Variables
    
    const string file = "runners.txt";      //The file used for input
    
    string myrunners[runneramount];         //This array is for the runners namess

    double miles[runneramount][maxentries];   //This array is for the miles each runner has ran

    double mileaverage[runneramount];       //This array is for storing the average miles each runner has ran for the week

    double miletotal[runneramount];         //This array is for storing the miles each runner has ran added up
    
    int numrecords;     //This is used for a check to make sure there arent too manny runners in the file
    
    numrecords = runnerFileData(myrunners, miles, file);
    if (numrecords == -1)
    {
        cout << "Too many runners in the file" << endl; //Check to make sure there aren't too many runners inputted
        exit;
    }
    
    runnerAvgTotal(miles, mileaverage, miletotal, numrecords);

    milesOutput(myrunners, miles, mileaverage, miletotal, numrecords);
    
    return;
}


    //Functions

int runnerFileData(string names[], double array[][maxentries], string file)
{
    int numrecords = 0;                         //Value used for indexing
   
    ifstream runnerfile(file);                  //Opening the input file
   
    if (!runnerfile)
    {
        cout << "File will not open" << endl;   //File open check
        exit;
    }
    while (runnerfile >> names[numrecords])     //This places the runners name into the runner array
    {
       if (numrecords < runneramount)
       {
        for (int A = 0; A < maxentries; A++)      //This fills out the miles for each runner in the 2D array and counts up in the index using A to fill in every spot
            runnerfile >> array[numrecords][A];
        numrecords++;                           //Counts up for the next place in the array
       }
        
       else
       {
           return -1;                          //Used as a true or false value for the runner input check
       }
   
    }

    runnerfile.close();                        //Closing input file

    return numrecords;
}

void runnerAvgTotal(const double array[][maxentries], double avg[], double total[], int numrecords)
{
    double sum;                                         //this is used to add all of the miles together
    for (int row = 0; row < numrecords; row++)          //This is used for indexing the arrays on which runner is being calculated
    {
        sum = 0;
        for (int col = 0; col < maxentries; col++)      //This indexes the 2d array fow which day ran
        {
            sum += array[row][col];                     //Adding the value from the array to the sum
        }

        total[row] = sum;                               //This writes the total miles ran for the current runner

        avg[row] = sum / maxentries;                    //Thjs calculates then writes the average miles ran for the current runner
    }
}

void milesOutput(const string names[], const double array[][maxentries], const double avg[], const double total[], int numrecords)
{
    cout << "Daily Miles Ran" << endl;                                                                                                          //Title of the graph
    cout << "Runner       Sunday       Monday       Tuesday      Wednesday    Thursday     Friday       Saturday     Average  Total" << endl;   //Header of the graph 
    for (int row = 0; row < numrecords; row++)                                                                                                  //Used to choose which runners data is being written
    {
        cout << setw(13) << left << names[row];                                                                                                 //Outputs the names of the runner                                                   

        for (int col = 0; col < maxentries; col++)                                                                                              //Indexes the data points for the miles each runner ran
            cout << setw(12) << array[row][col] << " ";                                                                                         //Outputs the mile for that day
        cout << fixed << setprecision(2) << setw(9) << avg[row];                                                                                //Outputs the average miles ran that week
        cout << setprecision(0) << total[row] << endl;                                                                                          //Outputs the total mile ran that week
    }
}
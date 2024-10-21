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


    //Global Structs

struct runnerInfo
{
    string runnername;
    double miles[maxentries];
    double averagemiles;
    double totalmiles;
};

    //Prototype Functions

int runnerFileData(runnerInfo runners[], string file);  //This function reads the input file and outputs the data to the parallel arrays

void runnerAvgTotal(runnerInfo runners[], int numrecords);  //This function takes the inputted miles and calculates the average and total miles each runner has ran

void milesOutput(runnerInfo runners[], int numrecords);     //This function takes all the data and calculations and outputs it to be read by the user

    //Main

int main()
{
    //Variables

    runnerInfo runners[runneramount];

    string file = "runners.txt";

    int numrecords;     //This is used for a check to make sure there arent too manny runners in the file

    numrecords = runnerFileData(runners, file);
    if (numrecords == -1)
    {
        cout << "Too many runners in the file" << endl; //Check to make sure there aren't too many runners inputted
        exit;
    }

    runnerAvgTotal(runners, numrecords);

    milesOutput(runners, numrecords);

}


    //Functions

int runnerFileData(runnerInfo runners[], string file)
{
    int numrecords = 0;                         //Value used for indexing
   
    ifstream runnerfile(file);                  //Opening the input file
   
    if (!runnerfile)
    {
        cout << "File will not open" << endl;   //File open check
        exit;
    }
    while (runnerfile >> runners[numrecords].runnername)     //This places the runners name into the runner array struct
    {
       if (numrecords < runneramount)
       {
        for (int A = 0; A < maxentries; A++)      //This fills out the miles for each runner in the struct and counts up in the index using A to fill in every spot
            runnerfile >> runners[numrecords].miles[A];
        numrecords++;                           //Counts up for the next place in the struct
       }
        
       else
       {
           return -1;                          //Used as a true or false value for the runner input check
       }
   
    }

    runnerfile.close();                        //Closing input file

    return numrecords;
}

void runnerAvgTotal(runnerInfo runners[], int numrecords)
{
    double sum;                                         //this is used to add all of the miles together
    for (int row = 0; row < numrecords; row++)          //This is used for indexing the structs on which runner is being calculated
    {
        sum = 0;
        for (int col = 0; col < maxentries; col++)      //This indexes the struct for which day ran
        {
            sum += runners[row].miles[col];                     //Adding the value from the struct to the sum
        }

        runners[row].totalmiles = sum;                               //This writes the total miles ran for the current runner

        runners[row].averagemiles = sum / maxentries;                    //Thjs calculates then writes the average miles ran for the current runner
    }
}

void milesOutput(runnerInfo runners[], int numrecords)
{
    cout << "Daily Miles Ran" << endl;                                                                                                          //Title of the graph
    cout << "Runner       Sunday       Monday       Tuesday      Wednesday    Thursday     Friday       Saturday     Average  Total" << endl;   //Header of the graph 
    for (int row = 0; row < numrecords; row++)                                                                                                  //Used to choose which runners data is being written
    {
        cout << setw(13) << left << runners[row].runnername;                                                                                                 //Outputs the names of the runner                                                   

        for (int col = 0; col < maxentries; col++)                                                                                              //Indexes the data points for the miles each runner ran
            cout << setw(12) << runners[row].miles[col] << " ";                                                                                         //Outputs the mile for that day
        cout << fixed << setprecision(2) << setw(9) << runners[row].averagemiles;                                                                                //Outputs the average miles ran that week
        cout << setprecision(0) << runners[row].totalmiles << endl;                                                                                          //Outputs the total mile ran that week
    }
}
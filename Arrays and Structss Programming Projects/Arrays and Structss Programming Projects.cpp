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



int fileRead(string[], double array[][maxmiles], string file);  //This function reads the input file and outputs the data to the parallel arrays


int main()
{
    //Variables
    
    string file = "runner.txt";
    
    string myrunners[runneramount];

    double miles[runneramount][maxmiles];
    
    
}

int fileRead(string[], double array[][maxmiles], string file)
{

}
// Program-11-CS201-Alex-Ghasemi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

//include media
#include "Media.h"
#include "Functions.h"
using namespace std;
/*
name:alex ghasemi
project: media lbirary
class: CS201
psuedo code
take file of media dn file of commands
load the media into class based vectors
follow the commands to proform the correct output
//FOR THE CORRECT FORMAT AND SORTING PLEASE RUN IN VISUAL STUDIO FOR CORRECT OUTPUT



*/

int main()
{
    string data;
    //read the media list
    ifstream inFile("mediaList.txt");
    //start output files
    ofstream outErrorFile("Errors.txt");
    ofstream outFile("output.txt");
    vector<Media*> totalMedia;
    //check if open
    if (!inFile.is_open()) {
        cout << "Failed to open mediaList.txt" << endl;
        return 1;
    }
    //read the file and load
    readMediaList(inFile, outErrorFile, totalMedia);
    inFile.close();
    
    //open the commands
    ifstream ninFile("mediaCommands.txt"); 
    //read the whole file
    while (getline(ninFile, data)) {
        if (data[0] == 'M') {
            printMovieList(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'B') {
            printBookList(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'A') {
            printAllMedia(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'T') {
            printTotals(outFile, totalMedia);
        }
        else if (data[0] == 'S') {
            printSongList(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'N') {
            addNewMedia(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'K') {
            listKeyName(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'L') {
            listMovieStars(data, outFile, outErrorFile, totalMedia);
        }
        else if (data[0] == 'Q') {
        break;
        }
        else {
            outErrorFile << "The command : " << data[0] << " is invalid." << endl << endl;
        }
    }
    
    ninFile.close();
    outFile.close();
    outErrorFile.close();

}

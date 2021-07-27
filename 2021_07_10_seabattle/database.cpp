//
//  database.cpp
//  2021_07_10_seabattle
//
//  Created by Gleb Markin on 10.07.2021.
//

#include "database.hpp"
#include <fstream>
#include <iostream>
#include <cstdio>
using std::ifstream;
extern int *const posYp;
extern int *const posXp;


std::string readData () {
	ifstream indata; // indata is like cin
	std::string OldShipNames; // variable for input value
	indata.open("examp.txt"); // opens the file
	if(!indata) { // file couldn't be opened
		std::cerr << "Error: file could not be opened" << std::endl;
		exit(1);
	}
	indata >> OldShipNames;
	while ( !indata.eof() ) { // keep reading until end-of-file
		std::cout << "The next word is " << OldShipNames << std::endl;
		indata >> OldShipNames; // sets EOF flag if no value found
	}
	indata.close();
	std::cout << "End-of-file reached.." << std::endl;
	return OldShipNames;
}


 
//std::string *OldShipNames = nullptr;
//std::string *NewShipName = nullptr;

int writeData (std::string OldShipNames, std::string NewShipName, int *posYp, int *posXp) {
	std::ofstream outdata;
	outdata.open("examp.txt");
	if( !outdata ) { // file couldn't be opened
		std::cerr << "Error: file could not be opened on WRITE" << std::endl;
		exit(1);
	}
	int shipY = *posYp - 1; // stop using pointer to prevent changing values across program
	int shipX = *posXp - 1;
	std::string shipYpos = std::to_string(shipY);
	std::string shipXpos = std::to_string(shipX);
	std::string writeInFile = OldShipNames + NewShipName + shipYpos + shipXpos;
	
	//std::string writeInFile;
	//outdata << usedNamesString << *retrivedBoyName;
	
	outdata << writeInFile;
	
	outdata.close();
	
	return 0;

}


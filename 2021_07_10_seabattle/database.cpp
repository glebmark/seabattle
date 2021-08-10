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
#include "grid.hpp"
using std::ifstream;
extern int *const posYp;
extern int *const posXp;


std::string readData (int gameMode) {
	
	if (*player_p == 2 && gameMode == 1) {
		gameMode = 2;
	} else if (*player_p == 2 && gameMode == 2) {
		gameMode = 1;
	}
	
	std::string OldShipNames; // variable for input value
	if (gameMode == 1) { // DEFENCE MODE
		ifstream indata; // indata is like cin
		indata.open("player1.txt"); // opens the file
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

		
	} else if (gameMode == 2) { // ATTACK MODE
		ifstream indata; // indata is like cin
		
		indata.open("player2.txt"); // opens the file
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
		
	}
	return OldShipNames;
}


 
//std::string *OldShipNames = nullptr;
//std::string *NewShipName = nullptr;

int writeData (std::string OldShipNames, std::string NewShipName, int *posYp, int *posXp) {
	
	if (*player_p == 1) {
		std::ofstream outdata;
		outdata.open("player1.txt");
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
	} 	else if (*player_p == 2) {
		std::ofstream outdata;
		outdata.open("player2.txt");
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
	}
	
	
	return 0;

}


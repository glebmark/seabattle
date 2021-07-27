//
//  grid.cpp
//  2021_07_10_seabattle
//
//  Created by Gleb Markin on 10.07.2021.
//

#include <iostream>
#include "grid.hpp"
#include "service.hpp"
#include <stdlib.h>
#include <unistd.h>
#include "shipCreator.hpp"

using std::string;
using std::cout;
using std::endl;

int posY = 5;
int posX = 5;
int *const posYp = &posY;
int *const posXp = &posX;

unsigned long posYshipOne1 = 0;
unsigned long posXshipOne1 = 0;
unsigned long *const posYshipOne1p = &posYshipOne1;
unsigned long *const posXshipOne1p = &posXshipOne1;

unsigned long posYshipOne2 = 0;
unsigned long posXshipOne2 = 0;
unsigned long *const posYshipOne2p = &posYshipOne2;
unsigned long *const posXshipOne2p = &posXshipOne2;

unsigned long posYshipOne3 = 0;
unsigned long posXshipOne3 = 0;
unsigned long *const posYshipOne3p = &posYshipOne3;
unsigned long *const posXshipOne3p = &posXshipOne3;

unsigned long posYshipOne4 = 0;
unsigned long posXshipOne4 = 0;
unsigned long *const posYshipOne4p = &posYshipOne4;
unsigned long *const posXshipOne4p = &posXshipOne4;



void grid(){
	std::cout << "Void grid..." << std::endl;
	//*typedKey = 'k';
	
	// mesh size
	const int meshX = 13;
	const int meshY = 13;
	// mesh
	std::string mesh[meshY][meshX] =
	{
		{" ","  "," 1 "," 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 "," 10"," ",},//1
		{"   ","---","---","---","---","---","---","---","---","---","---"},		//2
		{"1 ","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//3
		{"2 ","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//4
		{"3 ","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//5
		{"4 ","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//6
		{"5 ","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//7
		{"6 ","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//8
		{"7 ","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//9
		{"8 ","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//10
		{"9 ","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//11
		{"10","|","   ","   ","   ","   ","   ","   ","   ","   ","   ","   ","|"},//12
		{"   ","---","---","---","---","---","---","---","---","---","---"},	   //13
	};
	
	const std::string bb = "#";
	mesh[*posYp][*posXp] = bb+bb+bb;
	std::cout << "works1" << std::endl;
//	if (*posYshipOne1p && *posXshipOne1p) {
//		std::cout << "works2" << std::endl;
//	mesh[*posYshipOne1p + 1][*posXshipOne1p + 1] = bb+bb+bb;
//	}
	//cout << "ERROR HERE in GRID"<< endl;
	mesh[*posYshipOne1p + 1][*posXshipOne1p + 1] = bb+bb+bb;
	//cout << "ERROR HERE in GRID2"<< endl;
	mesh[*posYshipOne2p + 1][*posXshipOne2p + 1] = bb+bb+bb;
	mesh[*posYshipOne3p + 1][*posXshipOne3p + 1] = bb+bb+bb;
	mesh[*posYshipOne4p + 1][*posXshipOne4p + 1] = bb+bb+bb;
	//cout << "ERROR HERE in GRID3"<< endl;
	 //shipTwo #1 and its coordinates
	// shipTwo #1 + its second block coordinates
	// other ships...
	
	
	
	
	for(int i = 0; i < meshY; i++)
	{
		for(int j = 0; j < meshX; j++)
		{
			std::cout << mesh[i][j];
		}
		std::cout << std::endl;
	}
	
}




//
// while cycle start here
//
void cycle () {
	std::cout << "Cycle began..." << std::endl;
	const int maxChars = 1;
	char      stringBuffer[ maxChars+1 ];
	memset(   stringBuffer , 0 , maxChars+1 ); // initialize to 0
	bool work = true;
	int frames = 1;
	readData_of_Old_Names();
	
	std::cout << "Press 'h' for help\nUse 'wasd' for moving, 'q' for rotation and 'e' for placing of ship" << std::endl;
	
	while (work) {
		int shipSize = 0;
		*stringBuffer = 'x';
		
		std::cout << "Type size of ship: 1, 2, 3 or 4" << std::endl;
		std::cin >> shipSize;
		if (shipSize == 1 || shipSize == 2 || shipSize == 3 || shipSize == 4) {
	
		while(work) {
			//std::cout << "It's buffer INSIDE: " << stringBuffer << std::endl;
			getStr(stringBuffer , maxChars);
			ClearScreen();
				//		std::cout << "you typed: " << *stringBuffer << std::endl;
			
			if (*stringBuffer == 'p') { // to FULL EXIT from program
				break;
			}
			if (*stringBuffer == 'c') { // to change size of ship
				break;
			}
			if (*stringBuffer == 'h') { // show help window
				ClearScreen();
				std::cout << "Press 'h' for help\nPress 1, 2, 3 or 4 for chosing size of ship\nPress 'p' for exit from program\nPress 'c' to change size of ship" << std::endl;
				break;
			}
			
			//test2
			//test4
			ships (stringBuffer, shipSize);
//			if (sizeShip == 1)
//			{
//				ship1 (stringBuffer);
//			} else if (sizeShip == 2) {
//					//ship2 (stringBuffer);
//			} else if (sizeShip == 3) {
//					//ship3 (stringBuffer);
//			} else if (sizeShip == 4) {
//					//ship4 (stringBuffer);
//			} else {
//				std::cout << "You typed wrong size of ship!" << std::endl;
//				break;
//			}
			
			std::cout << "Press 'h' for help." << std::endl;
			std::cout << "Y-coordinate: " << posY - 1 << std::endl;
			std::cout << "X-coordinate: " << posX - 1 << std::endl;
			grid(); // draw grid
			
			
			
				//std::cout << "you typed AFTER: " << *stringBuffer << std::endl;
			frames++;
			std::cout << "frames showed: " << frames << std::endl;
		}
		}	else {
			ClearScreen();
			std::cout << "You haven't typed an integer!" << std::endl;
			std::cin.clear(); //clear bad input flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			
			//continue;
		}
		
		frames++;
		std::cout << "frames showed: " << frames << std::endl;
		if (*stringBuffer == 'p') { // FULL EXIT from program
			break;
		}
	}
}




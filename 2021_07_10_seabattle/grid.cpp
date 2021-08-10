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

unsigned long posYshipTwo1 = 0;
unsigned long posXshipTwo1 = 0;
unsigned long *const posYshipTwo1p = &posYshipTwo1;
unsigned long *const posXshipTwo1p = &posXshipTwo1;
unsigned long posYshipTwo1_2 = 0;
unsigned long posXshipTwo1_2 = 0;
unsigned long *posYshipTwo1p_2 = &posYshipTwo1_2;
unsigned long *posXshipTwo1p_2 = &posXshipTwo1_2;

unsigned long posYshipTwo2 = 0;
unsigned long posXshipTwo2 = 0;
unsigned long *const posYshipTwo2p = &posYshipTwo2;
unsigned long *const posXshipTwo2p = &posXshipTwo2;
unsigned long posYshipTwo2_2 = 0;
unsigned long posXshipTwo2_2 = 0;
unsigned long *posYshipTwo2p_2 = &posYshipTwo2_2;
unsigned long *posXshipTwo2p_2 = &posXshipTwo2_2;

unsigned long posYshipTwo3 = 0;
unsigned long posXshipTwo3 = 0;
unsigned long *const posYshipTwo3p = &posYshipTwo3;
unsigned long *const posXshipTwo3p = &posXshipTwo3;
unsigned long posYshipTwo3_2 = 0;
unsigned long posXshipTwo3_2 = 0;
unsigned long *posYshipTwo3p_2 = &posYshipTwo3_2;
unsigned long *posXshipTwo3p_2 = &posXshipTwo3_2;

unsigned long posYshipThr1 = 0;
unsigned long posXshipThr1 = 0;
unsigned long *const posYshipThr1p = &posYshipThr1;
unsigned long *const posXshipThr1p = &posXshipThr1;
unsigned long posYshipThr1_2 = 0;
unsigned long posXshipThr1_2 = 0;
unsigned long *posYshipThr1p_2 = &posYshipThr1_2;
unsigned long *posXshipThr1p_2 = &posXshipThr1_2;
unsigned long posYshipThr1_3 = 0;
unsigned long posXshipThr1_3 = 0;
unsigned long *posYshipThr1p_3 = &posYshipThr1_3;
unsigned long *posXshipThr1p_3 = &posXshipThr1_3;

unsigned long posYshipThr2 = 0;
unsigned long posXshipThr2 = 0;
unsigned long *const posYshipThr2p = &posYshipThr2;
unsigned long *const posXshipThr2p = &posXshipThr2;
unsigned long posYshipThr2_2 = 0;
unsigned long posXshipThr2_2 = 0;
unsigned long *posYshipThr2p_2 = &posYshipThr2_2;
unsigned long *posXshipThr2p_2 = &posXshipThr2_2;
unsigned long posYshipThr2_3 = 0;
unsigned long posXshipThr2_3 = 0;
unsigned long *posYshipThr2p_3 = &posYshipThr2_3;
unsigned long *posXshipThr2p_3 = &posXshipThr2_3;

unsigned long posYshipFou1 = 0;
unsigned long posXshipFou1 = 0;
unsigned long *const posYshipFou1p = &posYshipFou1;
unsigned long *const posXshipFou1p = &posXshipFou1;
unsigned long posYshipFou1_2 = 0;
unsigned long posXshipFou1_2 = 0;
unsigned long *posYshipFou1p_2 = &posYshipFou1_2;
unsigned long *posXshipFou1p_2 = &posXshipFou1_2;
unsigned long posYshipFou1_3 = 0;
unsigned long posXshipFou1_3 = 0;
unsigned long *posYshipFou1p_3 = &posYshipFou1_3;
unsigned long *posXshipFou1p_3 = &posXshipFou1_3;
unsigned long posYshipFou1_4 = 0;
unsigned long posXshipFou1_4 = 0;
unsigned long *posYshipFou1p_4 = &posYshipFou1_4;
unsigned long *posXshipFou1p_4 = &posXshipFou1_4;



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
	
	mesh[*posYshipOne1p + 1][*posXshipOne1p + 1] = bb+bb+bb;
	
	mesh[*posYshipOne2p + 1][*posXshipOne2p + 1] = bb+bb+bb;
	mesh[*posYshipOne3p + 1][*posXshipOne3p + 1] = bb+bb+bb;
	mesh[*posYshipOne4p + 1][*posXshipOne4p + 1] = bb+bb+bb;
	
	mesh[*posYshipTwo1p + 1][*posXshipTwo1p + 1] = bb+bb+bb;
	mesh[*posYshipTwo1p_2 + 1][*posXshipTwo1p_2 + 1] = bb+bb+bb;
	
	mesh[*posYshipTwo2p + 1][*posXshipTwo2p + 1] = bb+bb+bb;
	mesh[*posYshipTwo2p_2 + 1][*posXshipTwo2p_2 + 1] = bb+bb+bb;
	
	mesh[*posYshipTwo3p + 1][*posXshipTwo3p + 1] = bb+bb+bb;
	mesh[*posYshipTwo3p_2 + 1][*posXshipTwo3p_2 + 1] = bb+bb+bb;
	
	mesh[*posYshipThr1p + 1][*posXshipThr1p + 1] = bb+bb+bb;
	mesh[*posYshipThr1p_2 + 1][*posXshipThr1p_2 + 1] = bb+bb+bb;
	mesh[*posYshipThr1p_3 + 1][*posXshipThr1p_3 + 1] = bb+bb+bb;
	
	mesh[*posYshipThr2p + 1][*posXshipThr2p + 1] = bb+bb+bb;
	mesh[*posYshipThr2p_2 + 1][*posXshipThr2p_2 + 1] = bb+bb+bb;
	mesh[*posYshipThr2p_3 + 1][*posXshipThr2p_3 + 1] = bb+bb+bb;
	
	mesh[*posYshipFou1p + 1][*posXshipFou1p + 1] = bb+bb+bb;
	mesh[*posYshipFou1p_2 + 1][*posXshipFou1p_2 + 1] = bb+bb+bb;
	mesh[*posYshipFou1p_3 + 1][*posXshipFou1p_3 + 1] = bb+bb+bb;
	mesh[*posYshipFou1p_4 + 1][*posXshipFou1p_4 + 1] = bb+bb+bb;
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
			getStr(stringBuffer , maxChars);
			ClearScreen();
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
			
			ships (stringBuffer, shipSize);
			
			std::cout << "Press 'h' for help." << std::endl;
			std::cout << "Y-coordinate: " << posY - 1 << std::endl;
			std::cout << "X-coordinate: " << posX - 1 << std::endl;
			grid(); // draw grid
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




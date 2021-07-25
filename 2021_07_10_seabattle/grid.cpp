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

int posY = 5; // aiming focus
int posX = 5; // aiming focus
int *const posYp = &posY; // aiming focus
int *const posXp = &posX; // aiming focus

int posYshipOne1 = 0;
int posXshipOne1 = 0;
int *const posYshipOne1p = &posYshipOne1;
int *const posXshipOne1p = &posXshipOne1;

int posYshipOne2 = 0;
int posXshipOne2 = 0;
int *const posYshipOne2p = &posYshipOne2;
int *const posXshipOne2p = &posYshipOne2;



void grid(){
	//std::cout << "Void grid..." << std::endl;
	//*typedKey = 'k';
	
	// mesh size
	const int meshX = 13;
	const int meshY = 13;
	// mesh
	std::string mesh[meshY][meshX] =
	{
		{" ","  "," 1 "," 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 "," 10"," ",},//1
		{"   ","---","---","---","---","---","---","---","---","---","---"},//2
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
		{"   ","---","---","---","---","---","---","---","---","---","---"},//13
	};
	
	const std::string bb = "#";
	mesh[*posYp][*posXp] = bb+bb+bb;
	mesh[*posYshipOne1p][*posXshipOne1p] = bb+bb+bb;
	mesh[*posYshipOne2p][*posXshipOne2p] = bb+bb+bb;
	
	
	
	
	for(int i = 0; i < meshX; i++)
	{
		for(int j = 0; j < meshY; j++)
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
	//std::cout << "Cycle began..." << std::endl;
	const int maxChars = 1;
	char      stringBuffer[ maxChars+1 ];
	memset(   stringBuffer , 0 , maxChars+1 ); // initialize to 0
	bool work = true;
	int frames = 1;
	int shipSize = 0;

	std::cout << "Press 'h' for help\nPress 'c' for chosing size of ship\nPress 'wasd' for moving, 'q' for rotation and 'e' for placing of ship" << std::endl;
	//std::cout << "Type size of ship..." << std::endl;
	//std::cin >> shipSize;
			
		while(work) {
			
			getStr(stringBuffer , maxChars);
			ClearScreen();
			std::cout << "It's buffer INSIDE: " << stringBuffer << std::endl;
				//		std::cout << "you typed: " << *stringBuffer << std::endl;
			
			
			if (*stringBuffer == 'h') { // show help window
				ClearScreen();
				std::cout << "Press 'h' for help\nPress 1, 2, 3 or 4 for chosing size of ship\nPress 'p' for exit from program\nPress 'c' to change size of ship" << std::endl;
				//break;
			}
			
			
			if (*stringBuffer == 'c') { // to change size of ship
				ClearScreen();
				std::cout << "Type size of ship..." << std::endl;
				std::cin >> shipSize;
				*stringBuffer = 'x';
				if (shipSize / 1) {
					continue;
				} else {
					std::cout << "You haven't typed an integer!" << std::endl;
					break;
				}
				
				
			}
			
			
			
			ships (stringBuffer, shipSize);
			
			std::cout << "Press 'h' for help." << std::endl;
			std::cout << "Y-coordinate: " << posY - 1 << std::endl;
			std::cout << "X-coordinate: " << posX - 1 << std::endl;
			grid(); // draw grid
			
			
			
				//std::cout << "you typed AFTER: " << *stringBuffer << std::endl;
			frames++;
			std::cout << "frames showed: " << frames << std::endl;
			if (*stringBuffer == 'p') { // FULL EXIT from program
				break;
			}
		}
		//frames++;
		//std::cout << "frames showed: " << frames << std::endl;
		
	}




//
//  attackMode.cpp
//  2021_07_10_seabattle
//
//  Created by Gleb Markin on 10.08.2021.
//

#include "attackMode.hpp"
#include "service.hpp"
#include "grid.hpp"
#include "shipCreator.hpp"
#include <iostream>
#include <vector>
//#include <termios.h>
//#include <term.h>
//#include <unistd.h>
using std::string;
using std::cout;
using std::endl;



void attack(int gameMode) {
	bool work = true;
	const int maxChars = 1;
	char      stringBuffer[ maxChars+1 ];
	memset (stringBuffer , 0 , maxChars+1 ); // initialize to 0
	*stringBuffer = 'x';
	readData_of_Old_Names(gameMode);
	while (work) {
		cout << "ATTACK MODE BEGAN" << endl;
		getStr(stringBuffer , maxChars);
		ClearScreen();
		
		if (*stringBuffer == 'w')
		{
			if (*posYp == 2) {
				*posYp = *posYp;
			} else {
				*posYp = *posYp - 1;
			}
		}
		
		if (*stringBuffer == 's')
		{
			if (*posYp == 11) {
				*posYp = *posYp;
			} else {
				*posYp = *posYp + 1;
			};
		}
		
		if (*stringBuffer == 'a')
		{
			if (*posXp == 2) {
				*posXp = *posXp;
			} else {
				*posXp = *posXp - 1;
			};
		}
		
		if (*stringBuffer == 'd')
		{
			if (*posXp == 11) {
				*posXp = *posXp;
			} else {
				*posXp = *posXp + 1;
			};
		}
		
		std::vector<unsigned long> recordedYX = { // load all recorded coordinates from player1.txt or player2.txt
			*posYshipOne1p,
			*posXshipOne1p,
			*posYshipOne2p,
			*posXshipOne2p,
			*posYshipOne3p,
			*posXshipOne3p,
			*posYshipOne4p,
			*posXshipOne4p,
			
			*posYshipTwo1p,
			*posXshipTwo1p,
			*posYshipTwo1p_2,
			*posXshipTwo1p_2,
			
			*posYshipTwo2p,
			*posXshipTwo2p,
			*posYshipTwo2p_2,
			*posXshipTwo2p_2,
			
			*posYshipTwo3p,
			*posXshipTwo3p,
			*posYshipTwo3p_2,
			*posXshipTwo3p_2,
			
			*posYshipThr1p,
			*posXshipThr1p,
			*posYshipThr1p_2,
			*posXshipThr1p_2,
			*posYshipThr1p_3,
			*posXshipThr1p_3,
			
			*posYshipThr2p,
			*posXshipThr2p,
			*posYshipThr2p_2,
			*posXshipThr2p_2,
			*posYshipThr2p_3,
			*posXshipThr2p_3,
			
			*posYshipFou1p,
			*posXshipFou1p,
			*posYshipFou1p_2,
			*posXshipFou1p_2,
			*posYshipFou1p_3,
			*posXshipFou1p_3,
			*posYshipFou1p_4,
			*posXshipFou1p_4,
		};

		
		
		if (*stringBuffer == 'f') {
			int posY = *posYp;
			posY--;
			int posX = *posXp;
			posX--;
			bool exist = false;
			for (int i = 0; i <= 40; i++) {
				if (((posY == recordedYX[i]) && (posX == recordedYX[i+1]))) { //|| ((recordedYX[i] == 0) && (recordedYX[i+1] == 0))
					std::cout << "HIT!" << std::endl;
					exist = true;
				}
				if (exist == true) {
					break;
				}
			}
		}
		
		grid();
		
		if (*stringBuffer == 'p') { // to FULL EXIT from program
			break;
		}
	}
}

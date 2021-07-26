//
//  shipCreator.cpp
//  2021_07_10_seabattle
//
//  Created by Gleb Markin on 10.07.2021.
//

#include "shipCreator.hpp"
#include <string>
#include "grid.hpp"
#include "database.hpp"
#include <iostream>

extern int *const posYp;
extern int *const posXp;
extern unsigned long *const posYshipOne1p;
extern unsigned long *const posXshipOne1p;
extern unsigned long *const posYshipOne2p;
extern unsigned long *const posXshipOne2p;
extern unsigned long *const posYshipOne3p;
extern unsigned long *const posXshipOne3p;
extern unsigned long *const posYshipOne4p;
extern unsigned long *const posXshipOne4p;

using std::string;
using std::cout;
using std::endl;



string shipName = "ship"; // name of ship
//string shipNameSize1 = "One"; // name of ship of size 1
//string shipNameSize2 = "Two"; // name of ship of size 2
//string shipNameSize3 = "Three"; // name of ship of size 3
//string shipNameSize4 = "Four"; // name of ship of size 4
// shipOne144shipOne278shipOne399shipOne487
string shipNameSizeMesh[4] = {"One","Two","Thr","Fou"};
//int shipNumber1 = 1; // number of such ship
//int shipNumber2 = 2; // number of such ship
//int shipNumber3 = 3; // number of such ship
//int shipNumber4 = 4; // number of such ship


string readData_of_Old_Names() {
	cout << "start of read old names" << endl;
	string OldShipNames = readData(); // read ship names inside file
	cout << "start read data" << endl;
	
	string shipNameSize = "";
	int jk = 0;
	for (int i = 0; i <= 3; i++) {
		shipNameSize = shipNameSizeMesh[i];
	
		for (int i = 1; i <= 4; i++) {
			std::size_t found; // finding position of first char of new full name of such ship inside all recorded names of ship
			string number = std::to_string(i);
			string ParticularOldShipName = shipName + shipNameSize + number; // shipOne1
			
			found = OldShipNames.find(ParticularOldShipName); // finding position of first char of particular full name of such ship inside all recorded names of ship
			int found_int = static_cast<int>(found);
			//cout << "its found: " << found_int + 2 << endl;
			if (found!=std::string::npos) {} // find position of ParticularFullShipName in OldShipNames
			
			
			//found_int = found_int + 1;
			string posYship;
			posYship = OldShipNames.at(found_int + 8);
			
			unsigned long posYship_int;
			try {
				posYship_int = stoi(posYship);
			} catch (const std::invalid_argument &ia) {
				std::cerr << "Invalid argument: " << ia.what() << std::endl;
			}
			std::cout << "posYship_int: " << posYship_int << std::endl;

			/////////////////////////////////
			string posXship;
			posXship = OldShipNames.at(found_int + 9);
			
			unsigned long posXship_int;
			try {
				posXship_int = stoi(posXship);
			} catch (const std::invalid_argument &ia) {
				std::cerr << "Invalid argument: " << ia.what() << std::endl;
			}
//			cout << "ITS FOUND: " << found << endl;
			std::cout << "posXship_int: " << posXship_int << std::endl;
			
			cout << "ParticularOldShipName is: " << ParticularOldShipName << endl;
			
			if (ParticularOldShipName == "shipOne1" && !found) {
				cout << "ParticularOldShipName...ShipOne1..." << ParticularOldShipName << endl;
				*posYshipOne1p = posYship_int;
				*posXshipOne1p = posXship_int;
			}
			
			if (ParticularOldShipName == "shipOne2" && found) {
				cout << "ParticularOldShipName...shipOne2..." << ParticularOldShipName << endl;
				*posYshipOne2p = posYship_int;
				*posXshipOne2p = posXship_int;
			}
				
			
			
			jk++;
			cout << "second cycle for " << jk << endl;
				
			
		}
	
	}
	return "x";
}




void ships (char *typedKey, int shipSize)
{
	if (*typedKey == 'w')
	{
		if (*posYp == 2) {
			*posYp = *posYp;
		} else {
			*posYp = *posYp - 1;
			        }
	}

	if (*typedKey == 's')
	{
		if (*posYp == 11) {
			*posYp = *posYp;
		} else {
			*posYp = *posYp + 1;
		};
	}
	
	if (*typedKey == 'a')
	{
		if (*posXp == 2) {
			*posXp = *posXp;
		} else {
			*posXp = *posXp - 1;
		};
	}
	
	if (*typedKey == 'd')
	{
		if (*posXp == 11) {
			*posXp = *posXp;
		} else {
			*posXp = *posXp + 1;
		};
	}
	
	if (*typedKey == 'e') {
		
		// if shipsize add here?
		
		

		
		
//		std::string shipNumber = std::to_string(shipNumber1); // transform int number to string so it will be possible to concatenate number of such ship to new full name
//		std::string NewFullShipName = shipName + shipNumber; // creating of new full name of such ship
		

		
	
//			shipNumber = std::to_string(shipNumber2);
//			NewFullShipName = shipName + shipNumber;
//			found = OldShipNames.find(NewFullShipName);
//			if (found!=std::string::npos)
//				std::cout << "first 'needle' found at: " << found << '\n';
//			*posYshipOne2p = found + 8;
//			*posXshipOne2p = found + 9;
			
			
			
			
//			for (shipNumber1; shipNumber1 <= 4; shipNumber1++) {
//				std::string shipNumber = std::to_string(shipNumber1);
//				std::string NewFullShipName = shipName + shipNumber;
//
//
				
//				if (!(strstr(OldShipNames.c_str(), NewFullShipName.c_str()))) {
//					writeData (OldShipNames, NewFullShipName, posYp, posXp);
//					break;
//				}
				
				
				
			//}
			
		
		
		
	}
	
	
	
	
	
	
		//std::string OldShipNames = "dsf";
	
	
	
	
	
}


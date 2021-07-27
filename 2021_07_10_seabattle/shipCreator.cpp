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


string ParticularOldShipNameMesh[10] = {"shipOne1","shipOne2","shipOne3","shipOne4",\
	"shipTwo1","shipTwo2","shipTwo3", "shipThr1","shipThr2","shipFou1",};

string readData_of_Old_Names() {
	cout << "start of read old names" << endl;
	//string OldShipNames = " ";
	string OldShipNames = readData(); // read ship names inside file
	cout << "start read data" << endl;
	cout << "OldShipNames: " << OldShipNames << endl;
	
	string shipNameSize = "";
	for (int i = 0; i <= 10; i++) {
		
		string ParticularOldShipName = ParticularOldShipNameMesh[i];
		//cout << "ITS ParticularOldShipName: " << ParticularOldShipName << endl;
		std::size_t found = 0; // finding position of first char of new full name of such ship inside all recorded names of ship
		found = OldShipNames.find(ParticularOldShipName); // finding position of first char of particular full name of such ship inside all recorded names of ship
		if (found!=std::string::npos) {} // find position of start of ParticularFullShipName in OldShipNames
		int found_int = static_cast<int>(found); // size_t found to int found_int
		
		// record value of position Y in string type
		string posYship;
		try {
			posYship = OldShipNames.at(found_int + 8);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
		
		// transform string position Y into unsigned long
		unsigned long posYship_int;
		try {
			posYship_int = stoi(posYship);
		} catch (const std::invalid_argument &ia) {
			std::cerr << "Invalid argument: " << ia.what() << std::endl;
		}
		
		// record value of position X in string type
		string posXship;
		try {
			posXship = OldShipNames.at(found_int + 9);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
		
		// transform string position X into unsigned long
		unsigned long posXship_int;
		try {
			posXship_int = stoi(posXship);
		} catch (const std::invalid_argument &ia) {
			std::cerr << "Invalid argument: " << ia.what() << std::endl;
		}
		
		if (ParticularOldShipName == "shipOne1" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipOne1p = posYship_int;
			*posXshipOne1p = posXship_int;
		}
		
		if (ParticularOldShipName == "shipOne2" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipOne2p = posYship_int;
			*posXshipOne2p = posXship_int;
		}
		if (ParticularOldShipName == "shipOne3" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipOne3p = posYship_int;
			*posXshipOne3p = posXship_int;
		}
		if (ParticularOldShipName == "shipOne4" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipOne4p = posYship_int;
			*posXshipOne4p = posXship_int;
		}
		
		// more ships 2 and 3 and 4
	
	}
	return "";
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
		string OldShipNames = readData(); // read ship names inside file
		if (shipSize == 1) {
			for (int i = 0; i <=3; i++) {
				string NewFullShipName = ParticularOldShipNameMesh[i];
				if (!(strstr(OldShipNames.c_str(), NewFullShipName.c_str()))) {
					writeData (OldShipNames, NewFullShipName, posYp, posXp);
					readData_of_Old_Names();
					break;
				}
			}
		}
	}
}


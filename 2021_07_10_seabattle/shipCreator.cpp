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
#include <tuple>
#include <vector>
#include "service.hpp"

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
using std::tuple;
using std::vector;


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
		catch (const std::out_of_range &oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
		
		// transform string position Y into unsigned long
		unsigned long posYship_int;
		try {
			posYship_int = stoi(posYship);
		} catch (const std::invalid_argument &ia) {
			std::cerr << "Invalid argument: " << ia.what() << std::endl;
		} catch (const std::out_of_range &oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
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
		} catch (const std::out_of_range &oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
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


//tuple<int, int> readData_for_check_pos (string NewFullShipName) {
//	string OldShipNames = readData(); // read ship names inside file
//	std::size_t found = 0; // finding position of first char of new full name of such ship inside all recorded names of ship
//	found = OldShipNames.find(NewFullShipName); // finding position of first char of particular full name of such ship inside all recorded names of ship
//	unsigned long posYship_int;
//	unsigned long posXship_int;
//	if (found!=std::string::npos) { // find position of start of ParticularFullShipName in OldShipNames
//	int found_int = static_cast<int>(found); // size_t found to int found_int
//
//		// record value of position Y in string type
//	string posYship;
//	try {
//		posYship = OldShipNames.at(found_int + 8);
//	}
//	catch (const std::out_of_range &oor) {
//		std::cerr << "Out of Range error: " << oor.what() << '\n';
//	}
//
//		// transform string position Y into unsigned long
//
//	try {
//		posYship_int = stoi(posYship);
//	} catch (const std::invalid_argument &ia) {
//		std::cerr << "Invalid argument: " << ia.what() << std::endl;
//	} catch (const std::out_of_range &oor) {
//		std::cerr << "Out of Range error: " << oor.what() << '\n';
//	}
//
//		// record value of position X in string type
//	string posXship;
//	try {
//		posXship = OldShipNames.at(found_int + 9);
//	}
//	catch (const std::out_of_range& oor) {
//		std::cerr << "Out of Range error: " << oor.what() << '\n';
//	}
//
//		// transform string position X into unsigned long
//
//	try {
//		posXship_int = stoi(posXship);
//	} catch (const std::invalid_argument &ia) {
//		std::cerr << "Invalid argument: " << ia.what() << std::endl;
//	} catch (const std::out_of_range &oor) {
//		std::cerr << "Out of Range error: " << oor.what() << '\n';
//	}
//	} else {
//		posYship_int = 0;
//		posXship_int = 0;
//	}
//
//	return {posYship_int, posXship_int};
//}


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
		//vector<int> recordedPosY;
		//vector<int> recordedPosX;
		vector<int> recordedYX;
		recordedYX.push_back(*posYshipOne1p);
		recordedYX.push_back(*posXshipOne1p);
		recordedYX.push_back(*posYshipOne2p);
		recordedYX.push_back(*posXshipOne2p);
		recordedYX.push_back(*posYshipOne3p);
		recordedYX.push_back(*posXshipOne3p);
		recordedYX.push_back(*posYshipOne4p);
		recordedYX.push_back(*posXshipOne4p);
		
		
//		for (int k = 0; k <= 10; k++) {
//			string NewFullShipName = ParticularOldShipNameMesh[k];
//
//			//auto [posYship_int, posXship_int] = readData_for_check_pos (NewFullShipName);
////			recordedPosY.push_back(posYship_int);
////			recordedPosX.push_back(posXship_int);
////			std::cout << "ITS posYship_int from file" << posYship_int << endl;
////			std::cout << "ITS posXship_int from file" << posXship_int << endl;
//
//		}
			
			int posY = *posYp;
			posY--;
			int posX = *posXp;
			posX--;
			
			std::cout << "ITS posY!!!: " << posY << endl;
			
			std::cout << "ITS posX!!!: " << posX << endl;
		for (int x : recordedYX) {
			cout << "its recordedPosYX" << x << " ";
		}
//		for (int x : recordedPosX) {
//			cout << "its recordedPosX" << x << " ";
//		}
		bool exist = false;
		for (int i = 0; i <= 20; i++) {
			if (((posY == recordedYX[i]) && (posX == recordedYX[i+1]))) { //|| ((recordedYX[i] == 0) && (recordedYX[i+1] == 0))
				std::cout << "ITS here..............................." << std::endl;
				exist = true;
			}
			if (exist == true) {
				break;
			}
		}
		
		if (exist == false || recordedYX.empty()) {
			if (shipSize == 1) {
				for (int i = 0; i <=3; i++) {
					string NewFullShipName = ParticularOldShipNameMesh[i];
					
					if (!(strstr(OldShipNames.c_str(), NewFullShipName.c_str()))) {
						writeData (OldShipNames, NewFullShipName, posYp, posXp);
						std::cout << "WRITING..." << endl;
						readData_of_Old_Names();
						break;
					}
				}
			}
		}
	}
}


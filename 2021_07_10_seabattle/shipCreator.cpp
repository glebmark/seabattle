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

//extern int *const posYp;
//extern int *const posXp;
//extern unsigned long *const posYshipOne1p;
//extern unsigned long *const posXshipOne1p;
//extern unsigned long *const posYshipOne2p;
//extern unsigned long *const posXshipOne2p;
//extern unsigned long *const posYshipOne3p;
//extern unsigned long *const posXshipOne3p;
//extern unsigned long *const posYshipOne4p;
//extern unsigned long *const posXshipOne4p;
//
//extern unsigned long *const posYshipTwo1p;
//extern unsigned long *const posXshipTwo1p;
//extern unsigned long *posYshipTwo1p_2;
//extern unsigned long *posXshipTwo1p_2;
//
//extern unsigned long *const posYshipTwo3p;
//extern unsigned long *const posXshipTwo3p;
//extern unsigned long *posYshipTwo3p_2;
//extern unsigned long *posXshipTwo3p_2;

//extern unsigned long *const posYshipThr1p;
//extern unsigned long *const posXshipThr1p;
//extern unsigned long *posYshipThr1p_2;
//extern unsigned long *posXshipThr1p_2;
//extern unsigned long *posYshipThr1p_3;
//extern unsigned long *posXshipThr1p_3;
//
//extern unsigned long *const posYshipThr2p;
//extern unsigned long *const posXshipThr2p;
//extern unsigned long *posYshipThr2p_2;
//extern unsigned long *posXshipThr2p_2;
//extern unsigned long *posYshipThr2p_3;
//extern unsigned long *posXshipThr2p_3;

//extern unsigned long *const posYshipFou1p;
//extern unsigned long *const posXshipFou1p;
//extern unsigned long *posYshipFou1p_2;
//extern unsigned long *posXshipFou1p_2;
//extern unsigned long *posYshipFou1p_3;
//extern unsigned long *posXshipFou1p_3;
//extern unsigned long *posYshipFou1p_4;
//extern unsigned long *posXshipFou1p_4;

using std::string;
using std::cout;
using std::endl;
using std::tuple;
using std::vector;


string ParticularOldShipNameMesh[10] = {"shipOne1","shipOne2","shipOne3","shipOne4",\
	"shipTwo1","shipTwo2","shipTwo3", "shipThr1","shipThr2","shipFou1",};

string readData_of_Old_Names() {
	cout << "start of read old names" << endl;
	string OldShipNames = readData(); // read ship names inside file
	cout << "start read data" << endl;
	cout << "OldShipNames: " << OldShipNames << endl;
	
	string shipNameSize = "";
	for (int i = 0; i <= 10; i++) {
		
		string ParticularOldShipName = ParticularOldShipNameMesh[i];
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
		if (ParticularOldShipName == "shipTwo1" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipTwo1p = posYship_int;
			*posXshipTwo1p = posXship_int;
			// store coordinates of dependent block of ship
			unsigned long posYshipTwo1p_2_var = *posYshipTwo1p;
			unsigned long posXshipTwo1p_2_var = *posXshipTwo1p;
			*posYshipTwo1p_2 = posYshipTwo1p_2_var;
			*posXshipTwo1p_2 = posXshipTwo1p_2_var + 1;
		}
		if (ParticularOldShipName == "shipTwo2" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipTwo2p = posYship_int;
			*posXshipTwo2p = posXship_int;
				// store coordinates of dependent block of ship
			unsigned long posYshipTwo2p_2_var = *posYshipTwo2p;
			unsigned long posXshipTwo2p_2_var = *posXshipTwo2p;
			*posYshipTwo2p_2 = posYshipTwo2p_2_var;
			*posXshipTwo2p_2 = posXshipTwo2p_2_var + 1;
		}
		if (ParticularOldShipName == "shipTwo3" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipTwo3p = posYship_int;
			*posXshipTwo3p = posXship_int;
				// store coordinates of dependent block of ship
			unsigned long posYshipTwo3p_2_var = *posYshipTwo3p;
			unsigned long posXshipTwo3p_2_var = *posXshipTwo3p;
			*posYshipTwo3p_2 = posYshipTwo3p_2_var;
			*posXshipTwo3p_2 = posXshipTwo3p_2_var + 1;
		}
		
		if (ParticularOldShipName == "shipThr1" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipThr1p = posYship_int;
			*posXshipThr1p = posXship_int;
				// store coordinates of dependent block of ship
			unsigned long posYshipThr1p_2_var = *posYshipThr1p;
			unsigned long posXshipThr1p_2_var = *posXshipThr1p;
			*posYshipThr1p_2 = posYshipThr1p_2_var;
			*posXshipThr1p_2 = posXshipThr1p_2_var + 1;
			*posYshipThr1p_3 = posYshipThr1p_2_var;
			*posXshipThr1p_3 = posXshipThr1p_2_var + 2;
		}
		if (ParticularOldShipName == "shipThr2" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipThr2p = posYship_int;
			*posXshipThr2p = posXship_int;
				// store coordinates of dependent block of ship
			unsigned long posYshipThr2p_2_var = *posYshipThr2p;
			unsigned long posXshipThr2p_2_var = *posXshipThr2p;
			*posYshipThr2p_2 = posYshipThr2p_2_var;
			*posXshipThr2p_2 = posXshipThr2p_2_var + 1;
			*posYshipThr2p_3 = posYshipThr2p_2_var;
			*posXshipThr2p_3 = posXshipThr2p_2_var + 2;
		}
		if (ParticularOldShipName == "shipFou1" && (strstr(OldShipNames.c_str(), ParticularOldShipName.c_str()))) {
			*posYshipFou1p = posYship_int;
			*posXshipFou1p = posXship_int;
				// store coordinates of dependent block of ship
			unsigned long posYshipFou1p_2_var = *posYshipFou1p;
			unsigned long posXshipFou1p_2_var = *posXshipFou1p;
			*posYshipFou1p_2 = posYshipFou1p_2_var;
			*posXshipFou1p_2 = posXshipFou1p_2_var + 1;
			*posYshipFou1p_3 = posYshipFou1p_2_var;
			*posXshipFou1p_3 = posXshipFou1p_2_var + 2;
			*posYshipFou1p_4 = posYshipFou1p_2_var;
			*posXshipFou1p_4 = posXshipFou1p_2_var + 3;
		}
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
		vector<int> recordedYX;
		recordedYX.push_back(*posYshipOne1p);
		recordedYX.push_back(*posXshipOne1p);
		recordedYX.push_back(*posYshipOne2p);
		recordedYX.push_back(*posXshipOne2p);
		recordedYX.push_back(*posYshipOne3p);
		recordedYX.push_back(*posXshipOne3p);
		recordedYX.push_back(*posYshipOne4p);
		recordedYX.push_back(*posXshipOne4p);
		
		recordedYX.push_back(*posYshipTwo1p);
		recordedYX.push_back(*posXshipTwo1p);
		recordedYX.push_back(*posYshipTwo1p_2);
		recordedYX.push_back(*posXshipTwo1p_2);
		
		recordedYX.push_back(*posYshipTwo2p);
		recordedYX.push_back(*posXshipTwo2p);
		recordedYX.push_back(*posYshipTwo2p_2);
		recordedYX.push_back(*posXshipTwo2p_2);
		
		recordedYX.push_back(*posYshipTwo3p);
		recordedYX.push_back(*posXshipTwo3p);
		recordedYX.push_back(*posYshipTwo3p_2);
		recordedYX.push_back(*posXshipTwo3p_2);
		
		recordedYX.push_back(*posYshipThr1p);
		recordedYX.push_back(*posYshipThr1p);
		recordedYX.push_back(*posYshipThr1p_2);
		recordedYX.push_back(*posXshipThr1p_2);
		recordedYX.push_back(*posYshipThr1p_3);
		recordedYX.push_back(*posXshipThr1p_3);
		
		recordedYX.push_back(*posYshipThr2p);
		recordedYX.push_back(*posYshipThr2p);
		recordedYX.push_back(*posYshipThr2p_2);
		recordedYX.push_back(*posXshipThr2p_2);
		recordedYX.push_back(*posYshipThr2p_3);
		recordedYX.push_back(*posXshipThr2p_3);
		
		recordedYX.push_back(*posYshipFou1p);
		recordedYX.push_back(*posYshipFou1p);
		recordedYX.push_back(*posYshipFou1p_2);
		recordedYX.push_back(*posXshipFou1p_2);
		recordedYX.push_back(*posYshipFou1p_3);
		recordedYX.push_back(*posXshipFou1p_3);
		recordedYX.push_back(*posYshipFou1p_4);
		recordedYX.push_back(*posXshipFou1p_4);
		
		//add all coordinates of ships
		
			int posY = *posYp;
			posY--;
			int posX = *posXp;
			posX--;
			
			std::cout << "ITS posY!!!: " << posY << endl;
			std::cout << "ITS posX!!!: " << posX << endl;
		for (int x : recordedYX) {
			cout << "its recordedPosYX" << x << " ";
		}
		
		bool exist = false;
		for (int i = 0; i <= 40; i++) {
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
			} else if (shipSize == 2) {
				for (int i = 4; i <=6; i++) {
					string NewFullShipName = ParticularOldShipNameMesh[i];
					
					if (!(strstr(OldShipNames.c_str(), NewFullShipName.c_str()))) {
						writeData (OldShipNames, NewFullShipName, posYp, posXp);
						std::cout << "WRITING..." << endl;
						readData_of_Old_Names();
						break;
					}
				}
			} else if (shipSize == 3) {
				for (int i = 7; i <=8; i++) {
					string NewFullShipName = ParticularOldShipNameMesh[i];
					
					if (!(strstr(OldShipNames.c_str(), NewFullShipName.c_str()))) {
						writeData (OldShipNames, NewFullShipName, posYp, posXp);
						std::cout << "WRITING..." << endl;
						readData_of_Old_Names();
						break;
					}
				}
			} else if (shipSize == 4) {
				int i = 9;
				string NewFullShipName = ParticularOldShipNameMesh[i];
				
				if (!(strstr(OldShipNames.c_str(), NewFullShipName.c_str()))) {
					writeData (OldShipNames, NewFullShipName, posYp, posXp);
					std::cout << "WRITING..." << endl;
					readData_of_Old_Names();
//					break;
				}
//				for (int i = 9; i <=9; i++) {
//
//				}
			}
		}
	}
}


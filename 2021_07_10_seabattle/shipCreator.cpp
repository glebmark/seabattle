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
extern int *const posYshipOne1p;
extern int *const posXshipOne1p;
extern int *const posYshipOne2p;
extern int *const posXshipOne2p;

void ships (char *typedKey, int shipSize)
{
	std::string shipName = "shipOne";
	int shipNumber1 = 1;
	int shipNumber2 = 2;
	int shipNumber3 = 3;
	int shipNumber4 = 4;
	

	if (shipSize == 1) {

		if (*typedKey == 'w')
		{
			if (*posYp == 2) {
				*posYp = *posYp;
			} else {
				*posYp = *posYp - 1;
			};
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
		
	} //else if (shipSize != '1' || shipSize != '2' || shipSize != '3' || shipSize != '4' || shipSize != '0' ) {
		//return 1;
	//}
	if (*typedKey == 'e') {
		std::string OldShipNames = readData();
		
		
		std::string shipNumber = std::to_string(shipNumber1);
		std::string NewFullShipName = shipName + shipNumber;
		std::size_t found = OldShipNames.find(NewFullShipName);
		if (found!=std::string::npos)
			std::cout << "first 'needle' found at: " << found << '\n';
		*posYshipOne1p = found + 8;
		*posXshipOne1p = found + 9;
		
		shipNumber = std::to_string(shipNumber2);
		NewFullShipName = shipName + shipNumber;
		found = OldShipNames.find(NewFullShipName);
		if (found!=std::string::npos)
			std::cout << "first 'needle' found at: " << found << '\n';
		*posYshipOne2p = found + 8;
		*posXshipOne2p = found + 9;
		
		
		
		
		for (shipNumber1; shipNumber1 <= 4; shipNumber1++) {
			std::string shipNumber = std::to_string(shipNumber1);
			std::string NewFullShipName = shipName + shipNumber;
			
			
			
			if (!(strstr(OldShipNames.c_str(), NewFullShipName.c_str()))) {
				writeData (OldShipNames, NewFullShipName, posYp, posXp);
				break;
			}
			
			
			
		}
		
		
		
		
	}
	
	
	
	
	
	
	//std::string OldShipNames = "dsf";
	
	
	
	
	
}

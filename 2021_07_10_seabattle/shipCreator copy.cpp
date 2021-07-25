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

extern int *const posYp;
extern int *const posXp;


void ship1 (char *typedKey)
{
	std::string shipName = "shipOne";
	std::string shipNumber1 = "One";
	std::string shipNumber2 = "Two";
	std::string shipNumber3 = "Three";
	std::string shipNumber4 = "Four";
	
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
	
	
	
	//int ships =
	readData();
	//if ((strstr(ships.c_str(), shipName.c_str())))
	
	std::string NewFullShipName = shipName + shipNumber1;
	//writeData (ships, NewFullShipName);

}

//
//  database.hpp
//  2021_07_10_seabattle
//
//  Created by Gleb Markin on 10.07.2021.
//

#ifndef database_hpp
#define database_hpp

#include <stdio.h>
#include <string>
#include <fstream>
extern int *const posYp;
extern int *const posXp;

std::string readData();
int writeData (std::string OldShipNames, std::string NewShipName, int *posYp, int *posXp);


#endif /* database_hpp */


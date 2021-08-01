//
//  main.cpp
//  2021_07_10_seabattle
//
//  Created by Gleb Markin on 10.07.2021.
//

#include <iostream>
#include "grid.hpp"
#include "OS.hpp"

int main(int argc, const char * argv[]) {
	char x = *get_platform_name();
	std::cout << "ITS OS: " << x << std::endl;
	cycle(); // run main cycle
	return 0;
}


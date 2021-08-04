# seabattle

It is my first study project written in c++. I had been coding it for couple of weeks before I uploaded it here.
This version of Sea Battle (also known as Battleship) designed to be purely a terminal game.
Multiple players and remote access via TCP are going to be added soon.

tested on Macos 11.2.1
complier: clang-1205.0.22.11
linker settings: -lcurses

todo:
- forbid add new ships //done!
- add write function calling which will write some service value at begin of file - it is needed to prevent reading into variable "found" zero value, which broke checking if statement at first ship
- decide wether program will allow place vertical ships, or just horizontal
- delete showing zero zero pointer

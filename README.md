# seabattle

It is my first study project written in c++. I had been coding it for couple of weeks before I uploaded it here.
This version of Sea Battle (also known as Battleship) designed to be purely a terminal game.
Multiple players and remote access via TCP are going to be added soon.

tested on Macos 11.2.1
linker settings: -lcurses

todo:
- add support of Windows and Linux
- forbid add new ships
- add write function calling which will write some service value at begin of file - it is needed to prevent reading into variable "found" zero value, which broke checking if statement at first ship
- decide wether program will allow place vertical ships, or just horizontal
- delete showing zero zero pointer

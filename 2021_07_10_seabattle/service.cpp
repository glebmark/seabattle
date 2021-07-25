//
//  service.cpp
//  2021_07_10_seabattle
//
//  Created by Gleb Markin on 10.07.2021.
//

#include "service.hpp"
#include <termios.h>
#include <unistd.h>
#include <term.h>


	// get typed key
char *getStr( char *buffer , int maxRead ) {
	int  numRead  = 0;
	char ch;
	
	struct termios old = {0};
	struct termios newm = {0};
	if( tcgetattr( 0 , &old ) < 0 )        perror( "tcgetattr() old settings" );
	if( tcgetattr( 0 , &newm ) < 0 )        perror( "tcgetaart() newm settings" );
	cfmakeraw( &newm );
	if( tcsetattr( 0 , TCSADRAIN , &newm ) < 0 ) perror( "tcssetattr makeraw newm" );
	
	for( int i = 0 ; i < maxRead ; i++)  {
		ch = getchar();
		switch( ch )  {
			case EOF:
			case '\n':
			case '\r':
				goto exit_getStr;
				break;
				
			default:
					//        printf( "%1c" , ch );
				buffer[ numRead++ ] = ch;
				if( numRead >= maxRead )  {
					goto exit_getStr;
				}
				break;
		}
	}
	
exit_getStr:
	if( tcsetattr( 0 , TCSADRAIN , &old) < 0)   perror ("tcsetattr reset to old" );
		//  printf( "\n" );
		//    cout << "its bufer! " << buffer << endl;
	return buffer;
}

void ClearScreen()
{
	if (!cur_term)
	{
		int result;
		setupterm( NULL, STDOUT_FILENO, &result );
		if (result <= 0) return;
	}
	
	putp( tigetstr( "clear" ) );
}


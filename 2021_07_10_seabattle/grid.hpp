//
//  grid.hpp
//  2021_07_10_seabattle
//
//  Created by Gleb Markin on 10.07.2021.
//

#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>

void cycle();
void grid();
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

extern unsigned long *const posYshipTwo1p;
extern unsigned long *const posXshipTwo1p;
extern unsigned long *posYshipTwo1p_2;
extern unsigned long *posXshipTwo1p_2;

extern unsigned long *const posYshipTwo2p;
extern unsigned long *const posXshipTwo2p;
extern unsigned long *posYshipTwo2p_2;
extern unsigned long *posXshipTwo2p_2;

extern unsigned long *const posYshipTwo3p;
extern unsigned long *const posXshipTwo3p;
extern unsigned long *posYshipTwo3p_2;
extern unsigned long *posXshipTwo3p_2;


extern unsigned long *const posYshipThr1p;
extern unsigned long *const posXshipThr1p;
extern unsigned long *posYshipThr1p_2;
extern unsigned long *posXshipThr1p_2;
extern unsigned long *posYshipThr1p_3;
extern unsigned long *posXshipThr1p_3;

extern unsigned long *const posYshipThr2p;
extern unsigned long *const posXshipThr2p;
extern unsigned long *posYshipThr2p_2;
extern unsigned long *posXshipThr2p_2;
extern unsigned long *posYshipThr2p_3;
extern unsigned long *posXshipThr2p_3;

extern unsigned long *const posYshipThr3p;
extern unsigned long *const posXshipThr3p;
extern unsigned long *posYshipThr3p_2;
extern unsigned long *posXshipThr3p_2;
extern unsigned long *posYshipThr3p_3;
extern unsigned long *posXshipThr3p_3;

extern unsigned long *const posYshipFou1p;
extern unsigned long *const posXshipFou1p;
extern unsigned long *posYshipFou1p_2;
extern unsigned long *posXshipFou1p_2;
extern unsigned long *posYshipFou1p_3;
extern unsigned long *posXshipFou1p_3;
extern unsigned long *posYshipFou1p_4;
extern unsigned long *posXshipFou1p_4;

extern int *const player_p;
extern int *const gameMode;


#endif /* grid_hpp */


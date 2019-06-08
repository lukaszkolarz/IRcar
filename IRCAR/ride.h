#ifndef IRCAR_RIDE_H			
#define IRCAR_RIDE_H



#include <avr/io.h>
#include <util/delay.h>

#define direction_DDR DDRD		//defining constants 
#define direction_PORT PORTD
#define Rfore 3
#define Rrear 4					//right engine direction ports
#define Lfore 5
#define Lrear 6					//left engine direction ports

#define Lenable 0				//enable (in future may be PWM)
#define Penable 1

void forward();					//defining functions	
void left();
void right();
void reverse();
void stop_run();
void stop_turn();




#endif
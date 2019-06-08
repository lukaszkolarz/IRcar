#include <avr/io.h>
#include <util/delay.h> 
#include "ride.h"
#include "IR_Receiver.h"
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>

struct IR_Packet received_packet;

int main(void)
{
	direction_DDR |= (1<<Rfore) | (1<<Lfore) | (1<<Rrear) | (1<<Lrear) | (1<<Penable) | (1<<Lenable);			//setting 3,4,5,6 bytes on portD as an output
    init_receiver();
	sei();
	
	while (1)																									//essential program
    {
		cli();
		uint8_t check_result = check_new_packet(&received_packet);
		sei();
		
		if (check_result)																						
		{	
				if(received_packet.command==7)//left			
					left();
				if(received_packet.command==6)//right
					right();
				if(received_packet.command==64)//forward
					forward();
				if(received_packet.command==65)//backward
					reverse();
				}
		_delay_ms(50);
	
    }
}


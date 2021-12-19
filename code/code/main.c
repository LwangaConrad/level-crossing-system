/*
 * code.c
 *
 * Created: 12/17/2021 7:14:04 PM
 * Author : conrad
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000ul
#define rs PH0
#define rw PH1
#define enable PH2
#define dataline PORTJ
unsigned char word[] = "Cross";
unsigned char word2[] = "Stop";

int main(void)
{
    /*
		LWANGA CONRAD ARTHUR 1800721116 18/U/21116/PS
		ASIIMWE JULIANA 217009724 17/U/3029/EVE
	*/
	DDRG = 0x00;
	DDRL = 0xFF;
	DDRF = 0b00001111;
	DDRJ = 0xFF;
	DDRH = 0xFF;
	DDRK = 0xFF;
	DDRB = 0xFF;
	DDRA = 0xFF;
	int x,l,t,i;
	int wer = 0;
	TCCR0B |= (1<<CS00);
	TCNT0 = 0x0;

	PORTF = 0xFF;
	PORTA = 0x3;
	PING = 0xFF;
	//switch on green led
	PORTB |= 0xF;
	PORTH &= ~(1<<enable);
	_delay_ms(1);
	PORTH |= (1<<enable);
	_delay_ms(1);

	PORTH &= ~(1<<rs);
	PORTH &= ~(1<<rw);

	PORTH &= ~(1<<enable);
	_delay_ms(1);
	PORTH |= (1<<enable);
	_delay_ms(1);

	PORTJ = 0x0F;
	PORTH &= ~(1<<enable);
	_delay_ms(1);
	PORTH |= (1<<enable);
	_delay_ms(1);

	PORTH |= (1<<rs);
	PORTH &= ~(1<<rw);
	for(x = 0; x < 5; x++){
		PORTJ = word[x];
		PORTH &= ~(1<<enable);
		_delay_ms(1);
		PORTH |= (1<<enable);
		_delay_ms(1);
	}
	    while (1) 
    {
		//when 0 is pressed
		PORTF = 0b11111011;
		if((PINF & (1<<7)) == 0){
			//switch off green leds
			PORTB &= 0xF0;
			//turn motor clockwise
			PORTL = 0b00000010;
			//change led to 3 minutes
			PORTA = 0xd;
			//change lcd status to --Stop--
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH &= ~(1<<rs);
			PORTH &= ~(1<<rw);
			
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTJ = 0x01;
			PORTH &= ~(1<<enable);
			_delay_ms(1);
			PORTH |= (1<<enable);
			_delay_ms(1);
			
			PORTH |= (1<<rs);
			PORTH &= ~(1<<rw);
			
			for(l = 0; l < 4; l++){
				PORTJ = word2[l];
				PORTH &= ~(1<<enable);
				_delay_ms(1);
				PORTH |= (1<<enable);
				_delay_ms(1);
			}
			
					for (i = 0; i < 20; i++)
					{
						//light red led
						PORTB ^= 0xF0;
						//sound buzzer
						PORTK ^= (1<<0);
						_delay_ms(200);
					}
					for (i = 0; i < 180; i++)
					{
						PORTL = 0b00000000;
						PORTB ^= 0xF0;
						PORTK ^= (1<<0);
						_delay_ms(200);
					}
					for (i = 0; i < 100; i++)
					{
						PORTB ^= 0xF0;
						PORTK ^= (1<<0);
						_delay_ms(200);
					}
						//remove 1 minute from led 
						PORTA = 0x25;
					for (i = 0; i < 300; i++)
					{
						PORTB ^= 0xF0;
						PORTK ^= (1<<0);
						_delay_ms(200);
					}
						//remove 1 minute from led
						PORTA = 0x9f;
					for (i = 0; i < 300; i++)
					{
						PORTB ^= 0xF0;
						PORTK ^= (1<<0);
						_delay_ms(200);
					}
						//remove 1 minute from led to bring it back to 0
						PORTA = 0x3;
						//stop buzzer
						PORTK &= ~(1<<0);
						//switch on green led
						PORTB |= 0xF;
						//turn motor anticlockwise
						PORTL = 0b00000001;
						//change lcd status to Cross
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
						
						PORTH &= ~(1<<rs);
						PORTH &= ~(1<<rw);
						
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
						
						PORTJ = 0x01;
						PORTH &= ~(1<<enable);
						_delay_ms(1);
						PORTH |= (1<<enable);
						_delay_ms(1);
						
						PORTH |= (1<<rs);
						PORTH &= ~(1<<rw);

						for(t = 0; t < 5; t++){
							PORTJ = word[t];
							PORTH &= ~(1<<enable);
							_delay_ms(1);
							PORTH |= (1<<enable);
							_delay_ms(1);
						}
						for (i = 0; i < 20; i++)
						{
							_delay_ms(200);
						}
						PORTL = 0b00000000;
						
				}
		}
}




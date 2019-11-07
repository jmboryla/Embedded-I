#include <avr/io.h>
#include <util/delay.h>

int main (void){
  //initializing DDRB so that pins 11,12,and 13 are in output mode
  DDRD = 0x7F;
  DDRB = 0x00;
  //Infinite loop
  while (1)
  {
     //9
    PORTD= 0x6F;
    _delay_ms(1000);
     //8
    PORTD= 0x7F;
    _delay_ms(1000);
    //7
    PORTD= 0x07;
    _delay_ms(1000);
     //6
    PORTD= 0x7D;
    _delay_ms(1000);
    //5
    PORTD= 0x6D;
    _delay_ms(1000);
    //4
    PORTD= 0x66;
    _delay_ms(1000);
      //3
    PORTD= 0x4F;
    _delay_ms(1000);
      //2
    PORTD= 0x5B;
    _delay_ms(1000);
     //1
    PORTD= 0x06;
    _delay_ms(1000);
    
    
  
 
  }
  return 0;
}


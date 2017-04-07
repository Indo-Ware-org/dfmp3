#include <mega328p.h>
#include <dfmp3.c>

#define music PIND.2

void main(void){
#pragma optsize-
CLKPR=0x80;
CLKPR=0x00;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

UCSR0B=0x98;// UART 9600bps
UCSR0C=0x06;
UBRR0L=0x67;

ACSR=0x80;

PORTD.2=1;
//Playback MP3 dari SD card dfmp3(playbacksource,1);
while (1){

//Mainkan track no.1      
dfmp3(tracknum,1);
//tunggu hingga music berhenti
while(music);while(!music);

//Mainkan track no.2      
dfmp3(tracknum,2);
//tunggu hingga music berhenti
while(music);while(!music);

//Mainkan track no.3      
dfmp3(tracknum,3);
//tunggu hingga music berhenti
while(music);while(!music);
      }
}

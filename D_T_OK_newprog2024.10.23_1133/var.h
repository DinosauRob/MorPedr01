

//2024 10 29 - 00.08

#define data_h  PORTG &= ~(1 << 5) // pin 4 data  l
#define data_l  PORTG |=  (1 << 5) // pin 4 data  h
#define inh_l   PORTE &= ~(1 << 3) // pin 5 data  l
#define inh_h   PORTE |=  (1 << 3) // pin 5 data  h
#define shift_l PORTH &= ~(1 << 3) // pin 6 data  l
#define shift_h PORTH |=  (1 << 3) // pin 6 data  h
#define store_l PORTH &= ~(1 << 4) // pin 7 store l
#define store_h PORTH |=  (1 << 4) // pin 7 store h

#define KEY PINE & (1 << 5)

#define GIU   'a'
#define SU    'b'
#define CLEAR 'c'
#define SX    'd'
#define STP   'e'
#define ENTER 'f'
#define START 'g'
#define F5    'h'
#define F4    'i'
#define F3    'j'
#define F2    'k'
#define F1    'l'
#define DX    'm'
#define ESC   'n'
#define CTRL  'o'

volatile bool debora=false;
volatile char key='x';
volatile byte sh_4=0;
volatile byte sh_12=0;
volatile byte sh_4_m=0;
volatile byte sh_12_m=0;
volatile bool key_r=false;
volatile byte kf=false;

static uint16_t unos[] = 
{ 0b1111111111111110, 0b1111111111111101, 0b1111111111111011, 0b1111111111110111,
  0b1111111111101111, 0b1111111111011111, 0b1111111110111111, 0b1111111101111111,
  0b1111111011111111, 0b1111110111111111, 0b1111101111111111, 0b1111011111111111,
  0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000 };

static uint16_t m4[] = 
{ 0b1000111111111111, 0b0100111111111111, 0b0010111111111111, 0b0001111111111111, 0b1001111111111111 };
//{ 0b1000111111111111, 0b0100111111111111, 0b0010111111111111, 0b0001111111111111};


const uint16_t matrix_hex[] = 
{
    0xF7,   // A
    0x128F, // B
    0x0039, // C
    0x120F, // D
    0xF9,   // E
    0xF1,   // F
    0x00BD, // G
    0xF6,   // H
    0x1209, // I
    0x001E, // J        
    0b0000110001110000, // K
    0x0038, // L
    0x0536, // M
    0b0000100100110110, // N
    0x003F, // O
    0xF3,   // P
    0b0000100000111111, // Q
        
    0b0000100011110011, // R
    0b0000000011101101, // S
    0x1201, // T
    0x003E, // U
    0b0010010000110000, // V
    0x2836, // W
    0x2D00, // X
    0x1500, // Y tsrnmkhgfedcba
    0b0010010000001001, // Z
    0b0000000000111111,  // 0
    0x406,  // 1
    0xDB,   // 2
    0x8F,   // 3
    0xE6,   // 4
    0b0000000011101101,   // 5
    0xFD,   // 6
    0x1401, // 7
    0b0000000011111111,   // 8
    0b0000000011101111    // 9
};


char sgrattona()
{
   
  if( sh_4_m==0 )
  {
    switch (sh_12_m) { case  0: return GIU; break;
                       case  1: return SU; break;
                       case  2: return CLEAR; break;
                       case  3: return '0'; break;
                       case  4: return '9'; break;
                       case  5: return '8'; break;
                       case  6: return '7'; break;
                       case  7: return '6'; break;
                       case  8: return '?'; break; 
                       case  9: return '?'; break; 
                       case 10: return '?'; break; 
                       case 11: return '?'; break; 
                       default: return 'z'; break; } 
  }
  if( sh_4_m==1 )
  {
    switch (sh_12_m) { case  0: return SX; break; //sinistra
                       case  1: return STP; break; //start
                       case  2: return '.'; break; //punto
                       case  3: return '5'; break; //5
                       case  4: return '4'; break; //4
                       case  5: return '3'; break; //3
                       case  6: return '2'; break; //2
                       case  7: return '1'; break; //1
                       case  8: return '?'; break; 
                       case  9: return '?'; break; 
                       case 10: return '?'; break; 
                       case 11: return '?'; break; 
                       default: return 'z'; break; } 
  }
  if( sh_4_m==2 )
  {
    switch (sh_12_m) { case  0: return ENTER; break; 
                       case  1: return START; break; 
                       case  2: return '-'; break; 
                       case  3: return F5; break; 
                       case  4: return F4; break; 
                       case  5: return F3; break; 
                       case  6: return F2; break; 
                       case  7: return F1; break; 
                       case  8: return '?'; break; 
                       case  9: return '?'; break; 
                       case 10: return '?'; break; 
                       case 11: return '?'; break; 
                       default: return 'z'; break; } 
  }
  if( sh_4_m==3 )
  {
    switch (sh_12_m) { case  0: return DX; break; 
                       case  1: return ESC; break; 
                       case  2: return CTRL; break; 
                       case  3: return '?'; break; 
                       case  4: return '?'; break; 
                       case  5: return '?'; break; 
                       case  6: return '?'; break; 
                       case  7: return '?'; break; 
                       case  8: return '?'; break; 
                       case  9: return '?'; break; 
                       case 10: return '?'; break; 
                       case 11: return '?'; break; 
                       default: return '?'; break; } 
  }
}



/*
// a.h
#ifndef A_H
#define A_H

// Dichiarazioni e definizioni di a.h

#include "b.h"

#endif // A_H

// b.h
#ifndef B_H
#define B_H

// Dichiarazioni e definizioni di b.h

#include "a.h"

#endif // B_H


#include "main.h"

*/

















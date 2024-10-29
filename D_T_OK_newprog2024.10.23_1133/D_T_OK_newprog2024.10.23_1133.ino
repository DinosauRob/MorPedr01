

//2024 10 29 - 00.08
//#include "/home/utente/progetti/arduino/esempio.h"// Percorso esterno assoluto
//#include "../librerie/esempio.h"// Percorso esterno relativo
#include <EEPROM.h>
#include "var.h"
#include "funz.h"
#include "menu.h"


void setup() 
{
  Serial.begin(115200);
  pinMode(3,  INPUT); //key
  pinMode(4, OUTPUT); data_h;
  pinMode(5, OUTPUT); inh_l;
  pinMode(6, OUTPUT); shift_h;
  pinMode(7, OUTPUT); store_h;


  Serial.println("23 Ott 2024 - 12:01");
}

void loop() 
{
//  if(Serial.available()){ser();}
  
  if(kf)
  {
    kf=false;
    matrix[0]=key=sgrattona();
    Serial.print(sh_4_m);    
    Serial.print('\t');    
    Serial.print(sh_12_m);
    Serial.print('\t');
    Serial.println(key);
  }

  scan();
}
void tastierella()
{
  switch('3')
  {
    case 'a': break;
    case 'b': break;
    case 'c': break;
    case 'd': break;
    case 'e': break;
    case 'f': break;
    case 'g': break;
    case 'h': break;
    case 'i': break;
    case 'j': break;
    case 'k': break;
    case 'l': break;
    case 'm': break;
    case 'n': break;
    case 'o': break;
     default: break;
  }
}


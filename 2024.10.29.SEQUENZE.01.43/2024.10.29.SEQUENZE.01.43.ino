
#define BAMF (1 << 0) // BIT APRI   MORSA FISSA
#define BCMF (1 << 1) // BIT CHIUDI MORSA FISSA
#define BAMM (1 << 2) // BIT APRI   MORSA MOBILE
#define BCMM (1 << 3) // BIT CHIUDI MORSA MOBILE
#define BACM (1 << 4) // BIT AVANTI   CARRO
#define BICM (1 << 5) // BIT INDIETRO CARRO
#define BDAR (1 << 6) // BIT DISCESA ARCHETTO
#define BSAR (1 << 7) // BIT SALITA  ARCHETTO
#define BLAM (1 << 8) // BIT LAMA



/////// XXX (XX & ~ RESET ) | SET )
#define AMF (Y1 & ~ BCMF ) | BAMF )
#define CMF (Y1 & ~ BAMF ) | BCMF )
#define RMF (Y1 & ~ (BAMF | BCMF) )

#define AMM (Y1 & ~ BCMM ) | BAMM )
#define CMM (Y1 & ~ BAMM ) | BCMM )
#define RMM (Y1 & ~ (BAMM | BCMM) )

#define ACAR (Y1 & ~ BICM ) | BACM )
#define ICAR (Y1 & ~ BACM ) | BICM )
#define RCAR (Y1 & ~ (BICM | BACM) )

#define DARC (Y1 & ~ BSAR ) | BDAR )
#define SARC (Y1 & ~ BDAR ) | BSAR )
#define RARC (Y1 & ~ (BSAR | BDAR) )

#define LAMA_R Y1 & ~ BLAM
#define LAMA_S Y1 | BLAM

#define FC_AA  X1&&(1 << 0) // BIT FC LAMA ALTA
#define FC_AB  X1&&(1 << 1) // BIT FC LAMA BASSA
#define RALLE  X1&&(1 << 2) // BIT FC RALLENTATORE
#define PRESS  X1&&(1 << 3) // BIT PRESSOSTATO OK
#define XXXX2  X1&&(1 << 4) // BIT INDEFINITO
#define XXXX1  X1&&(1 << 5) // BIT INDEFINITO
#define P_STA  X1&&(1 << 6) // BIT PULSANTE START
#define FC_AVA X1&&(1 << 7) // BIT FC CARRO AVANTI
#define FC_IND X1&&(1 << 8) // BIT FC CARRO INDIETRO

#define MAN 0
#define UNO 1
#define AUT 2
#define RESET 3
#define START 4
#define ALT 5


byte Y1 = 0;
byte X1 = 0;
byte autoManSing = MAN;


void setup() 
{
  
}
void loop() 
{
  switch(autoManSing)
  {
    case MAN: manuale();    break;
    case UNO: singolo();    break;
    case AUT: automatico(); break;
  }

}
byte manSw=0;
byte manNextSw=0;
unsigned long ManNextTime=0;
void manuale()
{
  switch(manSw)
  {
    case  0: if(key==START){manSw=10;} break;
    case 10: if(){} break;
    case 20: if(){} break;
    case 30: if(){} break;
    case 40: 
      LAMA_S; 
      nextTime=millis()+500;
      nextSw=41;
      sw_man=99;
    break;
    case 41: if(){} break;
    case 60: if(){} break;
    case 70: if(){} break;
    case 80: if(){} break;
    case 99: if(millis()>nextTime){manSw=nextSw;} break;
  }
}
void singolo(){}
void automatico(){}
 
//      if(FC_IND){RCAR;} else{ICAR;}
//      if(FC_AA) {RARC;} else{SARC;}
//      if(FC_AA) {RARC;} else{SARC;}
//      if(FC_AA) {RARC;} else{SARC;}
      

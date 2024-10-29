

//2024 10 29 - 00.08

#define TAMF millis()+500
#define TCMF millis()+500

unsigned long t_mf=0;
byte smf=0;


byte MorsaFissa()
{
  switch ( smf )
  {
    case  0: break; // da resettare
    case 10: AMF; t_mf=TAMF; break; // in apertura
    case 20: break; // aperta
    case 30: break; // in chiusura
    case 40: break; // chiusa
  }
}

bool mfc = false,
     mfa = false,
    arcs = false,
    arcg


    
void chiudiMorsa1()
{
  switch ( contareset )
  {
    case 10: arcSU(); break;
    
  }
  
}

byte fase_taglio = 10;
void taglia()
{
  switch ( fase_taglio )
  {
    case 10: if ( MFC ){ fase_taglio++; }
    case 10: if ( MFC ){ fase_taglio++; }
  }
}
byte matrix[30]="000000000000000000000000000000";

void scrivi(byte dove,String cosa)//102 scive sopra , cifra 3 _x________...
{                                 //201 scive sotto , cifra 0 X_________...
  if(dove>=101&&dove<=112)
  {
    for (int i = dove-101; i<cosa.length() && i<12; i++)
    {
      matrix[12+i] = cosa[i];
    }
  }
  else if(dove>=201&&dove<=212)
  {
    for (int i = dove-201; i<cosa.length() && i<12; i++)
    {
      matrix[i] = cosa[i];
    }
  }
  else{Serial.println("stai scrivendo a cazzo");}
}


void exmpl()
{
  String Str = "Hello, world!";
  char arr[] = "Hello, world!";
  for (int i = 0; i < Str.length(); i++){char c = Str[i];}
  for (int i = 0; arr[i] != '\0';   i++){char c = arr[i];}
}





























void shift_led(uint16_t a,uint16_t b,byte c);
void shift_595(uint16_t value);
uint16_t strippa(char c);
void scan();

void scan()
{
  for (sh_12 = 0; sh_12 < 12; sh_12++) 
  {
    shift_595(unos[sh_12]&m4[sh_4]);
    if(debora)
    {
      if(KEY&&sh_4_m==sh_4&&sh_12_m==sh_12){debora=false;}
    }
    if(!debora&&!(KEY)&&key_r) 
    {
      debora=true;
      sh_4_m=sh_4; 
      sh_12_m=sh_12;
      kf=true;
    }
    shift_led(strippa( matrix[(sh_12*2)+1] ),strippa( matrix[sh_12*2] ),0);
  }
  if(sh_4<3){sh_4++;} else{sh_4=0;}
}

void shift_595(uint16_t value) 
{
  key_r=false;
  shift_l;
  store_h; 
  delayMicroseconds(90);
  for (int i = 0; i < 16; i++) 
  {
    if (value & (1 << i)) {data_h;}
    else                  {data_l;}  
    shift_h; 
    
  delayMicroseconds(3);
    shift_l;  
    
  delayMicroseconds(90);
  }
  data_l;
  store_l; 
  store_h;
  
  delayMicroseconds(90);
  
  key_r=true;
}

void shift_led(uint16_t a,uint16_t b,byte c) 
{
  shift_l;
  data_h;
  inh_h; 
  shift_h; 
  shift_l; 
  for (int i = 0; i < 14; i++) 
    {
      if (a & (1 << i)) {data_h;}
      else              {data_l;}   
      shift_h; 
      shift_l; 
    }
  for (int i = 0; i < 14; i++) 
    {
      if (b & (1 << i)) {data_h;}
      else              {data_l;}   
      shift_h; 
      shift_l; 
    }
  for (int i = 0; i < 6; i++) 
    {
      if (c & (1 << i)) {data_h;}
      else              {data_l;}   
      shift_h; 
      shift_l; 
    }
  inh_l; 
}

uint16_t strippa(char c) 
{
    if (c >= 'A' && c <= 'Z')       { return matrix_hex[c - 'A'];    } 
    else if (c >= '0' && c <= '9')  { return matrix_hex[c - '0' + 26]; }
    else if (c >= '0' && c <= '9')  { return matrix_hex[c - '0' + 26]; }
    else if (c==' ')                { return 0b0000000000000000; }
    return 0; // Restituisce 0 se il carattere non è valido
}


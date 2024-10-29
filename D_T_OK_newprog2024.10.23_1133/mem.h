

//2024 10 29 - 00.08

//  Byte:  MSB                                                LSB
//         bit 7  bit 6  bit 5  bit 4  bit 3  bit 2  bit 1  bit 0

//EEPROM:  bit 1  bit 2  bit 3  bit 4  bit 5  bit 6  bit 7  bit 8
//#include <stdint.h>
//uint4_t my_4bit_var = 0b1010; // Assegna il valore binario 1010 (10 in decimale)

void avariable() 
{
  uint32_t avariato;
  EEPROM.put(0, avariato);
  EEPROM.get(0, avariato);
  EEPROM.get(sizeof(avariato), avariato);
  
  EEPROM.write(0, 0x42);
  EEPROM.read(0);
}

void writeEEPROM(byte b0, byte b1, byte b2, byte b3) {
  EEPROM.begin(512); // Inizializza la EEPROM
  
  // Scrivi i 4 byte nel settore predefinito
  EEPROM.write(EEPROM_SECTOR * 4, b0);
  EEPROM.write(EEPROM_SECTOR * 4 + 1, b1);
  EEPROM.write(EEPROM_SECTOR * 4 + 2, b2);
  EEPROM.write(EEPROM_SECTOR * 4 + 3, b3);
  
  EEPROM.commit(); // Salva le modifiche nella EEPROM
  EEPROM.end(); // Termina l'utilizzo della EEPROM
}

// Funzione per leggere 4 byte dalla EEPROM
void readEEPROM(byte* b0, byte* b1, byte* b2, byte* b3) {
  EEPROM.begin(512); // Inizializza la EEPROM
  
  // Leggi i 4 byte dal settore predefinito
  *b0 = EEPROM.read(EEPROM_SECTOR * 4);
  *b1 = EEPROM.read(EEPROM_SECTOR * 4 + 1);
  *b2 = EEPROM.read(EEPROM_SECTOR * 4 + 2);
  *b3 = EEPROM.read(EEPROM_SECTOR * 4 + 3);
  
  EEPROM.end(); // Termina l'utilizzo della EEPROM

  sector_address = 10 * 4 = 40

}


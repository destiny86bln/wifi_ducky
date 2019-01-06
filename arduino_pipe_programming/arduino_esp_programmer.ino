/* Temp Programm for the Arduino Controller on the CJMCU-3212
 * Needed to Flash the ESP2866 on the CJMCU-3212 board
 * Baud rate for the default baud rate of the nodemcu firmware flasher tool https://github.com/nodemcu/nodemcu-flasher
 */
int program_pin = 12;
int enable_pin = 13;

void setup()
{
  Serial1.begin(230400);
  Serial.begin(230400);
  pinMode(enable_pin, OUTPUT);
  pinMode(program_pin, OUTPUT);
  digitalWrite(program_pin, LOW);
  digitalWrite(enable_pin,HIGH);
}

void loop()
{
  while(Serial1.available()){
    Serial.write((uint8_t)Serial1.read());
  }

  if(Serial.available()){
    while(Serial.available()){
      Serial1.write((uint8_t)Serial.read());
    }
  }
}

int LED = 41;

void setup(){
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop(){
  byte a;
  while(Serial2.available()){
    byte inChar = (byte)Serial2.read();
    a = inChar; 
  }
  a = a - 48;
  Serial.print(a);
  Serial.print(F("\n"));
}

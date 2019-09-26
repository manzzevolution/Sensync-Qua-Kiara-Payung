void initFunction(){
  SerialMega.begin(9600);
  Serial.begin(115200);
  pinMode(pinLED,OUTPUT);
  pinMode(pinReset,OUTPUT);
  digitalWrite(pinReset,HIGH);
}

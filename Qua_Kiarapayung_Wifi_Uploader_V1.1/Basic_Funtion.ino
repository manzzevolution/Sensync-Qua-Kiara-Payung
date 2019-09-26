void resetData(){
  for(int i = 0; i < 9;i++){
    dataVal[i] = -1;
  }
}

void putHIGHReset(){
  digitalWrite(pinReset,HIGH);  
}

void resetArduinoMega(){
  Serial.println(F("Reset !"));
  digitalWrite(pinReset,HIGH);  
  delay(500);
  digitalWrite(pinReset,LOW);  
  delay(500);
  digitalWrite(pinReset,HIGH);
}

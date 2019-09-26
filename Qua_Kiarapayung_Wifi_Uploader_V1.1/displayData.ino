void displayData(){
  Serial.println(F("--------------------"));  
  Serial.print(F("pH           : ")); Serial.println(dataVal[0]);
  Serial.print(F("D-Oxygen     : ")); Serial.println(dataVal[1]);
  Serial.print(F("Conductivity : ")); Serial.println(dataVal[2]);    
  Serial.print(F("Turbidity    : ")); Serial.println(dataVal[3]);    
  Serial.print(F("Temperature  : ")); Serial.println(dataVal[4]);    
  Serial.print(F("Salt         : ")); Serial.println(dataVal[5]);    
  Serial.print(F("TDS          : ")); Serial.println(dataVal[6]);    
  Serial.print(F("SWSG         : ")); Serial.println(dataVal[7]);       
  Serial.print(F("Stat         : ")); Serial.println(dataVal[8]);   
  Serial.println(F("--------------------"));  
}

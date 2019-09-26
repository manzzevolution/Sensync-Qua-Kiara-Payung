String getDataFromMega(){
  bool quit = false;
  String seriesData = "";
  SerialFlashln("Waiting data from Mega");
  waktuLama = millis();
  SerialMega.setTimeout(100);
  Serial.setTimeout(100);
  while ((!quit) && (millis() - waktuLama <= timeout)){
    if (millis() % 1000 == 0){
      delay(1);
    }
    seriesData = SerialMega.readStringUntil('\n');
//    seriesData = Serial.readStringUntil('\n');
    if (seriesData != ""){
      quit = true;
    }
    Serial.print("Timeout Timer : ");
    Serial.print((millis() - waktuLama)/1000);
    Serial.print(" Seconds - Timeout in :");
    Serial.print(timeout/1000);
    Serial.println(" Seconds");
    digitalWrite(pinLED,!(digitalRead(pinLED)));
  }
  if (millis() - waktuLama >= timeout){
    cekTimeout = true;
  } else {
    cekTimeout = false;
  }
  Serial.println();
  SerialFlash("Raw Data : ");Serial.print(seriesData);SerialFlash(" Timeout Checker: ");Serial.println(cekTimeout);
  return seriesData;
}

void parsingData (String txt){
  //SerialFlashln("Parsing Data");
  String text = txt + ",";
  String arrayData[20];
  jumlahKoma = 0;
  int datake = 0;
  for(int i = 0; i < text.length();i++){
    if (text[i] != ','){
      arrayData[datake] += text[i];
    } else {
      datake++;
      jumlahKoma++;
    }
  }
//  for checking data array
  for(int i = 0; i < 11; i++){
    Serial.print(i+1);SerialFlash(". ");Serial.println(arrayData[i]);
  }
  for(int i = 0; i < 9 ;i++){
    dataVal[i] = arrayData[i].toFloat();
  }
}

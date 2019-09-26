#include "config.h";
void setup() {
  initFunction();
}

void loop() {
  digitalWrite(pinLED,HIGH);
  resetData();
  SerialMega.flush();
  parsingData(getDataFromMega());
  displayData();
  if (!cekTimeout){
    if (jumlahKoma > 8){
      UploadToDashboard();
    }else {
      Serial.println("Invalid Data!");
    }
  } else {
    resetArduinoMega();
  }
}

// ------------------------------------ Wifi Init ------------------------------------------
#define SerialFlashln(x) Serial.println(F(x))
#define SerialFlash(x) Serial.print(F(x))

#include <SoftwareSerial.h> 
SoftwareSerial SerialMega(D5,D6);

#define menit 15
float dataVal[9];
unsigned long waktuLama = 0;
unsigned long timeout = 1000 * 60 * menit ;
int jumlahKoma = 0;
bool cekTimeout = false;
#include "WifiParam.h"
#define retry 5
#define pinLED 2    //D4
#define pinReset 13 //D7

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
char ssid2[] = SECRET_SSID2;   // your network SSID (name) 
char pass2[] = SECRET_PASS2;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

String myStatus = "";
// ------------------------------------ Wifi End ------------------------------------------

// ------------------------------------ Sensync Dashboard Init ------------------------------------------
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

#define confirmResponse "ived"
#define idSensync "krwgq1"
#define uidSensync "DI7989104"

// ------------------------------------ End Sensync Dashboard ------------------------------------------

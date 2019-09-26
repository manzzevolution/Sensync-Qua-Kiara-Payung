void UploadToDashboard(){
  // Connect or reconnect to WiFi
  digitalWrite(pinLED,LOW);
  Serial.println(F("Upload to Sensync Dashboard"));
  delay(2000);
  Serial.println(F("Connect to WiFi"));
  delay(500);
  if(WiFi.status() != WL_CONNECTED){
    Serial.print(F("Attempting to connect to SSID: "));
    Serial.println(SECRET_SSID);
    int n = 1;
    while((WiFi.status() != WL_CONNECTED) && (n <= retry)){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    getIPWiFi();
  } else {
    Serial.println(F("Already Connected"));
    getIPWiFi();
  }
  httpPhase1();
}
void httpPhase1(){
  HTTPClient http;    //Declare object of class HTTPClient
  String Link;
  String dataString[3];
  http://server.getsensync.com/proc/krwg_air/process1.php?id=krwgq3&val0=7.44&val1=0.00&val2=0.00&val3=17.70&val4=35.00&val5=0.00&val6=0.00&val7=0.00&stat=0
  
  dataString[0] = "http://server.getsensync.com/proc/krwg_air/process1.php?id=" + String(idSensync);
  dataString[1] = "&val0=" + String(dataVal[0]) + "&val1=" + String(dataVal[1]) + "&val2=" + String(dataVal[2]) + "&val3=" + String(dataVal[3]);
  dataString[2] = "&val4=" + String(dataVal[4]) + "&val5=" + String(dataVal[5]) + "&val6=" + String(dataVal[6]) + "&val7=" + String(dataVal[7]) + "&stat=" + String((int)dataVal[8]);
  Link = dataString[0] + dataString[1] + dataString[2]; 
  Serial.println(F("Link Set.."));
  http.begin(Link);     //Specify request destination
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload
  Serial.println(Link);
  Serial.print(F("HTTP return code: "));
  Serial.println(httpCode);   //Print HTTP return code
  Serial.print(F("Response: "));
  Serial.println(payload);    //Print request response payload
  if (payload.indexOf(confirmResponse) > 0){
    SerialFlashln("Success");
    delay(2000);
  } else {
    SerialFlashln("Failed");
    delay(2000);
  }
  http.end();     //Close connection
}
void getIPWiFi(){
    IPAddress myIP = WiFi.localIP();
    String ipStr = String(myIP[0])+"."+String(myIP[1])+"."+String(myIP[2])+"."+String(myIP[3]);    
    Serial.println(F("WiFi connected"));
    Serial.println(F("IP address: "));
    Serial.println(WiFi.localIP());
    delay(2000);
}

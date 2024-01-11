#include <ESP8266WiFi.h>          
#include <Firebase_ESP_Client.h> 
#include <addons/RTDBHelper.h>   
#include "DHT.h"

#define WIFI_SSID "--wifi-name"    
#define WIFI_PASSWORD "--wifi-password" 
#define DATABASE_URL "" // RTDB의 URL
#define DATABASE_SECRET ""    // RTDB의 비밀번호

#define BRIGHT_PIN A0
#define DHT_PIN D7
#define DHTTYPE DHT11
#define LED_PIN D10

DHT dht(DHT_PIN, DHTTYPE);

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
unsigned long dataMillis = 0;

void setup(){
  Serial.begin(9600);
  dht.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  config.database_url = DATABASE_URL;
  config.signer.tokens.legacy_token = DATABASE_SECRET;
  Firebase.reconnectWiFi(true);
  Firebase.begin(&config, &auth);
  delay(1000);
}

void loop(){
  if (millis() - dataMillis > 5000) {
    dataMillis = millis();

    if(Firebase.RTDB.setInt(&fbdo, "/bright", analogRead(A0))){
      delay(500);

      if( Firebase.RTDB.getInt(&fbdo, "/bright"))
      {
        String temp = fbdo.to<const char *>();                
        int brightness = temp.toInt();                            
        Serial.print("brightness : "); 
        Serial.println(brightness);    
      } else Serial.println(fbdo.errorReason().c_str());      
    }
    if(Firebase.RTDB.setInt(&fbdo, "/humidity", dht.readHumidity())){
      delay(500);

      if( Firebase.RTDB.getInt(&fbdo, "/humidity"))
      {
        String temp = fbdo.to<const char *>();                
        int humidity = temp.toInt();                            
        Serial.print("humidity : "); 
        Serial.println(humidity);    
      } else Serial.println(fbdo.errorReason().c_str());      
    }
    if(Firebase.RTDB.setInt(&fbdo, "/temperature", dht.readTemperature())){
      delay(500);

      if( Firebase.RTDB.getInt(&fbdo, "/temperature"))
      {
        String temp = fbdo.to<const char *>();                
        int temperature = temp.toInt();                            
        Serial.print("temperature : "); 
        Serial.println(temperature);    
      } else Serial.println(fbdo.errorReason().c_str());      
    }
  }
}

#include <ESP8266WiFi.h>          
#include <Firebase_ESP_Client.h> 
#include <addons/RTDBHelper.h>    

#define WIFI_SSID "--wifi-name"    
#define WIFI_PASSWORD "--your wifi password" 
#define DATABASE_URL "" // RTDB의 URL
#define DATABASE_SECRET ""    // RTDB의 비밀번호

#define LED_PIN D10 

int readLEDstate = LOW; 

FirebaseData fbdo; 
FirebaseAuth auth; 
FirebaseConfig config;
unsigned long dataMillis = 0; 

void setup() {
  Serial.begin(9600);
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
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (millis() - dataMillis > 2000) { // 2초에 1번씩 실행
    dataMillis = millis();  

    // 값 읽어오기
    if( Firebase.RTDB.getInt(&fbdo, "/led")) {   
      String temp = fbdo.to<const char *>();                
      readLEDstate = temp.toInt();                            
      Serial.print("LED state: "); 
      Serial.println(readLEDstate);  
    } else Serial.println(fbdo.errorReason().c_str());      
    
    digitalWrite(LED_PIN, readLEDstate);

  }
}

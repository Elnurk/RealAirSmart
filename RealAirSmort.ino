#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <WiFiClientSecure.h>
#include <TroykaMQ.h>
#include <stdio.h>

#define PIN_MQ7 A0
MQ7 mq7(PIN_MQ7);
#define PIN_MQ135  A0
MQ135 mq135(PIN_MQ135);
#define PIN_MQ2  A0
MQ2 mq2(PIN_MQ2);
int mq7ratio = 0, mq7carbon = 0, mq2ratio = 0, mq2LPG = 0, mq2methane = 0, mq2smoke = 0, mq2hydrogen = 0, mq135ratio = 0, mq135CO2 = 0;
const int rele1 = D2;
const int rele2 = D3;
const int rele3 = D4;

// Set these to run example.
#define FIREBASE_HOST "realairsmort.firebaseio.com"
#define FIREBASE_AUTH "dedvJsRv3jHcHplnFaPeJiPlsJKrOdNenfPCHWWr"
#define WIFI_SSID "RedmiNote9Pro" 
#define WIFI_PASSWORD "elnurkkk"

void setup() {
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  digitalWrite(rele1, LOW); //Close to real time thing LOW = turn OFF, HIGH = turn ON Works MQ135
  digitalWrite(rele2, LOW); //Middle one MQ7
  digitalWrite(rele3, LOW); //Close to the edge MQ2
  // connect to wifi.
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  digitalWrite(rele1, HIGH);
  delay(120000);
  mq135.calibrate();
  for (int i = 0; i < 10; i++){
    mq135CO2 = mq135CO2 + mq135.readCO2();
  }
  mq135CO2 = mq135CO2 / 10;
  Serial.println(mq135CO2);
  digitalWrite(rele1, LOW);
  digitalWrite(rele2, HIGH);
  delay(120000);
  mq7.calibrate();
  for (int i = 0; i < 10; i++){
    mq7carbon = mq7carbon + mq7.readCarbonMonoxide();
  }
  mq7carbon = mq7carbon / 10;
  Serial.println(mq7carbon);
  digitalWrite(rele2, LOW);
  digitalWrite(rele3, HIGH);
  delay(120000);//120000
  mq2.calibrate();
  for (int i = 0; i < 10; i++) {
    mq2LPG = mq2LPG + mq2.readLPG();
    mq2methane = mq2methane + mq2.readMethane();
    mq2smoke = mq2smoke + mq2.readSmoke();
    mq2hydrogen = mq2hydrogen + mq2.readHydrogen();
  }
  mq2LPG = mq2LPG / 10;
  mq2methane = mq2methane / 10;
  mq2smoke = mq2smoke / 10;
  mq2hydrogen = mq2hydrogen / 10;
  Serial.println(mq2LPG);
  Serial.println(mq2methane);
  Serial.println(mq2smoke);
  Serial.println(mq2hydrogen);
  digitalWrite(rele3, LOW);
  
  // set value
  Firebase.setFloat("CO2", mq135CO2);
  if (Firebase.failed()) {
      Serial.print("setting mq 135 failed:");
      Serial.println(Firebase.error());  
      return; 
  }
  
    Firebase.setFloat("CO", mq7carbon);
  if (Firebase.failed()) {
      Serial.print("setting mq 7 failed:");
      Serial.println(Firebase.error());  
      return; 
  }
  
    Firebase.setFloat("LPG", mq2LPG);
  if (Firebase.failed()) {
      Serial.print("setting mq 2 failed:");
      Serial.println(Firebase.error());  
      return; 
  }
  
    Firebase.setFloat("Methane", mq2methane);
  if (Firebase.failed()) {
      Serial.print("setting mq 2 failed:");
      Serial.println(Firebase.error());  
      return; 
  }

    Firebase.setFloat("Smoke", mq2smoke);
  if (Firebase.failed()) {
      Serial.print("setting mq 2 failed:");
      Serial.println(Firebase.error());  
      return; 
  }

    Firebase.setFloat("Hydrogen", mq2hydrogen);
  if (Firebase.failed()) {
      Serial.print("setting mq 2 failed:");
      Serial.println(Firebase.error());  
      return; 
  }

  delay(3240000);
}

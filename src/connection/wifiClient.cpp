#include "wifiClient.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>


const char* ssid = "A1-580343";
const char* password = "jwSt";

const char* host = "10.0.0.42";
const int port = 8080;




void setupWifi() {
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}


void wifiLoop() {
  WiFiClient client;

  if(!client.connected(host, port)) {
    Serial.println("Connection failed!");
    return;
  }
}



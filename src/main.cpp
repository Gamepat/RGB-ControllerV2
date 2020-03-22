#include <Arduino.h>
#include <mqtt/mqtt.h>

#include <ESP8266WiFi.h>
#include <PubSubClient.h>



void setup() {
  Serial.begin(115200);
  Serial.println("Hello World");
  setupWifi();
  setupMQTT();
}

void loop() {
  mqttLoop();
}
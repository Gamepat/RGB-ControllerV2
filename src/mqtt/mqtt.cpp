#include <Arduino.h>


#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <mqtt/data.h>
#include <util/utils.h>
#include <hardwareControl/hardwareControl.h>



WiFiClient espClient;
PubSubClient client(espClient);


void callback(char* topic, byte* payload, unsigned int length);

void setupWifi() {
  delay(100);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setupMQTT() {
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}


//* Gets called when command is sent from broker
void callback(char* topic, byte* payload, unsigned int length) {
  
}



void reconnect() {
  //*Loop until we're reconnected

  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
     	//once connected to MQTT broker, subscribe to given topic
      client.subscribe(rgbTopic);
    } 
		else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 6 seconds before retrying
      delay(6000);
    }
  }
}


void mqttLoop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
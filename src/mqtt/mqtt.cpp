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
  rgb_uint8_t rgb_val;

  Serial.println();
  Serial.print("Command from MQTT broker is : [");
  Serial.print(topic);
  Serial.print(" : ");

  // get the first 8 characters from the payload
  char load[8] = "";
  for(int i = 0; i < 8; i++) {
    char c = (char)payload[i];
    strncat(load, &c, 1);
  }
  uint32_t hex_val = (uint32_t)strtol(load, NULL, 0);

  // Convert the hex value into 3 RGB values
  hexToRGBConverter(hex_val, &rgb_val);

  // set the hardware pins with the given RGB values
  pwmControl(rgb_val);

  // Debug output
  Serial.println(load);
  Serial.println();
  Serial.println(rgb_val.r);
  Serial.println(rgb_val.g);
  Serial.println(rgb_val.b);
  Serial.println();
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
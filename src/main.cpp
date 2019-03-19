#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <WiFiUdp.h>

WiFiManager wifiManager;
WiFiUDP udp;

void setup() {
  WiFi.hostname("power");
  wifiManager.autoConnect("Power Test");

  udp.begin(5000);

  Serial1.begin(115200);

  Serial1.printf("\nHello!...\n");

  pinMode(5, OUTPUT);
}

void loop() {
  // delay(2);
  digitalWrite(5, HIGH);

  size_t size = udp.parsePacket();
  if (size > 0) {
    Serial1.printf("Got a packet! size: %d\n", size);
  }

  // delay(2);
  digitalWrite(5, LOW);
}
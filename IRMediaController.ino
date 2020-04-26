#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

// import html, css and js from file.
#include "index.h"
#include "style.h"
#include "functionality.h"

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

ESP8266WebServer server(80);
const char* ssid = "Giaco"; //Enter Wi-Fi SSID
const char* password =  "whateverman"; //Enter Wi-Fi Password
 
void setup() {
  irsend.begin();

  Serial.begin(115200); //Begin Serial at 115200 Baud
  WiFi.begin(ssid, password);  //Connect to the WiFi network
  
  while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
      delay(500);
      Serial.println("Waiting to connect...");
  }
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP
  
  server.on("/", serveHTML);
  server.on("/style.css", serveCSS);
  server.on("/functionality.js", serveFunctionality);

  server.on("/up", HTTP_POST, volumeUp);
  server.on("/down", HTTP_POST, volumeDown);
  server.on("/audio1", HTTP_POST, audioChannel1);
  server.on("/audio2", HTTP_POST, audioChannel2);
  server.on("/av1", HTTP_POST, avChannel1);
  server.on("/av2", HTTP_POST, avChannel2);
  server.on("/av3", HTTP_POST, avChannel3);
  server.on("/av4", HTTP_POST, avChannel4);
  server.on("/av5", HTTP_POST, avChannel5);
  server.on("/hdmi1", HTTP_POST, hdmiChannel1);
  server.on("/hdmi2", HTTP_POST, hdmiChannel2);
  server.on("/hdmi3", HTTP_POST, hdmiChannel3);
  server.on("/pwrAmp", HTTP_POST, togglePowerAmp);
  server.on("/pwrTv", HTTP_POST, togglePowerTv);
  server.on("/input1", HTTP_POST, inputChannel1);
  server.on("/input2", HTTP_POST, inputChannel2);
  server.on("/input3", HTTP_POST, inputChannel3);
  server.on("/enter", HTTP_POST, enter);
  
  server.begin(); //Start the server
  Serial.println("Server listening");
}

void loop() {
  server.handleClient(); //Handling of incoming client requests
}

void serveHTML() {
  server.send(200, "text/html", html);
}

void serveCSS() {
  server.send(200, "text/css", css);
}

void serveFunctionality() {
  server.send(200, "text/application", functionality);
}

void volumeUp() { volume(10); }
void volumeDown() { volume(-10); }
void audioChannel1() { audioChannel(1); }
void audioChannel2() { audioChannel(2); }
void avChannel1() { avChannel(1); }
void avChannel2() { avChannel(2); }
void avChannel3() { avChannel(3); }
void avChannel4() { avChannel(4); }
void avChannel5() { avChannel(5); }
void hdmiChannel1() { hdmiChannel(1); }
void hdmiChannel2() { hdmiChannel(2); }
void hdmiChannel3() { hdmiChannel(3); }
void inputChannel1() { inputChannel(1); }
void inputChannel2() { inputChannel(2); }
void inputChannel3() { inputChannel(3); }

void volume(int increments) {
  Serial.print("Increments: ");
  Serial.println(increments);
  unsigned long code;

  if (increments > 0) {
    code = 0x5EA158A7;
  } else {
    code = 0x5EA1D827;
  }

  int i = 0;
  while (i < abs(increments)) {
    irsend.sendNEC(code);
    delay(20);
    i++;
  }

  server.send(200);
}

void audioChannel(int channel) {
  Serial.print("audio channel: ");
  Serial.println(channel);

  switch (channel) {
    case 1:
      irsend.sendNEC(0x5EA1A658); break;
    case 2:
      irsend.sendNEC(0x5EA116E8); break;
  }
  server.send(200);
}

void avChannel(int channel) {
  Serial.print("av channel: ");
  Serial.println(channel);

  switch (channel) {
    case 1:
      irsend.sendNEC(0x5EA1CA34); break;
    case 2:
      irsend.sendNEC(0x5EA16A94); break;
    case 3:
      irsend.sendNEC(0x5EA19A64); break;
    case 4:
      irsend.sendNEC(0x5EA13AC4); break;
    case 5:
      irsend.sendNEC(0x5EA1FA04); break;
  }
  server.send(200);
}

void hdmiChannel(int channel) {
  Serial.print("hdmi channel: ");
  Serial.println(channel);

  switch (channel) {
    case 1:
      irsend.sendNEC(0x5EA1E21C); break;
    case 2:
      irsend.sendNEC(0x5EA152AC); break;
    case 3:
      irsend.sendNEC(0x5EA1B24C); break;
    case 4:
      irsend.sendNEC(0x5EA10AF4); break;
  }
  server.send(200);
}

void togglePowerAmp() {
  irsend.sendNEC(0x7E8154AB, 32);
  Serial.println("Toggle power amp");
  server.send(200);
}

void togglePowerTv() {
  irsend.sendNEC(0x20DF10EF, 32);
  Serial.println("Toggle power");
  server.send(200);
}

void inputChannel(int channel) {
  Serial.print("input channel: ");
  Serial.println(channel);

  irsend.sendNEC(0x20DFD02F); delay(300);
  irsend.sendNEC(0x20DFD02F); delay(20);

  switch (channel) {
    case 1:
      irsend.sendNEC(0x20DFD02F); delay(20);
      irsend.sendNEC(0x20DF22DD); break;
    case 2:
      irsend.sendNEC(0x20DFD02F); delay(20);
      irsend.sendNEC(0x20DFD02F); delay(20);
      irsend.sendNEC(0x20DF22DD); break;
    case 3:
      irsend.sendNEC(0x20DFD02F); delay(20);
      irsend.sendNEC(0x20DFD02F); delay(20);
      irsend.sendNEC(0x20DFD02F); delay(20);
      irsend.sendNEC(0x20DF22DD); break;
  }
}

void enter() {
  irsend.sendNEC(0x20DF22DD, 32);
  Serial.println("nav enter");
  server.send(200);
}

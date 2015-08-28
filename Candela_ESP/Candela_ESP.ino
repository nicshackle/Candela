#include <NeoPixelBus.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCBundle.h>

NeoPixelBus strip = NeoPixelBus(1, 2);

WiFiClient client;
WiFiUDP port;

char packetBuffer[255];
unsigned int localPort = 7405;
IPAddress ip(192, 168, 1, 104); 
IPAddress gateway(192, 168, 1, 1);  
IPAddress subnet(255, 255, 255, 0);  

int red;
int green;
int blue;

void redCallback(OSCMessage &msg, int offset) {
  red = msg.getInt(0);
}

void greenCallback(OSCMessage &msg, int offset) {
  green = msg.getInt(0);
}

void blueCallback(OSCMessage &msg, int offset) {
  blue = msg.getInt(0);
}


void setup() {
  Serial.begin(9600);
  WiFi.config(ip, gateway, subnet); 
  WiFi.begin("ssid", "password");
  port.begin(localPort);
  strip.Begin();
  strip.Show();
}


void loop() {
  OSCBundle bndl;
  int size;

  //receive a bundle
  if ( (size = port.parsePacket()) > 0)
  {

    while (size--) {
      char c = port.read();
      bndl.fill(c);
    }
    if (!bndl.hasError())
    {
      bndl.route("/red", redCallback);
      bndl.route("/green", greenCallback);
      bndl.route("/blue", blueCallback);

      strip.SetPixelColor(0, RgbColor(red, green, blue));
      strip.Show();

    }
  }
}







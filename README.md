# Candela

Wireless RGB LED lights, controllable over OSC. Designed for use in a hackathon.

OSC is implemented over UDP, so can react very quickly (good for real time visaulizations).

##Usage

Each module will have a static IP. The following endpoints can be refernence in an OSC bundle:
* `\red` controls the red channel (0~255 int)
* `\green` controls the green channel (0~255 int)
* `\blue` controls the blue channel (0~255 int)

Note that the OSC data must be sent as a bundle (see example processing sketch)

##Notes

* For the hackthon - the Arduino code should not be modified (other people need to use the units as well)
* Arduino code requires NeoPixelBus and ESP8266WiFi libraries 




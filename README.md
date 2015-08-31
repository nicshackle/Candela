# Candela

Wireless RGB LED lights, controllable over OSC. Designed for use in a hackathon.

OSC is implemented over UDP, so the units can react very quickly (good for real time visaulizations).

##Usage

Each module will have a static IP, and communicate via port 7405. The following endpoints can be refernenced in an OSC bundle:
* `\red` controls the red channel (0~255 int)
* `\green` controls the green channel (0~255 int)
* `\blue` controls the blue channel (0~255 int)

Note that the OSC data must be sent as a bundle (see example processing sketch)

##Example

The example processing sketch presents you with a colour picker. On clicking a colour, the colour value is read as RGB, and sent as an OSC bundle.

##Notes

* For the hackthon - the Arduino code should not be modified (other people need to use the units as well)
* Arduino code requires NeoPixelBus and ESP8266WiFi libraries 
* During the hackthon, you will have use of one unit (or more, depending on turnout). If you would like to make use of many units, you may do so, but will only have the opportunity to during presentation.
* We will provide a WiFi network to join, on which the units are connected to.

`good luck, and happy hacking!`




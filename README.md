# Candela

Wireless LED 'throwie' lights, controllable over OSC. Designed for the `Amaze Hackathon`.

##Usage

Each module will have a static IP. The following endpoints can be refernence in an OSC bundle:
* `\red` controls the red channel (0~255 int)
* `\green` controls the green channel (0~255 int)
* `\blue` controls the blue channel (0~255 int)

Note that the OSC data must be sent as a bundle (see example processing sketch)




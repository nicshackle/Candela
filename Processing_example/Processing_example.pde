import oscP5.*;
import netP5.*;

PImage wheel;

OscP5 oscP5;
NetAddress myRemoteLocation;

void setup() {
  wheel = loadImage("colormap.gif");
  size(wheel.width,wheel.height);
  
  /* start oscP5, listening for incoming messages at port 12000 */
  oscP5 = new OscP5(this,12000);

  myRemoteLocation = new NetAddress("192.168.1.109",7405);
  image(wheel,0,0);
}


void draw() {
//  background(0);  
}


void mousePressed() {
  int pointval = get(mouseX,mouseY);
  /* create an osc bundle */
  OscBundle myBundle = new OscBundle();
  
  /* createa new osc message object */
  OscMessage red = new OscMessage("/red");
  red.add(int(red(pointval)));  
  /* add an osc message to the osc bundle */
  myBundle.add(red);
  
  /* createa new osc message object */
  OscMessage green = new OscMessage("/green");
  green.add(int(green(pointval)));  
  /* add an osc message to the osc bundle */
  myBundle.add(green);
  
  /* createa new osc message object */
  OscMessage blue = new OscMessage("/blue");
  blue.add(int(blue(pointval)));  
  /* add an osc message to the osc bundle */
  myBundle.add(blue);
  
  myBundle.setTimetag(myBundle.now() + 1000);
  oscP5.send(myBundle, myRemoteLocation);
}


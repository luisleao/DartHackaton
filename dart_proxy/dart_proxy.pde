/**
 * Serial Duplex 
 * by Tom Igoe. 
 * 
 * Sends a byte out the serial port when you type a key
 * listens for bytes received, and displays their value. 
 * This is just a quick application for testing serial data
 * in both directions. 
 */

import processing.net.*;
import processing.serial.*;

Serial myPort;      // The serial port

int port = 10002;
boolean myServerRunning = true;
Server myServer;
int textLine = 60;



void setup() {
  size(400, 300);
  // create a font with the third font available to the system:
  PFont myFont = createFont(PFont.list()[2], 14);
  textFont(myFont);

  // List all the available serial ports:
  println(Serial.list());

  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 57600);
  myPort.bufferUntil('\n'); 
  
  myServer = new Server(this, port); // Starts a myServer on port 10002

}



void mousePressed()
{
  // If the mouse clicked the myServer stops
  if (myServerRunning) {
    myServer.stop();
    myServerRunning = false;
  } else {
    myServer = new Server(this, port);
    myServerRunning = true;
  }
}


void draw() {
  background(0);
  
  if (myServerRunning == true)
  {
    text("server", 15, 45);
    Client thisClient = myServer.available();
    if (thisClient != null) {
      if (thisClient.available() > 0) {
        String inputString = thisClient.readString();
        myPort.write(inputString);
        //print(inputString);
        print("mesage from: " + thisClient.ip() + " : " + inputString);
        
        //#text("mesage from: " + thisClient.ip() + " : " + inputString, 15, textLine);
        //textLine = textLine + 35;
      }
    }
  } 
  else 
  {
    text("server", 15, 45);
    text("stopped", 15, 65);
  }
  
}

void serialEvent(Serial myPort) {
  String inString = myPort.readString();
  myServer.write(inString);
  print(inString);
  
  //char inByte = (char)myPort.read();
  //myServer.write(inByte);
  //print((char)inByte);
}

void keyPressed() {
  // Send the keystroke out:
  //myPort.write(key);
  //whichKey = key;
}



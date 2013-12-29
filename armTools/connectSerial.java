import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import controlP5.*; 
import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public void connectSerial(int theValue) 
{
  if(running  == 1)//check to make sure we're in run mode
  {
    int serialPortIndex = (int)serialList.value();//get the serial port selected from the serlialList
    
    //try to connect to the port at 115200bps, otherwise show an error message
    try
    {
      sPort = new Serial(this, Serial.list()[serialPortIndex], 38400);
    }
    catch(Exception e)
    {
      if(debug ==1){println("Error Opening Serial Port");}
      errorGroup.setVisible(true);
      errorText.setVisible(true);        
      errorText.setText("Error Connecting to Port - try a different port or try closing other applications using the current port");    
    }     
     connectButton.lock();
      connectButton.setColorBackground(color(200));
      disconnectButton.unlock();
      disconnectButton.setColorBackground(color(2,52,77));
    controGroup.setVisible(true);
    delayMs(100);//add delay for some systems
      startupGroup.setVisible(false);
    
    
    //send a command to see if the ArbotiX is connected. 
 /*   if(pingArbotix()== 1)
    {
      //show scan and test group
      scanGroup.setVisible(true);
      testGroup.setVisible(true);
      
      //hide error groups
      startupGroup.setVisible(false);
      errorGroup.setVisible(false);
      
      //lock connect button and change apperance, unlock disconnect button and change apperance
      connectButton.lock();
      connectButton.setColorBackground(color(200));
      disconnectButton.unlock();
      disconnectButton.setColorBackground(color(2,52,77));
      autoSearchButton.lock();
      autoSearchButton.setColorBackground(color(200));
    }
    else
    {
      if(debug ==1){println("ArbotiX Not detected");}
      errorGroup.setVisible(true);
      errorText.setVisible(true);
      errorText.setText("No ArbotiX detected on this port. Make sure your ArbotiX is powered on and try again, or try a different port.");    
      sPort.stop();  //disconnect from serial port
      sPort = null;  //set serial port to null, so other functions can easily know we're not connected
    }*/
  }     
}// end connectSerial


/************************************
 * disconnectSerial
 *
 * disconnectSerial will receive changes from  controller(button) with name disconnectSerial
 * disconnectSerial will disconnect from the current serial port and hide GUI elements that should only
 * be available when connected to an arbotix
 ************************************/  
public void disconnectSerial(int theValue) 
{
  //check to make sure we're in run mode and that the serial port is connected
  if(running ==1 && sPort != null)
  {
    sPort.stop();//stop/disconnect the serial port   
    sPort = null;//set the serial port to null, incase another function checks for connectivity
    //curIdField.setValue("No Servo Connected");//change current id field to a prompt
    //curIdField.valueLabel().style().marginLeft = 0;
    //dynaModelNameField.setValue("");//change model name field to nothing
    //servoScanned = 0; //disconnecting the serial port also disconnects any currently connected sercos
    //hide the scan set and test group
    controGroup.setVisible(false);
   // setGroup.setVisible(false);
   // testGroup.setVisible(false);
    //make visible the statup prompt
    startupGroup.setVisible(true);

    //unlock connect button and change apperance, lock disconnect button and change apperance
    connectButton.unlock();
    connectButton.setColorBackground(color(2,52,77));
    autoSearchButton.unlock();
    autoSearchButton.setColorBackground(color(2,52,77));
    disconnectButton.lock();
    disconnectButton.setColorBackground(color(200));
  
  }
}//end disconnectSerial


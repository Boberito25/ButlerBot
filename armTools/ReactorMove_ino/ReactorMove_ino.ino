#include <ax12.h>
#include <BioloidController.h>
#include "poses.h"


#define BASE_MIN    0
#define BASE_MAX    1023

#define SHOULDER_MIN  205 
#define SHOULDER_MAX  810

#define ELBOW_MIN    210
#define ELBOW_MAX    900

#define WRIST_MIN    200
#define WRIST_MAX    830

#define WROT_MIN     0
#define WROT_MAX     1023

#define GRIP_MIN     0
#define GRIP_MAX     512

int GetServoNo();
int GetAngle(int no);
void doPose(int Base, int Shoulder, int Elbow, int Wrist, int Wrot, int grip);
int SetAngle(int no, int angle);
void setNextPose(int no, int angle);
void ScanServo();
void readAngles();
void Move();
void MoveTest();
void RelaxServos();
void parseMove(int counter, int* path);

char incomingChar;
String message,SOPHeader,EOPTail,endChars;
String Eof,Startseq,Endseq,getangles;

BioloidController bioloid = BioloidController(1000000);

const int SERVOCOUNT = 8;
prog_uint16_t currPose[SERVOCOUNT+1];
int id;
int pos;
int pos2;
int conn;
boolean IDCheck;
boolean RunCheck;

void setup() {
  
   delay (100);   
   Serial.begin(9600);
   /*   Serial.println("###########################\n");    
   Serial.println("Serial Communication Established.\n");   
   Serial.println("###########################"); */
   SOPHeader = "Start:";
   EOPTail = ":End";
   Eof = "ARRDONE";
   Startseq = "STARTSEQ";
   getangles = "GETANG";
   Endseq = "ENDSEQ";
   pinMode(0,OUTPUT);  
   bioloid.setup(8);
   currPose[0] = 8;
   //initialize variables 
   id = 1;
   pos = 0;
   conn = 0;
   IDCheck = 1;
   RunCheck = 0;
  //open serial port

  //Check Lipo Battery Voltage
/*  CheckVoltage();

  MoveCenter();
*/
//  
  delay(10);
  
//Scan Servos, return position.
/*  ScanServo();
  
  MoveTest();
  
  MoveHome();*/

  RelaxServos();
  doPose(512, 512, 512, 512, 512, 512); 
  RunCheck = 1;


  
}

void loop(){
  // read the sensor:
    //int inByte = Serial.read();
    char c = 0;
    char in = 'X';
    while (!conn) {
      if ((c = Serial.read()) == 'X') {
          Serial.print("X");
          conn = 1;
      }
    }
    int no;
    int angle;
    /*
    switch (inByte) {
  
      case '0':
        Serial.println("Got byte from program");
        break;
      case '1':    
        ScanServo();
        break;
  
      case '2':    
        no = GetServoNo();
        if (no == -1) {
          break;
        }
        GetAngle(no);
        Move();
        break;
      case '3':
        doPose(512, 512, 512, 512, 512, 512);
        break;
      case '4':    
        RelaxServos();
        break;     
  
      case '5':
        Move();
        MoveTest();
        break;
    } */

    readAngles();
}

int GetServoNo() {
  Serial.println("Waiting for servo #:");
    delay(3000);
    int inByte = -1;
    String angle = "";
    if (Serial.available() > 0) { //if data is available
        inByte = Serial.read() - 48; //get the servo number
        Serial.print("Servo ID: ");
        Serial.println(inByte);
        return inByte;
    }
    else {
        return -1; //if no servo given, continue
    }
}
  
int GetAngle(int no) {
  for (int i = 1; i <= SERVOCOUNT; i++) {
      currPose[i] = ax12GetRegister(i, 36, 2);
      bioloid.setNextPose(i, currPose[i]);

      Serial.println(bioloid.getId(i));
  }
  setNextPose(no, 300);
}

void doPose(int Base, int Shoulder, int Elbow, int Wrist, int Wrot, int grip) {
  unsigned long starttime, stoptime;
  starttime = millis();
  setNextPose(Base, Shoulder, Elbow, Wrist, Wrot, grip);
  stoptime = millis();
  //Serial.println("time setNextPose = ");
  //Serial.println(stoptime - starttime);
  starttime = millis();
  Move();
  stoptime = millis();
  //Serial.println("time Move = ");
  //Serial.println(stoptime - starttime);
  //Serial.println("Hello:End");
}

int SetAngle(int no, int angle) {
  for (int i = 1; i <= SERVOCOUNT; i++) {
      currPose[i] = ax12GetRegister(i, 36, 2);
      bioloid.setNextPose(i, currPose[i]);

      Serial.println(bioloid.getId(i));
  }
  setNextPose(no, angle);
}

void setNextPose(int Base, int Shoulder, int Elbow, int Wrist, int Wrot, int grip) {
  int thatsTheRightNumber = 300;
      thatsTheRightNumber = max(min(Base, BASE_MAX), BASE_MIN);
      bioloid.setNextPose(1, thatsTheRightNumber);

      thatsTheRightNumber = max(min(Shoulder, SHOULDER_MAX), SHOULDER_MIN);
      bioloid.setNextPose(2, thatsTheRightNumber);
      bioloid.setNextPose(3, 1024-thatsTheRightNumber);

      thatsTheRightNumber = max(min(Elbow, ELBOW_MAX), ELBOW_MIN);
      bioloid.setNextPose(4, thatsTheRightNumber);
      bioloid.setNextPose(5, 1024-thatsTheRightNumber);

      thatsTheRightNumber = max(min(Wrist, WRIST_MAX), WRIST_MIN);
      bioloid.setNextPose(6, thatsTheRightNumber);

      thatsTheRightNumber = max(min(Wrot, WROT_MAX), WROT_MIN);
      bioloid.setNextPose(7, thatsTheRightNumber);

      thatsTheRightNumber = max(min(grip, GRIP_MAX), GRIP_MIN);
      bioloid.setNextPose(8, thatsTheRightNumber);

}
      
void ScanServo(){
  id = 1;  
  Serial.println("###########################");
  Serial.println("Starting Servo Scanning Test.");
  Serial.println("###########################");
      
  while (id <= SERVOCOUNT){
  pos =  ax12GetRegister(id, 36, 2);
  Serial.print("Servo ID: ");
  Serial.println(id);
  Serial.print("Servo Position: ");
  Serial.println(pos);
  
  if (pos <= 0){
  Serial.println("###########################");
  Serial.print("ERROR! Servo ID: ");
  Serial.print(id);
  Serial.println(" not found. Please check connection and verify correct ID is set.");
  Serial.println("###########################"); 
  IDCheck = 0;
  }
  
  id = (id++)%SERVOCOUNT;
  delay(10);
  }
  if (IDCheck == 0){
    Serial.println("###########################");
    Serial.println("ERROR! Servo ID(s) are missing from Scan. Please check connection and verify correct ID is set.");
    Serial.println("###########################");  
  }
  else{
  Serial.println("All servo IDs present.");
  }
}

void readAngles() {
  /*unsigned long starttime, stoptime;
  starttime = millis();*/
  int i = 0;
  //message = "";
  while(Serial.available()) {
      //Start reading the stream
      //Serial.println("before read");
      incomingChar = Serial.read();
      message.concat(incomingChar); //Concatanate the received characters to the string message
      if(message.endsWith(Startseq)) {
        message = String("");
        while(1) {
          if (Serial.available()) {
            incomingChar=Serial.read();
            message.concat(incomingChar);
          }
          if (message.endsWith(Endseq)) {
            break;
          }
        }
        message = message.substring(0,message.length()-Endseq.length());
        int s = message.toInt();
        int *path = (int*)malloc(sizeof(int) * s * 6);
        Serial.println(s);
        while(Serial.available()) {
          Serial.print(message);
          incomingChar = Serial.read();
          message.concat(incomingChar);
          if (message.endsWith(SOPHeader)) {
            message = "";
            while(Serial.available()) { //Start receiving once data is available on the serial link
              incomingChar=Serial.read();
              message.concat(incomingChar);
              if(message.endsWith(EOPTail)) {
                message = message.substring(0,message.length()-EOPTail.length());
                parseMove(i, path);
                i++;
              }
              break;
            }
          }
        }
      }
          if (message.endsWith(Eof)) {
            for (int j = 0; j < i; j++) {
              Serial.println(path[j*6]);
              Serial.println(path[j*6+1]);
              Serial.println(path[j*6+2]);
              Serial.println(path[j*6+3]);
              Serial.println(path[j*6+4]);
              Serial.println(path[j*6+5]);
              //doPose(path[j*6], path[j*6+1], path[j*6+2], path[j*6+3], path[j*6+4], path[j*6+5]);
            }
            return;
          }
        }
      }
      //Serial.print("Q");
      if (message.endsWith(getangles)) {
        message = "";
        int id = 1;
        Serial.print(",");
        while (id <= SERVOCOUNT) {
          pos =  ax12GetRegister(id, 36, 2);
          Serial.print(pos);
          Serial.print(",");
          id++;
        }
        Serial.print("Q");
        conn = 0;
        return;
      }
  }/*
  for (int j = 0; j < i; j++) {
    doPose(path[j*6], path[j*6+1], path[j*6+2], path[j*6+3], path[j*6+4], path[j*6+5]);
  }*/
  return;

  /*while(Serial.available()) { //Start receiving once data is available on the serial link
        int i = 0;
        //Start reading the stream
        incomingChar=Serial.read();
        message.concat(incomingChar); //Concatanate the received characters to the string message
          
        if(message.endsWith(SOPHeader)){ //If the last characters correspond to the SOP Heade strip it off and start considering this a valid message
          message="";
        }
        //Check for EOP trailer and strip it off
        if(message.endsWith(EOPTail)){ // If in the debug state signal that the EOP has been detected
          message=message.substring(0,message.length()-EOPTail.length());
          parseMove(message, path, i);
          i++;
        }
        if(message.endsWith(EOF)) {
          break;
        }
  }
  stoptime = millis();
  Serial.println("Time = ");
  Serial.println(stoptime - starttime);*/
}
  
  
void parseMove(int counter, int *path) {
  
  int Base, Shoulder, Shoulder1, Elbow, Elbow1, Wrist, Wrot, grip;
  char *str;
  char* delim = ",";
  char temp[message.length()+1];
  message.toCharArray(temp, message.length());
  Base = atoi(strtok_r(temp, delim, &str));
  Shoulder = atoi(strtok_r(NULL, delim, &str));
  Shoulder1 = atoi(strtok_r(NULL, delim, &str));
  Elbow = atoi(strtok_r(NULL, delim, &str));
  Elbow1 = atoi(strtok_r(NULL, delim, &str));
  Wrist = atoi(strtok_r(NULL, delim, &str));
  Wrot = atoi(strtok_r(NULL, delim, &str));
  grip = atoi(strtok_r(NULL, delim, &str));
  
  path[counter * 6] = Base;
  path[counter * 6 + 1] = Shoulder;
  path[counter * 6 + 2] = Elbow;
  path[counter * 6 + 3] = Wrist;
  path[counter * 6 + 4] = Wrot;
  path[counter * 6 + 5] = grip;
  //doPose(Base, Shoulder, Elbow, Wrist, Wrot, grip);
  /*Serial.println(Base);
  Serial.println(Shoulder);
  Serial.println(Elbow);
  Serial.println(Wrist);
  Serial.println(Wrot);
  Serial.println(grip);*/

}
  
  
void Move(){
    delay(10);                    // recommended pause

    //bioloid.loadPose(Center);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    //Serial.println("Moving servos to centered position");  
    for (int i = 1; i <= SERVOCOUNT; i++) {
        //Serial.println(bioloid.getCurPose(i));
        //Serial.println(bioloid.getNextPose(i));
    }
    bioloid.interpolateSetup(50); // setup for interpolation from current->next over 1/2 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }
}

void MoveTest(){
  //Serial.println("###########################");
  //Serial.println("Initializing Movement Sign Test");  
  //Serial.println("###########################");
  delay(10);  
  id = 1;
  pos = pos2 = 512;
 
// Base Servo Test

  //Serial.println("Moving Servo ID: 1");
  
  while(pos >= 312){  
  SetPosition(1, pos);
  pos = pos--;
  delay(10);
  }

  while(pos <= 512){  
  SetPosition(1, pos);
  pos = pos++;
  delay(10);
  }
  
  delay(500);

// Shoulder Servos Test  
  
  Serial.println("Moving Servo IDs: 2 & 3 (Shoulder)"); 
  while(pos >= 312){  
  SetPosition(2, pos);
  SetPosition(3, pos2);
  pos = pos--;
  pos2 = pos2++;
  delay(10);
  }

  while(pos <= 512){  
  SetPosition(2, pos);
  SetPosition(3, pos2);
  pos = pos++;
  pos2 = pos2--;
  delay(10);
  }

  delay(500);
  
// Elbow Servo Test  
  
  Serial.println("Moving Servo IDs: 4 & 5 (Elbow)"); 
  while(pos <= 712){  
  SetPosition(4, pos);
  SetPosition(5, pos2);
  pos = pos++;
  pos2 = pos2--;
  delay(10);
  }

  while(pos >= 512){  
  SetPosition(4, pos);
  SetPosition(5, pos2);
  pos = pos--;
  pos2 = pos2++;
  delay(10);
  }
  
  delay(500);  
  
  //Wrist Servo Test
  
  Serial.println("Moving Servo ID: 6");
  
  while(pos <= 712){  
  SetPosition(6, pos);
  pos = pos++;
  delay(10);
  }

  while(pos >= 512){  
  SetPosition(6, pos);
  pos = pos--;
  delay(10);
  }
  
  delay(500);   
  
  //Wrist Rotate Servo Test  

  Serial.println("Moving Servo ID: 7");
  
  while(pos >= 312){  
  SetPosition(7, pos);
  pos = pos--;
  delay(10);
  }

  while(pos <= 512){  
  SetPosition(7, pos);
  pos = pos++;
  delay(10);
  }
  
  delay(500);   
  
  //Gripper Servo Test  
  
    Serial.println("Moving Servo ID: 8");
  
  while(pos >= 312){  
  SetPosition(8, pos);
  pos = pos--;
  delay(10);
  }

  while(pos <= 512){  
  SetPosition(8, pos);
  pos = pos++;
  delay(10);
  }
  
  delay(500);   
  
}

void RelaxServos(){
  id = 1;
  /*Serial.println("###########################");
  Serial.println("Relaxing Servos.");
  Serial.println("###########################");    
  */while(id <= SERVOCOUNT){
    Relax(id);
    id = (id++)%SERVOCOUNT;
    delay(50);
  }
}
    


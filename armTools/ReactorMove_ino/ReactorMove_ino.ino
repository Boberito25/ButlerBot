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

BioloidController bioloid = BioloidController(1000000);

const int SERVOCOUNT = 8;
prog_uint16_t currPose[SERVOCOUNT+1];
int id;
int pos;
int pos2;
boolean IDCheck;
boolean RunCheck;

void setup(){
   pinMode(0,OUTPUT);  
   bioloid.setup(8);
   currPose[0] = 8;
   //initialize variables 
   id = 1;
   pos = 0;
   IDCheck = 1;
   RunCheck = 0;
  //open serial port
   Serial.begin(9600);
   delay (500);   
    Serial.println("###########################");    
   Serial.println("Serial Communication Established.");    
  //Check Lipo Battery Voltage
/*  CheckVoltage();

  MoveCenter();
*/
//  
  delay(5000);
  
//Scan Servos, return position.
/*  ScanServo();
  
  MoveTest();
  
  MoveHome();
*/  
 
  RunCheck = 1;
}

void loop(){
  // read the sensor:
  
    int inByte = Serial.read();
    int no;
    int angle;
    switch (inByte) {

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
    } 
  
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
  setNextPose(1, Base);
  setNextPose(2, Shoulder);
  setNextPose(4, Elbow);
  setNextPose(6, Wrist);
  setNextPose(7, Wrot);
  setNextPose(8, grip);
  Move();
}

int SetAngle(int no, int angle) {
  for (int i = 1; i <= SERVOCOUNT; i++) {
      currPose[i] = ax12GetRegister(i, 36, 2);
      bioloid.setNextPose(i, currPose[i]);

      Serial.println(bioloid.getId(i));
  }
  setNextPose(no, angle);
}

void setNextPose(int no, int angle) {
  int thatsTheRightNumber = 300;
  switch (no) {
    case 1:
      thatsTheRightNumber = max(min(angle, BASE_MAX), BASE_MIN);
      bioloid.setNextPose(1, thatsTheRightNumber);
      break;
    case 2:
    case 3:
      thatsTheRightNumber = max(min(angle, SHOULDER_MAX), SHOULDER_MIN);
      bioloid.setNextPose(2, thatsTheRightNumber);
      bioloid.setNextPose(3, 1024-thatsTheRightNumber);
      break;
    case 4:
    case 5:
      thatsTheRightNumber = max(min(angle, ELBOW_MAX), ELBOW_MIN);
      bioloid.setNextPose(4, thatsTheRightNumber);
      bioloid.setNextPose(5, 1024-thatsTheRightNumber);
      break;
    case 6:
      thatsTheRightNumber = max(min(angle, WRIST_MAX), WRIST_MIN);
      bioloid.setNextPose(6, thatsTheRightNumber);
      break;
    case 7:
      thatsTheRightNumber = max(min(angle, WROT_MAX), WROT_MIN);
      bioloid.setNextPose(7, thatsTheRightNumber);
      break;
    case 8:
      thatsTheRightNumber = max(min(angle, GRIP_MAX), GRIP_MIN);
      bioloid.setNextPose(8, thatsTheRightNumber);
      break;
    default:
      break;
  }
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
  delay(1000);
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

void Move(){
    delay(100);                    // recommended pause

    //bioloid.loadPose(Center);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    Serial.println("Moving servos to centered position");  
    for (int i = 1; i <= SERVOCOUNT; i++) {
        Serial.println(bioloid.getCurPose(i));
        Serial.println(bioloid.getNextPose(i));
    }
    delay(1000);
    bioloid.interpolateSetup(1000); // setup for interpolation from current->next over 1/2 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }
}

void MoveTest(){
  Serial.println("###########################");
  Serial.println("Initializing Movement Sign Test");  
  Serial.println("###########################");
  delay(500);  
  id = 1;
  pos = pos2 = 512;
 
// Base Servo Test

  Serial.println("Moving Servo ID: 1");
  
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
  Serial.println("###########################");
  Serial.println("Relaxing Servos.");
  Serial.println("###########################");    
  while(id <= SERVOCOUNT){
    Relax(id);
    id = (id++)%SERVOCOUNT;
    delay(50);
  }
}
    

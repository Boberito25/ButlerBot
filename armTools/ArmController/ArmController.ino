#include <ax12.h>
#include <BioloidController.h>
#include <avr/pgmspace.h>

BioloidController bioloid = BioloidController(1000000);

const int SERVOCOUNT = 8;
prog_uint16_t currPose[SERVOCOUNT+1];

void setup(){
   pinMode(0,OUTPUT);  
   currPose[0] = 8;
   currPose[1] = 512;
   currPose[2] = 512;
   currPose[3] = 512;
   currPose[4] = 512;
   currPose[5] = 512;
   currPose[6] = 512;
   currPose[7] = 512;
   currPose[8] = 512;
   //initialize variables 
  //open serial port
   Serial.begin(9600);
   delay (500);   
    Serial.println("###########################");    
   Serial.println("Serial Communication Established.");  
}

void readServos() {
    int i;
    int pos;
    for (i = 0; i < SERVOCOUNT; i++) {
      pos =  ax12GetRegister(i, 36, 2);
      Serial.print("Servo ID: ");
      Serial.println(i);
      Serial.print("Servo Position: ");
      Serial.println(pos);
    }
}

void loop(){
    Serial.println("Waiting for servo #:");
    delay(3000);
    int inByte = -1;
    int angle = 0;
    if (Serial.available() > 0) { //if data is available
        inByte = Serial.read();
        Serial.print("Servo ID: ");
        Serial.println(inByte);
    }
    else {
        return;
    }

    if (inByte < 0 || inByte >= SERVOCOUNT) {
        Serial.println("Give a valid id plz");
        return;
    }
    Serial.print("Waiting for angle:");
    delay (3000);
    if (Serial.available() > 0) {
        angle = Serial.read();
    }
    else {
        return;
    }
    if (angle < 300 || angle > 800) {
        Serial.println("Give a reasonable angle plz");
        return;
    }
    currPose[inByte] = angle;
    Serial.print("Servo Position: ");
    Serial.println(angle);

    MoveSomewhere();

}

void MoveSomewhere(){
    delay(100);                    // recommended pause
    bioloid.loadPose(currPose);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    Serial.println("###########################");
    Serial.println("Moving servos to pose position");
    Serial.println("###########################");    
    delay(1000);
    bioloid.interpolateSetup(1000); // setup for interpolation from current->next over 1/2 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }
}

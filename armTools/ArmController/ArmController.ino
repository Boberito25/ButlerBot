#include <ax12.h>
#include <BioloidController.h>
#include <avr/pgmspace.h>

BioloidController bioloid = BioloidController(8);

const int SERVOCOUNT = 8;
prog_uint16_t currPose[SERVOCOUNT+1];

void setup(){
   pinMode(0,OUTPUT);
   Serial.begin(9600);
   delay(500); 
   bioloid.setup(8);
   bioloid.poseSize = SERVOCOUNT;
   currPose[0] = 8;
  
   Serial.println("###########################");    
   Serial.println("Serial Communication Established.");  
   Serial.println("###########################");
   Serial.println("Relaxing Servos...");
   bioloid.readPose();
   readServos();
   delay(5000);
   Serial.println("Initializing Servos...");
   initServos();
   //initialize variables 
   //open serial port
   delay (500);
   //bioloid.readPose();
}

void RelaxServos(){
  int id = 1;
  delay(500);
  Serial.println("Relaxing Servos...");
  while(id <= SERVOCOUNT){
    Relax(id);
    id++;
  }

}

void readServos() {
    int i;
    int pos;
    for (i = 0; i < SERVOCOUNT; i++) {
      pos =  bioloid.getCurPose(i);
      Serial.print("Servo ID: ");
      Serial.println(i + 1);
      Serial.print("Servo Position: ");
      Serial.println(pos);
    }
}

void initServos() {
    int i;
    int pos;
    Serial.println("Initializing Servos");
    for (i = 0; i < SERVOCOUNT; i++) {
      pos = ax12GetRegister(i + 1, 36, 2);
      currPose[i + 1] = pos;
      Serial.println(pos);

    }
}

void loop(){
    Serial.print("Servo 1 is at angle: ");
    Serial.println(currPose[1]);
    MoveSomewhere();
    Serial.println("Waiting for servo #:");
    delay(3000);
    int inByte = -1;
    String angle = "";
    if (Serial.available() > 0) { //if data is available
        inByte = Serial.read() - 48; //get the servo number
        Serial.print("Servo ID: ");
        Serial.println(inByte);
    }
    else {
        return; //if no servo given, continue
    }

    if (inByte < 0 || inByte >= SERVOCOUNT) {
        Serial.println("Give a valid id plz");
        return;
    }

    currPose[inByte] = 800;
    Serial.print("Servo Position: ");
    Serial.println(angle);
}

void MoveSomewhere(){
    delay(100);                    // recommended pause
    bioloid.loadPose(currPose);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    for (int i = 1; i <= SERVOCOUNT; i++) {
        Serial.println(bioloid.getCurPose(i));
        Serial.println(bioloid.getNextPose(i));
    }
    Serial.println("Moving servos to pose position");   
    delay(1000);
    bioloid.interpolateSetup(1000); // setup for interpolation from current->next over 1/2 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }
}

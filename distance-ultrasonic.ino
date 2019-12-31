#include <LiquidCrystal.h>

// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

/*
 * Sensor 1 
 * VCC - YELLOW
 * GND - BROWN
 * TRIG - ORANGE
 * ECHO - RED
 */ 
int trigPin1 = 50;
int echoPin1 = 52;
 
 /* 
 * Sensor 2
 * VCC - GREEN
 * GND - RED
 * TRIG - BLUE
 * ECHO - ORANGE
 */
 int trigPin2 = 53;
 int echoPin2 = 51;
 /*
 * 
 *  Sensor 3 
 * VCC - BROWN
 * GND - RED
 * TRIG - YELLOW
 * ECHO - ORANGE
 *
 */
 int trigPin3 = 48;
 int echoPin3 = 49;
 
 /* Sensor 4
 * VCC - GREEN
 * GND - BLACK
 * TRIG - YELLOW 
 * ECHO - WHITE
 */

 int trigPin4 = 46;
 int echoPin4 = 47;


// Steering wheel
int left = 5;
int right = 6;


//int trigPin = 6;    // Trigger
//int echoPin = 4;    // Echo
int ledPin = 43;
//long duration, cm, inches;
int rsPin = 31;
int ePin = 33;
int pind4 = 35;
int pind5 = 37;
int pind6 = 41;
int pind7 = 39;

long duration1, cm1, inches1;
long duration2, cm2, inches2;
long duration3, cm3, inches3;
long duration4, cm4, inches4;

int distances[4];

int targetDistance;
int distanceTravelled;
int distanceToTarget;
int selectedSensor = 0;

LiquidCrystal lcd(rsPin, ePin, pind4, pind5, pind6, pind7);
 
void setup() {

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
    // set up the LCD's number of columns and rows:
    
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Initializing...");
  
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  // Sensor 2
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  // Sensor 3
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  // Sensor 4
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Steering wheel
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);

  digitalWrite(left, HIGH);
  digitalWrite(right, LOW);


  start();
  delay(300);
  Serial.print("Selected sensor -> ");
  Serial.print(selectedSensor);
  Serial.println();
}


 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  //digitalWrite(trigPin, LOW);
  //delayMicroseconds(5);
  //digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin, LOW);

  //updateDistances();

  drive();


  
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  //pinMode(echoPin, INPUT);
  //duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  //cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  //inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135

  //blinkLed(cm);

  //lcd.clear();
  //lcd.print("Dist to obj:");
  //lcd.setCursor(12, 0);
  //lcd.print(cm);
  //lcd.setCursor(14, 0);
  //lcd.print("cm");


  //delay(250);
  //forward();
  //delay(1000);
  //stop();
  //turnRight();
  //delay(1000);
//

  

}

void updateDistanceTravelled(){
  switch(selectedSensor){
    case 1: 
      readSensor1();
      distanceTravelled = cm1;
      break;
    case 2:
      readSensor2();
      distanceTravelled =  cm2;
      break;
    case 3:
      readSensor3();
      distanceTravelled = cm3;
      break;
    case 4:
      readSensor4();
      distanceTravelled = cm4;
      break;
  }

  Serial.print("Distance travelled -> ");
  Serial.print(distanceTravelled);
  Serial.println();
}

void readSensor1(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
 
  // Convert the time into a distance
  cm1 = (duration1/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches1 = (duration1/2) / 74;   // Divide by 74 or multiply by 0.0135

  distances[0] = cm1;

  Serial.print(inches1);
  Serial.print(" s1 in, ");
  Serial.print(cm1);
  Serial.print(" s1 cm");
  Serial.println();
  
  delay(250);
}

void readSensor2(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
 
  // Convert the time into a distance
  cm2 = (duration2/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches2 = (duration2/2) / 74;   // Divide by 74 or multiply by 0.0135

  distances[1] = cm2;

  Serial.print(inches2);
  Serial.print(" s2 in, ");
  Serial.print(cm2);
  Serial.print(" s2 cm");
  Serial.println();
  
  delay(250);
}

void readSensor3(){
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin3, INPUT);
  duration3 = pulseIn(echoPin3, HIGH);
 
  // Convert the time into a distance
  cm3 = (duration3/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches3 = (duration3/2) / 74;   // Divide by 74 or multiply by 0.0135

  distances[2] = cm3;

  Serial.print(inches3);
  Serial.print(" s3 in, ");
  Serial.print(cm3);
  Serial.print(" s3 cm");
  Serial.println();
  
  delay(250);
}

/**
 * 
 * 
 */
void readSensor4(){
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin4, INPUT);
  duration4 = pulseIn(echoPin4, HIGH);
 
  // Convert the time into a distance
  cm4 = (duration4/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches4 = (duration4/2) / 74;   // Divide by 74 or multiply by 0.0135

  distances[3] = cm4;
  Serial.print(inches4);
  Serial.print(" s4 in, ");
  Serial.print(cm4);
  Serial.print(" s4 cm");
  Serial.println();
  
  delay(250);
}


// Sound alarm
void alarm(int cm){
  if(cm <= 9){
     
  }
}

/*
 * Find maximum element in array
 */
int find_maximum(int a[], int n) {
  int c, index = 0;

  for (c = 1; c <= n; c++)
    if (a[c] > a[index])
      index = c;

  return index;
}

void start(){
  checkDirection();
}

bool isTurningLeft = false;
bool isTurningRight = false;
bool needsToUpdateDirection = false;


void drive(){
  checkDistanceToTarget();
  updateDistanceToObject();
 // if(needsToUpdateDirection){
 //   checkDirection();
 //   needsToUpdateDirection = false;
 // }
  switch(selectedSensor){
    case 1: 
      reverse();
      break;
    case 2:
        if(isTurningLeft){
          Serial.print("Is turning left");
          Serial.println();
          needsToUpdateDirection = false;
          
          turnLeft();
          turnWheelBack();
        }
        forward();
      break;
    case 3:
       forward();
      break;
    case 4:
        if(isTurningRight){
          Serial.print("Is turning right");
          Serial.println();
          needsToUpdateDirection = false;
          turnRight();
          turnWheelBack(); 
        }
        forward();
      break;
  }
}

void updateDistanceToObject(){
  switch(selectedSensor){
    case 1: 
      readSensor1();
      targetDistance = cm1;
      break;
    case 2:
      readSensor2();
      targetDistance = cm2;
      break;
    case 3:
      readSensor3();
      targetDistance = cm3;
      break;
    case 4:
      readSensor4();
      targetDistance = cm4;
      break;
  }
}

void readSensors(){
  delay(500);
  readSensor1();
  delay(500);
  readSensor2();
  delay(500);
  readSensor3();
  delay(500);
  readSensor4();
  delay(500);
}

void updateDistances(){
  readSensors();
}

void checkDistanceToTarget(){
  Serial.print("Selected sensor -> ");
  Serial.print(selectedSensor);
  Serial.println();
  updateDistanceToObject();
  if(targetDistance <= 9){ 
    Serial.print(" Distance To Travel -> ");
    Serial.print(distanceToTarget);
    Serial.println();
    Serial.print("Time to stop");
    Serial.println();
    stop(3000);
    checkDirection();
  }

  Serial.print("Distance to target -> ");
  Serial.print(targetDistance);
  Serial.println();
} 

void checkDirection(){
  lcd.clear();
  lcd.print("Searching");
  delay(250);
  updateDistances();
  Serial.print("Current Distances");
  Serial.println();
  for(int i = 0; i < 4; i++){
    Serial.print("Sensor -> ");
    Serial.print(i+1);
    Serial.print(" Distance -> ");
    Serial.print(distances[i]);
    Serial.println();
  }
  int index = find_maximum(distances, 3);
  Serial.print("Maximum Index -> ");
  Serial.print(index);
  Serial.println();
  switch(index){
    case 0: 
      selectedSensor = 1;
      readSensor1();
      distanceToTarget = cm1;
      break;
    case 1:
      selectedSensor = 2;
      isTurningLeft = true;
      readSensor2();
      distanceToTarget = cm2;
      break;
    case 2:
      selectedSensor = 3;
      readSensor3();
      distanceToTarget = cm3;
      break;
    case 3:
      selectedSensor = 4;
      isTurningRight = true;
      readSensor4();
      distanceToTarget = cm4;
      break;
  }

    Serial.print(" Distance To Target -> ");
    Serial.print(targetDistance);
    Serial.println();
    Serial.print(" Distance To Reach Target -> ");
    Serial.print(distanceToTarget);
    Serial.println();
  
}

void accelerate(int speed){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
  delay(20);
}

void forward(){
  
  lcd.clear();
  lcd.print("Forward");
  accelerate(100);
  lcd.setCursor(0, 1); 
  lcd.print("Distance - ");
  lcd.print(distanceToTarget - targetDistance);
  lcd.print("cm");
}

void deccelerate(){
  for (int i = 255; i > 0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
 
}

void reverse(){
  
  lcd.clear();
  lcd.print("Backward");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 100);
  delay(20);
}

void rightSteer(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
  delay(20);
}

void leftSteer(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
  delay(20);
}

void turnRight(){
  
  lcd.clear();
  lcd.print("Right");
  isTurningRight = false;
  rightSteer();
  delay(10);
  accelerate(100);
  delay(500);
}

void turnLeft(){
  lcd.clear();
  lcd.print("Left");
  isTurningLeft = false;
  leftSteer();
  delay(30);
  accelerate(50);
  delay(500);
}

void turnWheelBack(){
  delay(100);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(100);
}

void stop(int time){
  lcd.clear();
  lcd.print("Stopped");
  lcd.setCursor(0, 1); 
  lcd.print("Distance - ");
  lcd.print(distanceToTarget - targetDistance);
  lcd.print("cm");
  blinkLed(5);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  needsToUpdateDirection = true;
  delay(time);
}


/*
 * Blink LED 5 times
 */

void blinkLed(int cm){
  if(cm <= 9){
    for(int i = 0; i < 5; i++){
      delay(150);
      digitalWrite(ledPin, HIGH);
      delay(150);
      digitalWrite(ledPin, LOW);
    }
  }else{
    digitalWrite(ledPin, LOW);
  }
}

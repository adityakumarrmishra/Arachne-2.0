#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include<SoftwareSerial.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
#define SERVOMIN 120  // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 675 
#define SERVO_MIN 150  // Adjust this value based on your servo
#define SERVO_MAX 600 
 // This is the 'maximum' pulse length count (out of 4096)
 int stepSize = 2;  
  bool reachedTarget;
  int c=0;
void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  yield();
  undeploy();
  setServoAngle(10,90);  
           setServoAngle(9,90);    
  
  delay(10000);
  // stand();
         setServoAngle(10,0);  
           setServoAngle(9,0);    
  
}
void loop(){
//   if(c==0){
//   // stand();
//   delay(5000);
//   c++;
//   }
// else{
//   forward();
// }
// left();
if(c==0)
{
int val;
if(Serial.available() > 0){
    val = Serial.read();
          if(val=='I'){
             setServoAngle(10,90);  
           setServoAngle(9,90);  
           c++;
           delay(10000) ;
           stand();
          }
}
}
          if(c==1)
          {
            forward();
          }
}

// delay(5000);
//  forward();

void undeploy(){
  int currentPos[8] = {613,505,290, 227, 505,582, 381, 212 }; 

int targetPos[8] = {613,505,290, 227, 505,582, 381, 212 }; 
  do {
    reachedTarget = true;
    for (int i = 0; i < 8; i++) {
      if (currentPos[i] < targetPos[i]) {
        currentPos[i] += stepSize;
        if (currentPos[i] > targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      } else if (currentPos[i] > targetPos[i]) {
        currentPos[i] -= stepSize;
        if (currentPos[i] < targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      }
      pwm.setPWM(i + 1, 0, currentPos[i]);
    }
    delay(10);  // Delay for smooth movement
  } while (!reachedTarget); 
}
void stand() {
  int currentPos[8] = {613,505,290, 227, 505,582, 381, 212  }; 

int targetPos[8] = {444,505,290, 444, 505,428, 381, 381 }; 
  do {
    reachedTarget = true;
    for (int i = 0; i < 8; i++) {
      if (currentPos[i] < targetPos[i]) {
        currentPos[i] += stepSize;
        if (currentPos[i] > targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      } else if (currentPos[i] > targetPos[i]) {
        currentPos[i] -= stepSize;
        if (currentPos[i] < targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      }
      pwm.setPWM(i + 1, 0, currentPos[i]);
    }
    delay(10);  // Delay for smooth movement
  } while (!reachedTarget); 
}

void firstfeet(){
  int currentPos[8] = {444,505,  505, 505,   290,400,   381, 444 };  
int targetPos[8] = {444,290,  290,505,   505, 400,  597, 444};
 do {
    reachedTarget = true;
    for (int i = 0; i < 8; i++) {
      if (currentPos[i] < targetPos[i]) {
        currentPos[i] += stepSize;
        if (currentPos[i] > targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      } else if (currentPos[i] > targetPos[i]) {
        currentPos[i] -= stepSize;
        if (currentPos[i] < targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      }
      pwm.setPWM(i + 1, 0, currentPos[i]);
    }
    delay(10);  // Delay for smooth movement
  } while (!reachedTarget);
}

void firstthurst(){
   int currentPos[8] = {381,290,  290,444,   505,351,  597, 381 };  
   int targetPos[8] = {381,505,  505, 444,   290, 351,  381,381};

   do {
    reachedTarget = true;
    for (int i = 0; i < 8; i++) {
      if (currentPos[i] < targetPos[i]) {
        currentPos[i] += stepSize;
        if (currentPos[i] > targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      } else if (currentPos[i] > targetPos[i]) {
        currentPos[i] -= stepSize;
        if (currentPos[i] < targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      }
      pwm.setPWM(i + 1, 0, currentPos[i]);
    }
    delay(10);  // Delay for smooth movement
  } while (!reachedTarget);
}
void forward()
{
firstfeet();
  firstthurst();
}
void leftmove1()
{
   int currentPos[8] = {444,505,  505, 505,   290,428,   381, 444 };  
int targetPos[8] = {444,505,  505, 505,   505, 428,  597, 444};
 do {
    reachedTarget = true;
    for (int i = 0; i < 8; i++) {
      if (currentPos[i] < targetPos[i]) {
        currentPos[i] += stepSize;
        if (currentPos[i] > targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      } else if (currentPos[i] > targetPos[i]) {
        currentPos[i] -= stepSize;
        if (currentPos[i] < targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      }
      pwm.setPWM(i + 1, 0, currentPos[i]);
    }
    delay(10);  // Delay for smooth movement
  } while (!reachedTarget);
}


void combineleft()
{
 int currentPos[8] = {444,505,  505, 505,   505,428,   597, 381 };  
int targetPos[8] = {444,290,  290, 444,   290, 428, 381, 381};
 do {
    reachedTarget = true;
    for (int i = 0; i < 8; i++) {
      if (currentPos[i] < targetPos[i]) {
        currentPos[i] += stepSize;
        if (currentPos[i] > targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      } else if (currentPos[i] > targetPos[i]) {
        currentPos[i] -= stepSize;
        if (currentPos[i] < targetPos[i]) {
          currentPos[i] = targetPos[i];
        }
        reachedTarget = false;
      }
      pwm.setPWM(i + 1, 0, currentPos[i]);
    }
    delay(10);  // Delay for smooth movement
  } while (!reachedTarget);
}

void left()
{
  leftmove1();
  combineleft();
}
void moveServoSmoothly(uint8_t servoNum, int startPulse, int endPulse, int stepDelay) {
  int stepSize = (startPulse < endPulse) ? 1 : -1;

  for (int pulse = startPulse; (stepSize > 0) ? (pulse <= endPulse) : (pulse >= endPulse); pulse += stepSize) {
    pwm.setPWM(servoNum, 0, pulse);
    delay(10);
  }
}
void setServoAngle(uint8_t servoNumber, uint16_t angle) {
  // Convert angle to PWM value
  uint16_t pwmValue = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.setPWM(servoNumber, 0, pwmValue);  // The third argument is always 0 for Adafruit_PWMServoDriver
}
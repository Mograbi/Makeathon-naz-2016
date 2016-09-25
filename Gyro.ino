#include "CurieIMU.h"

int BUZZER = 8 ;// setting controls the digital IO foot buzzer
int redPin = 6;
int bluePin = 7;
unsigned int count = 0;
int sum = 0;
const int buttonPin = 2;
int buttonState = 0;
int flag = 0;

void print_z(int gz, int sum) {
  Serial.print(gz);
  Serial.print("\t");
  Serial.print(sum);
  Serial.println("");
}
void buzzer(void) {
  if (flag) {
    digitalWrite(redPin, HIGH);
      digitalWrite(redPin, LOW);
      flag = 0;
  } else {
    digitalWrite(bluePin, HIGH);
      digitalWrite(bluePin, LOW);
      flag = 1;
  }
      digitalWrite (BUZZER, HIGH) ;// send voice
      delay (1) ;// Delay 1ms
      digitalWrite (BUZZER, LOW) ;// do not send voice
      delay (1) ;// delay ms
      
      // edwe
}

void setup() {
  //Serial.begin(9600); // initialize //Serial communication
  //while (!Serial);    // wait for the //Serial port to open

  // initialize device
  //Serial.println("Initializing IMU device...");
  CurieIMU.begin();
  pinMode (BUZZER, OUTPUT) ;

  // Set the accelerometer range to 250 degrees/second
  CurieIMU.setGyroRange(250);
  pinMode(redPin, OUTPUT);
pinMode(bluePin, OUTPUT);
 pinMode(buttonPin, INPUT);
 attachInterrupt(buttonPin,up,RISING); // digital pin 2 // up
}

void up() {
  CurieIMU.begin();
  CurieIMU.setGyroRange(250);
  count = 0;
    sum = 0;
}
void loop() {
  
  float gx, gy, gz; //scaled Gyro values
   // delay(100);                  // waits for a second
  if (sum < -1500) {
    // nazel
    while (sum < -500) {
        buzzer();
      CurieIMU.readGyroScaled(gx, gy, gz);
      if (! (abs(gz) <= 30))
        sum += gz;
      //print_z(gz, sum);
    }
    //buzzer();
    delay(1000);
    up();
  } else if (sum <= -300) {
    // nazel
  }
  // read gyro measurements from device, scaled to the configured range
  CurieIMU.readGyroScaled(gx, gy, gz);
  
  // display tab-separated gyro x/y/z values
  if (! (abs(gz) <= 30))
    sum += gz;
  if (abs(gx) >= 40 || abs(gy) >= 40 || abs(gz) >= 40) {
    //buzzer();
    
  }
  //print_z(gz, sum);
}

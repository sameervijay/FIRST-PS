
#include <Wire.h>
#include <NewPing.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055();
NewPing sonar(11, 10, 500);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bno.begin();
  bno.setExtCrystalUse(true);
}

void loop(void) {
  // put your main code here, to run repeatedly:
  
  imu::Vector<3> degreesValues = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  imu::Vector<3> accel = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);

  Serial.print("Euler X ");
  Serial.print(degreesValues.x());
  Serial.print(" Y ");
  Serial.print(degreesValues.y());
  Serial.print(" Z ");
  Serial.print(degreesValues.z());
  Serial.print("\n");

  Serial.print("Distance: ");
  Serial.print(sonar.ping());
  Serial.print("\n");
  
  delay(400);
}

// 11, 10

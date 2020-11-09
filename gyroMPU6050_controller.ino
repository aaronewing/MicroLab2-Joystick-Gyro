/*================================================================
 * Lab 2: Game control with Joy Stick, Gyro, and Accelerometer
 * Controller Used: Joy Stick
 * Group 100: Sam St.Pierre, Aaron Ewing, Chandara Pheng
 * EECE.4520 - Microprocessors II
 * ===============================================================
 */

//Necessary libraries needed for gyroscope functionality
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

//Output pins -------------------------------------------------
const int buzzer = 4;     //Digital pin output

//Variables ---------------------------------------------------
int buzz = 0;

//Signal IO setup ---------------------------------------------
void setup() 
{
  //Start the I2C communication for comunicating with MPU6050
  Serial.begin(9600);  
  Wire.begin();
  pinMode(buzzer, OUTPUT);         
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() 
{
  mpu6050.update();

  //Move Forward (Key W)
  if(mpu6050.getGyroAngleX()<-50 && mpu6050.getGyroAngleY()<20) {      
    //Send Serial Port Data                  
    Serial.println("w");   
    delay(100);   
  }
  //Move Back (Key S)
  else if(mpu6050.getGyroAngleX()>50) {
    Serial.println("s");                                 
    delay(100);   
  }
  //Turn Left (Key A)
  else if (mpu6050.getGyroAngleY()<-60) {
    //Send Serial Port Data
    Serial.println("a");    
    delay(100);   
   }
  //Turn Right (Key D)
  else if(mpu6050.getGyroAngleY()>60) {
    //Send Serial Port Data
    Serial.println("d");                          
    delay(100);   
  }

  //Activate buzzer
  if (Serial.available() > 0) {
    buzz = Serial.read();

    if (buzz == '1') {
      tone(buzzer, 2000);
      delay(100);
      noTone(buzzer);
    }
  }
}

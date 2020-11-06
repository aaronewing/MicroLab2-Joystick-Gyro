/*================================================================
 * Lab 2: Game control with Joy Stick, Gyro, and Accelerometer
 * Controller Used: Joy Stick
 * Group 100: Sam St.Pierre, Aaron Ewing, Chandara Pheng
 * EECE.4520 - Microprocessors II
 * ===============================================================
 */


//Input pins ----------------------------------------------
const int x_axis = 0;       //Analog pin input
const int y_axis = 1;       //Analog pin input
const int sw_pin = 2;       //Digital pin input

//Output pins ---------------------------------------------
const int buzzer = 4;       //Digital pin output
int buzz = 0;
//Signal IO setup -----------------------------------------
void setup() {
  pinMode(sw_pin, INPUT);
  digitalWrite(sw_pin, HIGH);
  Serial.begin(9600);
}

void loop() {

  //X-axis read
  if (analogRead(x_axis) > 1000) {
    //send A
    Serial.println("d");
    delay(100);
  }
  else if (analogRead(x_axis) < 100) {
    //send D
    Serial.println("a");
    delay(100);
  }

  //Y-axis read
  if (analogRead(y_axis) > 1000) {
    //send S
    Serial.println("s");
    delay(100);
  }
  else if (analogRead('s') < 100) {
    //send W
    Serial.println("w");
    delay(100);
  }
  if (Serial.available() > 0) {
    buzz = Serial.read(); //reading input from snake game code

    if (buzz == '1') { //when an apple is touched the arduino should read this code
      tone(buzzer, 2000); //buzzer tone
      delay(100);
      noTone(buzzer);
    }
  }
}

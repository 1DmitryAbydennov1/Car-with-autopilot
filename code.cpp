#define SPEED_1      6  
#define DIR_1        7  
 
#define SPEED_2      5  
#define DIR_2        4  

#define IR_SENSOR_1  10  
#define IR_SENSOR_2  11  
#define IR_SENSOR_3  12  


#define FULL_SPEED   255  
#define STOP_SPEED   0    


#define ACTION_DELAY 500  

void setup() {

  pinMode(DIR_1, OUTPUT);
  pinMode(SPEED_1, OUTPUT);
  pinMode(DIR_2, OUTPUT);
  pinMode(SPEED_2, OUTPUT);
  
  pinMode(IR_SENSOR_1, INPUT);
  pinMode(IR_SENSOR_2, INPUT);
  pinMode(IR_SENSOR_3, INPUT);
  
  digitalWrite(DIR_1, LOW);
  digitalWrite(DIR_2, LOW);
  analogWrite(SPEED_1, STOP_SPEED);
  analogWrite(SPEED_2, STOP_SPEED);
}

void loop() {

  bool obstacleleft = !digitalRead(IR_SENSOR_1);
  bool obstaclecentre = !digitalRead(IR_SENSOR_2);
  bool obstacleright = !digitalRead(IR_SENSOR_3);

  if ((obstacleleft) || (obstacleleft && obstacleleft)) {
    digitalWrite(DIR_1, HIGH); 
    digitalWrite(DIR_2, HIGH);
    analogWrite(SPEED_1, FULL_SPEED);
    analogWrite(SPEED_2, FULL_SPEED);
    delay(700);

    digitalWrite(DIR_1, LOW); 
    digitalWrite(DIR_2, LOW);

    digitalWrite(DIR_2, HIGH);
    analogWrite(SPEED_1, STOP_SPEED);
    analogWrite(SPEED_2, FULL_SPEED);

    delay(500);

    digitalWrite(DIR_2, LOW);

    analogWrite(SPEED_1, FULL_SPEED);
    analogWrite(SPEED_2, FULL_SPEED);

    delay(500);

    analogWrite(SPEED_1, STOP_SPEED);
    analogWrite(SPEED_2, FULL_SPEED);

    delay(500);

  }
  else if (obstacleright) {
    digitalWrite(DIR_1, HIGH);
    digitalWrite(DIR_2, HIGH);
    analogWrite(SPEED_1, FULL_SPEED);
    analogWrite(SPEED_2, FULL_SPEED);
    delay(700);

    digitalWrite(DIR_1, LOW);
    digitalWrite(DIR_2, LOW);

    analogWrite(SPEED_1, STOP_SPEED);
    analogWrite(SPEED_2, FULL_SPEED);

    delay(500);

    analogWrite(SPEED_1, FULL_SPEED);
    analogWrite(SPEED_2, FULL_SPEED);

    delay(500);

    digitalWrite(DIR_2, HIGH);

    analogWrite(SPEED_1, STOP_SPEED);
    analogWrite(SPEED_2, FULL_SPEED);

    delay(500);



  }
  else {
    digitalWrite(DIR_1, LOW);
    digitalWrite(DIR_2, LOW);
    analogWrite(SPEED_1, FULL_SPEED);
    analogWrite(SPEED_2, FULL_SPEED);
  }
}
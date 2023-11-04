/*advanced motor movements 1
1. forward
2. reverse
3. right
4. left
*/
#define motFWDl  23
#define motREVl  22
#define motREVr  32
#define motFWDr	 33
const int encoderPin1A = 14;  // Encoder pin A
const int encoderPin1B = 12;  // Encoder pin B
const int encoderPin2A = 27;
const int encoderPin2B = 26;
volatile long encoder1Value = 0;
volatile long encoder2Value = 0;

void mLEFTforward() {
digitalWrite(motFWDl, HIGH);
digitalWrite(motREVl, LOW);
}
void mLEFTreverse(){
digitalWrite(motFWDl, LOW);
digitalWrite(motREVl, HIGH);
}
void mRIGHTforward(){  
digitalWrite(motFWDr, HIGH);
digitalWrite(motREVr, LOW);
}

void mRIGHTreverse(){
digitalWrite(motREVr, HIGH);
digitalWrite(motFWDr,LOW);
}
void robotSTOP(){
digitalWrite(motFWDr, LOW);
digitalWrite(motFWDl, LOW);
digitalWrite(motREVl, LOW);
digitalWrite(motREVr, LOW);
}
void mRIGHTstop(){
digitalWrite(motFWDr, LOW);
digitalWrite(motREVr, LOW);
}
void mLEFTstop(){
digitalWrite(motFWDl, LOW);
digitalWrite(motREVl, LOW);
}
void robotRIGHT(){
digitalWrite(motFWDl, HIGH);
digitalWrite(motREVl, LOW);
digitalWrite(motREVr, HIGH);
digitalWrite(motFWDr,LOW);
}
void robotLEFT(){
digitalWrite(motFWDl, LOW);
digitalWrite(motREVl, HIGH);
digitalWrite(motFWDr, HIGH);
digitalWrite(motREVr, LOW);
}
void robotFORWARD(){
digitalWrite(motFWDl, HIGH);
digitalWrite(motREVl, LOW);
digitalWrite(motFWDr, HIGH);
digitalWrite(motREVr, LOW);
}
void robotREVERSE(){
digitalWrite(motFWDl, LOW);
digitalWrite(motREVl, HIGH);
digitalWrite(motFWDr, HIGH);
digitalWrite(motREVr, LOW);

}



void setup() {

  Serial.begin(9600);


  pinMode(motFWDl, OUTPUT);
  pinMode(motREVl, OUTPUT);
  pinMode(motFWDr, OUTPUT);
  pinMode(motREVr, OUTPUT);
  Serial.begin(9600);


  pinMode(encoderPin1A, INPUT_PULLUP);
  pinMode(encoderPin1B, INPUT_PULLUP);
  pinMode(encoderPin2A, INPUT_PULLUP);
  pinMode(encoderPin2B, INPUT_PULLUP);


  attachInterrupt(digitalPinToInterrupt(encoderPin1A), updateEncoder1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPin2A), updateEncoder2, CHANGE);

}

void loop() {

robotFORWARD();
  delay (1500);
robotREVERSE();
  delay(1500);
robotRIGHT();
  delay(1500);
robotLEFT();
  delay(1500);
robotSTOP();
  delay(7500);




 Serial.print("  Encoder 1: ");
 Serial.println(encoder1Value);
 Serial.print("  Encoder 2: ");
 Serial.println(encoder2Value);

}


void updateEncoder1() {
  if (digitalRead(encoderPin1A) == digitalRead(encoderPin1B)) {
    encoder1Value++;
  } else {
    encoder1Value--;
  }
}
void updateEncoder2() {
  if (digitalRead(encoderPin2A) == digitalRead(encoderPin2B)) {
    encoder2Value++;
  } else {
    encoder2Value--;
  }
}

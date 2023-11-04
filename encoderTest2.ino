#define MotFwdL  23
#define MotRevL  22

//controlling motor via encoder value

const int encoderPin1A = 14;  // Encoder pin A
const int encoderPin1B = 12;  // Encoder pin B


volatile long encoder1Value = 0;

void robotFORWARD(){
digitalWrite(MotFwdL, HIGH);
digitalWrite(MotRevL, LOW);
}

void robotSTOP(){
digitalWrite(MotFwdL, LOW);
digitalWrite(MotRevL, LOW);
}


void setup() {

  Serial.begin(9600);


  pinMode(MotFwdL, OUTPUT);
  pinMode(MotRevL, OUTPUT);
  Serial.begin(9600);


  pinMode(encoderPin1A, INPUT_PULLUP);
  pinMode(encoderPin1B, INPUT_PULLUP);


  attachInterrupt(digitalPinToInterrupt(encoderPin1A), updateEncoder1, CHANGE);

}

void loop() {


  if (encoder1Value < 1500) {
   robotFORWARD();
  } else {
    robotSTOP();
  }

  Serial.print("  Encoder 1: ");
  Serial.println(encoder1Value);

}


void updateEncoder1() {
  if (digitalRead(encoderPin1A) == digitalRead(encoderPin1B)) {
    encoder1Value++;
  } else {
    encoder1Value--;
  }
}

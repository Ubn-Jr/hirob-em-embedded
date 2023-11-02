//The robot moves at the desired encoder value scale and the PWM value of the motors can be controlled.
#define motRm1  22
#define motRm2  23
#define motLm1  33
#define motLm2  32

const int encoderPin1A = 14;  // Encoder pin A
const int encoderPin1B = 12;  // Encoder pin B
volatile long encoder1Value = 0;

const int freq = 5000;
const int resolution = 8;

const int ledChannel1 = 1;
const int ledChannel2 = 3;
const int ledChannel3 = 6;
const int ledChannel4 = 7;

int desiredSpeed = 256;
int stopSpeed=0;
//unsigned long startTime = 0;  // Başlangıç zamanı

void updateEncoder1() {
  if (digitalRead(encoderPin1A) == digitalRead(encoderPin1B)) {
    encoder1Value++;
  } else {
    encoder1Value--;
  }
}

void setup() {
  Serial.begin(9600); //initialize serial comunication
  pinMode(encoderPin1A, INPUT_PULLUP);
  pinMode(encoderPin1B, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin1A), updateEncoder1, CHANGE);

  pinMode(motRm1, OUTPUT);
  pinMode(motRm2, OUTPUT);
  pinMode(motLm1, OUTPUT);
  pinMode(motLm2, OUTPUT);

  ledcSetup(ledChannel1, freq, resolution);
  ledcSetup(ledChannel2, freq, resolution);
  ledcSetup(ledChannel3, freq, resolution);
  ledcSetup(ledChannel4, freq, resolution);

  ledcAttachPin(motRm1, ledChannel1);
  ledcAttachPin(motRm2, ledChannel2);
  ledcAttachPin(motLm1, ledChannel3);
  ledcAttachPin(motLm2, ledChannel4);
}



void robotGo() {
  digitalWrite(motRm1, HIGH);
  digitalWrite(motRm2, LOW);
  digitalWrite(motLm1, HIGH);
  digitalWrite(motLm2, LOW);
  ledcWrite(ledChannel1, desiredSpeed);
  ledcWrite(ledChannel3, desiredSpeed);
  Serial.print("  Encoder 1: ");
  Serial.println(encoder1Value);
}
void robotSTOP() {
  digitalWrite(motRm1, LOW);
  digitalWrite(motRm2, LOW);
  digitalWrite(motLm1, LOW);
  digitalWrite(motLm2, LOW);
  ledcWrite(ledChannel1, stopSpeed);
  ledcWrite(ledChannel3, stopSpeed);
  Serial.print("  Encoder 1: ");
  Serial.println(encoder1Value);

}

void goRobot() {
  if (encoder1Value < 15000) {
    robotGo();
  } else {
    robotSTOP();
  }
}



void loop() {
  goRobot();
}

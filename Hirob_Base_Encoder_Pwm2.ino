//Hirob moves forward through a specific encoder value and then moves backward through a specific encoder value. This cycle repeats over and over.
#define motRm1  22
#define motRm2  23
#define motLm1  33
#define motLm2  32

int targetPosition = 15000;
int targetPositionReverse = 0;

const int encoderPin1A = 14;  // Encoder pin A
const int encoderPin1B = 12;  // Encoder pin B
volatile long encoder1Value = 0;

const int freq = 5000;
const int resolution = 8;

const int ledChannel1 = 1;
const int ledChannel2 = 3;
const int ledChannel3 = 6;
const int ledChannel4 = 7;

int desiredSpeed = 175;
int stopSpeed=0;
//unsigned long startTime = 0; 

void updateEncoder1() {
  if (digitalRead(encoderPin1A) == digitalRead(encoderPin1B)) {
    encoder1Value++;
  } else {
    encoder1Value--;
  }
}

void setup() {
  Serial.begin(9600);
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
void robotBack() {
  digitalWrite(motRm1, LOW);
  digitalWrite(motRm2, HIGH);
  digitalWrite(motLm1, LOW);
  digitalWrite(motLm2, HIGH);
  ledcWrite(ledChannel2, desiredSpeed);
  ledcWrite(ledChannel4, desiredSpeed);
  Serial.print("  Encoder 1: ");
  Serial.println(encoder1Value);
}
void robotSTOP() {
  digitalWrite(motRm1, LOW);
  digitalWrite(motRm2, LOW);
  digitalWrite(motLm1, LOW);
  digitalWrite(motLm2, LOW);
  ledcWrite(ledChannel1, stopSpeed);
  ledcWrite(ledChannel2, stopSpeed);
  ledcWrite(ledChannel3, stopSpeed);
  ledcWrite(ledChannel4, stopSpeed);
  Serial.print("  Encoder 1: ");
  Serial.println(encoder1Value);

}
//-------------------------------------------
bool stopped = false;
bool goingForward = true;

void goRobot() {
  if (goingForward) {
    if (encoder1Value < targetPosition) {
      robotGo();
    } else {
      robotSTOP();
      goingForward = false;
    }
  }
}

void backRobot() {
  if (!goingForward) {
    if (encoder1Value > targetPositionReverse) {
      robotBack();
    } else {
      robotSTOP();
      goingForward = true;
    }
  }
}

void loop() {
  goRobot(); 
  backRobot(); 
}

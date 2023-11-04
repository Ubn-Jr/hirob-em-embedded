//Controlling HIROB with pwm
//speeds up and slows down
#define motRm1  22
#define motRm2  23
#define motLm1  33
#define motLm2	32


const int freq=5000;
const int resolution = 8;
//---
const int ledChannel1=0;

void RIGHTGO(){
digitalWrite(motRm1, HIGH);
digitalWrite(motRm2, LOW);
digitalWrite(motLm1, LOW);
digitalWrite(motLm2, LOW);
}

void LEFTGO(){
digitalWrite(motLm1, HIGH);
digitalWrite(motLm2, LOW);
digitalWrite(motRm1, LOW);
digitalWrite(motRm2, LOW);
}

void RIGHTBACK(){
digitalWrite(motRm1, LOW);
digitalWrite(motRm2, HIGH);
digitalWrite(motLm1, LOW);
digitalWrite(motLm2, LOW);
}

void LEFTBACK(){
digitalWrite(motLm1, LOW);
digitalWrite(motLm2, HIGH);
digitalWrite(motRm1, LOW);
digitalWrite(motRm2, LOW);
}
//---
void ROBOTGO (){
digitalWrite(motLm1, HIGH);
digitalWrite(motLm2, LOW);
digitalWrite(motRm1, HIGH);
digitalWrite(motRm2, LOW);
}
void ROBOTBACK (){
digitalWrite(motRm1, LOW);
digitalWrite(motRm2, HIGH);
digitalWrite(motLm1, LOW);
digitalWrite(motLm2, HIGH);
}
void ROBOTSTOP (){
digitalWrite(motRm1, LOW);
digitalWrite(motRm2, LOW);
digitalWrite(motLm1, LOW);
digitalWrite(motLm2, LOW);
}
void RIGHTSTOP(){
digitalWrite(motRm1, LOW);
digitalWrite(motRm2, LOW);
}
void LEFTSTOP(){
digitalWrite(motLm1, LOW);
digitalWrite(motLm2, LOW);
}
//---
void ROBOTRIGHT(){
digitalWrite(motLm1, HIGH);
digitalWrite(motLm2, LOW);
digitalWrite(motRm1, LOW);
digitalWrite(motRm2, HIGH);
}
void ROBOTLEFT(){
digitalWrite(motLm1, LOW);
digitalWrite(motLm2, HIGH);
digitalWrite(motRm1, HIGH);
digitalWrite(motRm2, LOW);
}
void setup() {
  pinMode(motRm1, OUTPUT);
  pinMode(motRm2, OUTPUT);
  pinMode(motLm1, OUTPUT);
  pinMode(motLm2, OUTPUT);

  ledcSetup(ledChannel1, freq, resolution);
  ledcAttachPin(motRm1, ledChannel1);
  ledcAttachPin(motLm1, ledChannel1);
}
//---------------------------------
void loop() {
int dutyCycle = 0;
ROBOTGO();
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
  ledcWrite(ledChannel1, dutyCycle);
  delay (10);
  }
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
  ledcWrite(ledChannel1, dutyCycle);
  delay (10);
  }
}

#define motRm1  23
#define motRm2  22
#define motLm1  33
#define motLm2	32

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
//------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------
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
}

void loop() {
ROBOTSTOP();
delay(10000);
ROBOTGO();
delay (1000);
ROBOTBACK();
delay (1000);
ROBOTSTOP();
delay(3000);
RIGHTGO();
delay (1000);
LEFTGO();
delay(1000);
RIGHTBACK();
delay(1000);
LEFTBACK();
delay(1000);
ROBOTSTOP();
delay(3000);
ROBOTRIGHT();
delay(1000);
ROBOTLEFT();
delay(1000);
}

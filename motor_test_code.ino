//BASİC MOTOR CONTROLL
#define MotFwd  35
#define MotRev  34
#define MotFwdL  23
#define MotRevL  22



void setup() {

  pinMode(MotFwd, OUTPUT);
  pinMode(MotRev, OUTPUT);
  pinMode(MotFwdL, OUTPUT);
  pinMode(MotRevL, OUTPUT);
  Serial.begin(9600);

}

void loop() {

 digitalWrite(MotFwd, HIGH);
 digitalWrite(MotRev, LOW);
 digitalWrite(MotFwdL, HIGH);
 digitalWrite(MotRevL, LOW);
 Serial.print("Forward  ");

}

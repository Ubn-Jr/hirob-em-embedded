//average speed with HIROB
//HIROB constantly moves forward at an average speed
#define motRm1  22
#define motRm2  23
#define motLm1  33
#define motLm2  32

const int freq = 5000;
const int resolution = 8;
const int ledChannel1 = 0;
int desiredSpeed = 175;

void setup() {
  pinMode(motRm1, OUTPUT);
  pinMode(motRm2, OUTPUT);
  pinMode(motLm1, OUTPUT);
  pinMode(motLm2, OUTPUT);

  ledcSetup(ledChannel1, freq, resolution);
  ledcAttachPin(motRm1, ledChannel1);
  ledcAttachPin(motLm1, ledChannel1);
}

void loop() {
  
  for (int dutyCycle = 0; dutyCycle <= desiredSpeed; dutyCycle++) {
    ledcWrite(ledChannel1, dutyCycle);
    delay(10);
  }

  
  ledcWrite(ledChannel1, desiredSpeed);

  
  while (true) {
    
  }
}

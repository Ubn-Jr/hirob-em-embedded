//controlling HIROB with pulse width modulation
//movements: forward-backward-right-left
#define motRm1  22
#define motRm2  23
#define motLm1  33
#define motLm2  32

const int freq = 5000;
const int resolution = 8;

const int ledChannel1 = 1;
const int ledChannel2 = 3;
const int ledChannel3 = 6;
const int ledChannel4 = 7;

int desiredSpeed = 175;
unsigned long startTime = 0;  // Başlangıç zamanı

void setup() {
  pinMode(motRm1, OUTPUT);
  pinMode(motRm2, OUTPUT);
  pinMode(motLm1, OUTPUT);
  pinMode(motLm2, OUTPUT);
  
  ledcSetup(ledChannel1, freq, resolution);
  ledcAttachPin(motRm1, ledChannel1);


  ledcSetup(ledChannel2, freq, resolution);
  ledcAttachPin(motRm2, ledChannel2);
  

  ledcSetup(ledChannel3, freq, resolution);
  ledcAttachPin (motLm1, ledChannel3);
  
  ledcSetup(ledChannel4, freq, resolution);
  ledcAttachPin (motLm2, ledChannel4);

}

void robotRight(unsigned long duration) {
  unsigned long startTimeRight = millis();  // Başlangıç zamanı

  while (millis() - startTimeRight < duration) {  // Belirli bir süre boyunca sağa git
    ledcWrite(ledChannel2, desiredSpeed);
    ledcWrite(ledChannel3, desiredSpeed);
  }

  ledcWrite(ledChannel2, 0);  // LED'i kapat
  ledcWrite(ledChannel3, 0);  // LED'i kapat
}
void robotLeft(unsigned long duration) {
  unsigned long startTimeLeft = millis();  // Başlangıç zamanı

  while (millis() - startTimeLeft < duration) {  // Belirli bir süre boyunca sola git
    ledcWrite(ledChannel1, desiredSpeed);
    ledcWrite(ledChannel4, desiredSpeed);
  }

  ledcWrite(ledChannel1, 0);  // LED'i kapat
  ledcWrite(ledChannel4, 0);
}
void robotGo(unsigned long duration) {
  unsigned long startTimeGo = millis();  // Başlangıç zamanı

  while (millis() - startTimeGo < duration) {  // Belirli bir süre boyunca ileri git
    ledcWrite(ledChannel1, desiredSpeed);
    ledcWrite(ledChannel3, desiredSpeed);
  }

  ledcWrite(ledChannel1, 0);  // LED'i kapat
  ledcWrite(ledChannel3, 0);  // LED'i kapat
}
void robotBack(unsigned long duration) {
  unsigned long startTimeBack = millis();  // Başlangıç zamanı

  while (millis() - startTimeBack < duration) {  // Belirli bir süre boyunca geri git
    ledcWrite(ledChannel2, desiredSpeed);
    ledcWrite(ledChannel4, desiredSpeed);
  }

  ledcWrite(ledChannel2, 0);  // LED'i kapat
  ledcWrite(ledChannel4, 0);  // LED'i kapat
}
void loop() {
robotGo (5000);
delay (1000);
robotBack (5000);
delay(1000);
robotRight(5000);
delay (1000);
robotLeft (5000);
delay(1000);
}

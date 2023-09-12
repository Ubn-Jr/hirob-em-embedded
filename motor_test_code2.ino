//MOTOR PWM TEST

#define MotFwd  23  // Motor Forward pin
#define MotRev  22 // Motor Reverse pin


const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;


void setup() {

  pinMode(MotFwd, OUTPUT); 
  pinMode(MotRev, OUTPUT); 
  Serial.begin(9600); //initialize serial comunication

  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(MotRev, ledChannel);


}

void loop() {

 digitalWrite(MotFwd, LOW); 
 digitalWrite(MotRev, HIGH);
 
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  digitalWrite(MotFwd, HIGH); 
  digitalWrite(MotRev, LOW);
 

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }

} 

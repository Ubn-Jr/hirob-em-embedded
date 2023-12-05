#include <WiFi.h>
#include <PubSubClient.h>

// WiFi bilgileri
const char *ssid = "";          // WiFi ağının adı (SSID)
const char *password = "";  // WiFi ağının şifresi

// MQTT bilgileri
const char *mqtt_server = "";  // MQTT broker'ın IP adresi
const char *topic = "";      // Abone olunacak MQTT konusu
const char *mqtt_username = "";
const char *mqtt_password = "";
String command;

WiFiClient espClient;
PubSubClient client(espClient);

// Motor pinleri
#define motRm1  22
#define motRm2  23
#define motLm1  33
#define motLm2  32

void forward (){
  Serial.println("Forward command received");
  digitalWrite(motRm1, HIGH);
  digitalWrite(motRm2, LOW);
  digitalWrite(motLm1, HIGH);
  digitalWrite(motLm2, LOW);
}
void backward(){
  digitalWrite(motRm1, LOW);
  digitalWrite(motRm2, HIGH);
  digitalWrite(motLm1, LOW);
  digitalWrite(motLm2, HIGH);
}
void stop(){
  digitalWrite(motRm1, LOW);
  digitalWrite(motRm2, LOW);
  digitalWrite(motLm1, LOW);
  digitalWrite(motLm2, LOW);
}
void left(){
  digitalWrite(motLm2, HIGH);
  digitalWrite(motLm1, LOW);
  digitalWrite(motRm1, HIGH);
  digitalWrite(motRm2, LOW);
}
void right(){
  digitalWrite(motLm1, HIGH);
  digitalWrite(motLm2, LOW);
  digitalWrite(motRm1, LOW);
  digitalWrite(motRm2, HIGH);
}
void mqttCallback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Received command: ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  command = Serial.readString();
  if (command == "right")
  {
    right();
  }
  else if (command == "left")
  {
    left();
  }
  else if (command == "forward")
  {
    forward();
  }
  else if (command == "backward")
  {
    backward();
  }
  else if (command == "stop")
  {
    stop();
  }
}


  
  /*
  Serial.println();
  if (Serial.available()){
    String command = Serial.readStringUntil('\n');
    if (command == "right")
  {
    right();
  }
  else if (command == "left")
  {
    left();
  }
  else if (command == "forward")
  {
    forward();
  }
  else if (command == "backward")
  {
    backward();
  }
  else if (command == "stop")
  {
    stop();
  }
}
}
*/
/*
  // Gelen komutu işle
  if (payload[i] == 'right')
  {
    right();
  }
  else if (payload[i] == 'left')
  {
    left();
  }
  else if (payload[i] == 'forward')
  {
    forward();
  }
  else if (payload[i] == 'backward')
  {
    backward();
  }
  else if (payload[i] == 'stop')
  {
    stop();
  }
}
*/
void mqttConnect()
{
  /* Bağlantı başarılı olana kadar döngü */
  while (!client.connected())
  {
    Serial.print("MQTT connecting...");
    /* İstemci ID'si */
    String clientId = "ESP32Client";
    /* Şimdi bağlan */
    if (client.connect(clientId.c_str(), mqtt_username, mqtt_password))
    {
      Serial.println("connected");
      /* Abone olunan konu (topic) */
      client.subscribe(topic);
    }
    else
    {
      Serial.print("failed, status code =");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      /* Tekrar denemeden önce 5 saniye bekle */
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(9600);
  
  // WiFi'ye bağlan
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Motor pinlerini çıkış olarak ayarla
  pinMode(motLm1, OUTPUT);
  pinMode(motLm2, OUTPUT);
  pinMode(motRm1, OUTPUT);
  pinMode(motRm2, OUTPUT);

  // MQTT server'ı ve callback fonksiyonunu ayarla
  client.setServer(mqtt_server, 1883);
  client.setCallback(mqttCallback);
}

void loop()
{
  if (!client.connected())
  {
    mqttConnect();
  }
  
  client.loop();
}

#include <DHT.h>

#include <Wire.h>

#include <LiquidCrystal_I2C.h>

#include <Servo.h>
 //ldc
LiquidCrystal_I2C lcd(0x27, 16, 2);
//senzor umiditate/temperatura
DHT dht(8, DHT11);
//motor servo clasa
Servo myservo;
//us verde-gnd ,ldc maro-gnd, buton verde 4 rosu 3
//key pad
#define key1 2
#define key2 3
#define key3 4
#define key4 5
//pin data pentru dht11
#define dataPin 8
float t;
float u;
//buzzer
#define buzzer 11
//senzor ultrasonic
const int trigPin = 10;
const int echoPin = 7;
long duration;
int distance;
//esp8266 data pin
int d4 = 6;
//contor
int contor = 0;
//detector de apa
int msensor = A1;
int msvalue = 0;
boolean flag = false;

void temperatura_umiditate_oled() {
  lcd.backlight();
  lcd.print("tempature  ");
  lcd.print(t);
  lcd.setCursor(0, 1);
  lcd.print("humidity  ");
  lcd.print(u);
  delay(1000);
}

void temperatura_umiditate() {
  u = dht.readHumidity();
  t = dht.readTemperature();

  String temp = String(t);
  String um = String(u);
  //Serial.println("Temp: " + temp + " ,Um: " + um);  
}

void senzor_ultra_sonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  //Serial.print("Distance: ");
  //Serial.println(distance);
}

void servo() {
  myservo.write(90);
  delay(1000);
  myservo.write(0);
  delay(1000);
  Serial.println("Servo ON");
}

void nr_1() {
  lcd.begin();
  lcd.backlight();
  lcd.print("Activare servo!");
  Serial.println("Button activat din nr_1.");
  servo();
}

void nr_2() {
  lcd.begin();
  lcd.backlight();
  lcd.print("WiFi conectat!");
  lcd.setCursor(0, 1);
  lcd.print("192.168.0.227");

}

void nr_3() {
  lcd.begin();
  lcd.backlight();
  lcd.print(contor);
}

void nr_4() {
  lcd.begin();
  lcd.backlight();
  lcd.print("Sup!");
}

void setup() {
  Serial.begin(9600);
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
  pinMode(key3, INPUT_PULLUP);
  pinMode(key4, INPUT_PULLUP);
  pinMode(d4, INPUT); //esp8266 reciver
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(msensor, INPUT);
  dht.begin();
  myservo.attach(A0);

  lcd.begin();
  lcd.backlight();
  lcd.print("SMTrash-can!");
  lcd.setCursor(0, 1);
  lcd.print("v2.0");
}

void loop() {
  int val = digitalRead(d4);
  int key1S = digitalRead(key1);
  int key2S = digitalRead(key2);
  int key3S = digitalRead(key3);
  int key4S = digitalRead(key4);
  msvalue = analogRead(msensor);
  //Serial.println(msvalue);

  senzor_ultra_sonic();
  temperatura_umiditate();

  /*
    if((distance >=12 && distance <=20) || val == 1){
      servo();
      contor++; 
    }
    */
  if (distance >= 12 && distance <= 20) {
    Serial.println("Senzor ultrasonic");
    servo();
  }

  if (val == 1) {
    Serial.println("ESP activat servo.");
    servo();
  }

  if (t >= 25 || msvalue <= 600) {
    tone(buzzer, 100);
    delay(1000);
    noTone(buzzer);
    delay(1000);
    Serial.println("ALERTA");
  }

  if (!key1S) {
    delay(250);
    Serial.println("key 1 is pressed");
    lcd.clear();
    nr_1();
  }

  if (!key2S) {
    delay(250);
    Serial.println("key 2 is pressed");
    lcd.clear();
    nr_2();
  }

  if (!key3S) {
    delay(250);
    Serial.println("key 3 is pressed");
    lcd.clear();
    nr_3();
  }

  if (!key4S) {
    delay(250);
    Serial.println("key 4 is pressed");
    lcd.clear();
    temperatura_umiditate_oled();
    delay(1000);
  }
}

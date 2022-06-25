#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266mDNS.h> 
#include <ESP8266WebServer.h>
#include <ThingESP.h>
#include <DHT.h>

ThingESP8266 thing("serban", "SMTrashcanESP", "123456789");

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);

unsigned long previousMillis = 0;
const long INTERVAL = 6000;  

DHT dht (14, DHT11);

#define led  12         //d6
#define dataPin 14      //d5
float t;
float u;

//detector de apa
int msensor = A0; 
int msvalue = 0; 

const char* ssid = "UPC7F34B27";
const char* pass = "Zcwcfj5x7apd";

void handleRoot();
void handleLED();
void handleNotFound();

void temperatura_umiditate(){
  u = dht.readHumidity();
  t = dht.readTemperature();

  String temp = String(t);
  String um = String(u);
  Serial.println("Temp: " + temp + " ,Um: " + um);
  delay(1000);  
}


void deschide_led(){ 

      digitalWrite(led, HIGH);
      Serial.println("deschis");

      delay(2000);
      digitalWrite(led, LOW);
      delay(2000);
      
      server.sendHeader("Location", "/");
      server.send(303);
  }

  void apa(){
  msvalue = analogRead(msensor);
  Serial.println(msvalue);
  /*
if ( msvalue >= 800  )
{
  Serial.println("nu apa"); 
   
}
else
  Serial.println("apa");
 */ 
}
 

void setup() {
  Serial.begin(115200);

  thing.SetWiFi("UPC7F34B27", "Zcwcfj5x7apd");
  
  thing.initDevice();
  
  dht.begin();
  pinMode(led, OUTPUT);
  pinMode(msensor, INPUT);

  delay(10);
  Serial.print('\n');

     wifiMulti.addAP(ssid, pass);
     Serial.println("Se conecteaza...");
     int i=0;
     while(wifiMulti.run() !=WL_CONNECTED){
      delay(250);
      Serial.print('.');
      
      }
      Serial.println('\n');
      Serial.print("Se conecteza la: ");
      Serial.println(WiFi.SSID());
      Serial.print("Adresa Ip: \t");
      Serial.println(WiFi.localIP());
  
      if(MDNS.begin("esp8266")){
        Serial.println("mDNS responder started");
        }
      else{
        Serial.println("Error setting up MDNS responder!");
        }

        server.on("/", HTTP_GET, handleRoot);
        server.on("/deschide", HTTP_POST, deschide_led);

        server.onNotFound(handleNotFound);

        server.begin();
        Serial.println("HTTP server started");
      
}

void loop() {
  server.handleClient();
  temperatura_umiditate();
  apa();
  thing.Handle();
}

void handleRoot(){
  String val_val = WiFi.localIP().toString();
  String apa_detectata = "<h3>&#10071 Alerta: apa detectata.</h3>";
  String temperatura_ridicata = "<h3>&#10071 Alerta: temperatura anormala de ridicata.</h3>";
  String stat_apa = "<h3>Status :higrometru &#9989</h3>";
  String stat_temperatura = "<h3>Status temperatura: &#9989</h3>"; 
  String contor_tem="",contor_apa=""; 
  String contor_ref="<meta http-equiv=\"refresh\" content=\"5\">";
  
  if(t >=20){
   mesaj_tem++;
   contor_tem=temperatura_ridicata;
   
    String msg_tem="Temperatura ridicata!";
    thing.sendMsg("+40740700538", msg_tem);
    delay(5000);
  
  }
  else 
    contor_tem=stat_temperatura;
    
   
    
  if(msvalue <= 800){
     mesaj_apa++;
     contor_apa=apa_detectata;
      String msg_apa="Apa detectata!";
      thing.sendMsg("+40740700538", msg_apa);
      delay(5000);
     
  }
  else
    contor_apa=stat_apa;
    
   
  String update_text = "<!DOCTYPE html><html><head>"+ contor_ref +"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">  <title>SMTrash-can Panel</title><style> input[type=button], input[type=submit], input[type=reset] {   background-color: #4CAF50;  border-radius: 12px;  color: white;  width: 300px;  padding: 30px;  text-align: center;  text-decoration: none;  display: inline-block;  font-size: 30px;  margin: 4px 2px;  cursor: pointer;}div {  width: 300px;  padding: 20px;  border: 4px solid gray;  margin: 0;}</style></head><body style=\"background-color:powderblue;\"><center><font face = \"Comic sans MS\" size = \"5\"><h2>SMTrash-can Panel v2</h2> <br><form action =\"/deschide\" method=\"POST\"><input type=\"submit\" value=\"Deschide\" ></form>"+ contor_tem + contor_apa + "<h3><div>Temperatura:" + String(t) + "  <br> Umiditate: " + String(u) + "</h3></div><div><h4> Info  <br>  SSID: "+ String(ssid) +"  <br>  IP:" + val_val + "</div></h4></font></center></body></html>";
  server.send(200, "text/html", update_text); 

  }

void handleLED(){
  digitalWrite(led,!digitalRead(led));
  server.sendHeader("Location", "/");
  server.send(303);
  }

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found");           

  }

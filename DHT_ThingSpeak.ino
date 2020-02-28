#include <DHT.h>  
#include <ESP8266WiFi.h>
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
String apiKey = "ZSW7XM5EG5KVR2S0";     
const char *ssid =  "IoT";    
const char *pass =  "88899922";
const char* server = "api.thingspeak.com";
#define DHTPIN D3         
DHT dht(DHTPIN, DHT11);
WiFiClient client;
unsigned long myChannelNumber = 1003242;
const char * myWriteAPIKey = "ZSW7XM5EG5KVR2S0"; 
void setup() 
{
       Serial.begin(9600);
       delay(10);
       dht.begin();
       Serial.println("Connecting ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass);
       ThingSpeak.begin(client);
}
 
void loop() 
{
      float h = dht.readHumidity();
      float t = dht.readTemperature();
                    if (isnan(h) || isnan(t)) 
                 {
                     Serial.println("Sensor Tidak Dapat Mendeteksi");
                      return;
                 }
                 ThingSpeak.writeField(myChannelNumber, 1,t, myWriteAPIKey);
                 ThingSpeak.writeField(myChannelNumber, 2,h, myWriteAPIKey);
                 delay(100);
                 //ThingSpeak.read();
}

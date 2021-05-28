#define TX_ESP32_PIN 9
#define RX_ESP32_PIN 10

#include <WiFi.h>
#include <HTTPClient.h>
const char* ap_ssid = "edes home";
const char* ap_password = "Eliana@1";
String serverName = "http://hydropoda.smartiotindo.com/";

unsigned long lastTime = 0;
unsigned long timerDelay = 5000; // 5s timer

void setup() {
  Serial.begin(115200); 
  setupHTTP();
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
  //Send an HTTP POST request every 10 minutes
  sendDataHTTP(6.5, 220, 24.5, 88.7, 1708.1945, "rizkia@telu"); delay(5000);
  getDataHTTP("kangkung");delay(5000);

  if ((millis() - lastTime) > timerDelay) {
    lastTime = millis();
  }
}

void sendDataHTTP(float pH, int ppm, float temp, float hum, int uv, String warna){
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      String serverPath = serverName+"tes2.php?key_api=HibahYPT2021&s0="+hum+"&s1="+temp+"&s2="+uv+"&s3="+ppm+"&s4="+pH+"&s5="+warna;   
      http.begin(serverPath.c_str());       // Your Domain name with URL path or IP address with path
      int httpResponseCode = http.GET();      // Send HTTP GET request
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
}

void getDataHTTP(String plantName){
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;
      String serverPath = serverName+"tes3.php?key_api=HibahYPT2021&jenis="+plantName;   
      http.begin(serverPath.c_str());       // Your Domain name with URL path or IP address with path
      int httpResponseCode = http.GET();      // Send HTTP GET request
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
}

void setupHTTP(){
  WiFi.begin(ap_ssid, ap_password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
const char* serverUrl = "http://your_server_url/api/energy";

void setup() {
  Serial.begin(115200);
  setup_wifi();
}

void setup_wifi() {
  delay(10);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(" connected");
}

void loop() {
  float energyUsage = readEnergyUsage();
  sendDataToServer(energyUsage);
  delay(60000); // Send data every minute
}

float readEnergyUsage() {
  // Simulate energy usage reading from the sensor
  // Replace with actual sensor reading code
  return random(100, 500) / 10.0;
}

void sendDataToServer(float energyUsage) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");
    
    String payload = "{\"energyUsage\": " + String(energyUsage) + "}";
    int httpResponseCode = http.POST(payload);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Response: " + response);
    } else {
      Serial.println("Error on sending POST");
    }

    http.end();
  } else {
    Serial.println("WiFi not connected");
  }
}

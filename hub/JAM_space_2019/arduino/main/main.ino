#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define SSID     ""
#define PASSWORD ""
#define TOKEN    ""

#define BUTTON_PIN D0
#define BUZZER_PIN D2
#define LED_PIN    D8

ESP8266WiFiMulti wifi;

// the setup function runs once when you press reset or power the board
void setup() {
  // Logger setup
  Serial.begin(9600);

  // Pins setup
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Wifi setup
  WiFi.mode(WIFI_STA);
  wifi.addAP(SSID, PASSWORD);
}

String makeRequest(String url, char method, String payload) {
  if ((wifi.run() != WL_CONNECTED)) {
    Serial.println("Wifi not connected");
    digitalWrite(LED_BUILTIN, HIGH);
    return "";
  }
  digitalWrite(LED_BUILTIN, LOW);

  WiFiClient client;
  HTTPClient http;

  if (!http.begin(client, "http://space.omnirem.dev" + url)) {
    Serial.println("Could not connect to server");
    digitalWrite(LED_BUILTIN, HIGH);
    return "";
  }
  
  int httpCode;
  http.addHeader("Authorization", TOKEN);
  if (method == 'G') {
      httpCode = http.GET();
  } else {
      http.addHeader("Content-Type", "application/json; charset=utf-8");
      http.addHeader("Content-Length", String(payload.length()));
      httpCode = http.POST(payload);
  }
  if (httpCode == HTTP_CODE_OK) {
      return http.getString();
  } else {
    Serial.println(String("Error in request, code: ") + httpCode);
    digitalWrite(LED_BUILTIN, HIGH);
    return "";
  }
}

// the loop function runs over and over again forever
void loop() {
  buttonChecker();
  pauseChecker();
}

void buttonChecker() {
  static int oldVal = 0;
  static int start = 0;
  int val = digitalRead(BUTTON_PIN);

  if (val == HIGH && oldVal == LOW) {
    start = millis();
  } else if (val == LOW && oldVal == HIGH) {
    int sec = (millis() - start) / 100;
    if (sec != 0) {
      sec = sec > 60 ? 60 : sec;
      Serial.println(String("Start a pause, size: ") + sec);
      makeRequest("/api/pause", 'P', String("{\"size\":") + sec + "}");
    }
    start = millis();
  }
  oldVal = val;
}

void pauseChecker() {
  static String oldDate = "";
  static String oldDate2 = "";
  static int limiter = 0;

  if (limiter >= 0) {
    limiter--;
    return;
  }
  limiter = 100000;
  
  String pause = makeRequest("/api/pause?origin=Arduino", 'G', "");
  if (pause == "")
    return;
    
  String date = pause.substring(0, 24);
  String lastPause = pause.substring(25, 50);
  if (oldDate2 != "" && lastPause > oldDate2) {
    Serial.println("Pause received");
    notification();
    oldDate2 = lastPause;
    oldDate = lastPause;
  } else if (date > oldDate) {
    oldDate2 = oldDate;
    oldDate = date;
  }
}

void notification() {
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 695);
  delay(150);
  digitalWrite(LED_PIN, LOW);
  tone(BUZZER_PIN, 575);
  delay(200);
  tone(BUZZER_PIN, 0);
  delay(10);
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 575);
  delay(300);
  digitalWrite(LED_PIN, LOW);
  tone(BUZZER_PIN, 0);
  delay(10);
  tone(BUZZER_PIN, 510);
  delay(100);
  tone(BUZZER_PIN, 0);
  delay(10);
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 575);
  delay(100);
  tone(BUZZER_PIN, 0);
  delay(10);
  tone(BUZZER_PIN, 695);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  tone(BUZZER_PIN, 0);
}

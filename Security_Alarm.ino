#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "NEXUS";
const char* password = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

const int LED_PIN = D1;
const int IR_PIN = D2;
const int BUZZER_PIN = D5;

void handleRoot() {

  int irState = digitalRead(IR_PIN);
  bool detected = (irState == LOW);

  String systemStatus = detected ? "ALERT" : "PROTECTED";
  String presenceStatus = detected ? "ACTIVITY DETECTED" : "NO ACTIVITY";
  String lightStatus = detected ? "ON" : "OFF";
  String alarmStatus = detected ? "ACTIVE" : "STANDBY";

  String mainClass = detected ? "alert" : "protected";

  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>

<meta name="viewport" content="width=device-width, initial-scale=1">

<title>SmartGuard</title>

<style>

* {
  box-sizing: border-box;
}

body {
  margin: 0;
  background: #0b1016;
  color: #ffffff;
  font-family: Arial, sans-serif;
}

.header {
  text-align: center;
  padding: 30px 20px 20px;
}

.brand {
  font-size: 28px;
  font-weight: bold;
  letter-spacing: 3px;
}

.subtitle {
  margin-top: 6px;
  color: #8d98a6;
  font-size: 12px;
  letter-spacing: 2px;
}

.connection {
  margin-top: 18px;
  display: inline-block;
  padding: 7px 15px;
  border-radius: 20px;
  background: #12351f;
  color: #4cff88;
  font-size: 12px;
  font-weight: bold;
}

.container {
  text-align: center;
  max-width: 480px;
  margin: auto;
  padding: 10px 18px 30px;
}

.status-panel {
  text-align: center;
  padding: 28px 15px;
  border-radius: 20px;
  margin-bottom: 18px;
  background: #151c24;
  border: 1px solid #27313d;
}

.status-label {
  color: #8d98a6;
  font-size: 12px;
  letter-spacing: 2px;
}

.main-status {
  font-size: 32px;
  font-weight: bold;
  margin-top: 10px;
}

.protected {
  color: #4cff88;
}

.alert {
  color: #ff4d5a;
}

.card {
  background: #151c24;
  border: 1px solid #27313d;
  border-radius: 18px;
  padding: 20px;
  margin: 14px 0;
}

.card-title {
  color: #8d98a6;
  font-size: 12px;
  letter-spacing: 2px;
  margin-bottom: 9px;
}

.card-value {
  font-size: 22px;
  font-weight: bold;
}

.footer {
  text-align: center;
  color: #5e6977;
  font-size: 11px;
  margin-top: 25px;
  letter-spacing: 1px;
}

</style>

<meta http-equiv="refresh" content="1">

</head>

<body>

<div class="header">

<div class="brand">
SMARTGUARD
</div>

<div class="subtitle">
SMART SAFETY SYSTEM
</div>

<div class="connection">
SYSTEM ONLINE
</div>

</div>


<div class="container">


<div class="status-panel">

<div class="status-label">
SYSTEM STATUS
</div>

<div class="main-status %MAINCLASS%">
%SYSTEMSTATUS%
</div>

</div>


<div class="card">

<div class="card-title">
PRESENCE
</div>

<div class="card-value %MAINCLASS%">
%PRESENCE%
</div>

</div>


<div class="card">

<div class="card-title">
WARNING LIGHT
</div>

<div class="card-value %MAINCLASS%">
%LIGHT%
</div>

</div>


<div class="card">

<div class="card-title">
ALARM
</div>

<div class="card-value %MAINCLASS%">
%ALARM%
</div>

</div>


<div class="footer">
SMARTGUARD SECURITY SYSTEM
</div>

</div>

</body>
</html>
)rawliteral";

  page.replace("%MAINCLASS%", mainClass);
  page.replace("%SYSTEMSTATUS%", systemStatus);
  page.replace("%PRESENCE%", presenceStatus);
  page.replace("%LIGHT%", lightStatus);
  page.replace("%ALARM%", alarmStatus);

  server.send(200, "text/html", page);
}


void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(IR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  WiFi.softAP(ssid, password);

  Serial.println();
  Serial.println("SMARTGUARD");
  Serial.println("Smart Safety System");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);

  server.begin();

  Serial.println("SMARTGUARD ONLINE");
}


void loop() {

  int irState = digitalRead(IR_PIN);

  if (irState == LOW) {

    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

  } else {

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

  }

  server.handleClient();
}
#include <WiFi.h>
#include <WebServer.h>
const char *ssid = "ESP32ap";
const char *password = "12345678";
WebServer server(80);
void handleRoot() {
  server.send(200, "text/html","<h1>TTGO hello world!</h1>");
}
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);

  

  //server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

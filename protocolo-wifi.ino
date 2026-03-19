#include <WiFi.h>

// Substitua pelas suas credenciais de rede
const char* ssid = "Galaxy A117882";
const char* password = "ueqm5463";

void setup() {
  Serial.begin(115200);
  Serial.print("Conectando a: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int tentativas = 0;
  while (WiFi.status() != WL_CONNECTED && tentativas < 20) {
    delay(500);
    Serial.print(".");
    tentativas++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n Conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("RSSI (sinal): ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
  } else {
    Serial.println("\n Falha na conexão!");
  }
}
void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconectando...");
    WiFi.reconnect();
  }
  delay(10000);
}
#include <WiFi.h>
#include <WiFiUdp.h>
#include <random>

const char* ssid = "OPPO F19 Pro+";
const char* password = "njau36i5";
const char* host = "192.168.29.70";  // IP address of the receiving server
const int port = 8888;                // Port number of the receiving server

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  udp.begin(port);
}

void loop() {
  for (int i = 0; i < 5; i++) {  // Generate and send 5 random numbers
    // Generate a random number
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    int randomNum = dist(gen);

    // Convert the random number to a string
    String data = String(randomNum);

    // Send the data over UDP
    udp.beginPacket(host, port);
    udp.print(data);
    udp.endPacket();

    Serial.print("Sent: ");
    Serial.println(data);

    delay(1000);  // Wait for 1 second before sending the next random number
  }
}
#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  // 初始化Wi-Fi模块
  WiFi.mode(WIFI_STA); // 设置为STA模式（客户端模式）
  //WiFi.disconnect(); // 断开当前连接（如果有的话）
  delay(100); // 等待Wi-Fi模块初始化完成
  Serial.println("Scanning available networks...");
}

void loop() {
  // 开始扫描Wi-Fi网络
  int networksFound = WiFi.scanNetworks();
  if (networksFound == 0) {
    Serial.println("No networks found.");
  } else {
    Serial.print("Found networks: ");
    Serial.println(networksFound);
    for (int i = 0; i < networksFound; i++) {
      // 打印每个网络的SSID和RSSI值
      Serial.print("Network ");
      Serial.print(i + 1);
      Serial.print(": SSID: ");
      Serial.print(WiFi.SSID(i));
      Serial.print(", RSSI: ");
      Serial.print(WiFi.RSSI(i));
      Serial.println(" dBm");
      delay(10); // 等待一段时间再扫描下一个网络
    }
  }
  delay(5000); // 等待5秒后再次扫描
}

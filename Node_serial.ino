#include <SoftwareSerial.h>
SoftwareSerial serial(12, 14); // (Rx, tx) d6 d5
#include <ArduinoJson.h>

double humedad; double temperatura; int humplantas;

void setup() {
  Serial.begin(9600);
  serial.begin(9600);
  while (!Serial) continue;
}

void loop() {
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& Objetojson = jsonBuffer.parseObject(serial);
  if (Objetojson == JsonObject::invalid())
    return;

  humedad = Objetojson["humedad"];
  temperatura = Objetojson["temperatura"];
  humplantas = Objetojson["humplantas"];

  Serial.print("humedad: "); Serial.print(humedad); Serial.println(" %");
  Serial.print("Temperatura: "); Serial.print(temperatura); Serial.println(" C");
  Serial.print("Humedad de las plantas "); Serial.print(humplantas); Serial.println(" %");
}

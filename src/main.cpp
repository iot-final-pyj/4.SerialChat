#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial swSer(21, 18);
void setup() {
    Serial.begin(115200);
    swSer.begin(9600);
    delay(3000);
    Serial.println();
    Serial.println("ready to chat");
}

void loop() {
    while (swSer.available()) {
        Serial.write(swSer.read());
    }
    while (Serial.available()) {
        swSer.write(Serial.read());
    }
}
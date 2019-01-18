/****************************************
 * Include Libraries
 ****************************************/

 #include "UbiMesh.h"

 /****************************************
 * Define Instances and Constants
 ****************************************/

UbiMesh UbiMesh("testtest");

void setup() {
    Serial.begin(115200);
}

void loop() {
    float value1 = analogRead(A0);

    bool flag = UbiMesh.ubiMeshPublish("test", "temp", value1);

    if (flag) {
        Serial.println("Value publish correctly");
    }

    delay(5000);

}
#define BLYNK_TEMPLATE_ID "TMPL3pNeK9kh2"
#define BLYNK_TEMPLATE_NAME "DHT IoT Sensor"
#define BLYNK_AUTH_TOKEN "oRaY2cV__5z9fn-e0x6KdEzMU2tYwA_h"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 // data pin is connected to D2 on esp
// program recognises D2 as pin 4

#define DHTTYPE DHT11 // Name the sensor as an object

char auth[] = "oRaY2cV__5z9fn-e0x6KdEzMU2tYwA_h";
char ssid[] = "Galaxy M317E44";
char pass[] = "ybjw4054";

DHT test(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT test successful !");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk connected successfully");
  test.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float h = test.readHumidity();
  float t = test.readTemperature();
  float f = test.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) 
  {
    Serial.println("Something is not working as intended");
    return; // because of void
  }

  Serial.println("Humidity: ");
  Serial.print(h);
  Serial.print(" %");
  Serial.println("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(1000);

}

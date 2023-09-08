#define BLYNK_TEMPLATE_ID "TMPL33YtuEdfs"
#define BLYNK_TEMPLATE_NAME "DHT IoT"
#define BLYNK_AUTH_TOKEN "HAcM1nLbf8kL9hEzHLe9GJ6kokLhUHWo"
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
char auth[] = "HAcM1nLbf8kL9hEzHLe9GJ6kokLhUHWo";
char ssid[] = "POCO X4 Pro 5G";
char pass[] = "hihihihi";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful!! ");
  Blynk.begin(auth ,ssid, pass);
  Serial.println("Connetcted blynk");
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intended!! ");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" Celsius");
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  delay(2000);
}

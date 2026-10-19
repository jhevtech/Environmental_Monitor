#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_SSD1306.h>
#include <BH1750.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1


Adafruit_BME280 bme;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
BH1750 lightMeter;

void setup() {
  // put your setup code here, to run:
  Serial.begin(9600);
  while(!Serial);

  Wire.begin();

  if (!bme.begin(0x76)) {
    Serial.println("BME280 not found!");
    while (1);
  }

  if (!lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("BH1750 not found!");
    while (1);
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 not found!");
    while (1);
  }

  Serial.println("All three sensors initialized.");
}

void loop() {
  // put your main code here, to run repeatedly:
  float tempC = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F;
  float lux = lightMeter.readLightLevel();

  // Print to Serial for your own debugging
  Serial.print("Temp: "); Serial.print(tempC); Serial.print(" C  ");
  Serial.print("Hum: "); Serial.print(humidity); Serial.print(" %  ");
  Serial.print("Pressure: "); Serial.print(pressure); Serial.print(" hPa  ");
  Serial.print("Lux: "); Serial.println(lux);

  // Draw everything into the buffer, then push once
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  /*display.setCursor(0, 0);
  display.println("Multi-sensor Environmental monitor"); */
  
  display.setCursor(0, 0);
  display.print("Temp: "); display.print(tempC); display.println(" C");

  display.setCursor(0, 16);
  display.print("Hum: "); display.print(humidity); display.println(" %");

  display.setCursor(0, 32);
  display.print("Pres: "); display.print(pressure); display.println(" hPa");

  display.setCursor(0, 48);
  display.print("Lux: "); display.println(lux);

  display.display();

  delay(2000);
}

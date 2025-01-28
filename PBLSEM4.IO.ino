#include <LiquidCrystal.h>

#define tempSensor A1     // Analog pin connected to the LM35 temperature sensor
#define moistureSensor A0 // Analog pin connected to the YL-69 sensor

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, ct = 9; // Pins connected to the LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                // Initialize LCD

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Hi:  T&M:");
}

void loop() {
  int tempValue = analogRead(tempSensor);         // Read temperature value from the LM35 sensor
  int moistureValue = analogRead(moistureSensor); // Read moisture value from the YL-69 sensor

  // Convert analog reading to temperature in Celsius
  float temperatureC = (tempValue / 1024.0) * 500.0;

  // Convert analog reading to moisture percentage (0-100%)
  int moisturePercentage = map(moistureValue, 0, 1023, 100, 0);

  lcd.clear(); // Clear the LCD screen

  // Display temperature and moisture on LCD
  lcd.setCursor(0, 0); // Set cursor to first row
  lcd.print("Hi ");
  lcd.print("Vishnu ");
  lcd.print("Sir");

  lcd.setCursor(0, 1); // Set cursor to second row
  lcd.print("T&M ");
  lcd.print(temperatureC);
  lcd.print("C ");
  lcd.print(moisturePercentage);
  lcd.print("%");

  // Print temperature and moisture to serial monitor
  Serial.print("Hi ");
  Serial.print("Vishnu ");
  Serial.println("Sir");
  Serial.print("T&M ");
  Serial.print(temperatureC);
  Serial.print("C ");
  Serial.print(moisturePercentage);
  Serial.println("%");


  delay(1000); // Delay before taking next reading
}


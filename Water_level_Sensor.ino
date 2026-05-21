/* 
Interfacing Water Level Sensor with Arduino UNO using is Analog Output pin of Module
by www.playwithcircuit.com
*/

#include <LiquidCrystal_I2C.h>  // Library to Run I2C LCD

// define the size of filter array
#define FILTER_SIZE 20
#define LOWER_THRESHOLD 5
#define UPPER_THRESHOLD 300

#define RED_PIN 10
#define BLUE_PIN 9
#define GREEN_PIN 8
#define BUZZER_PIN 2

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the analog pin for the soil moisture sensor
const int WaterSensorPin = A0;


//! Analog Value filter
int Filter(int sensorValue);

void setup() {
  // initialize the lcd
  lcd.init();
  // Turn on the Backlight
  lcd.backlight();
  // Clear the display buffer
  lcd.clear();
  // Make LED pins and Buzzer pin as output
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Turn Off all the pins
  digitalWrite(RED_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // Print a message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("Fill Percent:");
}

void loop() {

  // Variables to store sensor values
  int sensorValue;
  // Vaiable to Store fileted Value
  int filteredValue;
  // Fill percent
  int fillPercent;

  // Read the value from the soil moisture sensor
  sensorValue = analogRead(WaterSensorPin);
  filteredValue = Filter(sensorValue);
  fillPercent = map(filteredValue,LOWER_THRESHOLD, UPPER_THRESHOLD, 0, 100);

  // Display the filtered Analog Value on the LCD
  lcd.setCursor(0, 1);
  lcd.print(fillPercent);
  // Clear Previous Data
  lcd.print("%  ");

  // Change the color of LED as per water level
  if (fillPercent >= 99) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else if (fillPercent >= 10 && fillPercent < 99) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  } else if (fillPercent < 10) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Wait for 50 ms before the next loop
  delay(50);
}

//! Averaging filter to filter Analog Values
int Filter(int sensorValue) {
  static int analogArray[FILTER_SIZE] = { 0 };
  int filteredValue = 0;
  int i;

  //! Shift the Elemnent removing the oldest value stord at index 0
  for (i = 0; i < (FILTER_SIZE - 1); i++) {
    analogArray[i] = analogArray[i + 1];
  }

  //! Put the current value in the last element of Array i.e at index 9
  analogArray[9] = sensorValue;

  for (i = 0; i < FILTER_SIZE; i++) {
    filteredValue += analogArray[i];
  }

  //! Return Filtered Analog Value
  return (filteredValue / FILTER_SIZE);
}

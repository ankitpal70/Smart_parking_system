#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define IR_ENTRY  2
#define IR_EXIT   3
#define LED_GREEN 6
#define LED_RED   7
#define BUZZER    8
#define SERVO_PIN 9
#define MAX_SLOTS 4
#define GATE_OPEN   0
#define GATE_CLOSED 100

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gateServo;
int slots = MAX_SLOTS;

void showMessage(const char* line1, const char* line2, int slotsLeft = -1) {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(line1);
  lcd.setCursor(0, 1); lcd.print(line2);
  if (slotsLeft >= 0) lcd.print(slotsLeft);
}

void updateLEDs() {
  digitalWrite(LED_GREEN, slots > 0);
  digitalWrite(LED_RED,   slots == 0);
}

void openGate(int sensorPin) {
  gateServo.write(GATE_OPEN);
  while (digitalRead(sensorPin) == LOW);
  delay(1000);
  gateServo.write(GATE_CLOSED);
}

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(IR_ENTRY, INPUT);
  pinMode(IR_EXIT,  INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED,   OUTPUT);
  pinMode(BUZZER,    OUTPUT);

  gateServo.attach(SERVO_PIN);
  gateServo.write(GATE_CLOSED);
  digitalWrite(LED_GREEN, HIGH);

  showMessage("  ARDUINO", "PARKING SYSTEM");
  delay(2000);
}

void loop() {

  if (digitalRead(IR_ENTRY) == LOW) {
    delay(2000);
    if (slots > 0) {
      slots--;
      showMessage("CAR ENTERED", "Slot Left:", slots);
      openGate(IR_ENTRY);
    } else {
      digitalWrite(BUZZER, HIGH);
      showMessage("SORRY :(", "Parking Full");
      while (digitalRead(IR_ENTRY) == LOW);
      digitalWrite(BUZZER, LOW);
    }
  }

  if (digitalRead(IR_EXIT) == LOW && slots < MAX_SLOTS) {
    delay(2000);
    slots++;
    showMessage("CAR EXITED", "Slot Left:", slots);
    openGate(IR_EXIT);
  }

  updateLEDs();

  lcd.setCursor(0, 0); lcd.print("    WELCOME!    ");
  lcd.setCursor(0, 1); lcd.print("Slot Left: "); lcd.print(slots); lcd.print("  ");
}
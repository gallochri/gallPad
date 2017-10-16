#include <Arduino.h>
#include "DigiKeyboard.h"

#define LED 1
#define BTN1 0
#define BTN2 2

int BTN1_state = 0;
int BTN2_state = 0;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BTN1, INPUT);
    digitalWrite(BTN1,LOW);
    pinMode(BTN2, INPUT);
    digitalWrite(BTN2,LOW);
}

void loop() {
    DigiKeyboard.sendKeyStroke(0);
    BTN1_state = digitalRead(BTN1);
    if (BTN1_state == HIGH) {
        DigiKeyboard.println("pressed BTN1");
        digitalWrite(LED, HIGH);
    }

    BTN2_state = digitalRead(BTN2);
    if (BTN2_state == HIGH) {
        DigiKeyboard.println("pressed BTN2");
        digitalWrite(LED, HIGH);
    }
    delay(100);
    digitalWrite(LED, LOW);
}

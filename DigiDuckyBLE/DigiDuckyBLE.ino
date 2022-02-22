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
#define KEY_BK_SPACE   42  //BackSpace key as per documents at usb.org

SoftSerial BT(2,1);  //Bluetooth serial connection: RX = 2 , TX = 1

void setup(){
  BT.begin(9600);
  DigiKeyboard.delay(10000); //To allow for BT to connect
  
  BT.write("Intiate transmission...");
  while (true){
    if(BT.available()){ //inital messeage from connected device ensures read/write functionality through BT
      break;
    }
  }
  BT.write("\nReady To Receive Inputs:\n");
}

static char cmd;

void loop(){
  if(BT.available()){ //If serial transmisson coming through BT
    cmd = BT.read(); //Read character from BT serial channel
    
    switch (cmd){
      
      case '#': //emulates pressing windows key
        //BT.write("!!!Windows key pressed!!!\n"); //commented to enable multiline scripts from BT
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.delay(100);
        DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
        DigiKeyboard.delay(300);
        break;
        
      case '~': //emulates pressing of enter key
        //BT.write("!!!Enter key pressed!!!\n");
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.delay(500);
        DigiKeyboard.sendKeyStroke(KEY_ENTER);
        DigiKeyboard.delay(500);
        break;

      case '<': //emulates pressing of backspace key
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.delay(100);
        DigiKeyboard.sendKeyStroke(KEY_BK_SPACE);
        DigiKeyboard.delay(100);
        break;

      case '?': //opens run dialogue box
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.delay(500);
        DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
        DigiKeyboard.delay(500);
        break;

      case '^': //opens cmd as administrator
        
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT);
        DigiKeyboard.delay(500);
        DigiKeyboard.sendKeyStroke(KEY_A);
        DigiKeyboard.delay(1500);
        DigiKeyboard.sendKeyStroke(KEY_Y, MOD_ALT_LEFT);
        DigiKeyboard.delay(500);
        break;
        
      case '`': //shuts down host
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
  DigiKeyboard.update(); //updates keyboard to keep connection alive through usb
}

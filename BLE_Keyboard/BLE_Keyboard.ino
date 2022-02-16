#include <SoftSerial_INT0.h>
#include "DigiKeyboard.h"

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
        BT.write("!!!Windows key pressed!!!\n");
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
        cmd = BT.read();
        break;
        
      case '%':
        BT.write("!!!Enter key pressed!!!\n");
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.sendKeyStroke(KEY_ENTER);
        cmd = BT.read();
        break;
        
      default:
        DigiKeyboard.sendKeyStroke(0);
        DigiKeyboard.print(cmd);
    }
  }
  DigiKeyboard.update();
}

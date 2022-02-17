# DigiDucky

**DigiDucky** is a DIY RubberDucky device, based on DigiSpark ATTINY85 based microcontroller board.

## DigiDuckyBLE

This is the program that has to be uploaded to the microcontroller. It uses SoftSerial to connect with Bluetooth and can receive inputs from a BT serial terminal.
It can also receive multiline scripts from BT serial and execute on the host.  

Due to only 32kB of flash , 1kB of EEPROM... special key (KEY_ENTER,MOD_GUI_LEFT) need to be accessed using macros - ASCII character that are least used. This multiline scripts of DigiDucky are different to that of DuckyScript, So I call it QuackScript.

### QuackScript

* `#` corespondes to windows key and calls `DigiKeyboard.sendKeyStroke(MOD_GUI_LEFT)`  
* `~` coresponds to enter key and calls `DigiKeyboard.sendKeyStroke(KEY_ENTER)`  
* `<` coresponds to backspace key and calls `DigiKeyboard.sendKeyStroke(KEY_BK_SPACE)` where `KEY_BK_SPACE` is a macro defined to be `42 ` 
* `?` executes key combination to open *RUN* window    
* `^` executes key combination to open *cmd* in *Administrator* Mode  
  
**Note:**  \` runs a preprogammed script hardcoded in the program itself, in DigiDuckyBLE it shuts down the host pc.

### Resources

* USB Rubber Ducky Documentation by hak5darren: [https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Duckyscript](https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Duckyscript)  
* SoftSerial library modified by [J-Rios](https://github.com/J-Rios) to use INT0 instead PCINT0 interrupt: [https://github.com/J-Rios/Digispark_SoftSerial-INT0](https://github.com/J-Rios/Digispark_SoftSerial-INT0)
* USB Documentation by [usb.org](https://usb.org/): [https://usb.org/sites/default/files/hut1_22.pdf](https://usb.org/sites/default/files/hut1_22.pdf)
* [Digistump](https://github.com/digistump) drivers: [https://github.com/digistump/DigistumpArduino/releases/tag/1.6.7](https://github.com/digistump/DigistumpArduino/releases/tag/1.6.7)  
* [Digistump](https://github.com/digistump) DigiSpark Documentation: [https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkKeyboard/DigiKeyboard.h](https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkKeyboard/DigiKeyboard.h)  
* Digi-Spark scripts by [CedArctic](https://github.com/CedArctic): [https://github.com/CedArctic/DigiSpark-Scripts](https://github.com/CedArctic/DigiSpark-Scripts)

#include <MIDI.h>
#include <LiquidCrystal_I2C.h>
#include <OneButton.h>

int lcdColumns = 20;
int lcdRows = 4;

int expPin1 = 0;
int currentVal1 = 0;
int lastVal1 = 0;
boolean afinadorMode = false;
boolean stompMode = false;
boolean naoEhAouB = true;
boolean cenarioMode = false;
/*
boolean modoAB = false;

boolean isStompMode = true;
*/


boolean btnA1 = true;
boolean btnA2 = true;
boolean btnA3 = true;
boolean btnA4 = true;
boolean btnA5 = true;
boolean btnA6 = true;

boolean btnB1 = true;
boolean btnB2 = true;
boolean btnB3 = true;
boolean btnB4 = true;
boolean btnB5 = true;
boolean btnB6 = true;


LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
MIDI_CREATE_DEFAULT_INSTANCE();

// 48 ate 53 A   63 on 64 off
// 54 ate 59 B   63 on 64 off

/**  Button Config
      ------------------
      | 1    2   3   4 |
      |                |
      |                |
      | 3    4   5   6 |
      ------------------
*/

// configure buttons
OneButton button1(19, true, true);
OneButton button2(18, true, true);
OneButton button3(5, true, true);
OneButton button4(17, true, true);
OneButton button5(16, true, true);
OneButton button6(4, true, true);
OneButton button7(2, true, true);
OneButton button8(15, true, true);

#include "ModoStomp.h"

void setup(){
 
  lcd.init();                    
  lcd.backlight();
  lcd.clear();
  MIDI.begin();
  
  seletorStomp(true, true, true, true, true, true, true, true, true, true, true, true, true);
}


void loop(){
  /*
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Hello, World!");
  delay(1000);
  // clears the display to print new message
  lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear(); 
  */
}


void isStomp(boolean valor) {
  stompMode = valor;
}

void ativarStomp(boolean valor) {
  if (stompMode == false) {
    MIDI.sendControlChange(28, 63, 1);
    isStomp(valor);
  } else if (stompMode == true) {
    MIDI.sendControlChange(28, 64, 1);
    isStomp(valor);
  }
}

void pedalExpressao() {
  currentVal1 = analogRead(expPin1);
  currentVal1 = map(currentVal1, 0, 1023, 0, 127);
  currentVal1 = constrain(currentVal1, 0, 127);
  if (abs(currentVal1 - lastVal1) > 1) {
    MIDI.sendControlChange(11, currentVal1, 1);
  }

  lastVal1 = currentVal1;
  delay(5);
}

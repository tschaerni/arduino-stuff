/*
 * IR2KeyJW: based on IRrevcDemo (Version 0.1 July, 2009) of Ken Shirriff arcfn.com
 * Remote signal to keyboard use with openELEC
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Modified by JensLab at Feb, 2015 
 * Modified by tschaerni (robin@cerny.li) at Sep, 2016
 * OpenELEC / kodi - shortcuts
 * play/pause      - space
 * mute            - F8
 * volume +        - F10
 * volume -        - F9
 * menu            - m
 * info            - i
 * vorlauf         - f
 * rücklauf        - r
 * up              - pfeil nach oben
 * left            - pfeil nach links
 * right           - pfeil nach rechts
 * down            - pfeil nach unten
 * ok              - enter
 * back            - backspace
 * exit            - escape
 */

#include <IRremote.h>
#include <Keyboard.h>

int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;

// Recorded IRcodes
#define PLAY        0x807FA15E
// #define STOP        0x1478EC78
#define FORWARD     0x807F19E6
#define REWIND      0x807F59A6
#define UP          0x807F916E
#define DOWN        0x807F11EE
#define LEFT        0x807F51AE
#define RIGHT       0x807FD12E
#define ENTER       0x807FB14E
#define EXIT        0x807F31CE
#define BACK        0x807FF10E
// #define POWER       0x40CF3F38 // shutdown menu
#define MUTE        0x807F21DE
#define VOLUP       0x807F619E
#define VOLDOWN     0x807FE11E
#define MENU        0xB5B1729D
#define INFO        0x807F718E

// Mediaplayer hot keys
#define PLAY_KEY     Keyboard.write(32); // ASCII code for space
// #define STOP_KEY    Keyboard.write(120); // ASCII for x 
#define FORWARD_KEY  Keyboard.write(102); // ASCII for f 
#define REWIND_KEY   Keyboard.write(114); // ASCII for r 
#define UP_KEY       Keyboard.write(KEY_UP_ARROW); // Keyboard.press(KEY_UP_ARROW);      delay(100);  Keyboard.releaseAll();  
#define DOWN_KEY     Keyboard.write(KEY_DOWN_ARROW); // Keyboard.press(KEY_DOWN_ARROW);    delay(100);  Keyboard.releaseAll();  
#define LEFT_KEY     Keyboard.write(KEY_LEFT_ARROW); // Keyboard.press(KEY_LEFT_ARROW);    delay(100);  Keyboard.releaseAll();  
#define RIGHT_KEY    Keyboard.write(KEY_RIGHT_ARROW); // Keyboard.press(KEY_RIGHT_ARROW);   delay(100);  Keyboard.releaseAll();  
#define ENTER_KEY    Keyboard.write(KEY_RETURN);
#define EXIT_KEY     Keyboard.write(KEY_ESC);
#define BACK_KEY     Keyboard.write(KEY_BACKSPACE); // menue button
// #define POWER_KEY   Keyboard.write(115);  // ASCII for s, shutdown menu
#define MUTE_KEY     Keyboard.write(KEY_F8);  // F8 ?
// #define VOLUP_KEY    Keyboard.press(KEY_LEFT_SHIFT); Keyboard.write('1'); Keyboard.release(KEY_LEFT_SHIFT);  // mee for +
#define VOLUP_KEY    Keyboard.write(KEY_F10); // mee for +
#define VOLDOWN_KEY  Keyboard.write(KEY_F9); // mee for -
#define MENU_KEY     Keyboard.write(109); // ASCII for m
#define INFO_KEY     Keyboard.write(105); // ASCII for i

void setup()
{
  Serial.begin(9600); // for debugging
  irrecv.enableIRIn(); // Start the receiver
  Keyboard.begin();    // Start keyboard
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);  // for debugging
    // select action response to IR input
    switch(results.value) {
     case PLAY:
       PLAY_KEY;
       break;
//     case STOP:
//       STOP_KEY
//       break;
     case FORWARD:
       FORWARD_KEY
       break;
     case REWIND:
       REWIND_KEY
       break;
     case UP:
       UP_KEY
       break;
     case DOWN:
       DOWN_KEY
       break;
     case LEFT:
       LEFT_KEY
       break;
     case RIGHT:
       RIGHT_KEY
       break;
     case ENTER:
       ENTER_KEY
       break;
     case EXIT:
       EXIT_KEY
       break;
     case BACK:
       BACK_KEY
       break;
//     case POWER:
//       POWER_KEY
//       break;
     case MUTE:
       MUTE_KEY
       break;
     case VOLUP:
       VOLUP_KEY
       break;
     case VOLDOWN:
       VOLDOWN_KEY
       break;
     case MENU:
       MENU_KEY
       break;
     case INFO:
       INFO_KEY
       break;
     }

    irrecv.resume(); // Receive the next value    
  }
}

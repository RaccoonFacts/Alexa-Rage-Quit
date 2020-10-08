#include <AbsMouse.h>
#include<Keyboard.h>
#include<Wire.h>

const int led = 11;
int inbyte = 0;
int buttonPress = 0;

#define SLAVE_ADDR 9
#define ANSWERSIZE 3


void setup() {
Keyboard.begin();
AbsMouse.init(1920, 1080);
pinMode(led, OUTPUT);
digitalWrite(led, LOW);
Wire.begin(SLAVE_ADDR);
Wire.onReceive(receiveEvent);
Serial.begin(9600);
}


void receiveEvent() {
unsigned long currentMillis = millis();
  
  while(0 < Wire.available()) {
    buttonPress = Wire.read();
    
}
}
 
void loop() {
  if (buttonPress == 1) {
    rageQuit();
    quit();
  }
  if (buttonPress ==2 )
  {
    quit();
  }
  if (buttonPress == 0)
  {
    return;
  }
}
void rageQuit()
{
Serial.println("WORKING");
Keyboard.press(KEY_RIGHT_GUI);
Keyboard.release(KEY_RIGHT_GUI);  
delay(500);
Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press(KEY_LEFT_ALT);
Keyboard.press(KEY_DELETE);
Keyboard.releaseAll();
delay(500);
int i = 0;
do
{
digitalWrite(led, HIGH);
Keyboard.press(KEY_DOWN_ARROW);
Keyboard.release(KEY_DOWN_ARROW);
i++;
digitalWrite(led, LOW);
delay(500);
}
while( i < 4);
digitalWrite(led, HIGH);
Keyboard.press(KEY_RETURN);
Keyboard.release(KEY_RETURN);
digitalWrite(led, LOW);
delay(1500);
AbsMouse.move(1130, 200);
AbsMouse.press(MOUSE_LEFT);
digitalWrite(led, HIGH);
delay(100);
AbsMouse.release(MOUSE_LEFT);
delay(100);
digitalWrite(led, LOW);
AbsMouse.move(1130, 575); 
AbsMouse.press(MOUSE_LEFT);
AbsMouse.release(MOUSE_LEFT);
delay(5000);
digitalWrite(led, HIGH);
delay(2000);
AbsMouse.move(1210, 100);
AbsMouse.press(MOUSE_LEFT);
AbsMouse.release(MOUSE_LEFT);
digitalWrite(led, LOW);
delay(500);
digitalWrite(led, HIGH);
AbsMouse.move(1150, 90);
AbsMouse.press(MOUSE_LEFT);
AbsMouse.release(MOUSE_LEFT);
digitalWrite(led, LOW);
buttonPress = 2;
}




void quit()
{
  
  Keyboard.releaseAll();
  buttonPress == 0;
  Serial.println("quit function");
  
 
}

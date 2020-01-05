#include <IRremote.h>

IRsend irsend;
const int button1Pin = 4;
const int button2Pin = 5;
const int button3Pin = 6;
const int button4Pin = 7;
const int button5Pin = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
}

void sendSignal(long code) {
  Serial.print("Send signal: NEC (32 bits) ");
  Serial.println(code, HEX);
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(code, 32);
    delay(40);
  }
  delay(100);
}

void loop() {
  if (digitalRead(button1Pin) == HIGH) {
    Serial.println("Button 1");
    sendSignal(0x807fd827);
  } else if (digitalRead(button2Pin) == HIGH) {
    Serial.println("Button 2");
    sendSignal(0x807f7887);
  } else if (digitalRead(button3Pin) == HIGH) {
    Serial.println("Button 3");
    sendSignal(0x807fb04f);
  } else if (digitalRead(button4Pin) == HIGH) {
    Serial.println("Button 4");
    sendSignal(0x807f4887);
  } else if (digitalRead(button5Pin) == HIGH) {
    Serial.println("Button 5");
    sendSignal(0x807f08f7);
  }
}

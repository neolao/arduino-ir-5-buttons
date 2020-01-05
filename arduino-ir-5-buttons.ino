#include <IRremote.h>

IRsend irsend;
const int button1Pin = 2;
const int button2Pin = 3;
const int button3Pin = 4;
const int button4Pin = 5;
const int button5Pin = 6;

void setup()
{
}

void sendSignal(int code) {
  irsend.sendNEC(code, 32);
  delay(1000);
}

void loop() {
  if (digitalRead(button1Pin) == HIGH) {
    sendSignal(0x807fd827);
  } else if (digitalRead(button2Pin) == HIGH) {
    sendSignal(0x807f7887);
  } else if (digitalRead(button3Pin) == HIGH) {
    sendSignal(0x807fb04f);
  } else if (digitalRead(button4Pin) == HIGH) {
    sendSignal(0x807f4887);
  } else if (digitalRead(button5Pin) == HIGH) {
    sendSignal(0x807f08f7);
  }
}

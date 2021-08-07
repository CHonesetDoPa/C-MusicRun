
#include <TuyaWifi.h>

TuyaWifi my_device;
#define DPID_SWITCH1 101
#define DPID_SWITCH2 102
#define DPID_SWITCH3 103
#define DPID_SWITCH4 104
#define DPID_SWITCH5 105
#define DPID_SWITCH6 106
#define DPID_SWITCH7 107
unsigned char dp_bool_value = 0;
unsigned long last_time = 0;
void music_test(){
    noTone(5);
    digitalWrite(3,HIGH);
    delay(1000);
}

void setup(){
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  my_device.init("rtoqxyuwhnpr3aya", "1.0.0");
}

void loop(){


  if ((digitalRead(13) == LOW && digitalRead(6) == LOW) && (digitalRead(12) == LOW && digitalRead(8) == LOW)) {
    music_test();

  } else if (digitalRead(13) == LOW) {
    tone(5,532);
    digitalWrite(3,HIGH);
  } else if (digitalRead(12) == LOW) {
    tone(5,587);
    digitalWrite(3,HIGH);
  } else if (digitalRead(11) == LOW) {
    tone(5,659);
    digitalWrite(3,HIGH);
  } else if (digitalRead(10) == LOW) {
    tone(5,698);
    digitalWrite(3,HIGH);
  } else if (digitalRead(9) == LOW) {
    tone(5,784);
    digitalWrite(3,HIGH);
  } else if (digitalRead(8) == LOW) {
    tone(5,880);
    digitalWrite(3,HIGH);
  } else if (digitalRead(6) == LOW) {
    tone(5,988);
    digitalWrite(3,HIGH);
  } else {
    noTone(5);
    digitalWrite(3,LOW);

  }

}
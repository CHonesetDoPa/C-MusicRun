void setup(){
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
}

void loop(){
  if (digitalRead(13) == LOW && (digitalRead(12) == LOW && digitalRead(11) == LOW)) {
    for (int i = 1; i <= 10; i = i + (1)) {
      delay(50);
      tone(5,532);
      delay(50);
      noTone(5);
    }

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
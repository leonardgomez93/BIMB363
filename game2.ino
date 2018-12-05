#include <CapacitiveSensor.h>
CapacitiveSensor   novaTouch = CapacitiveSensor(A2,A3);
CapacitiveSensor   endSpace = CapacitiveSensor(A0,A1); 
int novaPos;
long touch1;
long touch2;
unsigned long t1 = millis();
unsigned long t2 = 0;
unsigned long t3 = 0;
int wait = 3000;


void setup() {
  novaTouch.set_CS_AutocaL_Millis(0xFFFFFFFF);
  endSpace.set_CS_AutocaL_Millis(0xFFFFFFFF);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  digitalWrite(A4,HIGH);
  digitalWrite(A5,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  reset();
  Serial.begin(9600);
}


void loop() {
  touch1 = novaTouch.capacitiveSensor(30);
  touch2 = endSpace.capacitiveSensor(30);
  Serial.println(touch1);
  if(touch1 > 1000) {
    nova();
    delay(5000);
  }
  if(touch2 > 500) {
    delay(3000);
    touch2 = endSpace.capacitiveSensor(30);
    if(touch2 > 500) {
      reset();
    }
  }
  delay(100);
}


void reset() {
  novaPos = 3;
  for(int i = 4; i <= 53; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  digitalWrite(A4,HIGH);
  digitalWrite(A5,HIGH);  
}

void nova() {
  int r = random(1,6);
  for(int i = 1; i <= 2; i++) {
    for(int j = 0; j <= 255; j++) {
      analogWrite(2, j);
      analogWrite(3, j);
      delay(5);
    }
    delay(100);
  }
  delay(500);
  for(int i = 1; i <= r; i++) {
    novaPos++;
    digitalWrite(novaPos, LOW);
    delay(1000 - (i * 200));
  }
}


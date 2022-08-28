#include <Wire.h>
float temp;
float humid;
bool t=0;
bool h=0;
void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 //Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);           /* start serial for debug */
 //pinMode(28,INPUT);
}

void loop() {/*
 //Serial.print("x");/*
 Serial.println(digitalRead(22)); 
 delay(1000);
 Serial.print("y");
 Serial.println(digitalRead(24));
 delay(1000); 
 Serial.print("z");
 Serial.println(digitalRead(26));
 delay(1000);
 Serial.print("q");
 Serial.println(digitalRead(28));
 delay(1000);*/delay(1000);}
/*
// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
   /* Serial.print(c);           /* print the character */
/*    char x=Wire.read();
    Serial.print(x);
  }
 Serial.println();             /* to newline */


// function that executes whenever data is requested from master
/*void requestEvent() {
 Wire.write("Hello NodeMCU");  /*send string on request */

void receiveEvent(int howMany) {
  String msg;
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    if(c=='H'){h=1;}
    if(c=='T'){t=1;}
    //if (c=='H' ||c=='T'){char c =Wire.read();}
    else{msg+=c;}
    
    
    //Serial.print(c);           /* print the character */
  }
 //Serial.print(msg);
 if(t){Serial.print("Temperature: ");temp=msg.toFloat();Serial.print(temp);}
 else{Serial.print("Humidity: ");humid=msg.substring(3).toFloat()/100;Serial.print(round(humid*100));Serial.print("%");}
 msg=""; 
 Serial.println();             /* to newline */
 t=0;
 h=0;
}
/*
#include <Wire.h>
int sens1;
int sens2;
int sens3;
int sens4;

void setup() {
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onRequest(requestEvent);
}

void loop() {
  while (Wire.available()) {
  char input=Wire.read();
  if (input==120){
      char sens1=Serial.read();
      Serial.println("Sens1: ");
      Serial.println(sens1);
     }
     else if (input==121){
      char sens2=Serial.read();
      Serial.println("Sens2: ");
      Serial.println(sens2);
     }
     else if (input==122){
      char sens3=Serial.read();
      Serial.println("Sens3: ");
      Serial.println(sens3);
     }
     else if (input==113){
      char sens4=Serial.read();
      Serial.println("Sens4: ");
      Serial.println(sens4);
     }
  }
  // put your main code here, to run repeatedly:
  delay(1000);
}
void requestEvent() {
  Serial.println("hello ");}*/

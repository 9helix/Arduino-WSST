/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp8266-nodemcu-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Wire.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    float a;
    int b;

} struct_message;

// Create a struct_message called myData
struct_message myData;
bool x=0;
bool y=0;
bool z=0;
bool q=0;
bool ambient=0;
bool object=0;
//char input;
int countera=0;
int countero=0;
String combine="";
float combnum;
// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  //Serial.print("Bytes received: ");
  //Serial.println(len);
  //Serial.print("Char: ");
  //Serial.println(myData.a);
  float input=myData.a;
  int in=myData.b;
  String out;
  if(in){Serial.println("Humidity");
  
  out+="H";
  
  }
  else{Serial.println("Temperature");out+="T";}
  out+=String(input);
  char out2[50];
  out.toCharArray(out2, 50);
  Wire.beginTransmission(8);
  Wire.write(out2);
  Wire.endTransmission();
  Serial.println(myData.a);
  /*
  if(ambient&&input!='>'&&input!='['&&input!=']'&&input!='<'){

    //Serial.println(input);
    combine+=input;


    countera++;
    }
  if (countera>4){
      //Serial.println();
    combnum=combine.toFloat();
    Serial.print("Humidity: ");
    Serial.println(combine);
    combine="";
    ambient=0;
    countera=0;}
  if(object&&input!='>'&&input!='['&&input!=']'&&input!='<'){

    //Serial.println(input);
    combine+=input;


    countero++;
    }
  if (countero>4){
      //Serial.println();
    combnum=combine.toFloat();
    Serial.print("Temperature: ");
    Serial.println(combine);
    combine="";
    object=0;
    countero=0;}*/
  //if(x){  //Wire.beginTransmission(8); 
  //Wire.write("x"); 
  //Wire.write(input);
  //Serial.println(input);
  //Wire.endTransmission();
  //Serial.print(input=='<');
   /* if(int(input)==49){digitalWrite(D1,LOW);}
  else{digitalWrite(D1,HIGH);}
  x=0;}
  if(y){ */ //Wire.beginTransmission(8); 
  //Wire.write("y");  
  //Wire.write(input);
  //Wire.endTransmission();/*
  /*  if(int(input)==49){
      digitalWrite(D2,HIGH);}
  else{digitalWrite(D2,LOW);}
    
  y=0;}*/
  //if(z){  //Wire.beginTransmission(8); 
  //Wire.write("z");  
  //Wire.write(input);
  //Wire.endTransmission();
  /*  if(int(input)==49){digitalWrite(D3,HIGH);}
  else{digitalWrite(D3,LOW);}
    //Serial.print("z");
  z=0;}*/
  //if(q){  //Wire.beginTransmission(8); 
  //Wire.write("q");  
  //Wire.write(input);
  //Wire.endTransmission();
  //if(int(input)==49){digitalWrite(D4,HIGH);}
  //else{digitalWrite(D4,LOW);}
    //Serial.print("q");
  //Serial.println(input.toInt());
  //q=0;}*/
  if(input=='<' &&!ambient){ambient=1;}
  if(input=='[' &&!object){object=1;}
  //else if(input==62){object=1;}
  //else if(input==91){z=1;Serial.print("z");}
  //else if(input==93){q=1;Serial.print("q");}
  //else{Serial.println(input);}
  

}
 
void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);
  // Initialize Serial Monitor
  Serial.begin(9600);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  Serial.println();
  Serial.print("ESP8266 Board MAC Addres:  ");
  Serial.println(WiFi.macAddress());
  Wire.begin();
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}
//int counter=0;

void loop() {
}

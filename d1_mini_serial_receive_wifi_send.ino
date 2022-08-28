//code for d1 mini wemos in serial communication
#include <ESP8266WiFi.h>
#include <espnow.h>
const unsigned int MAX_MESSAGE_LENGTH = 6;
uint8_t broadcastAddress[] = {0x44,0x17, 0x93, 0x11, 0x94, 0x82}; //mac adress of the target device

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  float a;
  int b;
} struct_message;

// Create a struct_message called myData
struct_message myData;


unsigned long timerDelay = 1000;  // send readings timer

// Callback when data is sent
/*
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  //Serial.print("Last Packet Send Status: ");
  if (sendStatus == 0){
    //Serial.println("Delivery success");
  }
  else{
    //Serial.println("Delivery fail");
  }
}
*/
bool lock=1;
void setup() {
  
  Serial.begin(9600);
  //pinMode(LED_BUILTIN, OUTPUT);
  WiFi.mode(WIFI_STA); //wifi activate
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  //esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
 
 
void loop() {
    /*
  //Serial.println("5");
  while(Serial.available() > 0){ //if theres something in serial
 
     char getChar = Serial.read(); //read byte from serial
     Serial.print(getChar);
     myData.a= getChar;


      // Send message via ESP-NOW
     esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));

 
  delay(250); 
  }*/
 //Check to see if anything is available in the serial receive buffer
 
 while (Serial.available() > 0)
 {
   //Create a place to hold the incoming message
   static char message[MAX_MESSAGE_LENGTH];
   static unsigned int message_pos = 0;

   //Read the next available byte in the serial receive buffer
   char inByte = Serial.read();
   //Serial.println(!lock);
   //Message coming in (check not terminating character) and guard for over message size
   if ( (inByte != ']'||inByte!='>') && (message_pos < MAX_MESSAGE_LENGTH - 1)&&!lock )
   {
    //Serial.println("hey");
     //Add the incoming byte to our message
     message[message_pos] = inByte;
     // Serial.println(inByte);
     message_pos++;
   }
   //Full message received...
   else if(!lock)
   {
     //Add null character to string
     message[message_pos] = '\0';

     //Print the message (or do other things)
     //Serial.println(message);
     myData.a=atof(message);
     Serial.println(myData.a);
     if (inByte=='>'){myData.b=1;}
     else{myData.b=0;}
     Serial.println(myData.b);
     esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
     //Reset for the next message
     message_pos = 0;
     lock=1;
   }
   if (inByte=='<' || inByte=='['){lock=0;}
 }
}

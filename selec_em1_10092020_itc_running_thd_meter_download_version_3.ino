
/*****
 
 this code is cpoyright to the Avl india Pvt limited
 Code Developer:-Kamal Singh 
 DATE :- 10/09/2020
 VERSION :- VERSION 3
 
*****/
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ModbusMaster.h>
#include <SoftwareSerial.h>
//#include <ESP8266mDNS.h>
//#include <WiFiUdp.h>
//#include <ArduinoOTA.h>
//#include <ESP8266WebServer.h>

ModbusMaster node;
SoftwareSerial mySerial(D7, D8); // RX, TX
const char* ssid = "Airtel_Zerotouch";                 // wifi ssid
const char* password =  "12345678";         // wifi password
const char* mqttServer = "192.168.1.5";    // IP adress Raspberry Pi
const int mqttPort = 1883;
const char* mqttUser = "";      // if you don't have MQTT Username, no need input
const char* mqttPassword = "";  // if you don't have MQTT Password, no need input
//ESP8266WebServer server;
//bool ota_flag = true;
//uint16_t time_elapsed = 0;
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[2000];
int value = 0;
int rst_cnt = 0;
int mqtt_conn_cnt = 0;
uint8_t wifi_pin = D5;
uint8_t mqtt_pin = D3;
uint8_t ser_dis = D2;


void setup() {

  
       
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(wifi_pin, OUTPUT);
  pinMode(mqtt_pin, OUTPUT);
  pinMode(ser_dis, OUTPUT); 

  digitalWrite(wifi_pin, LOW);
  digitalWrite(mqtt_pin, LOW);
  digitalWrite(ser_dis, HIGH);
  

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
         delay(1000);
          rst_cnt = rst_cnt+1; 
        digitalWrite(wifi_pin, LOW);
        Serial.print("connecting..time(Sec)");
        Serial.println(rst_cnt);
        if (rst_cnt>15)
        {
          ESP.restart();
        }
    
  }
  Serial.println("Connected to the WiFi network having IP");
  Serial.println(WiFi.localIP());
   digitalWrite(wifi_pin, HIGH);
 
   
 //ArduinoOTA.setPassword("avl376377");
 //ArduinoOTA.onStart([]() {
    //String type;
    //if (ArduinoOTA.getCommand() == U_FLASH) {
      //type = "sketch";
    //} else { // U_FS
      //type = "filesystem";
    //}

    // NOTE: if updating FS this would be the place to unmount FS using FS.end()
    //Serial.println("Start updating " + type);
  //});
  //ArduinoOTA.onEnd([]() {
    //Serial.println("\nEnd");
  //});
  //ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    //Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  //});
  //ArduinoOTA.onError([](ota_error_t error) {
    //Serial.printf("Error[%u]: ", error);
    //if (error == OTA_AUTH_ERROR) {
      //Serial.println("Auth Failed");
    //} else if (error == OTA_BEGIN_ERROR) {
      //Serial.println("Begin Failed");
    //} else if (error == OTA_CONNECT_ERROR) {
      //Serial.println("Connect Failed");
    //} else if (error == OTA_RECEIVE_ERROR) {
      //Serial.println("Receive Failed");
    //} else if (error == OTA_END_ERROR) {
      //Serial.println("End Failed");
    //}
  //});
 // ArduinoOTA.begin();
  //Serial.println("Ready");
  //Serial.print("IP address: ");
  //Serial.println(WiFi.localIP());


 //server.on("/restart",[](){
 ///server.send(200,"text/plain","restarting.......");
 //delay(200);
 //ESP.restart();
//});

//server.on("/setflag",[](){
 //server.send(200,"text/plain","setting_flag.......");
 //ota_flag = true;
 //time_elapsed = 0;
//});
 //server.begin();  

  
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
     digitalWrite(mqtt_pin, HIGH);
      Serial.println("connected");
       mySerial.begin(19200);
        // Modbus slave ID 1
         node.begin(1, mySerial); 
      
       
    } else {

          mqtt_conn_cnt = mqtt_conn_cnt+1;
      Serial.print("failed with state ");
      Serial.println(client.state());
      Serial.print("failed_count..");
      Serial.println(mqtt_conn_cnt);
      delay(50);
      digitalWrite(mqtt_pin, LOW);
      if (mqtt_conn_cnt>2)
      {
       ESP.restart();
    }

    }
  }

//  client.publish("esp8266", "Hello Raspberry Pi");
//  client.subscribe("esp8266");






}
void callback(char* topic, byte* payload, unsigned int length) {

 Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  Serial.println("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  Serial.println();
  Serial.println("-----------------------");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
  }

void loop() {
   int mqtt_result = 0;
   //if (ota_flag)
  //{
        // uint16_t time_start = millis();
         //while(time_elapsed<15000)
    //{
       //ArduinoOTA.handle();
       //time_elapsed = millis()- time_start;
       //delay(10);
    //}
        //ota_flag = false;
  //}
 //server.handleClient();
 uint8_t result;
 uint8_t result1;

  uint16_t data[50];
  float x;
  float x1;
  float x2;
  float x3;
  float x4;
  float x5;
  float x6;
  float x7;
  float x8;
  float x9;
  float x10;
  float x11;
  float x12;
  float x13;
  float x14;
  float x15;
  float x16;
  float x17;
  float x18;
  float x19;
  unsigned long *p;
  unsigned long *p1;
  unsigned long *p2;
  unsigned long *p3;
  unsigned long *p4;
  unsigned long *p5;
  unsigned long *p6;
  unsigned long *p7;
  unsigned long *p8;
  unsigned long *p9;
  unsigned long *p10;
  unsigned long *p11;
  unsigned long *p12;
  unsigned long *p13;
  unsigned long *p14;
  unsigned long *p15;
  unsigned long *p16;
  unsigned long *p17;
  unsigned long *p18;
  unsigned long *p19;

  while (!client.connected())   {
 
      
    Serial.println("Connecting to MQTT...or wifi not connecting");
    client.connect("ESP8266Client",mqttUser, mqttPassword);
    mqtt_result=mqtt_result+1;
    digitalWrite(mqtt_pin, LOW);
    delay(1000);
    Serial.println(mqtt_result);
    if (mqtt_result>3)
    {
    ESP.restart();
   
      } 
   }
   if (client.connected()) {
    digitalWrite(mqtt_pin, HIGH);
   }
  node.clearResponseBuffer();
  result = node.readInputRegisters(0,100);
  //result = node.readInputRegisters(0x30124,18);
   
   
  if (result == node.ku8MBSuccess)
  {
    long now = millis();
if (now - lastMsg > 900) {
lastMsg = now;
    data[0]=node.getResponseBuffer(0x38);
    data[1]=node.getResponseBuffer(0x39);
    data[2]=node.getResponseBuffer(0x0);
    data[3]=node.getResponseBuffer(0x1);
   
    data[4]=node.getResponseBuffer(0x2);
    data[5]=node.getResponseBuffer(0x3);
    data[6]=node.getResponseBuffer(0x4);
    data[7]=node.getResponseBuffer(0x5);
    data[8]=node.getResponseBuffer(0x8);
    data[9]=node.getResponseBuffer(0x9);
    data[10]=node.getResponseBuffer(0xA);
    data[11]=node.getResponseBuffer(0xB);
    data[12]=node.getResponseBuffer(0XC);
    data[13]=node.getResponseBuffer(0xD);
    data[14]=node.getResponseBuffer(0x10);
    data[15]=node.getResponseBuffer(0x11);
    data[16]=node.getResponseBuffer(0x12);
    data[17]=node.getResponseBuffer(0x13);
    data[18]=node.getResponseBuffer(0x14);
    data[19]=node.getResponseBuffer(0x15);
    data[20]=node.getResponseBuffer(0x16);
    data[21]=node.getResponseBuffer(0x17);
    data[22]=node.getResponseBuffer(0x2A);
    data[23]=node.getResponseBuffer(0x2B);
    data[24]=node.getResponseBuffer(0x3A);
    data[25]=node.getResponseBuffer(0x3B);
    data[26]=node.getResponseBuffer(0x36);
    data[27]=node.getResponseBuffer(0x37);
    data[28]=node.getResponseBuffer(0x60);
    data[29]=node.getResponseBuffer(0x61);
    data[30]=node.getResponseBuffer(0x62);
    data[31]=node.getResponseBuffer(0x63);
    //data[0]=node.getResponseBuffer(0x82);
    //data[1]=node.getResponseBuffer(0x83);
    //data[2]=node.getResponseBuffer(0x84);
    //data[3]=node.getResponseBuffer(0x85);
    //data[4]=node.getResponseBuffer(0x86);
    //data[5]=node.getResponseBuffer(0x87);
    //data[6]=node.getResponseBuffer(0x88);
    //data[7]=node.getResponseBuffer(0x89);
    //data[32]=node.getResponseBuffer(96);
    //data[33]=node.getResponseBuffer(97);
    //data[34]=node.getResponseBuffer(97);
    //data[35]=node.getResponseBuffer(98);
    //data[29]=node.getResponseBuffer(135);
    //data[30]=node.getResponseBuffer(134);
    //data[31]=node.getResponseBuffer(137);
    //data[32]=node.getResponseBuffer(136);
    //data[33]=node.getResponseBuffer(139);
    //data[34]=node.getResponseBuffer(138);
    //data[35]=node.getResponseBuffer(141);
    //data[36]=node.getResponseBuffer(140);
    //memcpy(&reading1,data,4);
    //memcpy(&reading2,data,8);
    //memcpy(&reading3,data,12);
    //memcpy(&reading4,data,16);
    //memcpy(&reading5,data,20);
    //memcpy(&reading6,data,24);
    //memcpy(&reading7,data,28);
    //memcpy(&reading8,data,32);
    //memcpy(&reading9,data,36);
    //memcpy(&reading10,data,40);
    //memcpy(&reading11,data,44);
    //memcpy(&reading12,data,48);
    //memcpy(&reading13,data,52);
    //memcpy(&reading14,data,56);
    //memcpy(&reading15,data,60);
    //memcpy(&reading16,data,64);
    //memcpy(&reading17,data,68);
    //memcpy(&reading18,data,72);
      //memcpy(&reading17,data,68);
    //memcpy(&reading18,data,72);
    //reading17=0.0;
    //reading18=0.0;
    //reading19=0.0;
    //reading20=0.0;
    //Serial.println(reading12);
    //Serial.println(reading13);
    //Serial.println(reading14);
    ///Serial.println("Reading humidity values");
    ///Serial.println(node.getResponseBuffer(0));//This shows humidity
    ///Serial.println("Reading temprature values");
    ///Serial.println(node.getResponseBuffer(1));//This shows temprature
    ///Serial.println(node.getResponseBuffer(2));
    p = (unsigned long*)&x;
   *p = (unsigned long)data[1]<<16| data[0];   
    p1 = (unsigned long*)&x1;
   *p1 = (unsigned long)data[3]<<16| data[2]; 
    p2 = (unsigned long*)&x2;
   *p2 = (unsigned long)data[5]<<16| data[4]; 
    p3 = (unsigned long*)&x3;
   *p3 = (unsigned long)data[7]<<16| data[6]; 
    p4 = (unsigned long*)&x4;
   *p4 = (unsigned long)data[9]<<16| data[8]; 
    p5 = (unsigned long*)&x5;
   *p5 = (unsigned long)data[11]<<16| data[10]; 
    p6 = (unsigned long*)&x6;
   *p6 = (unsigned long)data[13]<<16| data[12]; 
    p7 = (unsigned long*)&x7;
   *p7 = (unsigned long)data[15]<<16| data[14]; 
    p8 = (unsigned long*)&x8;
   *p8 = (unsigned long)data[17]<<16| data[16]; 
    p9 = (unsigned long*)&x9;
   *p9 = (unsigned long)data[19]<<16| data[18]; 
    p10 = (unsigned long*)&x10;
   *p10 = (unsigned long)data[21]<<16| data[20]; 
    p11 = (unsigned long*)&x11;
   *p11 = (unsigned long)data[23]<<16| data[22]; 
    p12 = (unsigned long*)&x12;
   *p12 = (unsigned long)data[25]<<16| data[24]; 
    p13 = (unsigned long*)&x13;
   *p13 = (unsigned long)data[27]<<16| data[26]; 
    p14 = (unsigned long*)&x14;
   *p14 = (unsigned long)data[29]<<16| data[28]; 
    p15 = (unsigned long*)&x15;
   *p15 = (unsigned long)data[31]<<16| data[30]; 
   
    //x16 = 0.0;
    //x17 = 0.0;
    //x18 = 0.0;
    //x19 = 0.0;

    node.clearResponseBuffer();
    delay(100);
  
   result1 = node.readInputRegisters(130,12); 
    //if (result1 == node.ku8MBSuccess)
  
   
    data[32]=node.getResponseBuffer(0x00);
    data[33]=node.getResponseBuffer(0x01);
    data[34]=node.getResponseBuffer(0x06);
    data[35]=node.getResponseBuffer(0x07);
   
    data[36]=node.getResponseBuffer(0x08);
    data[37]=node.getResponseBuffer(0x09);
    data[38]=node.getResponseBuffer(0x0A);
    data[39]=node.getResponseBuffer(0x0B);
    p16 = (unsigned long*)&x16;
   *p16 = (unsigned long)data[33]<<16| data[32]; 
    p17 = (unsigned long*)&x17;
   *p17 = (unsigned long)data[35]<<16| data[34]; 
    p18 = (unsigned long*)&x18;
   *p18 = (unsigned long)data[37]<<16| data[36];
    p19 = (unsigned long*)&x19;
   *p19 = (unsigned long)data[39]<<16| data[38];


    //snprintf (msg, 2000, "{\"msg\":\"EM1_THD_(V12)(Hz)->%.2f\",\"EM1_THD_(V23)->%.2f\",\"EM1_THD_V31(V31)->%.2f\",\"EM1_THD_I1->%.2f\"}", x,x1,x2,x3);
    snprintf (msg, 2000, "{\"msg\":\"EM1_Frequency(Hz)->%.2f\",\"EM1_Voltage Ph1-N(V)->%.2f\",\"EM1_Voltage Ph2-N(V)->%.2f\",\"EM1_Voltage Ph3-N(V)->%.2f\",\"EM1_Voltage Ph1-Ph2(V)->%.2f\",\"EM1_Voltage Ph2-Ph3(V)->%.2f\",\"EM1_Voltage Ph3-Ph1(V)->%.2f\",\"EM1_Current Ph1(A)->%.2f\",\"EM1_Current Ph2(A)->%.2f\",\"EM1_Current Ph3(A)->%.2f\",\"EM1_Current Avg(A)->%.2f\",\"EM1_Active Power(kW)->%.2f\",\"EM1_TOTAL Energy(kWh)->%.2f\",\"EM1_Power Factor->%.2f\",\"EM1_THD Voltage(V12)->%.2f\",\"EM1_THD Current(I1)->%.2f\",\"EM1_THD Current(I2)->%.2f\",\"EM1_THD Current(I3)->%.2f\",\"EM1_TOTAL Import Energy(kWh)->%.2f\",\"EM1_TOTAL Export Energy->%.2f\"}", x,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x16,x17,x18,x19,x14,x15);
    //snprintf (msg, 2000, "{\"msg\":\"%.2f\",\"%.2f\",\"%.2f\",\"%.2f\",\"%.2f\",\"%.2f\",\"%.2f\",\"%.2f\,\"%.2f\"}", reading14,reading13,reading14,reading13,reading14,reading13,reading14,reading13,reading11);
   
    puts (msg);
    client.publish("esp8266", msg);
    
    
   
    //client.subscribe("esp8266");
    //delay(200);
     node.clearResponseBuffer();
    client.loop();  
    
  }
  }
  if(result==node.ku8MBResponseTimedOut)
  {
    Serial.println("Inside Timeout block ");
  }

  if(result==node.ku8MBInvalidCRC)
  {
    Serial.println("Inside ku8MBInvalidCRC block ");
  }

  if(result==node.ku8MBInvalidFunction)
  {
    Serial.println("Inside ku8MBInvalidFunction block ");
  }

  if(result==node.ku8MBInvalidSlaveID)
  {
    Serial.println("Inside ku8MBInvalidFunction block ");
  }
  
  if(result==node.ku8MBSlaveDeviceFailure)
  {
    Serial.println("Inside ku8MBSlaveDeviceFailure block ");
  }

  if(result==node.ku8MBIllegalDataValue)
  {
    Serial.println("Inside ku8MBIllegalDataValue block ");
  }


  //delay(200);
}
   

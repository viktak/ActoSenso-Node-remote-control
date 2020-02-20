#define __debugSettings
#define __MQTT

#include "includes.h"

const uint16_t kCaptureBufferSize = 1024;
const uint8_t kTimeout = 50;  // Milli-Seconds
const uint16_t kFrequency = 38000;  // in Hz. e.g. 38kHz.
const uint16_t kMinUnknownSize = 12;
// Change to `true` if you miss/need the old "Raw Timing[]" display.
#define LEGACY_TIMING_INFO false

bool bonfoff= false;

//  ON
uint16_t IR_TOYOTOMI_ON[299] = {3076, 3012,  3082, 4390,  580, 526,  578, 530,  576, 528,  578, 528,  578, 1636,  576, 1638,  574, 1642,  572, 532,  574, 1644,  580, 1630,  572, 1642,  570, 1644,  580, 524,  580, 530,  576, 528,  578, 1638,  576, 1634,  576, 1638,  574, 532,  574, 532,  574, 532,  574, 532,  574, 1640,  572, 1642,  570, 536,  570, 536,  570, 540,  576, 526,  580, 1634,  578, 1636,  576, 1636,  576, 1638,  576, 530,  574, 536,  570, 532,  572, 534,  574, 1644,  578, 1630,  570, 1642,  570, 1644,  578, 1634,  578, 528,  578, 528,  578, 534,  572, 530,  576, 1640,  572, 1638,  574, 1640,  574, 532,  572, 534,  572, 534,  572, 534,  570, 1642,  570, 1644,  580, 1638,  574, 1636,  576, 530,  576, 530,  576, 530,  576, 534,  572, 1638,  574, 1640,  572, 1640,  574, 1640,  572, 534,  572, 536,  570, 536,  580, 526,  580, 1636,  576, 1634,  578, 1636,  576, 1638,  576, 39834,  3082, 3006,  3080, 4394,  576, 532,  574, 532,  574, 532,  574, 532,  574, 1640,  576, 1642,  576, 1632,  570, 538,  568, 1642,  580, 1634,  580, 1634,  578, 1636,  576, 530,  576, 530,  574, 534,  572, 1638,  574, 1638,  572, 1640,  572, 534,  572, 538,  578, 526,  570, 536,  572, 1644,  580, 1630,  578, 530,  576, 528,  578, 532,  574, 530,  576, 1640,  572, 1638,  574, 1640,  574, 1640,  576, 530,  572, 534,  576, 530,  572, 534,  572, 1642,  570, 1644,  580, 1634,  578, 1634,  578, 1636,  578, 528,  576, 530,  576, 530,  574, 532,  576, 1638,  572, 1640,  572, 1644,  568, 538,  578, 524,  570, 536,  570, 538,  568, 1644,  578, 1634,  578, 1636,  578, 1640,  572, 530,  576, 530,  574, 532,  574, 532,  574, 1642,  570, 1640,  572, 1642,  570, 1642,  570, 536,  580, 526,  580, 530,  574, 528,  578, 1636,  578, 1634,  576, 1638,  576, 1640,  572};  // UNKNOWN 88B3751F

//  OFF
uint16_t IR_TOYOTOMI_OFF[299] = {3074, 3014,  3082, 4390,  578, 528,  578, 532,  574, 530,  580, 526,  576, 1638,  578, 1636,  574, 1640,  572, 534,  572, 1644,  578, 1632,  568, 1644,  570, 1644,  578, 528,  578, 528,  578, 528,  578, 1640,  574, 530,  576, 530,  576, 530,  574, 532,  578, 1636,  574, 1640,  572, 1642,  570, 1642,  570, 536,  570, 536,  580, 530,  578, 526,  578, 1634,  580, 1632,  578, 1636,  576, 1638,  574, 532,  574, 536,  568, 532,  574, 532,  574, 1640,  572, 1642,  570, 1642,  570, 1644,  580, 1636,  576, 528,  578, 530,  574, 530,  578, 530,  574, 1636,  576, 1638,  574, 1640,  572, 534,  572, 534,  572, 534,  572, 534,  572, 1644,  568, 1646,  576, 1634,  578, 1634,  578, 528,  578, 530,  576, 530,  576, 530,  576, 1638,  574, 1638,  574, 1644,  580, 1630,  576, 530,  570, 536,  570, 536,  570, 540,  576, 1634,  578, 1634,  578, 1638,  574, 1636,  576, 39834,  3082, 3008,  3078, 4392,  576, 530,  576, 530,  576, 530,  576, 532,  574, 1642,  570, 1640,  572, 1640,  572, 538,  568, 1642,  570, 1644,  580, 1634,  578, 1638,  574, 532,  574, 530,  576, 530,  576, 1638,  574, 532,  574, 532,  572, 534,  576, 530,  572, 1640,  572, 1642,  570, 1646,  576, 1634,  578, 528,  578, 528,  578, 528,  578, 532,  572, 1638,  576, 1638,  574, 1638,  574, 1640,  572, 534,  572, 534,  572, 534,  572, 534,  570, 1642,  580, 1636,  580, 1632,  578, 1638,  574, 1636,  576, 534,  572, 530,  574, 532,  574, 532,  574, 1640,  572, 1644,  580, 1634,  568, 536,  570, 536,  580, 530,  576, 526,  578, 1634,  578, 1638,  574, 1636,  576, 1638,  578, 528,  574, 536,  572, 530,  574, 534,  572, 1640,  572, 1642,  570, 1642,  570, 1644,  578, 530,  576, 528,  578, 528,  576, 528,  578, 1638,  574, 1638,  576, 1638,  574, 1642,  570};  // UNKNOWN 2B64695F

IRrecv irrecv(IR_RECEIVE_GPIO, kCaptureBufferSize, kTimeout, false);
IRsend irsend(IR_SEND_GPIO);

decode_results results;

PCF857x i2c_io1(i2c_io1_address, &Wire);
PCF857x i2c_io2(i2c_io2_address, &Wire);
PCF857x i2c_io3(i2c_io3_address, &Wire);

volatile bool PCFInterruptFlag = false;
unsigned long inputPattern;

config appConfig;

// Current connection state
enum CONNECTION_STATE connectionState;

char defaultSSID[16];

//  Web server
ESP8266WebServer server(80);

//  Initialize Wifi
WiFiClient wclient;
PubSubClient PSclient(wclient);

//  Timers and their flags
os_timer_t heartbeatTimer;

bool needsHeartbeat = false;
bool ntpInitialized = false;

//  Other global variables
char timeout = 30;
bool isAccessPoint = false;
bool isAccessPointCreated = false;


// Daylight savings time rules for Greece
TimeChangeRule myDST = {"MDT", Fourth, Sun, Mar, 2, DST_TIMEZONE_OFFSET * 60};
TimeChangeRule mySTD = {"MST", First,  Sun, Nov, 2,  ST_TIMEZONE_OFFSET * 60};
Timezone myTZ(myDST, mySTD);

void LogEvent(int Category, int ID, String Title, String Data){
  if (PSclient.connected()){

    String msg = "{";

    msg += "\"Node\":" + (String)ESP.getChipId() + ",";
    msg += "\"Category\":" + (String)Category + ",";
    msg += "\"ID\":" + (String)ID + ",";
    msg += "\"Title\":\"" + Title + "\",";
    msg += "\"Data\":\"" + Data + "\"}";

    Serial.println(msg);

    #ifdef __MQTT
    if (PSclient.connected()){
      PSclient.publish(MQTT::Publish(MQTT_CUSTOMER + String("/") + MQTT_PROJECT + String("/") + String(ESP.getChipId()) + "/log/", msg ).set_qos(0));
    }
    #endif
  }
}

void heartbeatTimerCallback(void *pArg) {
  needsHeartbeat = true;
}

bool loadSettings(config& data) {
  fs::File configFile = SPIFFS.open("/config.json", "r");
  if (!configFile) {
    Serial.println("Failed to open config file");
    LogEvent(EVENTCATEGORIES::System, 1, "FS failure", "Failed to open config file.");
    return false;
  }

  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("Config file size is too large");
    LogEvent(EVENTCATEGORIES::System, 2, "FS failure", "Config file size is too large.");
    return false;
  }

  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);
  configFile.close();


  StaticJsonBuffer<SENSORDATA_JSON_SIZE> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(buf.get());

    if (!root.success()) {
    Serial.println("Failed to parse config file");
    LogEvent(EVENTCATEGORIES::System, 3, "FS failure", "Failed to parse config file.");
    return false;
  }

  #ifdef __debugSettings
  root.prettyPrintTo(Serial);
  #endif

  strcpy(appConfig.ssid, root["ssid"]);
  strcpy(appConfig.password, root["password"]);
  strcpy(appConfig.mqttServer, (const char*)root["mqttServer"]);

  appConfig.mqttPort = root["mqttPort"];

  appConfig.timeZone = root["timezone"];

  return true;
}

bool saveSettings() {
  StaticJsonBuffer<SENSORDATA_JSON_SIZE> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["ssid"] = appConfig.ssid;
  root["password"] = appConfig.password;

  root["timezone"] = appConfig.timeZone;

  root["mqttServer"] = appConfig.mqttServer;
  root["mqttPort"] = appConfig.mqttPort;

  #ifdef __debugSettings
  root.prettyPrintTo(Serial);
  #endif

  fs::File configFile = SPIFFS.open("/config.json", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    LogEvent(System, 4, "FS failure", "Failed to open config file for writing.");
    return false;
  }

  root.printTo(configFile);
  configFile.close();

  Serial.println("Json size: " + SENSORDATA_JSON_SIZE);
  return true;
}

void defaultSettings(){
  #ifdef __debugSettings
  strcpy(appConfig.ssid, DEBUG_WIFI_SSID);
  strcpy(appConfig.password, DEBUG_WIFI_PASSWORD);
  strcpy(appConfig.mqttServer, DEBUG_MQTT_SERVER);
  #else
  strcpy(appConfig.ssid, "ESP");
  strcpy(appConfig.password, "password");
  strcpy(appConfig.mqttServer, "test.mosquitto.org");
  #endif

  appConfig.mqttPort = 1883;

  appConfig.timeZone = 2;

  if (!saveSettings()) {
    Serial.println("Failed to save config");
  } else {
    Serial.println("Config saved");
  }
}

String DateTimeToString(time_t time){

  String myTime = "";
  char s[2];

  //  years
  itoa(year(time), s, DEC);
  myTime+= s;
  myTime+="-";


  //  months
  itoa(month(time), s, DEC);
  myTime+= s;
  myTime+="-";

  //  days
  itoa(day(time), s, DEC);
  myTime+= s;

  myTime+=" ";

  //  hours
  itoa(hour(time), s, DEC);
  myTime+= s;
  myTime+=":";

  //  minutes
  if(minute(time) <10)
    myTime+="0";

  itoa(minute(time), s, DEC);
  myTime+= s;
  myTime+=":";

  //  seconds
  if(second(time) <10)
    myTime+="0";

  itoa(second(time), s, DEC);
  myTime+= s;

  return myTime;
}

String TimeIntervalToString(time_t time){

  String myTime = "";
  char s[2];

  //  hours
  itoa((time/3600), s, DEC);
  myTime+= s;
  myTime+=":";

  //  minutes
  if(minute(time) <10)
    myTime+="0";

  itoa(minute(time), s, DEC);
  myTime+= s;
  myTime+=":";

  //  seconds
  if(second(time) <10)
    myTime+="0";

  itoa(second(time), s, DEC);
  myTime+= s;
  return myTime;
}

bool is_authenticated(){
  #ifdef __debugSettings
  return true;
  #endif
  if (server.hasHeader("Cookie")){
    String cookie = server.header("Cookie");
    if (cookie.indexOf("EspAuth=1") != -1) {
      LogEvent(EVENTCATEGORIES::Authentication, 1, "Success", "");
      return true;
    }
  }
  LogEvent(EVENTCATEGORIES::Authentication, 2, "Failure", "");
  return false;
}

void handleLogin(){
  String msg = "";
  if (server.hasHeader("Cookie")){
    String cookie = server.header("Cookie");
  }
  if (server.hasArg("DISCONNECT")){
    String header = "HTTP/1.1 301 OK\r\nSet-Cookie: EspAuth=0\r\nLocation: /login.html\r\nCache-Control: no-cache\r\n\r\n";
    server.sendContent(header);
    LogEvent(EVENTCATEGORIES::Login, 1, "Logout", "");
    return;
  }
  if (server.hasArg("username") && server.hasArg("password")){
    if (server.arg("username") == ADMIN_USERNAME &&  server.arg("password") == ADMIN_PASSWORD ){
      String header = "HTTP/1.1 301 OK\r\nSet-Cookie: EspAuth=1\r\nLocation: /status.html\r\nCache-Control: no-cache\r\n\r\n";
      server.sendContent(header);
      LogEvent(EVENTCATEGORIES::Login, 2, "Success", "User name: " + server.arg("username"));
      return;
    }
    msg = "<div class=\"alert alert-danger\"><strong>Error!</strong> Wrong user name and/or password specified.<a href=\"#\" class=\"close\" data-dismiss=\"alert\" aria-label=\"close\">&times;</a></div>";
    LogEvent(EVENTCATEGORIES::Login, 2, "Failure", "User name: " + server.arg("username") + " - Password: " + server.arg("password"));
  }

  fs::File f = SPIFFS.open("/pageheader.html", "r");
  String headerString;
  if (f.available()) headerString = f.readString();
  f.close();

  f = SPIFFS.open("/login.html", "r");

  String s, htmlString;

  while (f.available()){
    s = f.readStringUntil('\n');

    if (s.indexOf("%pageheader%")>-1) s.replace("%pageheader%", headerString);
    if (s.indexOf("%alert%")>-1) s.replace("%alert%", msg);

    htmlString+=s;
  }
  f.close();
  server.send(200, "text/html", htmlString);
}

void handleRoot() {
  LogEvent(EVENTCATEGORIES::PageHandler, 1, "Page requested", "/");

  if (!is_authenticated()){
    String header = "HTTP/1.1 301 OK\r\nLocation: /login.html\r\nCache-Control: no-cache\r\n\r\n";
    server.sendContent(header);
    return;
  }

  fs::File f = SPIFFS.open("/pageheader.html", "r");
  String headerString;
  if (f.available()) headerString = f.readString();
  f.close();

  f = SPIFFS.open("/index.html", "r");

  String FirmwareVersionString = String(FIRMWARE_VERSION) + " @ " + String(__TIME__) + " - " + String(__DATE__);

  String s, htmlString;

  while (f.available()){
    s = f.readStringUntil('\n');

    if (s.indexOf("%pageheader%")>-1) s.replace("%pageheader%", headerString);
    if (s.indexOf("%espid%")>-1) s.replace("%espid%", (String)ESP.getChipId());
    if (s.indexOf("%hardwareid%")>-1) s.replace("%hardwareid%", HARDWARE_ID);
    if (s.indexOf("%hardwareversion%")>-1) s.replace("%hardwareversion%", HARDWARE_VERSION);
    if (s.indexOf("%softwareid%")>-1) s.replace("%softwareid%", SOFTWARE_ID);
    if (s.indexOf("%firmwareversion%")>-1) s.replace("%firmwareversion%", FirmwareVersionString);

    htmlString+=s;
  }
  f.close();
  server.send(200, "text/html", htmlString);
  LogEvent(EVENTCATEGORIES::PageHandler, 2, "Page loaded", "/");
}

void handleStatus() {

  LogEvent(EVENTCATEGORIES::PageHandler, 1, "Page requested", "status.html");
  if (!is_authenticated()){
     String header = "HTTP/1.1 301 OK\r\nLocation: /login.html\r\nCache-Control: no-cache\r\n\r\n";
     server.sendContent(header);
     return;
  }

  fs::File f = SPIFFS.open("/pageheader.html", "r");
  String headerString;
  if (f.available()) headerString = f.readString();
  f.close();

  TimeChangeRule *tcr;        // Pointer to the time change rule
  time_t localTime = myTZ.toLocal(now(), &tcr);;

  String s;

  f = SPIFFS.open("/status.html", "r");

  String htmlString, ds18b20list;

  while (f.available()){
    s = f.readStringUntil('\n');

    //  System information
    if (s.indexOf("%pageheader%")>-1) s.replace("%pageheader%", headerString);
    if (s.indexOf("%chipid%")>-1) s.replace("%chipid%", (String)ESP.getChipId());
    if (s.indexOf("%uptime%")>-1) s.replace("%uptime%", TimeIntervalToString(millis()/1000));
    if (s.indexOf("%currenttime%")>-1) s.replace("%currenttime%", DateTimeToString(localTime));
    if (s.indexOf("%lastresetreason%")>-1) s.replace("%lastresetreason%", ESP.getResetReason());
    if (s.indexOf("%flashchipsize%")>-1) s.replace("%flashchipsize%",String(ESP.getFlashChipSize()));
    if (s.indexOf("%flashchipspeed%")>-1) s.replace("%flashchipspeed%",String(ESP.getFlashChipSpeed()));
    if (s.indexOf("%freeheapsize%")>-1) s.replace("%freeheapsize%",String(ESP.getFreeHeap()));
    if (s.indexOf("%freesketchspace%")>-1) s.replace("%freesketchspace%",String(ESP.getFreeSketchSpace()));

    //  Network settings
    switch (WiFi.getMode()) {
      case WIFI_AP:
        if (s.indexOf("%wifimode%")>-1) s.replace("%wifimode%", "Access Point");
        if (s.indexOf("%macaddress%")>-1) s.replace("%macaddress%",String(WiFi.softAPmacAddress()));
        if (s.indexOf("%networkaddress%")>-1) s.replace("%networkaddress%",WiFi.softAPIP().toString());
        if (s.indexOf("%ssid%")>-1) s.replace("%ssid%",String(WiFi.SSID()));
        if (s.indexOf("%subnetmask%")>-1) s.replace("%subnetmask%","n/a");
        if (s.indexOf("%gateway%")>-1) s.replace("%gateway%","n/a");
        break;
      case WIFI_STA:
        if (s.indexOf("%wifimode%")>-1) s.replace("%wifimode%", "Station");
        if (s.indexOf("%macaddress%")>-1) s.replace("%macaddress%",String(WiFi.macAddress()));
        if (s.indexOf("%networkaddress%")>-1) s.replace("%networkaddress%",WiFi.localIP().toString());
        if (s.indexOf("%ssid%")>-1) s.replace("%ssid%",String(WiFi.SSID()));
        if (s.indexOf("%subnetmask%")>-1) s.replace("%subnetmask%",WiFi.subnetMask().toString());
        if (s.indexOf("%gateway%")>-1) s.replace("%gateway%",WiFi.gatewayIP().toString());

        break;
    }

      htmlString+=s;
    }
    f.close();
  server.send(200, "text/html", htmlString);
  LogEvent(EVENTCATEGORIES::PageHandler, 2, "Page loaded", "status.html");
}

void handleGeneralSettings() {
  LogEvent(EVENTCATEGORIES::PageHandler, 1, "Page requested", "generalsettings.html");

  if (!is_authenticated()){
     String header = "HTTP/1.1 301 OK\r\nLocation: /login.html\r\nCache-Control: no-cache\r\n\r\n";
     server.sendContent(header);
     return;
   }

  if (server.method() == 2){  //  POST
    bool mqttDirty = false;

    if (server.hasArg("timezoneselector")){
      signed char oldTimeZone = appConfig.timeZone;
      appConfig.timeZone = atoi(server.arg("timezoneselector").c_str());

      adjustTime((appConfig.timeZone - oldTimeZone) * SECS_PER_HOUR);

      LogEvent(EVENTCATEGORIES::TimeZoneChange, 1, "New time zone", "UTC " + server.arg("timezoneselector"));
    }

    //  MQTT settings
    if (server.hasArg("mqttbroker")){
      if ((String)appConfig.mqttServer != server.arg("mqttbroker"))
        mqttDirty = true;
        sprintf(appConfig.mqttServer, "%s", server.arg("mqttbroker").c_str());
        LogEvent(EVENTCATEGORIES::MqttParamChange, 1, "New MQTT broker", appConfig.mqttServer);
    }

    if (server.hasArg("mqttport")){
      if (appConfig.mqttPort != atoi(server.arg("mqttport").c_str()))
        mqttDirty = true;
      appConfig.mqttPort = atoi(server.arg("mqttport").c_str());
      LogEvent(EVENTCATEGORIES::MqttParamChange, 2, "New MQTT port", server.arg("mqttport").c_str());
    }

    #ifdef __MQTT
    if (mqttDirty)
      PSclient.disconnect();
    #endif

    saveSettings();
  }

  fs::File f = SPIFFS.open("/pageheader.html", "r");
  String headerString;
  if (f.available()) headerString = f.readString();
  f.close();

  f = SPIFFS.open("/generalsettings.html", "r");

  String s, htmlString, timezoneslist;

  char ss[2];

  for (signed char i = -12; i < 15; i++) {
    itoa(i, ss, DEC);
    timezoneslist+="<option ";
    if (appConfig.timeZone == i){
      timezoneslist+= "selected ";
    }
    timezoneslist+= "value=\"";
    timezoneslist+=ss;
    timezoneslist+="\">UTC ";
    if (i>0){
      timezoneslist+="+";
    }
    if (i!=0){
      timezoneslist+=ss;
      timezoneslist+=":00";
    }
    timezoneslist+="</option>";
    timezoneslist+="\n";
  }

  while (f.available()){
    s = f.readStringUntil('\n');

    if (s.indexOf("%pageheader%")>-1) s.replace("%pageheader%", headerString);
    if (s.indexOf("%mqtt-servername%")>-1) s.replace("%mqtt-servername%", appConfig.mqttServer);
    if (s.indexOf("%mqtt-port%")>-1) s.replace("%mqtt-port%", String(appConfig.mqttPort));
    if (s.indexOf("%timezoneslist%")>-1) s.replace("%timezoneslist%", timezoneslist);

    htmlString+=s;
  }
  f.close();
  server.send(200, "text/html", htmlString);

  LogEvent(EVENTCATEGORIES::PageHandler, 2, "Page requested", "generalsettings.html");
}

void handleNetworkSettings() {
  LogEvent(EVENTCATEGORIES::PageHandler, 1, "Page requested", "networksettings.html");

  if (!is_authenticated()){
     String header = "HTTP/1.1 301 OK\r\nLocation: /login.html\r\nCache-Control: no-cache\r\n\r\n";
     server.sendContent(header);
     return;
   }

  if (server.method() == 2){  //  POST
    if (server.hasArg("ssid")){
      strcpy(appConfig.ssid, server.arg("ssid").c_str());
      strcpy(appConfig.password, server.arg("password").c_str());
      saveSettings();

      isAccessPoint=false;
      connectionState = STATE_CHECK_WIFI_CONNECTION;
      WiFi.disconnect(false);

    }
  }

  fs::File f = SPIFFS.open("/pageheader.html", "r");
  String headerString;
  if (f.available()) headerString = f.readString();
  f.close();

  f = SPIFFS.open("/networksettings.html", "r");
  String s, htmlString, wifiList;

  byte numberOfNetworks = WiFi.scanNetworks();
  for (size_t i = 0; i < numberOfNetworks; i++) {
    wifiList+="<div class=\"radio\"><label><input ";
    if (i==0) wifiList+="id=\"ssid\" ";

    wifiList+="type=\"radio\" name=\"ssid\" value=\"" + WiFi.SSID(i) + "\">" + WiFi.SSID(i) + "</label></div>";
  }

  while (f.available()){
    s = f.readStringUntil('\n');

    if (s.indexOf("%pageheader%")>-1) s.replace("%pageheader%", headerString);
    if (s.indexOf("%wifilist%")>-1) s.replace("%wifilist%", wifiList);
      htmlString+=s;
    }
    f.close();
  server.send(200, "text/html", htmlString);

  LogEvent(EVENTCATEGORIES::PageHandler, 2, "Page requested", "networksettings.html");
}

void handleIRRemote() {
  LogEvent(EVENTCATEGORIES::PageHandler, 1, "Page requested", "irremote.html");

  if (!is_authenticated()){
     String header = "HTTP/1.1 301 OK\r\nLocation: /login.html\r\nCache-Control: no-cache\r\n\r\n";
     server.sendContent(header);
     return;
   }

  if (server.method() == 2){  //  POST
    /*
    for (size_t i = 0; i < server.args(); i++) {
      Serial.print(server.argName(i));
      Serial.print(": ");
      Serial.println(server.arg(i));
    }
    */
    if(server.hasArg("clickedAction")){
      //Serial.println(server.arg("clickedAction"));
      if(server.arg("clickedAction")=="btnLights100"){
        irsend.sendNEC(0x1067c03f, 32);
      }else if(server.arg("clickedAction")=="btnLights66"){
        irsend.sendNEC(0x106740bf, 32);
      }else if(server.arg("clickedAction")=="btnLights33"){
        irsend.sendNEC(0x106700ff, 32);
      }else if(server.arg("clickedAction")=="btnLights0"){
        irsend.sendNEC(0x1067807f, 32);
      }else if(server.arg("clickedAction")=="btnTVOnOff"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0xa90, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVExternalInputSelector"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0xa50, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVGuide"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x6d25, 15);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVInfo"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x5d0, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVLeft"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x2d0, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVUp"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x2f0, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVDown"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0xaf0, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVRight"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0xcd0, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVEnter"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0xa70, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVReturn"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x62e9, 15);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVProgramUp"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x90, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnTVProgramDown"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x90, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnAmplifierOnOff"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x781, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnAmplifierHomeTheater"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0xbe1, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnAmplifierTV"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x561, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnAmplifierComputer"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0xa41, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnAmplifierVolumePlus"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x481, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnAmplifierVolumeMinus"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0xc81, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnAmplifierVolumeMute"){
        for (size_t i = 0; i < 3; i++) {
          irsend.sendSony(0x281, 12);
          delay(26);
        }
      }else if(server.arg("clickedAction")=="btnACOn"){
          irsend.sendRaw(IR_TOYOTOMI_ON, 300, 38);  // Send a raw data capture at 38kHz.
          delay(100);
      }else if(server.arg("clickedAction")=="btnACOff"){
          irsend.sendRaw(IR_TOYOTOMI_OFF, 300, 38);  // Send a raw data capture at 38kHz.
          delay(100);
      }
    }
  }

  

  fs::File f = SPIFFS.open("/pageheader.html", "r");
  String headerString;
  if (f.available()) headerString = f.readString();
  f.close();


  f = SPIFFS.open("/irremote.html", "r");

  String s, htmlString, controllerlist, pwmlist;

  while (f.available()){
    s = f.readStringUntil('\n');
    if (s.indexOf("%pageheader%")>-1) s.replace("%pageheader%", headerString);
    htmlString+=s;
  }
  f.close();
  server.send(200, "text/html", htmlString);
  LogEvent(EVENTCATEGORIES::PageHandler, 2, "Page requested", "irremote.html");
}

void handleTools() {
  LogEvent(EVENTCATEGORIES::PageHandler, 1, "Page requested", "tools.html");

  if (!is_authenticated()){
     String header = "HTTP/1.1 301 OK\r\nLocation: /login.html\r\nCache-Control: no-cache\r\n\r\n";
     server.sendContent(header);
     return;
   }

  if (server.method() == 2){  //  POST
    bool resetToDefaults = false;

    if (server.hasArg("reset")){
      LogEvent(EVENTCATEGORIES::Reboot, 1, "Reset", "");
      defaultSettings();
      ESP.reset();
    }

    if (server.hasArg("restart")){
      LogEvent(EVENTCATEGORIES::Reboot, 2, "Restart", "");
      ESP.reset();
    }
  }

  fs::File f = SPIFFS.open("/pageheader.html", "r");
  String headerString;
  if (f.available()) headerString = f.readString();
  f.close();

  f = SPIFFS.open("/tools.html", "r");

  String s, htmlString;

  while (f.available()){
    s = f.readStringUntil('\n');

    if (s.indexOf("%pageheader%")>-1) s.replace("%pageheader%", headerString);

      htmlString+=s;
    }
    f.close();
  server.send(200, "text/html", htmlString);

  LogEvent(EVENTCATEGORIES::PageHandler, 2, "Page requested", "tools.html");
}

/*
    for (size_t i = 0; i < server.args(); i++) {
      Serial.print(server.argName(i));
      Serial.print(": ");
      Serial.println(server.arg(i));
    }
*/

void handlePage() {

  if (!is_authenticated()){
     String header = "HTTP/1.1 301 OK\r\nLocation: /login.html\r\nCache-Control: no-cache\r\n\r\n";
     server.sendContent(header);
     return;
   }

   fs::File f = SPIFFS.open("/pageheader.html", "r");
   String headerString;
   if (f.available()) headerString = f.readString();
   f.close();

   f = SPIFFS.open("/page.html", "r");

   String s, htmlString;

   while (f.available()){
     s = f.readStringUntil('\n');

       htmlString+=s;
   }
   f.close();
   server.send(200, "text/html", htmlString);
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void SendHeartbeat(){
  if (PSclient.connected()){

    StaticJsonBuffer<JSON_OBJECT_SIZE(2)> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();

    root["Node"] = ESP.getChipId();
    root["Freeheap"] = ESP.getFreeHeap();

    root.prettyPrintTo(Serial);
    Serial.println();

    String myJsonString;
    root.prettyPrintTo(myJsonString);

    PSclient.publish(MQTT::Publish(MQTT_CUSTOMER + String("/") + MQTT_PROJECT + "/espheartbeat/", myJsonString ).set_qos(0));
  }

  needsHeartbeat = false;
}

void ScanI2C(){
  byte error, address;
  int nDevices;

  Serial.println("\nScanning for I2C devices...");

  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("Device ");
      Serial.print(nDevices);
      Serial.print(":\t0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);

      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknow error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found.\n");

}

void ICACHE_RAM_ATTR PCFInterrupt() {
  PCFInterruptFlag = true;
}

/*
Sample message expected:

{dig0:1, dig1:0, dig2:1, dig3:0, pwm0:127}

or

{
  "dig0": 1,
  "dig1": 0,
  "dig2": 1,
  "dig3": 0,
  "pwm0": 127
}

Order of parameters is ignored. Whitespaces/new line characters are ignored.
*/
void mqtt_callback(const MQTT::Publish& pub) {

  Serial.print("Topic:\t\t");
  Serial.println(pub.topic());

  Serial.print("Payload:\t");
  Serial.println(pub.payload_string());

  StaticJsonBuffer<CONTROL_COMMAND_JSON_SIZE> jsonBuffer;

  char json[pub.payload_len()];
  strcpy(json, pub.payload_string().c_str());

  JsonObject& root = jsonBuffer.parseObject(json);

  root.printTo(Serial);
  Serial.println();

  //  reset
  if (root.containsKey("reset")){
    LogEvent(EVENTCATEGORIES::MqttMsg, 1, "Reset", "");
    defaultSettings();
    ESP.reset();
  }

  //  restart
  if (root.containsKey("restart")){
    LogEvent(EVENTCATEGORIES::MqttMsg, 2, "Restart", "");
    ESP.reset();
  }

  if (!root.success()) {
    Serial.println("Failed to parse incoming string.");
    for (size_t i = 0; i < 10; i++) {
      digitalWrite(CONNECTION_STATUS_LED_GPIO, !digitalRead(CONNECTION_STATUS_LED_GPIO));
      delay(50);
    }
    return;
  }
}

void setup() {
  delay(1); //  Needed for PlatformIO serial monitor
  Serial.begin(115200);
  Serial.setDebugOutput(false);
  Serial.print("\nBooting node: ");
  Serial.print(ESP.getChipId());
  Serial.println("...");

  sprintf(defaultSSID,"ESP-%lu", ESP.getChipId());
  WiFi.hostname(defaultSSID);

  //  File system
  if (!SPIFFS.begin()){
    Serial.println("Error: Failed to initialize the filesystem!");
  }

  if (!loadSettings(appConfig)) {
    Serial.println("Failed to load config, creating default settings...");
    defaultSettings();
  } else {
    Serial.println("Config loaded.");
  }

  //  GPIOs

  //  outputs
  pinMode(CONNECTION_STATUS_LED_GPIO, OUTPUT);
  digitalWrite(CONNECTION_STATUS_LED_GPIO, HIGH);

  pinMode(ACTIVITY_LED_GPIO, OUTPUT);
  digitalWrite(ACTIVITY_LED_GPIO, HIGH);

  Wire.begin(SDA_GPIO, SCL_GPIO);
  ScanI2C();

  pinMode(I2C_INT_GPIO, INPUT_PULLUP);
  i2c_io1.resetInterruptPin();
  attachInterrupt(digitalPinToInterrupt(I2C_INT_GPIO), PCFInterrupt, FALLING);

  //  OTA
  ArduinoOTA.onStart([]() {
    Serial.println("OTA started.");
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA finished.");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    if (progress % 5 == 0){
      if (digitalRead(CONNECTION_STATUS_LED_GPIO)==HIGH)
        digitalWrite(CONNECTION_STATUS_LED_GPIO, LOW);
        else
        digitalWrite(CONNECTION_STATUS_LED_GPIO, HIGH);
    }
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Authentication failed.");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin failed.");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect failed.");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive failed.");
    else if (error == OTA_END_ERROR) Serial.println("End failed.");
  });

  ArduinoOTA.begin();

  Serial.println();

  server.on("/", handleRoot);
  server.on("/status.html", handleStatus);
  server.on("/generalsettings.html", handleGeneralSettings);
  server.on("/networksettings.html", handleNetworkSettings);
  server.on("/irremote.html", handleIRRemote);
  server.on("/tools.html", handleTools);
  server.on("/login.html", handleLogin);

  server.onNotFound(handleNotFound);

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started.");
  }

  //  Start HTTP (web) server
  server.begin();
  Serial.println("HTTP server started.");

  //  Authenticate HTTP requests
  const char * headerkeys[] = {"User-Agent","Cookie"} ;
  size_t headerkeyssize = sizeof(headerkeys)/sizeof(char*);
  server.collectHeaders(headerkeys, headerkeyssize );

  //  Timers
  os_timer_setfn(&heartbeatTimer, heartbeatTimerCallback, NULL);
  os_timer_arm(&heartbeatTimer, HEARTBEAT_INTERVAL * 1000, true);

  //  Randomizer
  srand(now());

  //  IR
  irrecv.enableIRIn();
  irsend.begin();

  // Set the initial connection state
  connectionState = STATE_CHECK_WIFI_CONNECTION;

}

void loop(){

  if (isAccessPoint){
    if (!isAccessPointCreated){
      Serial.print(" Could not connect to ");
      Serial.print(appConfig.ssid);
      Serial.println("\r\nReverting to Access Point mode.");

      delay(500);

      WiFi.mode(WiFiMode::WIFI_AP);
      WiFi.softAP(defaultSSID, DEFAULT_PASSWORD);

      IPAddress myIP;
      myIP = WiFi.softAPIP();
      isAccessPointCreated = true;

      Serial.println("Access point created. Use the following information to connect to the ESP device, then follow the on-screen instructions to connect to a different wifi network:");

      Serial.print("SSID:\t\t\t");
      Serial.println(defaultSSID);

      Serial.print("Password:\t\t");
      Serial.println(DEFAULT_PASSWORD);

      Serial.print("Access point address:\t");
      Serial.println(myIP);
    }
    server.handleClient();
  }
  else{
    switch (connectionState) {

      // Check the WiFi connection
      case STATE_CHECK_WIFI_CONNECTION:

        // Are we connected ?
        if (WiFi.status() != WL_CONNECTED) {
          // Wifi is NOT connected
          digitalWrite(CONNECTION_STATUS_LED_GPIO, HIGH);
          connectionState = STATE_WIFI_CONNECT;
        } else  {
          // Wifi is connected so check Internet
          digitalWrite(CONNECTION_STATUS_LED_GPIO, LOW);
          connectionState = STATE_CHECK_INTERNET_CONNECTION;
          server.handleClient();
        }
        break;

      // No Wifi so attempt WiFi connection
      case STATE_WIFI_CONNECT:
        {
          // Indicate NTP no yet initialized
          ntpInitialized = false;
          digitalWrite(CONNECTION_STATUS_LED_GPIO, HIGH);

          // Set station mode
          WiFi.mode(WIFI_STA);

          // Start connection process
          WiFi.begin(appConfig.ssid, appConfig.password);

          Serial.printf("Trying to connect to WIFI network: %s", appConfig.ssid);

          // Initialize iteration counter
          int i = 0;

          while ((WiFi.status() != WL_CONNECTED) && (i++ < 30)) {
            digitalWrite(CONNECTION_STATUS_LED_GPIO, LOW);
            Serial.print(".");
            delay(50);
            digitalWrite(CONNECTION_STATUS_LED_GPIO, HIGH);
            delay(950);
          }
          if (i == 31) {
            Serial.println();
            Serial.println("Could not connect to WiFi");
            delay(100);
            break;
          }
          digitalWrite(CONNECTION_STATUS_LED_GPIO, LOW);
          Serial.println(" Success!");
          Serial.print("IP address: ");
          Serial.println(WiFi.localIP());
          connectionState = STATE_CHECK_INTERNET_CONNECTION;
        }
        break;

      case STATE_CHECK_INTERNET_CONNECTION:

        // Do we have a connection to the Internet ?
        if (checkInternetConnection()) {
          // We have an Internet connection

          if (!ntpInitialized) {
            // We are connected to the Internet for the first time so set NTP provider
            initNTP();

            ntpInitialized = true;

            Serial.println("Connected to the Internet.");
          }

          connectionState = STATE_INTERNET_CONNECTED;
        } else  {
          connectionState = STATE_CHECK_WIFI_CONNECTION;
        }
        break;

      case STATE_INTERNET_CONNECTED:

        ArduinoOTA.handle();

        if (!PSclient.connected()) {
          PSclient.set_server(appConfig.mqttServer, appConfig.mqttPort);

          String msg = "{";
          msg += "\"Node\":" + (String)ESP.getChipId() + ",";
          msg += "\"Category\":1,";
          msg += "\"ID\":2,";
          msg += "\"Title\":\"Node offline\",";
          msg += "\"Data\":\"";
          msg += DateTimeToString(now());
          msg += "\"}";

          if (PSclient.connect("ESP-" + String(ESP.getChipId()), MQTT_CUSTOMER + String("/") + MQTT_PROJECT + String("/") + String(ESP.getChipId()) + "/log", 0, false, msg )){
            PSclient.set_callback(mqtt_callback);
            PSclient.subscribe(MQTT_CUSTOMER + String("/") + MQTT_PROJECT + String("/") + String(ESP.getChipId()) + "/incoming", 0);
            LogEvent(EVENTCATEGORIES::Conn, 1, "Node online", WiFi.localIP().toString());
          }
        }

        if (PSclient.connected()){
          PSclient.loop();
        }

        if (needsHeartbeat){
          SendHeartbeat();
          needsHeartbeat = false;

          
          if ( bonfoff ){
            irsend.sendRaw(IR_TOYOTOMI_ON, 300, 38);
          }else{
            irsend.sendRaw(IR_TOYOTOMI_OFF, 300, 38);
          }
            bonfoff=!bonfoff;
          
        }

        if (PCFInterruptFlag){

          //  The following order is important so that the interrupt flags get cleared!!!
          inputPattern = i2c_io3.read8();
          inputPattern<<=8;
          inputPattern|= i2c_io2.read8();
          inputPattern<<=8;
          inputPattern|= i2c_io1.read8();

          digitalWrite(ACTIVITY_LED_GPIO, LOW);
          Serial.println(inputPattern, BIN);
          switch (inputPattern) {
            case BUTTON_SONY_TV_ONOFF:
            Serial.println("BUTTON_SONY_TV_ONOFF");
            break;

            case BUTTON_SONY_TV_INPUT_SELECTOR:
            Serial.println("BUTTON_SONY_TV_INPUT_SELECTOR");
            break;

            case BUTTON_SONY_TV_ARROW_UP:
            Serial.println("BUTTON_SONY_TV_ARROW_UP");
            break;

            case BUTTON_SONY_TV_ARROW_DOWN:
            Serial.println("BUTTON_SONY_TV_ARROW_DOWN");
            break;

            case BUTTON_SONY_TV_ARROW_LEFT:
            Serial.println("BUTTON_SONY_TV_ARROW_LEFT");
            break;

            case BUTTON_SONY_TV_ARROW_RIGHT:
            Serial.println("BUTTON_SONY_TV_ARROW_RIGHT");
            break;

            case BUTTON_SONY_TV_ARROW_BACK:
            Serial.println("BUTTON_SONY_TV_ARROW_BACK");
            break;

            case BUTTON_SONY_TV_ARROW_ENTER:
            Serial.println("BUTTON_SONY_TV_ARROW_ENTER");
            break;


            case BUTTON_SONY_VOLUME_MUTE:
            Serial.println("BUTTON_SONY_VOLUME_MUTE");
            break;

            case BUTTON_SONY_VOLUME_UP:
            Serial.println("BUTTON_SONY_VOLUME_UP");
            break;

            case BUTTON_SONY_VOLUME_DOWN:
            Serial.println("BUTTON_SONY_VOLUME_DOWN");
            break;

            case BUTTON_SONY_CHANNEL_UP:
            Serial.println("BUTTON_SONY_CHANNEL_UP");
            break;

            case BUTTON_SONY_CHANNEL_DOWN:
            Serial.println("BUTTON_SONY_CHANNEL_DOWN");
            break;



            default:
            digitalWrite(ACTIVITY_LED_GPIO, HIGH);
          }

          delay(100);
          PCFInterruptFlag=false;
        }

        // Set next connection state
        connectionState = STATE_CHECK_WIFI_CONNECTION;
        break;
    }

  }
}

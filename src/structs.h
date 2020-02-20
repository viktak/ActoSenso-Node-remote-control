struct config{
  char ssid[32];
  char password[32];

  signed char timeZone;

  char mqttServer[64];
  int mqttPort;
};

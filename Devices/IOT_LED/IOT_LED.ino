/* IOT LED Control
 * this script is used for the device (nodemcu esp8266) to control the LED_BUILTIN based on the state of the switch in the webapp
 */

#include <ArduinoJson.h>
#include <Connection.h>

// connect to a wifi and create connection to webapp
Connection connection("wifi ssid", "wifi password", "http://robotik28-led.azurewebsites.net/");

void setup() {
  // setup LED_BUILTIN
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // request the button state to the server
  String json = connection.Get("data");

  // read the json
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, json);

  // convert to boolean
  bool state = doc["Button"] == "true";

  // turn on based on the state
  if (state)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(200);
}

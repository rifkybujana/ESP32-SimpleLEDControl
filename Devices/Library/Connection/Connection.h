/*
    Connection.h - A library created to make it easier to connect devices over the internet

    Author   : Rifky Bujana Bisri
    Github   : https://github.com/rifkybujana/Robotic28/Device/Connection/
    Linkedin : https://www.linkedin.com/in/rifkybujana/

    Variable:
    _ssid - wifi SSID
    _password - wifi Password
    _url - target URL
    
    WiFiMulti - WiFiMUlti object to do connection to the server

    Method:
    Get() - Do Get Request to the server
        Param:
        path - path of the get page in the server

    Post() - Do Post Request to the server
        Param:
        path - path of the post page in the server

        optional:
        key - the key of a data you want to send to server (single or array)
        value - the value of a data you want to send to server (single or array)
*/

#ifndef CONNECTION_H
#define CONNECTION_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define ERROR_GET_DATA "[HTTP] Error: Get... Failed\n"
#define ERROR_POST_DATA "[HTTP] Error: Post... Failed\n"
#define ERROR_CONNECTION "[HTTP] Error: Connection Failed\n"

class Connection
{
private:
    const char* _ssid;
    const char* _password;
    const char* _url;

    ESP8266WiFiMulti WiFiMulti;
public:
    Connection(char* ssid, char* password, char* url);
    ~Connection();

    String Get(String path);

    String Post(String path);
    String Post(String path, String key, String value);
    String Post(String path, String* key, String* value, int length);
};

#endif
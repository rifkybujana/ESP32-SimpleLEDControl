/*
    Connection.cpp - Source code of the Connection.h library, created to make it easier to connect devices over the internet
    
    Author   : Rifky Bujana Bisri
    Github   : https://github.com/rifkybujana/Robotic28/Device/Connection/
    Linkedin : https://www.linkedin.com/in/rifkybujana/
*/

#include "Connection.h"
#include <Arduino.h>

Connection::Connection(char* ssid, char* password, char* url)
{
    _ssid = ssid;
    _password = password;
    _url = url;

    Serial.begin(115200);

    for(uint8_t t = 4; t > 0; t--){
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    WiFi.mode(WIFI_STA);
    WiFiMulti.addAP(_ssid, _pass);
}

Connection::~Connection()
{
}

String Connection::Get(String path)
{
    if (WiFiMulti.run() == WL_CONNECTED){
        WiFiClient client;
        HTTPClient http;

        Serial.print("[HTTP] begin...\n");

        if (http.begin(client, _url + path)) 
        {
            Serial.print("[HTTP] GET...\n");
            int httpCode = http.GET();

            if (httpCode > 0)
            {
                Serial.printf("[HTTP] GET... code: %d\n", httpCode);

                if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY)
                {
                    String payload = http.getString();
                    return payload;
                }
            } 
            else 
            {
                Serial.printf("%s, code: %s\n", ERROR_GET_DATA, http.errorToString(httpCode).c_str());
            }

            http.end();
        } 
        else 
        {
            Serial.printf(ERROR_CONNECTION);
        }
    }

    return ERROR_GET_DATA;
}

String Connection::Post(String path)
{
    if (WiFiMulti.run() == WL_CONNECTED)
    {
        WiFiClient client;
        HTTPClient http;

        Serial.print("[HTTP] begin...\n");

        if (http.begin(client, url + path)) 
        {
            http.addHeader("Content-Type", "application/x-www-form-urlencoded");
            
            Serial.print("[HTTP] POST...\n");
            int httpCode = http.POST();

            if (httpCode > 0)
            {
                Serial.printf("[HTTP] POST... code: %d\n", httpCode);

                if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY)
                {
                    String payload = http.getString();
                    return payload;
                }
            } 
            else 
            {
                Serial.printf("%s, error: %s\n", ERROR_POST_DATA, http.errorToString(httpCode).c_str());
            }

            http.end();
        } 
        else 
        {
            Serial.printf(ERROR_CONNECTION);
        }
    }
    
    return ERROR_POST_DATA;
}

String Connection::Post(String path, String key, String value)
{
    if (WiFiMulti.run() == WL_CONNECTED)
    {
        WiFiClient client;
        HTTPClient http;

        Serial.print("[HTTP] begin...\n");

        if (http.begin(client, url + path)) 
        {
            http.addHeader("Content-Type", "application/x-www-form-urlencoded");
            
            Serial.print("[HTTP] POST...\n");
            int httpCode = http.POST(key + "=" + value);

            if (httpCode > 0)
            {
                Serial.printf("[HTTP] POST... code: %d\n", httpCode);

                if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY)
                {
                    String payload = http.getString();
                    return payload;
                }
            } 
            else 
            {
                Serial.printf("%s, error: %s\n", ERROR_POST_DATA, http.errorToString(httpCode).c_str());
            }

            http.end();
        } 
        else 
        {
            Serial.printf(ERROR_CONNECTION);
        }
    }
    
    return ERROR_POST_DATA;
}

String Connection::Post(String path, String* key, String* value, int length)
{
    if (WiFiMulti.run() == WL_CONNECTED)
    {
        WiFiClient client;
        HTTPClient http;

        Serial.print("[HTTP] begin...\n");

        if (http.begin(client, url + path)) 
        {
            http.addHeader("Content-Type", "application/x-www-form-urlencoded");
            
            Serial.print("[HTTP] POST...\n");
            
            String jsonData = key[0] + "=" + value[0];
            for (uint8_t i = 1; i < length; i++)
            {
                jsonData += "&" + key[i] + "=" + value[i];
            }

            int httpCode = http.POST(jsonData);

            if (httpCode > 0)
            {
                Serial.printf("[HTTP] POST... code: %d\n", httpCode);

                if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY)
                {
                    String payload = http.getString();
                    return payload;
                }
            } 
            else 
            {
                Serial.printf("%s, error: %s\n", ERROR_POST_DATA, http.errorToString(httpCode).c_str());
            }

            http.end();
        } 
        else 
        {
            Serial.printf(ERROR_CONNECTION);
        }
    }
    
    return ERROR_POST_DATA;
}
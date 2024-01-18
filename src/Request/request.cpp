#include <Wifi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include "request.h"

void connectToNetwork()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        int attempts = 0;
        WiFi.begin(WIFI_NAME, WIFI_PASS);

        while (WiFi.status() != WL_CONNECTED && attempts < 5)
        {
            delay(500);
            attempts++;
        }

        Serial.print("IP: ");
        Serial.println(WiFi.localIP());
        Serial.println("--------------------");
    }
}

bool isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}

void sendTemp(float temp)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        // FOR HTTPS
        WiFiClientSecure client;
        client.setInsecure();
        HTTPClient http;
        http.begin(client, URL);

        // FOR HTTP
        // WiFiClient client;
        // HTTPClient http;
        // http.begin(client, URL);

        // Specify content-type header
        http.addHeader("Authorization", "Bearer z69QAqx9JFpmTQx");
        http.addHeader("content-type", "application/json");

        // Data to send with HTTP POST
        String httpRequestData = "{ \"measure\": " + String(temp) + "}";

        // Send HTTP POST request
        int httpResponseCode = http.POST(httpRequestData);

        if (httpResponseCode > 0)
        {
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
        }
        // Free resources
        http.end();
    }
}
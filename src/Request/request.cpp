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
        WiFiClientSecure client;
        client.setInsecure();
        HTTPClient https;
        https.begin(client, URL);

        // Specify content-type header
        https.addHeader("Authorization", "Bearer z69QAqx9JFpmTQx");
        https.addHeader("content-type", "application/json");

        // Data to send with HTTP POST
        String httpRequestData = "{ \"measure\": " + String(temp) + "}";

        // Send HTTP POST request
        int httpResponseCode = https.POST(httpRequestData);

        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);

        // Free resources
        https.end();
    }
}
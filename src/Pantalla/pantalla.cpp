#include <string>
#include "pantalla.h"

// Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);
std::string currentNetwork("Disconnected");

void initDisplay()
{
    // reset OLED display via software
    pinMode(OLED_RST, OUTPUT);
    digitalWrite(OLED_RST, LOW);
    delay(20);
    digitalWrite(OLED_RST, HIGH);

    // initialize OLED
    Wire.begin(OLED_SDA, OLED_SCL);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false))
    { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }

    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println(currentNetwork.c_str());
    display.setTextSize(4);
    display.setCursor(0, 23);
    display.println("--.-");
    display.display();
}

void displayTemp(float temp)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println(currentNetwork.c_str());
    display.setTextSize(4);
    display.setCursor(0, 23);
    display.println(String(temp));
    display.display();
}

void updateNetwork(std::string newNetwork)
{
    currentNetwork = "Connected: ";
    currentNetwork += newNetwork;
}
#include <Arduino.h>
#include "Pantalla/pantalla.h"
#include "Request/request.h"

// Definicion de constantes
#define SENSOR_PIN A0                 // Patilla analogica donde esta conectado el sensor LM35
#define NUM_READS 4                   // Numero de lecturas que se van a realizar para calcular la media
#define DELAY_LOOP (1000 / NUM_READS) // Tiempo de espera entre lecturas
#define MIN_TEMP 5                    // Temperatura minima que se considera valida
#define MAX_TEMP 45                   // Temperatura maxima que se considera valida

// Definicion de variables
float Tempsfinal[NUM_READS]; // Temperaturas despues de aplicar formulas en grados centigrados
int numLoop = 0;             // Numero de veces que se ha ejecutado el loop

void setup()
{
  memset(Tempsfinal, 0, sizeof(Tempsfinal));
  numLoop = 0;

  analogReadResolution(12);
  analogSetAttenuation(ADC_0db); // Rango de 0 a 1.1V
  Serial.begin(9600);

  connectToNetwork();
  if (isConnected())
    updateNetwork(WIFI_NAME);
  initDisplay();
}

void loop()
{
  float TempLM35 = analogRead(SENSOR_PIN); // Lectura del sensor LM35 en mV
  Tempsfinal[numLoop] = TempLM35 * 1.156 * 100 / 4096;
  // if (Tempsfinal[numLoop] > MIN_TEMP && Tempsfinal[numLoop] < MAX_TEMP)
  numLoop++;

  if (numLoop == NUM_READS)
  {
    numLoop = 0;
    float Tempfinal = 0;
    for (int i = 0; i < NUM_READS; i++)
      Tempfinal += Tempsfinal[i];
    Tempfinal = Tempfinal / NUM_READS;
    Serial.print("Temperatura: ");
    Serial.print(Tempfinal);
    Serial.println(" °C");
    Serial.println("--------------------");

    if (isConnected())
      updateNetwork(WIFI_NAME);
    sendTemp(Tempfinal);
    displayTemp(Tempfinal);
  }
  delay(DELAY_LOOP);
}
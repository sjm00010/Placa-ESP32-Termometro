#define WIFI_NAME "NOMBRE_WIFI"                     // 9T
#define WIFI_PASS "PASS_WIFI"                       // nomelase
#define URL "http://IP_ORDENADOR_LOCAL:8080/sensor" // "https://uja-sensor-dev-zgkd.1.ie-1.fl0.io/sensor"
#define HTTPS false                                 // Indica si la conexion utiliza HTTPS o HTTP

void connectToNetwork();
bool isConnected();
void sendTemp(float temp);
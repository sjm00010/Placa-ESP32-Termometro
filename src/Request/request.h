#define WIFI_NAME "NOMBRE_WIFI"                                // 9T
#define WIFI_PASS "PASS_WIFI"                                  // nomelase
#define URL "https://uja-sensor-dev-zgkd.1.ie-1.fl0.io/sensor" // "http://192.168.1.132:8080/sensor" // "https://uja-sensor-dev-zgkd.1.ie-1.fl0.io/sensor"

void connectToNetwork();
bool isConnected();
void sendTemp(float temp);
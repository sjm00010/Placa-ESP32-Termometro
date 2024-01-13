#define WIFI_NAME "DIGIFIBRA-h9t5" // 9T
#define WIFI_PASS "ETDzucHAkF6Y"   // nomelase
#define URL "https://uja-sensor-dev-zgkd.1.ie-1.fl0.io/sensor"

void connectToNetwork();
bool isConnected();
void sendTemp(float temp);
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>        // Include the Wi-Fi library

const char* ssid     = "********";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "********";     // The password of the Wi-Fi network

ESP8266WebServer server(80);
void handleRoot();              // function prototypes for HTTP handlers
void handleNotFound();
void setPinData();

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println('\n');

  // Connect to WiFi network:
  Serial.println("Hello Noman");
  Serial.println("Connecting "); 
  WiFi.begin(ssid, password);

  // Show ... until connected:
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");

  // Print the IP address of the device:
  Serial.println(WiFi.localIP());

  // Server
  server.on("/", handleRoot);               // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/data", setPinData);
  server.onNotFound(handleNotFound);        // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"
  server.begin();                           // Actually start the server
  Serial.println("HTTP server started");
  
}

void loop(void){
  server.handleClient();                    // Listen for HTTP requests from clients
}

void handleRoot() {
  server.send(200, "text/plain", "Hello world!");   // Send HTTP status 200 (Ok) and send some text to the browser/client
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

void setPinData() {
  String message = "";
  String pin = server.arg("pin");
  if (pin == ""){     //Parameter not found
    message += "Pin not found";
    server.send(400, "text/plain", message);
    return;
  }
  String data = server.arg("data");
  if (data == ""){     //Parameter not found
    message += "Data not found";
    server.send(400, "text/plain", message);
    return;
  }
  String m = server.arg("mode");
  if (m == ""){     //Parameter not found
    message += "Data not found";
    server.send(400, "text/plain", message);
    return;
  }

  message = "<" + m + "" + pin + "," + data + ">";
  Serial.println(message);
  server.send(200, "text/plain", message);
  
}

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

void handle_root();
// SSID & Password
const char* ssid = "Família BARBA ARMENGOL"; // Enter your SSID here
const char* password = "937889539"; //Enter your Password here

WebServer server(80); // Object of WebServer(HTTP port, 80 is defult)



void setup() {
Serial.begin(115200);
Serial.println("Try Connecting to ");
Serial.println(ssid);
// Connect to your wi-fi modem
WiFi.begin(ssid, password);
// Check wi-fi is connected to wi-fi network
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected successfully");
Serial.print("Got IP: ");
Serial.println(WiFi.localIP()); //Show ESP32 IP on serial

server.on("/", handle_root);
server.begin();
Serial.println("HTTP server started");
delay(100);
}
void loop() {
server.handleClient();

}

// HTML & CSS contents which display on web server
const char HTML[] PROGMEM = R"rawliteral(
  <!doctype html>
<html lang="ca">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <title>Practica 3</title>
    

    <!-- Bootstrap core CSS -->
    <link rel="stylesheet" type="text/css" href="style.css">

    <!-- <style>
      .bd-placeholder-img {
        font-size: 1.125rem;
        text-anchor: middle;
        -webkit-user-select: none;
        -moz-user-select: none;
        user-select: none;
      }

      @media (min-width: 768px) {
        .bd-placeholder-img-lg {
          font-size: 3.5rem;
        }
      }
    </style> -->

    
    <!-- Custom styles for this template -->
    <!-- <link href="starter-template.css" rel="stylesheet"> -->
  </head>

    <body>
    
<div class="col-lg-8 mx-auto p-3 py-md-5">
  <header class="d-flex align-items-center pb-3 mb-5 border-bottom">
    <a href="/" class="d-flex align-items-center text-dark text-decoration-none">
      <!-- <svg xmlns="http://www.w3.org/2000/svg" width="40" height="32" class="me-2" viewBox="0 0 118 94" role="img"><title>Bootstrap</title><path fill-rule="evenodd" clip-rule="evenodd" d="M24.509 0c-6.733 0-11.715 5.893-11.492 12.284.214 6.14-.064 14.092-2.066 20.577C8.943 39.365 5.547 43.485 0 44.014v5.972c5.547.529 8.943 4.649 10.951 11.153 2.002 6.485 2.28 14.437 2.066 20.577C12.794 88.106 17.776 94 24.51 94H93.5c6.733 0 11.714-5.893 11.491-12.284-.214-6.14.064-14.092 2.066-20.577 2.009-6.504 5.396-10.624 10.943-11.153v-5.972c-5.547-.529-8.934-4.649-10.943-11.153-2.002-6.484-2.28-14.437-2.066-20.577C105.214 5.894 100.233 0 93.5 0H24.508zM80 57.863C80 66.663 73.436 72 62.543 72H44a2 2 0 01-2-2V24a2 2 0 012-2h18.437c9.083 0 15.044 4.92 15.044 12.474 0 5.302-4.01 10.049-9.119 10.88v.277C75.317 46.394 80 51.21 80 57.863zM60.521 28.34H49.948v14.934h8.905c6.884 0 10.68-2.772 10.68-7.727 0-4.643-3.264-7.207-9.012-7.207zM49.948 49.2v16.458H60.91c7.167 0 10.964-2.876 10.964-8.281 0-5.406-3.903-8.178-11.425-8.178H49.948z" fill="currentColor"></path></svg> -->
      
    </a>
  </header>

    <main>
    <div class="row g-5">
      <div class="col-md-6">
        <h2>Creadora de la web</h2>
       <div id="user_card">
        <div class="card mb-3" style="max-width: 540px;">
          <div class="row g-0">
            <div class="col-md-4">
              <img src="https://tienda.bricogeek.com/5833-thickbox_default/esp32-wroom-wifi-bluetooth.jpg" class="img-fluid rounded-start" alt="...">
            </div>
            <div class="col-md-8">
              <div class="card-body">
                <h5 class="card-title" id="user">Clara Barba</h5>
                <p class="card-text"><b>DNI: 45939999F </b></p>
                <p class="card-text"><b>Data naixement: 28/03/2002</b></p>
              </div>
            </div>
          </div>
        </div>
        <div>
        </div>
        </div>
      </div>
    </div>
  </main>
    <footer class="pt-5 my-5 text-muted border-top">
    Clara Barba  &middot; Processadors Digitals ESEIAAT UPC &middot; Curs 2021/2022
  </footer>
    </body>
</html>)rawliteral";


// Handle root url (/)
void handle_root() {
server.send(200, "text/html", HTML);
}




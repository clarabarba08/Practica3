# PRÀCTICA 3: WIFI I BLUETOOTH
<div align=right>
Clara Barba Armengol
<div>

<div align="justify">
En aquesta pràctica generarem un web server utilitzant la ESP32 i també realitzarem una comunicació serie amb una aplicació mòbil amb Bluetooth. 
<div>

## PRÀCTICA A: Generació d'un pàgina web
***
Per aquest exercici no és necessari fer cap muntatge a la Protoboard, només cal endollar la ESP32 a l'ordinador. 
En el codi que podem trobar en el fitxer *main.cpp* cal afegir-hi el nom de la Wifi i la contrassenya:
```cpp
const char* ssid = "NomWifi"; 
const char* password = "ContrassenyaWifi";
```
A continuació es crea l'objecte Web Server: 
```cpp
WebServer server(80);
```
Dins del setup hem d'inicialitzar el modem Wifi: 
```cpp
WiFi.begin(ssid, password);
```
Cal mostrar la IP de la web per pantalla per poder accedi-hi a través del buscador.
```cpp
Serial.print("Got IP: ");
Serial.println(WiFi.localIP());
```
I cridar la funció que escriu el contingut de la web:
```cpp
server.on("/", handle_root);
server.begin();
```
El contingut de la web està escrit en HTML i és el següent: 
```cpp
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1> La meva primera pàgina amb ESP32 - Station Mode &#128522;</h1>\
</body>\
</html>";
```
A continuació adjunto el vídeo del funcionament:
[Vídeo pràctica 3a](https://drive.google.com/file/d/1WF3GL8IefkeYHBxLWNnrWnyciLWYhuEg/view?usp=sharing)

En l'enunciat també se'ns demana modificar el fitxer HTML. He afegit més codi, com per exemple per afegir una foto. Ara la web té aquest aspecte:

![WEB](/web.png)

També he afegit un fitxer d'estil a la carpeta junt amb el fitxer on hi ha la web escrita:
- style.css
- index.html

Per accedir a aquests fitxer caldira utilitzar la llibreria *AsyncWebServer.h*, però en aquesta pràctica estem treballant amb la *Websrver.h* i no he trobat cap exemple per aquesta llibreria. 

## PRÀCTICA B: Comunicació Bluetooth amb el mòbil
***
El codi d'aquesta pràctica i el seu respectiu informe està en una carpeta de Github diferent, es troba a "Practica3b".

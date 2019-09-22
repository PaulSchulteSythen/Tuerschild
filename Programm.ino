//Bibliotheken laden
#include "libraries.h"


//eigene Dateien Laden
#include "logo.h" //Das me-logo also array einbinden
#include "Definitionen.h" //Definitionen wie z.B. ip-Adresse des Webservers


//Zum speichern der Namen, damit nicht aktualisiert wird, wenn sich die Daten nicht ändern
Preferences preferences;


//Port 80 für Serververbindung öffnen
WiFiServer server(80);


bool B_updating;
String S_personen = "";
String S_name1 = "";
String S_name2 = "";
String S_name3 = "";
String S_Status = "";


//Funktionen laden
#include "Funktionen.h"



void setup()
{
  //Serielle Kommunikation initialisieren
  Serial.begin(9600);
  display.init(9600);
  display.setRotation(1);//Bilschirm drehen
  delay(20);

  //Verbindung zum Wifi herstellen und überprüfen
  ConnectToWiFi();

  /*//Nach Ladenschluss bis zum nächsten Morgen in den deep sleep modus gehen
  if (getTime() >= I_endZeit) {
    Serial.print("Schlafe: ");
    Serial.println(((24 - (getTime() + 1)) * 60 + (60 - getMins()) + I_startZeit * 60) * 60000000);

    DatenLoschen();

    esp_sleep_enable_timer_wakeup(((24 - (getTime() + 1)) * 60 + (60 - getMins()) + I_startZeit * 60) * 60000000);
    esp_deep_sleep_start();
  }*/



  //Daten Laden
  loadData();

  //ist eine Verbindung zum Webserver da?
  checkWebserverConnection();


  //gucken, ob neue Daten da sind und wenn ja, Bildschirm aktualisieren
  BildschirmUpdaten();

  //Daten speichern
  saveData();


  //In den deep-sleep Modus gehen
  WiFi.disconnect(); //ohne diesen Befehl funktioniert das Auffwachen nach dem deep-sleep nicht mehr
  esp_sleep_enable_timer_wakeup(F_verzogerung * 60000000);
  esp_deep_sleep_start();
}

void loop()
{

}

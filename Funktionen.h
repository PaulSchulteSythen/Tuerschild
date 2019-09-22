
void DatenLoschen() {
  preferences.begin("az", false);
  preferences.putString("personen", "0");
  preferences.putString("name1", "");
  preferences.putString("name2", "");
  preferences.putString("name3", "");
  preferences.putString("status", "");
  preferences.end();
}
void loadData() {
  preferences.begin("az", false);
  S_personen = preferences.getString("personen", "0");
  S_name1 = preferences.getString("name1", "");
  S_name2 = preferences.getString("name2", "");
  S_name3 = preferences.getString("name3", "");
  S_Status = preferences.getString("status", "");
}

void saveData() {
  preferences.putString("personen", S_personen);
  preferences.putString("name1", S_name1);
  preferences.putString("name2", S_name2);
  preferences.putString("name3", S_name3);
  preferences.putString("status", S_Status);
  preferences.end();
}
String get_personen(int id) //Anzahl Personen bekommen
{

  WiFiClient client = server.available();
  HTTPClient http;
  http.begin(String(ac_get_host) + "/personen.php?id=" + id);

  //GET method
  int httpCode = http.GET();
  String payload = http.getString();
  //Serial.println(payload);
  http.end();
  return (payload);
}
String get_name(int id, int Name) //Namen bekommen
{

  WiFiClient client = server.available();
  HTTPClient http;
  http.begin(String(ac_get_host) + "/getName.php?name=" + Name + "&id=" + id);

  //GET method
  int httpCode = http.GET();
  String payload = http.getString();
  //Serial.println(payload);
  http.end();
  return (payload);
}
int getTime() //die aktuelle Minute kriegen
{

  WiFiClient client = server.available();
  HTTPClient http1;
  http1.begin(String(ac_get_host) + "/time.php");

  //GET method
  int httpCode1 = http1.GET();
  String date = http1.getString();
  //Serial.println(payload);
  http1.end();

  //Dieser Block muss leider sein, da die Typumwandlung schwer ist
  if (date == "00") {
    return (0);
  } else if (date == "01") {
    return (1);
  } else if (date == "02") {
    return (2);
  } else if (date == "03") {
    return (3);
  } else if (date == "04") {
    return (4);
  } else if (date == "05") {
    return (5);
  } else if (date == "06") {
    return (6);
  } else if (date == "07") {
    return (7);
  } else if (date == "08") {
    return (8);
  } else if (date == "09") {
    return (9);
  } else if (date == "10") {
    return (10);
  } else if (date == "11") {
    return (11);
  } else if (date == "12") {
    return (12);
  } else if (date == "13") {
    return (13);
  } else if (date == "14") {
    return (14);
  } else if (date == "15") {
    return (15);
  } else if (date == "16") {
    return (16);
  } else if (date == "17") {
    return (17);
  } else if (date == "18") {
    return (18);
  } else if (date == "19") {
    return (19);
  } else if (date == "20") {
    return (20);
  } else if (date == "21") {
    return (21);
  } else if (date == "22") {
    return (22);
  } else if (date == "23") {
    return (23);
  } else if (date == "24") {
    return (24);
  }

}
int getMins()  //die aktuelle Minute kriegen
{

  WiFiClient client = server.available();
  HTTPClient http1;
  http1.begin(String(ac_get_host) + "/timeMins.php");

  //GET method
  int httpCode1 = http1.GET();
  String date = http1.getString();
  //Serial.println(payload);
  http1.end();

  //Dieser Block muss leider sein, da die Typumwandlung schwer ist
  if (date == "01") {
    return 1;
  } else if (date == "02") {
    return 2;
  } else if (date == "03") {
    return 3;
  } else if (date == "04") {
    return 4;
  } else if (date == "05") {
    return 5;
  } else if (date == "06") {
    return 6;
  } else if (date == "07") {
    return 7;
  } else if (date == "08") {
    return 8;
  } else if (date == "09") {
    return 9;
  } else if (date == "10") {
    return 10;
  } else if (date == "11") {
    return 11;
  } else if (date == "12") {
    return 12;
  } else if (date == "13") {
    return 13;
  } else if (date == "14") {
    return 14;
  } else if (date == "15") {
    return 15;
  } else if (date == "16") {
    return 16;
  } else if (date == "17") {
    return 17;
  } else if (date == "18") {
    return 18;
  } else if (date == "19") {
    return 19;
  } else if (date == "20") {
    return 20;
  } else if (date == "21") {
    return 21;
  } else if (date == "22") {
    return 22;
  } else if (date == "23") {
    return 23;
  } else if (date == "24") {
    return 24;
  } else if (date == "25") {
    return 25;
  } else if (date == "26") {
    return 26;
  } else if (date == "27") {
    return 27;
  } else if (date == "28") {
    return 28;
  } else if (date == "29") {
    return 29;
  } else if (date == "30") {
    return 30;
  } else if (date == "31") {
    return 31;
  } else if (date == "32") {
    return 32;
  } else if (date == "33") {
    return 33;
  } else if (date == "34") {
    return 34;
  } else if (date == "35") {
    return 35;
  } else if (date == "36") {
    return 36;
  } else if (date == "37") {
    return 37;
  } else if (date == "38") {
    return 38;
  } else if (date == "39") {
    return 39;
  } else if (date == "40") {
    return 40;
  } else if (date == "41") {
    return 41;
  } else if (date == "42") {
    return 42;
  } else if (date == "43") {
    return 43;
  } else if (date == "44") {
    return 44;
  } else if (date == "45") {
    return 45;
  } else if (date == "46") {
    return 46;
  } else if (date == "47") {
    return 47;
  } else if (date == "48") {
    return 48;
  } else if (date == "49") {
    return 49;
  } else if (date == "50") {
    return 50;
  } else if (date == "51") {
    return 51;
  } else if (date == "52") {
    return 52;
  } else if (date == "53") {
    return 53;
  } else if (date == "54") {
    return 54;
  } else if (date == "55") {
    return 55;
  } else if (date == "56") {
    return 56;
  } else if (date == "57") {
    return 57;
  } else if (date == "58") {
    return 58;
  } else if (date == "59") {
    return 59;
  }

}
String get_status(int id) //jetzigen Status vom Webserver kriegen
{

  WiFiClient client = server.available();
  HTTPClient http;
  http.begin(String(ac_get_host) + "/getStatus.php?id=" + id);

  //GET method
  int httpCode = http.GET();
  String payload = http.getString();
  //Serial.println(payload);
  http.end();
  return (payload);
}
void showName(String name, int i, int pers)   //Name(n) anzeigen
{
  display.setTextColor(GxEPD_BLACK);
  if (pers == 3) {
    display.setFont(&FreeMonoBold12pt7b);
    if (i == 1) {
      display.setCursor(0, 50);
    } else if (i == 2) {
      display.setCursor(0, 70);
    } else if (i == 3) {
      display.setCursor(0, 90);
    }
    display.println(name);
  } else if (pers == 2) {
    display.setFont(&FreeMonoBold12pt7b);
    if (i == 1) {
      display.setCursor(0, 60);
    } else if (i == 2) {
      display.setCursor(0, 80);
    }
    display.println(name);
  } else if (pers == 1) {
    display.setFont(&FreeMonoBold18pt7b);
    display.setCursor(0, 75);
    display.println(name);
  }
}
void showStatus(const char name[], const GFXfont * f) //Status anzeigen
{
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 120);
  display.println(name);
}
void showRoom(const char name[], const GFXfont * f) //Raumnamen anzeigen
{
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 30);
  display.println(name);
}
void ConnectToWiFi() {
  //Auf Verbindung warten
  WiFi.begin(ac_ssid, ac_pwd);
  for (int j = 0; WiFi.status() != WL_CONNECTED && j < 20; j++)
  {
    delay(500);
    Serial.print("*");
  }

  //Falls nach der Wartezeit keine Verbindung besteht, Fehlermeldung ausgeben und neustarten
  if (WiFi.status() != WL_CONNECTED) {          //falls keine Verbindung: Anzeigen und preferences zurücksetzen
    Serial.println("Crash! Restart...");
    display.setFont(&FreeMonoBold12pt7b);
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(0, 90);
    display.println("WiFi nicht gefunden!");
    display.drawBitmap(logo, 200, 10, 84, 55, GxEPD_BLACK);
    display.update();

    //Damit der Chip nach dem Neustart den Bildschirm auch aktualisiert und nicht denkt, dass es keine neuen Daten gibt
    DatenLoschen();

    ESP.restart();
  }




  //Verbindung erfolgreich
  Serial.println("");
  Serial.println("WiFi Verbindung erfolgreich");
  Serial.print("IP Adresse des ESP32 Moduls: ");
  Serial.println(WiFi.localIP());//IP Adresse ausgeben

  //Server starten
  server.begin();

  //SSID ausgeben
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
}


void checkWebserverConnection() { //wenn get_personen() keinen Rückgabewert hat, besteht keine Verbindung zum Webserver
  if (get_personen(I_this_id) == "") {
    Serial.println("Host: " + String(ac_get_host) + " not found. Restarting...");
    display.setFont(&FreeMonoBold12pt7b);
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(0, 90);
    display.println(String(ac_get_host) + " nicht gefunden");
    display.drawBitmap(logo, 200, 10, 84, 55, GxEPD_BLACK);
    display.update();

    DatenLoschen();

    ESP.restart();
  }
}

void VirtuellenBildschirmAktualisieren() {
  //Personen ändern
  S_personen = get_personen(I_this_id);

  if (S_personen == "1") {
    S_name1 = get_name(I_this_id, 1);
    showName(S_name1, 1, 1);

  } else if (S_personen == "2") {
    S_name1 = get_name(I_this_id, 1);
    S_name2 = get_name(I_this_id, 2);
    showName(S_name1, 1, 2);
    showName(S_name2, 2, 2);

  } else if (S_personen == "3") {
    S_name1 = get_name(I_this_id, 1);
    S_name2 = get_name(I_this_id, 2);
    S_name3 = get_name(I_this_id, 3);
    showName(S_name1, 1, 3);
    showName(S_name2, 2, 3);
    showName(S_name3, 3, 3);
  }



  //Status ändern
  S_Status = get_status(I_this_id);
  if (S_Status == "1") {
    showStatus("Beschaeftigt", &FreeMonoBold18pt7b);
  } else if (S_Status == "2") {
    showStatus("Verfuegbar", &FreeMonoBold18pt7b);
  } else if (S_Status == "3") {
    showStatus("Besprechung", &FreeMonoBold18pt7b);
  } else if (S_Status == "4") {
    showStatus("Abwesend", &FreeMonoBold18pt7b);
  } else if (S_Status == "5") {
    showStatus("Ausser Haus", &FreeMonoBold18pt7b);
  } else if (S_Status == "6") {
    showStatus("Krank", &FreeMonoBold18pt7b);
  } else if (S_Status == "7") {
    showStatus("Urlaub", &FreeMonoBold18pt7b);
  }

  //Konstanten Raumname anzeigen
  showRoom(ac_raum, &FreeMonoBold18pt7b);

  //logo anzeigen
  display.drawBitmap(logo, 200, 10, 84, 55, GxEPD_BLACK);
}


void BildschirmUpdaten() {
  // den Bildschirm nur updaten, wenn neue Daten da sind
  B_updating = false;

  //Bildschirm updaten wenn sich der Status geändert hat
  if (S_Status != get_status(I_this_id)) {
    B_updating = true;   //Bildschrim updaten
  }

  //Bildschirm ändern, wenn sich die Anzahl der Personen geändert hat
  if (S_personen != get_personen(I_this_id)) {
    B_updating = true;   //Bildschirm updaten
  } else {
    //Falls Anzahl Personen gleich geblieben kann sich dennoch der Name einer Person geändert haben
    if (S_name1 != get_name(I_this_id, 1) || S_name2 != get_name(I_this_id, 2) || S_name3 != get_name(I_this_id, 3)) {
      B_updating = true;   //Bildschrim updaten
    }
  }


  //Bildschirm nur updaten, wenn neue Daten da sind
  if (B_updating) {
    VirtuellenBildschirmAktualisieren(); //Erstellt "virtuellen" Bildschirm
    display.update();
    Serial.println("Display updated");
  } else {
    Serial.println("Display not updated");
  }
}

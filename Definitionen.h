//Laufzeit
int I_startZeit = 7;
int I_endZeit =  17;
float F_verzogerung = 1;                            //Verzögerung in Minuten

//Access point credentials
const char* ac_ssid = "FRITZ!Box 7590 RQ";          //SSID
const char* ac_pwd = "8674772739467112";            //passwort
char ac_get_host[25] = "http://192.168.188.49";        //Webserver ip-Adresse

//Für jedes Schild unterschiedlich
int I_this_id = 1;                                  //id dieses esp32
char ac_raum[30] = "Raum 3";                        //fester Raum

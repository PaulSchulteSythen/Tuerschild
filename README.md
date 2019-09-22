15:15 11.09.2019

0. USBWebserver("https://www.usbwebserver.net/webserver/")
	Settings: 
		-Port von 8080 auf 80 setzen, damit der Server auch von außerhalb erreichbar ist
		-root verzeichnis 
1. Php Dateien (liegen unter /Webserver        (root Verzeichnis))
2. Datenbank "devices" mit:   (Anmeldedaten: Bentzername="root" ; Passwort="usbw"   (http://localhost/phpmyadmin; port=3307))
	a) Table:
		"devices"
	b) Struktur:  
		       Name     Typ      Länge/Werte   Kollation	  Null  Standard
			1	id	  int(11)			  Nein 	kein(e)	  AUTO_INCREMENT
			2	name1 	  varchar(50)	utf8_bin          Ja 	NULL	
			3	status	  int(10)			  Nein 	kein(e)	
			4	personen  int(1)			  Nein 	kein(e)	
			5	name2	  varchar(30)	utf8_general_ci   Nein 	kein(e)	
			6	name3	  varchar(30)	utf8_general_ci   Nein 	kein(e)	
	c) Für jeden Chip einen Datensatz: 
		Bsp: id 	name1 	     status 	personen 	name2 	        name3 
		     1 	     P. Schulte 	7 	   3 	    L. Van Buer 	Paul
	d) Sql code:
-----------------------------------------------------------------------------------------------------------------------
CREATE DATABASE devices;
USE devices;
CREATE TABLE devices(
   id   INT(11)               NOT NULL,
   name1 VARCHAR (50)     NOT NULL,
   name2 VARCHAR (50)     NOT NULL,
   name3 VARCHAR (50)     NOT NULL,
   status INT(10)		  NOT NULL,
   personen INT(1) 	  NOT NULL,
   PRIMARY KEY (id)
);
INSERT INTO devices (id, name1, name2, name3, status, personen)
VALUES (1, "P. Schulte", "L. Van Buer", "P. Lombe", 1, 3);
-----------------------------------------------------------------------------------------------------------------------
3. Datensätze können auf localhost geändert werden
4. Programm: FERTIG.ino
	-> definitionen wie z.B. die Start und Endzeit liegen in der Definitionen.h Datei.
5. Wiring:
	ESP32		Display
	
	GND		GND
	3V3		VCC
	4(D4)		BUSY
	RX2(16)		RST
	TX2(17)		DC
	5(D5)		CS
	18(D18)		CLK
	23(D23)		DIN


6. Bibliotheken
-Esp32 in Arduino IDE implementieren
https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
-GxEPD library
https://github.com/ZinggJM/GxEPD
-copy "https://github.com/adafruit/Adafruit-GFX-Library" files to "C:\Users\User\Documents\Arduino\libraries\GxEPD\src" folder

		
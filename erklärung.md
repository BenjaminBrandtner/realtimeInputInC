# Problem
Im C-Standard gibt es keine Funktion um einen Tastatur-Anschlag auszulesen, also eine Funktion die wartet bis der Benutzer irgendeine Taste drückt und diese sofort einliest.  
Es gibt nur die Möglichkeit in den stdin-Buffer zu schreiben und diesen mit Enter abzuschicken.  
Für Spiele und TUIs (Text-User-Interfaces, also grafisch fortgeschrittenere Programme auf der Konsole) ist dies aber nicht sehr benutzerfreundlich. Es gibt  viele verschiedene Bibliotheken, die die gewünschte Funktionalität bereitstellen; für Windows, für Linux, und auch plattformübergreifend.

# Lösung
Im folgenden sind drei Lösungen aufgezeigt. Sie beinhalten jeweils C-Quelltext der mit der jeweiligen Lösung realisiert ist. Das Programm ist immer dasselbe: Es bittet um Eingabe des Buchstaben q, ließt bei jedem Tastendruck den Input vom User ein und gibt ihn wieder aus, und beendet sich nach korrekter Eingabe.

## Windows
In Windows ist es einfach. In der Header Datei conio.h, deren Bibliothek nicht Teil des C-Standards ist, aber von den meisten Compilern für DOS, Windows3.x, Win32, u.A. mitgebracht wird, sind Funktionen zur Ein-Ausgabe im Terminal definiert.  
getch() wartet so lange, bis eine Taste gedrückt wird und liest diese ein.  
[C-Quelltext, nur auf Windows kompilierbar](windowsGetch.c), [kompilierte exe](windowsGetch.exe)

## Linux
Ähnliche Bibliotheken wie conio sind auf Linux termios und curses.
### Termios
Termios beinhaltet low-level Funktionen zum Terminal I/O. So kann man das Terminal in einen zeichenorientierten Modus umstellen, das Abfangverhalten von Sonderzeichen ändern, Zeichensatz ändern und vieles mehr.  
In den Quellen ist eine Seite aus "C von A bis Z" mit Code, der mit termios die getch Funktion in Linux nachbaut. [C-Quelltext](termiosGetch.c)
### Curses
Mit den curses-Bibliotheken können Programme geschrieben werden die sehr genau die Anzeige auf character-cell Terminals steuern können.  
Der Programmierer kann Fenster, Menüs, etc. an jeder Stelle des Bildschirms erstellen und die Bibliothek rechnet aus, was die geringsten Änderungen sind um das Ergebnis zu erzielen und kümmert sich darum, dass es für das angeschlossene Gerät die richtigen Befehle erzeugt. Das führt natürlich auch zu viel schnellerer Reaktionszeit, als mit purem C (für jede Änderung clear() und dann ein langes printf)  
TUI-Anwendungen lassen sich sehr einfach mit curses programmieren. Zu solchen gehört natürlich auch das Einlesen eines Tastaturanschlags ohne immer auf Enter drücken zu müssen, wofür die Bibliothek verschiedene Funktionen bereitstellt. [C-Quelltext](ncursesGetch.c)  
Diese Funktionen können allerdings (glaube ich) nicht verwendet werden ohne auch die grafischen Funktionen von ncurses zu benutzen, das heißt, eine Reihe neuer Funktionen zur Ausgabe müssen gelernt werden.



# Quellen
- C von A bis Z, Kurze Erklärung, sowie Code für getch-Funktion mit termios: http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/016_c_ein_ausgabe_funktionen_006.htm#mja821f1d0ab158bed792eccc5f30e3f84

## Conio
- Mit Code-Grundgerüst für ein Spiel: https://www.c-plusplus.net/forum/topic/39320/getch-getche-kbhit-getchar
- https://en.wikipedia.org/wiki/Conio.h

## Termios
Man findet kaum Anfängerinformationen zu dieser Bibliothek, wahrscheinlich weil es so low-level ist und echte physische Terminals heute kaum noch genutzt werden.

- http://pronix.linuxdelta.de/C/Linuxprogrammierung/Linuxsystemprogrammieren_C_Kurs_Kapitel6.shtml#6_1
- https://en.wikibooks.org/wiki/Serial_Programming/termios

## Curses
### NCURSES installieren
- https://websetnet.net/how-to-install-ncurses-library-on-a-linux/?q=%2Fde%2Fhow-to-install-ncurses-library-on-a-linux%2F

### Mit NCURSES programmieren
- http://www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html
- http://www.paulgriffiths.net/program/c/curin1.php

### Hintergrundinformation
- In Overview ist eine sehr gute Erklärung des Zweckes der curses-Bibliothek: https://en.wikipedia.org/wiki/Curses_(programming_library)
- https://www.linuxquestions.org/questions/programming-9/differences-between-ncurses-library-and-termios-struct-w-r-t-keyboard-reading-805611/

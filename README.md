# syspr-examprep

Eine Sammlung aus Aufgaben aus alten Prüfungsaufgaben für das Modul syspr an der FHNW.

Um die Einzelnen Programme auszuführen können die C-Files mit gcc compiliert werden und anschliessend anhand der 
Beispiele hier im README ausgeführt werden.

## addN

Schreiben Sie ein Programm addN, das n als Command Line Argumente übergebene Zahlen
in n Threads zu int konvertiert, aufaddiert, und in main() das Resultat ausgibt.

```
$ ./addN 3 4 2 
9
```

## checkin

Schreiben Sie ein Programm checkin, das mit einer POSIX Message Queue eine Flughafen Check-in Warteschlange umsetzt, die
es erlaubt, Reisende mit checkin scan name eco|biz zu erfassen und später mit checkin next herauszufinden, wer als
nächstes dran kommt. Business Reisende sollen dabei solche mit Economy Ticket überholen, wie hier gezeigt.

```
$ ./checkin scan bart eco 
added bart (eco) to queue 
$ ./checkin scan lisa biz 
added lisa (biz) to queue 
$ ./checkin next
next is lisa
```

## socketpair

Schreiben Sie ein Programm, das mit socketpair() zwei verbundene UNIX Domain Sockets erstellt und diese nutzt, um ein (
per Command Line übergebenes) ASCII-Zeichen vom Parent- zum Child-Prozess und wieder zurück zu senden, wo es dann
ausgegeben wird.

```
$ ./socketpair a
a
```
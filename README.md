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

## secChild

Schreiben Sie ein Programm, das eine Sekunde lang (CPU Zeit) Child-Prozesse erzeugt und dann ausgibt, wie viele
Child-Prozesse in dieser Zeit erzeugt werden konnten.

```
$ ./secChild
5388
```

## socketpair

Schreiben Sie ein Programm, das mit socketpair() zwei verbundene UNIX Domain Sockets erstellt und diese nutzt, um ein (
per Command Line übergebenes) ASCII-Zeichen vom Parent- zum Child-Prozess und wieder zurück zu senden, wo es dann
ausgegeben wird.

```
$ ./socketpair a
a
```

# IPC mit pipes / len
Schreiben Sie ein Programm len, das die Länge des Outputs eines beliebigen Programms
ausgibt, dessen Pfadname per Command Line übergeben wird. Nutzen Sie dazu eine Pipe und
den dup2() Call, der stdout auffd "umbiegt", mit dup2(fd, STDOUT__FILENO)
```
$ ./len ./hello
51
```

# udp2tcp / Sockets
Gegeben den folgenden Code, implementieren Sie in main() ein Programm udp2tcp das ein
UDP Paket (max. 4096 Bytes) empfängt, und dessen Inhalt per TCP an die Absender-Adresse
zurücksendet, aber auf den Port 8080, statt dem ursprünglichen Absender-Port. Falls dort ein TCP Server antwortet, soll die ganze Antwort auf die Konsole ausgegeben werden

# mq_carousel / POSIX IPC
Schreiben Sie ein Programm mq__carousel, welches alle Messages aus einer per Pfadname
gegebenen POSIX Message Queue herausliest, auf die Konsole ausgibt, und dann wieder in
die Queue schreibt. Vereinfachung: Alle Messages haben dieselbe Priorität

# dogbday
Angenommen, dass 7 "Hundejahre" einem "Menschenjahr" entsprechen, schreiben Sie ein
Programm dogbday, das ein Geburtsdatum (nach 01.01.1970) nimmt, und den diesem Alter entsprechenden "Hundegeburtstag" ausgibt. Das Datum soll jeweils im Format "%d.%m.%Y"
in Lokalzeit geparsed und ausgegeben werden, wie im Beispiel.
```
$ ./dogbday 07.01.2003
07.01.2021
```

# sum
Schreiben Sie ein Programm sum, das die String-Längen seiner Command Line Argumente
parallel berechnet, in je einem Thread, und dann die korrekte Summe ausgibt.
```
$ ./sum it was all a dream
14
```

# sd / IPC mit pipes
Schreiben Sie ein Programm sd, welches die maximale Tiefe des Stacks bestimmt, indem es eine rekursive Funktion aufruft, in einem Child Prozess, welche in jeder Iteration die aktuelle Stack-Tiefe per Pipe an den Parent schickt, der dann den letzten Wert ausgibt.
```
$ ./sd
262008 forks until Stackoverflow
```
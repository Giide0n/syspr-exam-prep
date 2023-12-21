# syspr-examprep

## addN

Schreiben Sie ein Programm add, das n als Command Line Argumente übergebene Zahlen
in n Threads zu int konvertiert, aufaddiert, und in main() das Resultat ausgibt.

```
$ ./add 3 4 2 
9
```

## socketpair

Schreiben Sie ein Programm, das mit socketpair() zwei verbundene UNIX Domain Sockets erstellt und diese nutzt, um ein (
per Command Line übergebenes) ASCII-Zeichen vom Parent- zum Child-Prozess und wieder zurück zu senden, wo es dann
ausgegeben wird.
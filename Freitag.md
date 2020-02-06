# Freitag

Freitags gibt es kein neues Thema, stattdessen werden die Themen der Woche wiederholt und vertieft.

Hole bisher verpasste Aufgaben nach, oder beschäftige dich mit Aufgaben aus dem folgenden Pool.

## Tankstelle

Schreibe eine Funktion `void tankstelle(unsigned x)`, welche die Ziffern von `x` in 7-Segment-Form auf die Konsole schreibt.

Beispielsweise soll `tankstelle(8075)` folgendes auf die Konsole schreiben:

```
 _   _   _   _
|_| | |   | |_
|_| |_|   |  _|
```

## Umgekehrte polnische Notation

Schreibe eine Funktion `int nelop(const char * s)`, welche die Formel in `s` (umgekehrt polnisch notiert) ausrechnet und das Ergebnis zurückliefert.

Beispielsweise soll `nelop("1 2 + 9 4 - *")` als Ergebnis 15 liefern, weil (1 + 2) * (9 - 4) = 15 ist.

Zur Implementierung bietet sich ein Stack für die eingelesenen Zahlen und Zwischenergebnisse an:

| Token | Stack | Explanation                   |
| :---: | ----- | ----------------------------- |
| 1     | 1     | push 1                        |
| 2     | 1 2   | push 2                        |
| +     | 3     | replace top 2 with sum        |
| 9     | 3 9   | push 9                        |
| 4     | 3 9 4 | push 4                        |
| -     | 3 5   | replace top 2 with difference |
| *     | 15    | replace top 2 with product    |

## Labyrinth-Generator

Übersetze den folgenden rekursiven Pseudo-Code zum Generieren eines Labyrinths nach C:

```
generate_labyrinth():
    initialize labyrinth according to figure below
    probe_neighbours(topleft)
    print labyrinth

probe_neighbours(position):
    for each neighbour of position, in random order:
        if neighbour is marked
            tear down wall to neighbour
            unmark neighbour
            probe_neighbours(neighbour)

+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
|   | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| * | * | * | * | * | * | * | * | * | * | * | * | * | * | * |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
```

## Auto-Vervollständigung

Schreibe eine Funktion `int autocomplete(const char * typed, const char * vocabulary[], const char ** result)`.
Diese Funktion soll für alle Strings in `vocabulary`, die mit dem String `typed` anfangen, das auf `typed` folgende längste gemeinsame Präfix finden.
Die Länge dieses Präfixes soll zurückgeliefert werden, und ein String, der mit diesem Präfix anfängt, in `*result` abgelegt werden. Beispiel:

```c
int main(void)
{
    const char * vocabulary[] = {"fool", "baroness", "barometer", "quick"};
    const char * lcp;
    int len = autocomplete("b", vocabulary, &lcp);
    assert(len == 3);
    assert(lcp[0] == 'a');
    assert(lcp[1] == 'r');
    assert(lcp[2] == 'o');
}
```

## Spiel

Programmiere ein Spiel deiner Wahl, z.B.

- Tic Tac Toe
- Vier Gewinnt
- Othello
- Blackjack

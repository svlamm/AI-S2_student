# Procedureel programmeren in Python - oefeningen


(c) 2024 Hogeschool Utrecht<br>
Auteur: David Isaacs Paternostro


## 1.1.a. Piramide

Schrijf een programma dat een piramide van variabele lengte afdrukt, zoals in het voorbeeld hieronder. Druk ieder karakter apart af. De gebruiker geeft aan hoe groot de piramide is. Implementeer je programma twee keer, de eerste keer met twee `for` loops, en daarna met twee `while` loops. Maak ook versies die de pyramide een andere kant op laten wijzen.

```
Hoe groot? 5
*
**
***
****
*****
****
***
**
*
```

## 1.1.b. Tekstcheck

Schrijf een functie die de eerste index teruggeeft waarop twee strings een verschillende  waarde hebben. Bedenk zelf een goede functienaam. Het complete programma vraagt om twee strings aan de gebruiker en print de index waarop deze twee strings verschillen. Zorg je dat de functie goed test. Let op: een string mag spaties bevatten!

Voorbeeld output:
```
Geef een string: lalala Ik eet uit voor het ontbijt.
Geef een string: lalala Ik eet citroen op zondag tijdens het ontbijt!
Het eerste verschil zit op index 14.
```

## 1.1.c. Lijstcheck

a. Schrijf een functie count() die berekent hoe vaak een geheel getal x in een lijst voorkomt.

b. Schrijf een functie die in een gegeven lijst het grootste verschil tussen twee op een volgende getallen bepaalt.

c. Schrijf een functie, die bepaalt of een gegeven lijst met alleen 1’en en 0’en aan de volgende eisen voldoet:
  - Het aantal enen is groter dan aan het aantal nullen
  - Er mogen niet meer dan 12 nullen zijn.

Bedenk zelf wat het return type van deze functie moet zijn. Gebruik in je programma de functie count() die je hebt geschreven bij de vorige opgave.

## 1.1.d. Palindroom

Schrijf een functie die checkt of een woord een palindroom is. Schrijf een versie die gebruikt maakt van een bibliotheekfunctie die een string voor je omdraait. Maak ook een versie waarbij jij zelf het omdraaien verzorgt. Probeer zo min mogelijk code te gebruiken.

## 1.1.e. Sorteren

Bedenk en schrijf zelf een functie die een lijst met getallen op volgorde sorteert.

## 1.1.f. Gemiddelde berekenen

Schrijf een functie die het gemiddelde van een lijst met cijfers berekent. Schrijf er ook een die als input een lijst van lijsten met cijfers krijgt, en als uitvoer een lijst met de gemiddelden teruggeeft.

## 1.1.g. Random

Schrijf een programma dat een willekeurig getal kiest en de gebruiker net zo lang laat gokken tot dat ze het goed heeft. 

## 1.1.h. Compressie

Schrijf een compress-programma, dat uit een gegeven bestand een nieuwe bestand maakt, waarbij van iedere regel alle spaties en tabs aan het begin van de regel zijn verwijderd.
Verder zijn alle lege regels verwijderd (een lege regel bevat ’\n’ , eventueel voorafgegaan door spaties en tabs(‘\t’)).

## 1.1.i. Cyclisch verschuiven

Schrijf een functie met twee parameters. De eerste parameter, ch, is een character. De tweede parameter, n, geeft aan hoeveel posities de bitjes van ch opgeschoven moeten
worden. Als n > 0 is dan worden de bitjes naar links geschoven. Als n < 0 is dan worden de bitjes naar rechts geschoven. De bitjes die wegvallen worden aan de andere kant van
de byte weer teruggeplaatst.
Voorbeeld 1: ch met bitwaarde 1011000 en n is gelijk aan 3 resulteert in een ch met de bitwaarde: 1000101.
Voorbeeld 2: ch met bitwaarde 1011100 en n is gelijk aan -4 resulteert in een ch met de bitwaarde: 1100101.

## 1.1.j. Fibonaci

De rij van Fibonacci is genoemd naar Leonardo van Pisa, bijgenaamd Fibonacci, die de rij noemt in zijn boek Liber abaci uit 1202. De rij begint met 0 en 1 en vervolgens is elk
volgende element van de rij steeds de som van de twee voorgaande elementen. Bij de rij gebruiken we de notatie fn voor het aangeven van het n-de element van de rij. f9 is
bijvoorbeeld gelijk aan 34. De eerste elementen van de rij zijn dan als volgt:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584
Implementeer een functie die fn uitrekent gegeven integer n. De functie moet recursief zijn.

Meer oefenen met recursie: implementeer de eerdere sorteer-bereken-controleer opdrachten met recursieve functies.

## 1.1.k. Caesarcijfer

Schrijf een programma voor Caesarcijfers. Voorbeeld van de interactie met het programma:

```
Geef een tekst: To be or not to be, That is the question
Geef een rotatie: 4
Caesarcode: Xs fi sv rsx xs fi, Xlex mw xli uyiwxmsr
```

## 1.1.l. FizzBuzz

Schrijf een programma dat de getallen 1 tot 100 print, maar print voor veelvouden van drie 'fizz' in plaats van het getal en voor veelvouden van vijf print 'buzz' in plaats van
het getal. Getallen die zowel veelvoud zijn van drie als van vijf worden afgedrukt als 'fizzbuzz'.

> Het FizzBuzz-probleem was een tijdje populair bij sollicitatiegesprekken voor programmeurs. Het probleem kan op verschillende manieren opgelost worden (ook afhankelijk van de programmeertaal) en de verschillende uitwerkingen hebben andere voor- en nadelen die interessant zijn om te bespreken tijdens een sollicitatiegesprek.

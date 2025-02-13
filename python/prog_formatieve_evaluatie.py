#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Procedureel programmeren in Python
Formatieve evaluatie

(c) 2024 Hogeschool Utrecht,
Peter van den Berg (peter.vandenberg@hu.nl)

Opdracht: beantwoord de vragen en implementeer de functies zoals aangegeven staat bij elke opgave.

TIP: Bij elke functie staat een voorbeeldaanroep met daarbij de verwachte uitkomst. 
     Als je nog niet zeker bent van je oplossing, kun je meer van dit soort testjes maken.

LET OP! Het is niet toegestaan om bestaande modules te importeren en te
        gebruiken, zoals `math` en `statistics` (builtins en/of random mogen wel gebruikt worden).
"""

import builtins
import random

GREEN = "\x1b[32m"
RED = "\x1b[31m"
BLACK = "\x1b[0m"


# Opgave 1. Leg uit wat het verschil is tussen de onderstaande stukken code:

# Stuk code 1
# if <conditie_1>:
#     <code_blok_1>
# if <conditie_2>:
#     <code_blok_2>

#  Stuk code 2
# if <conditie_1>:
#     <code_blok_1>
# elif <conditie_2>:
#     <code_blok_2>

# TODO: <geef hier je antwoord>


# Opgave 2. Wat doet break in een for-loop? En continue?

# TODO: <geef hier je antwoord>


# Opgave 3. De range() functie kan drie argumenten meekrijgen. 
# Geef een voorbeeld van een range() functie met drie argumenten en leg uit wat de argumenten betekenen.

# TODO: <geef hier je antwoord>


# Opgave 4. Wat is het verschil tussen onderstaande functies

# def functie_1():
#     print(<expressie_1>)

# def functie_2():
#     return <expressie_1>

# TODO: <geef hier je antwoord>


# Opgave 5. Wat is het belangrijkste verschil tussen een tuple en een list? Geef een voorbeeld van een tuple.

# TODO: <geef hier je antwoord>


# Opgave 6. Implementeer de functie trek_twee_kaarten() zoals beschreven in de desbetreffende docstring.

def trek_twee_kaarten():
    """
    Trekt twee willekeurige kaarten uit een lijst van kaarten, en geef de totale waarde van deze kaarten terug.
    De lijst met kaarten verandert niet na het trekken van een kaart (je hoeft dus geen kaarten te poppen uit de lijst).
    De lijst met kaarten bevat de getallen 2 t/m 10, J, Q, K en A.
    - De getallen 2 t/m 10 hebben de waarde van het getal zelf.
    - De kaarten J, Q en K hebben de waarde 10.
    - De kaart A heeft de waarde 11.

    TIP: gebruik de random module om een willekeurige kaart te kiezen.

    Returns:
        int: De som van de twee kaarten.
    """
    pass


# Test de functie `trek_twee_kaarten()`
verwachtte_waarde = 21
random.seed(6)  # Zorgt ervoor dat de random getallen altijd hetzelfde zijn.
print(f"trek_twee_kaarten() =? {verwachtte_waarde}: ", end='')

if trek_twee_kaarten() == verwachtte_waarde:
    print(GREEN + 'de functie `trek_twee_kaarten()` geeft het juiste antwoord!' + BLACK)
else:
    print(RED + 'de functie `trek_twee_kaarten()` geeft niet het juiste antwoord...' + BLACK)


# Opgave 7. Implementeer de functie beste_speler(scores) zoals beschreven in de desbetreffende docstring.

def beste_speler(scores):
    """
    Vindt de spelersnaam met de hoogste score uit de gegeven scores.

    Args:
        scores (dict): De spelers (keys) met hun bijbehorende scores (values).

    Returns:
        string: De naam van de speler die de hoogste score heeft.
    """
    pass


# Test de functie `beste_speler()`
gegeven_argument = {'Sanne': 10, 'Isabella': 20, 'Yassine': 30}
verwachtte_waarde = 'Yassine'

print(f"beste_speler({gegeven_argument}) =? {verwachtte_waarde}: ", end='')
if beste_speler(gegeven_argument) == verwachtte_waarde:
    print(GREEN + 'de functie geeft het juiste antwoord!' + BLACK)
else:
    print(RED + 'de functie geeft niet het juiste antwoord...' + BLACK)


# Opgave 8. Implementeer de functie vraag_getal_onder_n(n) zoals beschreven in de desbetreffende docstring.

def vraag_getal_onder_n(n):
    """
    Vraag de gebruiker om een getal tussen 1 en n te geven. 
    Als de gebruiker een getal buiten deze range invoert, 
    print dan een foutmelding en vraag opnieuw om een getal.

    Args:
        n (int): Het maximale getal om te vragen aan de gebruiker.

    Returns:
        int: Het ingevoerde getal tussen 1 en n.
    """
    pass


# Test de functie `vraag_getal_onder_n()`
gegeven_argument = 11
verwachtte_waarde = 3
inputs = ["12", "3"]  # Simuleert de input; eerst een 12 en dan een 3
builtins.input = lambda _: inputs.pop()  # Past deze simulatie toe op de daadwerkelijke input

print(f"vraag_getal_onder_n({gegeven_argument}) =? {verwachtte_waarde}: ", end='')
if vraag_getal_onder_n(gegeven_argument) == verwachtte_waarde:
    print(GREEN + 'de functie geeft het juiste antwoord!' + BLACK)
else:
    print(RED + 'de functie geeft niet het juiste antwoord...' + BLACK)

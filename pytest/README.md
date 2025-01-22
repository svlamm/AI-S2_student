# Testen in Python



(c) 2024 Hogeschool Utrecht<br>
Auteur: Tijmen Muller

## Waarom testen?

Het is een ‘fact of life’ dat software fouten (bugs) bevat. Het is natuurlijk een goed voornemen om geen fouten te maken tijdens het schrijven, maar dat zal het aantal fouten nooit tot nul reduceren. Het herstellen van een fout is doorgaans duurder in latere fasen van de ontwikkeling van een applicatie, dus het is verstandig fouten zo vroeg mogelijk te vinden. Eén reden hiervoor is dat het verbeteren van een fout vaak een nieuwe fout introduceert, en als je pech hebt meer dan één.

Voor technische software geldt dit misschien nog wel sterker dan voor andere software: als een bug pas tijdens het gebruik van een kerncentrale aan het licht komt is er misschien geen centrale meer om je gewijzigde software te gebruiken. (Als je dichtbij woonde is er misschien ook geen ‘jij’ meer om die wijziging te maken.)

Het is dus verstandig software zo vroeg mogelijk te testen. Er is een ontwikkelmethode die er op is gebaseerd dat je pas code mag schrijven of wijzigen als je eerst een test hebt geschreven die (met de code die je tot nu toe hebt) faalt: _test driven development_.

## Unit tests

De kleinste eenheden code die we schrijven worden units genoemd, en het testen daarvan dus unit testing. Een unit test heeft meestal een simpel patroon:
- zet een paar dingen (bijvoorbeeld objecten) klaar;
- laat de te testen code iets doen met die dingen en/of een nieuw ding maken;
- verifieer dat de oude dingen en/of de nieuwe dingen de verwachte waarden hebben.

Neem als voorbeeld de functie `add_elements()` voor lijsten, die de elementen van twee lijsten bij elkaar optelt. Bijvoorbeeld: `add_elements([1, 2], [4, 3])` geeft als resultaat de lijst `[5, 5]`. Als we het patroon van unit testing volgen, dan hebben we de volgende stappen:
- we hebben om te beginnen twee lijsten nodig met daarin een aantal bekende waarden;
- we roepen de functie aan, zodat we een nieuwe lijst krijgen;
- we controleren of de nieuwe lijst de verwachte waarden heeft én we controleren of de originele lijst nog de oude waarden heeft.

Om te controleren of aan een bepaalde voorwaarde is voldaan kun je `assert` gebruiken. Een `assert` met een argument dat evalueert tot `False` geeft een `AssertionError`.

Richt je test zo in dat het waarschijnlijk is dat realistische fouten in de te testen code ook aan het licht komen. Als je alleen test dat `add_elements([0, 0], [0, 0])` gelijk is aan `[0, 0]`, dan zijn er voor de hand liggende fouten die je niet zult ontdekken.

Gegeven onderstaande tests, welke fout(en) zouden hier bijvoorbeeld nog niet ontdekt worden?

```python
# Unit test 1
lst1 = [0, 0]
lst2 = [0, 0]
lst3 = add_elements(lst1, lst2)

assert lst1 == [0, 0]
assert lst2 == [0, 0]
assert lst3 == [0, 0]

# Unit test 2
lst1 = [1, 2]
lst2 = [4, 3]
lst3 = add_elements(lst1, lst2)

assert lst1 == [1, 2]
assert lst2 == [4, 3]
assert lst3 == [5, 5]
```

## `pytest`

Als er een fout in de code van `add_elements()` zit en een test dus faalt, dan krijgen we van Python een foutmelding, bijvoorbeeld:

```
Traceback (most recent call last):
  File "prog09_test.py", line 9, in <module>
    assert lst3 == [0, 0]
           ^^^^^^^^^^^^^^
AssertionError
```

Het zou handig zijn als de bovenstaande foutmelding ook aan zou geven wat de waarden in `lst3` zijn. Ook zou het handig zijn als _alle_ tests uitgevoerd zouden worden en de applicatie niet meteen bij de eerste falende test stopt. Een module die zoiets (en nog veel meer) voor je doet heet een 'unit test framework'. Wij gebruiken een simpel maar populair unit test framework voor Python: `pytest`.

Een `pytest` applicatie wordt geschreven in een bestandsnaam dat begint met `test_` en bevat een reeks met testfuncties die ook weer beginnen met `test_`. Elke testfunctie test bij voorkeur precies één situatie. We kunnen bovenstaande tests bijvoorbeeld plaatsen in een bestand genaamd `test_vector.py`. De code van `add_elements()` zelf staat in een ander bestand genaamd `vector.py` en wordt geimporteerd.

```py
# test_vector.py

from vector import add_elements

def test_add_elements_zero():
    lst1 = [0, 0]
    lst2 = [0, 0]
    lst3 = add_elements(lst1, lst2)

    assert lst1 == [0, 0]
    assert lst2 == [0, 0]
    assert lst3 == [0, 0]

def test_add_elements_five():

    lst1 = [1, 2]
    lst2 = [4, 3]
    lst3 = add_elements(lst1, lst2)

    assert lst1 == [1, 2]
    assert lst2 == [4, 3]
    assert lst3 == [5, 5]
```

Als we nu `pytest` aanroepen in de command line (of vanuit de IDE), dan krijgen we veel nuttige informatie, die we kunnen gebruiken om de code te verbeteren, ongeveer zoiets:

```
============================== test session starts ==============================
platform linux -- Python 3.12.4, pytest-7.4.4, pluggy-1.0.0
rootdir: /mnt/c/workspace/semesters/ai-s2/docent/code/prog
plugins: anyio-4.2.0
collected 2 items

test_vector.py FF                                                         [ 50%]

=================================== FAILURES ====================================
____________________________ test_add_elements_zero _____________________________

    def test_add_elements_zero():
        lst1 = [0, 0]
        lst2 = [0, 0]
        lst3 = add_elements(lst1, lst2)

        assert lst1 == [0, 0]
        assert lst2 == [0, 0]
>       assert lst3 == [0, 0]
E       assert [0, 1] == [0, 0]
E         At index 1 diff: 1 != 0
E         Use -v to get more diff

prog09_test.py:10: AssertionError
____________________________ test_add_elements_five _____________________________

    def test_add_elements_five():

        lst1 = [1, 2]
        lst2 = [4, 3]
        lst3 = add_elements(lst1, lst2)

        assert lst1 == [1, 2]
        assert lst2 == [4, 3]
>       assert lst3 == [5, 5]
E       assert [0, 1] == [5, 5]
E         At index 0 diff: 0 != 5
E         Use -v to get more diff

test_vector.py:20: AssertionError
============================ short test summary info ============================
FAILED test_vector.py::test_add_elements_zero - assert [0, 1] == [0, 0]
FAILED test_vector.py::test_add_elements_five - assert [0, 1] == [5, 5]
========================== 2 failed, 2 passed in 0.16s ==========================
```

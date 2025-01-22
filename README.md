# Procedureel en object-georiënteerd programmeren


(c) 2024 Hogeschool Utrecht<br>
Auteurs: David Isaacs Paternostro en Tijmen Muller


In deze repository staan de voorbeelden en oefeningen die horen bij het procedureel en
georiënteerd programmeren in semester 2 van de studierichting Artificial Intelligence. We
raden je aan om vanaf dit semester gebruik te maken van conda omgevingen (zie
https://docs.conda.io/) voor je verschillende
opdrachten en projecten. Het voordeel van deze omgevingen is dat je de configuratie van
Python (bijvoorbeeld de packages die je hebt geinstalleerd) onderling onafhankelijk houdt
voor je projecten. Dit voorkomt vaak problemen met _dependencies_.


## Installatie

Als er nog geen omgeving genaamd `ai-s2` is, creeer deze dan door in de Anaconda
Prompt (`conda`) naar de directory van deze repository te gaan en daar te typen:
```conda env create -f ai_s2_conda.yaml```

### Interpreter instellen in PyCharm

1. Ga naar File >> Settings >> Project: _projectnaam_ >> Project Interpreter en dan:
   1. kies `ai-s2` in het dropdown menu; of
   2. ga naar Add Interpreter >> Add Local Interpreter >> Conda Environment >>
      Use Existing Environment >> selecteer `ai-s2` in het dropdown menu.
2. Klik rechtsonder in de GUI waar je 'Python' ziet staan.

### Interpreter instellen in VSCode

1. Klik rechtsonder in de GUI waar je 'Python' ziet staan. Er komt midden bovenin je
   scherm een dropdown menu, kies daar: `ai-s2`.

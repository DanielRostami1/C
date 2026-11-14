# Kostenvoranschlag für Malerarbeiten (C)

Ein Konsolenprogramm in C zur Verwaltung von Kunden und zur automatischen Berechnung von Kostenvoranschlägen für Malerarbeiten – inklusive Flächenberechnung, Rabattlogik und Eingabevalidierung.

## 📋 Beschreibung

Dieses Programm simuliert die Angebotserstellung eines Malerbetriebs. Für jeden Kunden werden Name, Telefonnummer, Anzahl der Räume, die Fläche jedes einzelnen Raums sowie der Quadratmeterpreis erfasst. Anschließend berechnet das Programm die Gesamtfläche, den Gesamtpreis und gewährt automatisch Rabatte ab bestimmten Flächengrößen.

Das Projekt entstand als Übungsprojekt im Bereich C-Programmierung und deckt zentrale Konzepte ab: Strukturen (`struct`), Arrays, Zeiger, Funktionen, Eingabevalidierung und Menüführung.

## ✨ Funktionen

- **Kundenverwaltung** bis zu 30 Kunden pro Sitzung
- **Eingabevalidierung** für alle Felder:
  - Name darf nicht leer sein und keine Ziffern enthalten
  - Anzahl der Räume muss zwischen 1 und 30 liegen
  - Flächen und Preise müssen gültige positive Zahlen sein
  - Fehlerhafte Eingaben (z. B. Buchstaben statt Zahlen) werden abgefangen und der Eingabepuffer bereinigt
- **Automatische Flächenberechnung** über alle Räume eines Kunden
- **Rabattlogik**:
  - ab 100 m² → 10 % Rabatt
  - ab 50 m² → 5 % Rabatt
  - unter 50 m² → kein Rabatt
- **Übersichtliche Ausgabe** aller Kundendaten und berechneten Angebote

## 🛠️ Technologie-Stack

- **Sprache:** C (C99 oder neuer)
- **Compiler:** MSVC / GCC / Clang
- **Besonderheit:** Verwendet `scanf_s` (Microsoft-spezifische sichere Variante) → **empfohlen für Windows / Visual Studio**

> ⚠️ **Hinweis zur Portabilität:** `scanf_s` ist eine Microsoft-Erweiterung und nicht Teil des C-Standards. Auf Linux/macOS (GCC/Clang) muss das Programm angepasst werden (siehe Abschnitt „Kompilieren und Ausführen").

## 🚀 Kompilieren und Ausführen

### Unter Windows (Visual Studio / MSVC)

1. Projekt in Visual Studio öffnen oder Datei als `.c` speichern
2. Kompilieren und starten (F5) – oder per Konsole:
   ```bash
   cl main.c
   main.exe
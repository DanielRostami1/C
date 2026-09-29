
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// ===========================================================
// Programm: Kostenvoranschlag für Malerarbeiten
// ===========================================================

// ===========================================================
// Struktur für einen Kunden
// ===========================================================

struct Customer {
    char name[50];          // Kundenname
    char tel[20];           // Telefonnummer
    int quantities;         // Anzahl der Räume
    float meter[30];        // Fläche jedes Raumes
    float sumMeter;         // Gesamtfläche
    float price;            // Preis pro Quadratmeter
};

// ===========================================================
// Funktionsdeklarationen
// ===========================================================

void addCustomer(int* count, struct Customer customers[]);
void costEstimate(int count, struct Customer customers[]);
void showCustomer(int count, struct Customer customers[]);
void menu(struct Customer customers[]);

// ===========================================================
// Hauptfunktion
// ===========================================================

int main(void)
{
    struct Customer customers[30];

    menu(customers);

    return 0;
}

// ===========================================================
// Kunden hinzufügen
// ===========================================================

void addCustomer(int* count, struct Customer customers[])
{
    int result;

    // Prüfen, ob bereits 30 Kunden gespeichert sind
    if (*count >= 30)
    {
        printf("Die maximale Anzahl von Kunden ist 30.\n");
        return;
    }

    printf("\n========== Kunden hinzufügen ==========\n");

    // -------------------------------------------------------
    // Name eingeben
    // -------------------------------------------------------

    printf("Name: ");

    scanf_s(" %49[^\n]", customers[*count].name, 50);

    // Prüfen, ob der Name leer ist
    if (customers[*count].name[0] == '\0')
    {
        printf("Der Name darf nicht leer sein!\n");
        return;
    }

    // Prüfen, ob der Name eine Zahl enthält
    for (int i = 0; customers[*count].name[i] != '\0'; i++)
    {
        if (isdigit((unsigned char)customers[*count].name[i]))
        {
            printf("Der Name darf keine Zahlen enthalten!\n");
            return;
        }
    }

    // -------------------------------------------------------
    // Telefonnummer eingeben
    // -------------------------------------------------------

    printf("Telefonnummer: ");

    scanf_s(" %19[^\n]", customers[*count].tel, 20);

    // -------------------------------------------------------
    // Anzahl der Räume eingeben
    // -------------------------------------------------------

    do
    {
        printf("Anzahl der Räume (1-30): ");

        result = scanf_s("%d", &customers[*count].quantities);

        // Wenn keine Zahl eingegeben wurde
        if (result != 1)
        {
            printf("Bitte geben Sie eine gültige Zahl ein.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            continue;
        }

        // Anzahl der Räume prüfen
        if (customers[*count].quantities < 1 ||
            customers[*count].quantities > 30)
        {
            printf("Die Anzahl der Räume muss zwischen 1 und 30 liegen.\n");
        }

    } while (customers[*count].quantities < 1 ||
             customers[*count].quantities > 30);

    // -------------------------------------------------------
    // Gesamtfläche auf 0 setzen
    // -------------------------------------------------------

    customers[*count].sumMeter = 0;

    // -------------------------------------------------------
    // Fläche der einzelnen Räume eingeben
    // -------------------------------------------------------

    for (int i = 0; i < customers[*count].quantities; i++)
    {
        do
        {
            printf("Fläche von Raum %d in m²: ", i + 1);

            result = scanf_s("%f", &customers[*count].meter[i]);

            // Wenn keine Zahl eingegeben wurde
            if (result != 1)
            {
                printf("Bitte geben Sie eine gültige Zahl ein.\n");

                int c;
                while ((c = getchar()) != '\n' && c != EOF);

                continue;
            }

            // Fläche prüfen
            if (customers[*count].meter[i] <= 0)
            {
                printf("Die Fläche muss größer als 0 sein.\n");
            }

        } while (customers[*count].meter[i] <= 0);

        // Fläche zur Gesamtfläche addieren
        customers[*count].sumMeter += customers[*count].meter[i];
    }

    // -------------------------------------------------------
    // Preis eingeben
    // -------------------------------------------------------

    do
    {
        printf("Preis pro Quadratmeter: ");

        result = scanf_s("%f", &customers[*count].price);

        // Wenn keine Zahl eingegeben wurde
        if (result != 1)
        {
            printf("Bitte geben Sie eine gültige Zahl ein.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            continue;
        }

        // Preis prüfen
        if (customers[*count].price < 0)
        {
            printf("Der Preis darf nicht unter 0 liegen.\n");
        }

    } while (customers[*count].price < 0);

    // Anzahl der Kunden erhöhen
    (*count)++;

    printf("Kunde wurde erfolgreich gespeichert.\n");
}

// ===========================================================
// Kostenvoranschlag berechnen
// ===========================================================

void costEstimate(int count, struct Customer customers[])
{
    if (count == 0)
    {
        printf("\nEs wurden noch keine Kunden gespeichert.\n");
        return;
    }

    printf("\n========== Kostenvoranschlag ==========\n");

    for (int i = 0; i < count; i++)
    {
        float totalPrice;
        float discount = 0;

        // Gesamtpreis berechnen
        totalPrice = customers[i].sumMeter * customers[i].price;

        // Rabatt berechnen
        if (customers[i].sumMeter >= 100)
        {
            discount = 10;
        }
        else if (customers[i].sumMeter >= 50)
        {
            discount = 5;
        }

        // Rabatt abziehen
        totalPrice -= totalPrice * discount / 100;

        // Ergebnis ausgeben
        printf("\nKunde: %s\n", customers[i].name);
        printf("Gesamtfläche: %.2f m²\n", customers[i].sumMeter);
        printf("Preis pro m²: %.2f Euro\n", customers[i].price);
        printf("Rabatt: %.0f %%\n", discount);
        printf("Gesamtpreis: %.2f Euro\n", totalPrice);
    }
}

// ===========================================================
// Kunden anzeigen
// ===========================================================

void showCustomer(int count, struct Customer customers[])
{
    if (count == 0)
    {
        printf("\nEs wurden noch keine Kunden gespeichert.\n");
        return;
    }

    printf("\n========== Kundendaten ==========\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nKunde %d\n", i + 1);

        printf("Name: %s\n", customers[i].name);

        printf("Telefonnummer: %s\n", customers[i].tel);

        printf("Anzahl der Räume: %d\n", customers[i].quantities);

        // Fläche jedes Raumes anzeigen
        for (int j = 0; j < customers[i].quantities; j++)
        {
            printf("Raum %d: %.2f m²\n",
                   j + 1,
                   customers[i].meter[j]);
        }

        printf("Gesamtfläche: %.2f m²\n",
               customers[i].sumMeter);

        printf("Preis pro m²: %.2f Euro\n",
               customers[i].price);
    }
}

// ===========================================================
// Menü
// ===========================================================

void menu(struct Customer customers[])
{
    int selection = 0;
    int result;
    int count = 0;

    do
    {
        printf("\n====================================\n");
        printf("       Kostenvoranschlag\n");
        printf("====================================\n");
        printf("1. Kunden hinzufügen\n");
        printf("2. Angebot berechnen\n");
        printf("3. Kunden anzeigen\n");
        printf("4. Programm beenden\n");
        printf("Ihre Auswahl: ");

        result = scanf_s("%d", &selection);

        // Prüfen, ob eine Zahl eingegeben wurde
        if (result != 1)
        {
            printf("Bitte geben Sie eine Zahl von 1 bis 4 ein.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            continue;
        }

        switch (selection)
        {
        case 1:
            addCustomer(&count, customers);
            break;

        case 2:
            costEstimate(count, customers);
            break;

        case 3:
            showCustomer(count, customers);
            break;

        case 4:
            printf("Programm wird beendet!\n");
            break;

        default:
            printf("Ungültige Auswahl!\n");
            break;
        }

    } while (selection != 4);
}


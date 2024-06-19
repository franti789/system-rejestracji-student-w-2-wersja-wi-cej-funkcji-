#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 100

// Struktura przechowująca dane studenta
typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int age;
    float grade;
    char albumNumber[MAX_NAME_LENGTH];
} Student;

Student studentDatabase[MAX_STUDENTS]; // Tablica przechowująca studentów
int studentCount = 0; // Licznik studentów

// Funkcja dodająca nowego studenta do bazy
void addStudent() {
    // Sprawdzenie, czy baza danych nie jest pełna
    if (studentCount >= MAX_STUDENTS) {
        printf("Baza danych jest pelna!\n");
        return;
    }

    // Pobranie danych studenta
    printf("Podaj imie studenta: ");
    scanf("%s", studentDatabase[studentCount].firstName);
    printf("Podaj nazwisko studenta: ");
    scanf("%s", studentDatabase[studentCount].lastName);
    printf("Podaj wiek studenta: ");
    scanf("%d", &studentDatabase[studentCount].age);
    studentDatabase[studentCount].grade = -1; // Brak oceny na początku
    strcpy(studentDatabase[studentCount].albumNumber, ""); // Pusty numer albumu na początku
    studentCount++;
}

// Funkcja dodająca ocenę do konkretnego studenta
void addGrade() {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    // Pobranie imienia i nazwiska studenta
    printf("Podaj imie studenta, do ktorego chcesz dodac ocene: ");
    scanf("%s", firstName);
    printf("Podaj nazwisko studenta: ");
    scanf("%s", lastName);

    // Wyszukanie studenta w bazie danych
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentDatabase[i].firstName, firstName) == 0 && strcmp(studentDatabase[i].lastName, lastName) == 0) {
            // Pobranie i przypisanie oceny
            printf("Podaj ocene dla studenta %s %s: ", firstName, lastName);
            scanf("%f", &studentDatabase[i].grade);
            printf("Ocena zostala dodana.\n");
            return;
        }
    }
    // Komunikat, gdy student nie zostanie znaleziony
    printf("Nie znaleziono studenta o imieniu %s %s.\n", firstName, lastName);
}

// Funkcja dodająca numer albumu do konkretnego studenta
void addAlbumNumber() {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    // Pobranie imienia i nazwiska studenta
    printf("Podaj imie studenta, do ktorego chcesz dodac numer albumu: ");
    scanf("%s", firstName);
    printf("Podaj nazwisko studenta: ");
    scanf("%s", lastName);

    // Wyszukanie studenta w bazie danych
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentDatabase[i].firstName, firstName) == 0 && strcmp(studentDatabase[i].lastName, lastName) == 0) {
            // Pobranie i przypisanie numeru albumu
            printf("Podaj numer albumu dla studenta %s %s: ", firstName, lastName);
            scanf("%s", studentDatabase[i].albumNumber);
            printf("Numer albumu zostal dodany.\n");
            return;
        }
    }
    // Komunikat, gdy student nie zostanie znaleziony
    printf("Nie znaleziono studenta o imieniu %s %s.\n", firstName, lastName);
}

// Funkcja edytująca numer albumu konkretnego studenta
void editAlbumNumber() {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    // Pobranie imienia i nazwiska studenta
    printf("Podaj imie studenta, ktorego numer albumu chcesz edytowac: ");
    scanf("%s", firstName);
    printf("Podaj nazwisko studenta: ");
    scanf("%s", lastName);

    // Wyszukanie studenta w bazie danych
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentDatabase[i].firstName, firstName) == 0 && strcmp(studentDatabase[i].lastName, lastName) == 0) {
            // Pobranie i przypisanie nowego numeru albumu
            printf("Podaj nowy numer albumu dla studenta %s %s: ", firstName, lastName);
            scanf("%s", studentDatabase[i].albumNumber);
            printf("Numer albumu zostal zmieniony.\n");
            return;
        }
    }
    // Komunikat, gdy student nie zostanie znaleziony
    printf("Nie znaleziono studenta o imieniu %s %s.\n", firstName, lastName);
}

// Funkcja usuwająca ocenę konkretnego studenta
void removeGrade() {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    // Pobranie imienia i nazwiska studenta
    printf("Podaj imie studenta, u ktorego chcesz usunac ocene: ");
    scanf("%s", firstName);
    printf("Podaj nazwisko studenta: ");
    scanf("%s", lastName);

    // Wyszukanie studenta w bazie danych
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentDatabase[i].firstName, firstName) == 0 && strcmp(studentDatabase[i].lastName, lastName) == 0) {
            studentDatabase[i].grade = -1; // Usuniecie oceny
            printf("Ocena zostala usunieta.\n");
            return;
        }
    }
    // Komunikat, gdy student nie zostanie znaleziony
    printf("Nie znaleziono studenta o imieniu %s %s.\n", firstName, lastName);
}

// Funkcja edytująca ocenę konkretnego studenta
void editGrade() {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    // Pobranie imienia i nazwiska studenta
    printf("Podaj imie studenta, ktorego ocene chcesz edytowac: ");
    scanf("%s", firstName);
    printf("Podaj nazwisko studenta: ");
    scanf("%s", lastName);

    // Wyszukanie studenta w bazie danych
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentDatabase[i].firstName, firstName) == 0 && strcmp(studentDatabase[i].lastName, lastName) == 0) {
            // Pobranie i przypisanie nowej oceny
            printf("Podaj nowa ocene dla studenta %s %s: ", firstName, lastName);
            scanf("%f", &studentDatabase[i].grade);
            printf("Ocena zostala zmieniona.\n");
            return;
        }
    }
    // Komunikat, gdy student nie zostanie znaleziony
    printf("Nie znaleziono studenta o imieniu %s %s.\n", firstName, lastName);
}

// Funkcja usuwająca konkretnego studenta z bazy
void removeStudent() {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    // Pobranie imienia i nazwiska studenta
    printf("Podaj imie studenta, ktorego chcesz usunac: ");
    scanf("%s", firstName);
    printf("Podaj nazwisko studenta: ");
    scanf("%s", lastName);

    // Wyszukanie studenta w bazie danych
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(studentDatabase[i].firstName, firstName) == 0 && strcmp(studentDatabase[i].lastName, lastName) == 0) {
            // Przesunięcie pozostałych studentów w tablicy
            for (int j = i; j < studentCount - 1; j++) {
                studentDatabase[j] = studentDatabase[j + 1];
            }
            studentCount--;
            printf("Student %s %s zostal usuniety.\n", firstName, lastName);
            return;
        }
    }
    // Komunikat, gdy student nie zostanie znaleziony
    printf("Nie znaleziono studenta o imieniu %s %s.\n", firstName, lastName);
}

// Funkcja wyświetlająca całą bazę studentów
void displayDatabase() {
    printf("\nBaza danych studentow:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Imie: %s, Nazwisko: %s, Wiek: %d, Ocena: ", studentDatabase[i].firstName, studentDatabase[i].lastName, studentDatabase[i].age);
        if (studentDatabase[i].grade == -1)
            printf("Brak oceny");
        else
            printf("%.2f", studentDatabase[i].grade);
        printf(", Numer albumu: %s\n", studentDatabase[i].albumNumber);
    }
}

// Funkcja główna z menu wyboru opcji
int main() {
    int choice;

    while (1) {
        // Wyświetlenie menu
        printf("\n--- Menu ---\n");
        printf("1. Dodanie ucznia do bazy\n");
        printf("2. Dodanie oceny do konkretnego studenta\n");
        printf("3. Usuniecie oceny konkretnego ucznia\n");
        printf("4. Wyswietlenie bazy ze studentami, ocenami i wiekiem\n");
        printf("5. Usuniecie studenta z listy\n");
        printf("6. Edycja oceny konkretnego studenta\n");
        printf("7. Dodanie numeru albumu do konkretnego studenta\n");
        printf("8. Edycja numeru albumu konkretnego studenta\n");
        printf("9. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf("%d", &choice);

        // Wybór opcji na podstawie wprowadzonego numeru
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                addGrade();
                break;
            case 3:
                removeGrade();
                break;
            case 4:
                displayDatabase();
                break;
            case 5:
                removeStudent();
                break;
            case 6:
                editGrade();
                break;
            case 7:
                addAlbumNumber();
                break;
            case 8:
                editAlbumNumber();
                break;
            case 9:
                exit(0); // Wyjście z programu
            default:
                printf("Niepoprawny wybor. Sprobuj ponownie.\n");
        }
    }

    return 0;
}

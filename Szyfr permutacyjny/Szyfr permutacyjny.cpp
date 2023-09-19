#include <iostream>
#include <string>

// Funkcja do szyfrowania tekstu permutacyjnie
std::string szyfrujPermutacyjnie(const std::string &tekst, const std::string &klucz) {
    std::string zaszyfrowanyTekst = tekst;
    
    // Sprawdzenie, czy długość klucza jest wystarczająca
    if (klucz.length() != 26) {
        std::cerr << "Klucz powinien zawierać 26 unikalnych liter alfabetu łacińskiego." << std::endl;
        return "";
    }
    
    // Przeprowadź permutację
    for (size_t i = 0; i < tekst.size(); ++i) {
        if (std::isalpha(tekst[i])) {
            char litera = std::toupper(tekst[i]);
            size_t indeks = litera - 'A';
            char zaszyfrowanaLitera = klucz[indeks];
            if (islower(tekst[i])) {
                zaszyfrowanyTekst[i] = tolower(zaszyfrowanaLitera);
            } else {
                zaszyfrowanyTekst[i] = zaszyfrowanaLitera;
            }
        }
    }
    
    return zaszyfrowanyTekst;
}

// Funkcja do deszyfrowania tekstu permutacyjnie
std::string deszyfrujPermutacyjnie(const std::string &zaszyfrowanyTekst, const std::string &klucz) {
    std::string tekst = zaszyfrowanyTekst;

    // Sprawdzenie, czy długość klucza jest wystarczająca
    if (klucz.length() != 26) {
        std::cerr << "Klucz powinien zawierać 26 unikalnych liter alfabetu łacińskiego." << std::endl;
        return "";
    }

    // Przeprowadź odwrotną permutację
    for (size_t i = 0; i < zaszyfrowanyTekst.length(); ++i) {
        if (isalpha(zaszyfrowanyTekst[i])) {
            char zaszyfrowanaLitera = toupper(zaszyfrowanyTekst[i]);
            size_t indeks = klucz.find(zaszyfrowanaLitera);
            char litera = 'A' + indeks;
            if (islower(zaszyfrowanyTekst[i])) {
                tekst[i] = tolower(litera);
            } else {
                tekst[i] = litera;
            }
        }
    }

    return tekst;
}

int main() {
    std::string tekst, klucz{"QWERTYUIOPASDFGHJKLZXCVBNM"};
    
    // Wprowadź tekst do zaszyfrowania
    std::cout << "Wprowadź tekst do zaszyfrowania: ";
    std::getline(std::cin, tekst);
    
    // // Wprowadź klucz permutacji
    // std::cout << "Wprowadź klucz permutacji (26 unikalnych liter alfabetu łacińskiego): ";
    // std::getline(std::cin, klucz);
    
    // Szyfruj tekst
    std::string zaszyfrowanyTekst = szyfrujPermutacyjnie(tekst, klucz);
    
    // Wyświetl zaszyfrowany tekst
    std::cout << "Zaszyfrowany tekst: " << zaszyfrowanyTekst << std::endl;
    //----------------------------------------------------------
     // Deszyfruj tekst
    tekst = deszyfrujPermutacyjnie(zaszyfrowanyTekst, klucz);

    // Wyświetl zdeszyfrowany tekst
    std::cout << "Zdeszyfrowany tekst: " << tekst << std::endl;
    return 0;
}

#include "cezar.hpp"
std::string szyfruj(std::string napis, const int klucz)
{
    std::string wynik{};
    for (char x : napis)
    {
        auto param = 'a';
        if (std::isupper(x))
        {
            param = 'A';
        }
        wynik += ((x - param + klucz) % 26) + param;
    }
    return wynik;
}

std::string deszyfruj(std::string napis, const int klucz)
{
    std::string wynik{};
    for (char x : napis)
    {
        auto param = 'a';
        if (std::isupper(x))
        {
            param = 'A';
        }
        wynik += ((x - param - klucz) % 26) + param;
    }
    std::cout << wynik << "\n";
    return wynik;
}

void deszyfrujBruteForce(std::string napis)
{
    for (int klucz = 1; klucz < 25; klucz++)
    {
        std::string wynik{};
        for (char x : napis)
        {
            auto param = 'a';
            if (std::isupper(x))
            {
                param = 'A';
            }
            wynik += ((x - param - klucz) % 26) + param;
        }
        std::cout << wynik << " Wartosc klucza: " << klucz << "\n";
    }
}
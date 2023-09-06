#include"cezar.hpp"
#include<iostream>

int main(){
    std::string napis("ALAmaKOta");
    auto wynik=szyfruj(napis, 2);
    std::cout << wynik << '\n';
    //std::cout << deszyfruj(wynik,2) << "\n";
    deszyfrujBruteForce(wynik);
}
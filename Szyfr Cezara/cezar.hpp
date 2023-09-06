#pragma once
#include <string>
#include <iostream>
std::string szyfruj(std::string napis, const int klucz);
std::string deszyfruj(std::string napis, const int klucz);
void deszyfrujBruteForce(std::string napis);
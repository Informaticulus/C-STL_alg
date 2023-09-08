#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Funkcja do dekodowania tekstu za pomocą szyfru Cezara
string decryptCaesarCipher(string encryptedText, int shift) {
    string decryptedText = "";

    for (char& c : encryptedText) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base - shift + 26) % 26 + base;
        }
        decryptedText += c;
    }

    return decryptedText;
}

// Funkcja do analizy częstotliwości występowania liter w tekście
vector<int> analyzeFrequency(string text) {
    vector<int> frequency(26, 0);

    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            frequency[c - base]++;
        }
    }

    return frequency;
}

int main() {
    string encryptedText;
    cout << "Podaj zaszyfrowany tekst: ";
    getline(cin, encryptedText);

    vector<int> frequency = analyzeFrequency(encryptedText);

    // Szukamy najczęściej występującej litery
    int maxFrequency = 0;
    char mostFrequentChar;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentChar = 'A' + i;
        }
    }

    // Zakładamy, że najczęściej występująca litera to 'E' (indeks 4)
    int shift = (mostFrequentChar - 'E' + 26) % 26;

    string decryptedText = decryptCaesarCipher(encryptedText, shift);

    cout << "Odkodowany tekst: " << decryptedText << endl;

    return 0;
}

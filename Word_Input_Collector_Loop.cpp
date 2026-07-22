/**
 * ============================================================================
 * Problem / Program: Dynamic Word Input Collector Loop
 * Description: Reads 'N' words into a vector list with a repeat loop choice for user interaction.
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    char repeatChoice;

    do {
        int wordCount;
        cout << "\nHow many words would you like to input? ";
        cin >> wordCount;

        if (wordCount <= 0) {
            cout << "Invalid count specified!" << endl;
            continue;
        }

        vector<string> wordsList(wordCount);
        for (int i = 0; i < wordCount; i++) {
            cout << "Enter word for index [" << i << "]: ";
            cin >> wordsList[i];
        }

        cout << "\nCaptured Words List:" << endl;
        for (int i = 0; i < wordCount; i++) {
            cout << "  [" << i << "] " << wordsList[i] << endl;
        }

        cout << "\nRepeat word input process? (Y/N): ";
        cin >> repeatChoice;

    } while (toupper(repeatChoice) == 'Y');

    return 0;
}

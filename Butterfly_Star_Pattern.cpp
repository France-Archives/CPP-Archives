/**
 * ============================================================================
 * Problem / Program: Butterfly / Hourglass Star Pattern Generator
 * Description: Generates a symmetrical dual-side butterfly/hourglass star pattern based on user-defined row height input.
 * ============================================================================
 */

#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int rows;
    char choice;

    do {
        cout << "Enter number of rows: ";
        cin >> rows;

        if (rows <= 0) {
            cout << "Invalid row count! Please enter a positive integer.\n";
            continue;
        }
        cout << endl;

        for (int i = 0; i < rows; i++) {
            // Print left triangle stars
            for (int j = 0; j <= i; j++) {
                cout << "* ";
            }

            // Print middle dynamic spacing
            for (int s = (rows * 2) - 1; s >= (i * 2) + 1; s--) {
                cout << "  ";
            }

            // Print right triangle stars
            for (int k = 0; k <= i; k++) {
                cout << "* ";
            }

            cout << endl;
        }

        cout << "\nTry another row configuration? (Y/N): ";
        cin >> choice;
        cout << endl;

    } while (toupper(choice) == 'Y');

    cout << "Program exited successfully." << endl;
    return 0;
}

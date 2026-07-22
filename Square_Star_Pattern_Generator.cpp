/**
 * ============================================================================
 * Problem / Program: Square Star Pattern Generator
 * Description: Nested loop pattern generator rendering an N x N solid square grid of star characters.
 * ============================================================================
 */

#include <iostream>

using namespace std;

int main() {
    int sideSize;

    cout << "=== SQUARE STAR PATTERN GENERATOR ===" << endl;
    cout << "Enter side size of square: ";
    cin >> sideSize;

    if (sideSize <= 0) {
        cout << "Invalid side size!" << endl;
        return 1;
    }

    for (int i = 1; i <= sideSize; i++) {
        for (int j = 1; j <= sideSize; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}

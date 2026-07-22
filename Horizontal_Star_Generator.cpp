/**
 * ============================================================================
 * Problem / Program: Horizontal Star Line Generator
 * Description: Simple loop program printing a single horizontal line of stars based on user-specified length.
 * ============================================================================
 */

#include <iostream>

using namespace std;

int main() {
    int numberOfStars;

    cout << "=== HORIZONTAL STAR GENERATOR ===" << endl;
    cout << "Enter number of stars: ";
    cin >> numberOfStars;

    if (numberOfStars <= 0) {
        cout << "Invalid star count!" << endl;
        return 1;
    }

    for (int i = 1; i <= numberOfStars; i++) {
        cout << "*";
    }
    cout << endl;

    return 0;
}

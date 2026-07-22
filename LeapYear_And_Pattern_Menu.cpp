/**
 * ============================================================================
 * Problem / Program: Leap Year Checker & Pattern Menu System
 * Description: Interactive menu program evaluating leap year conditions and rendering custom nested loop geometric star patterns.
 * ============================================================================
 */

#include <iostream>

using namespace std;

int main() {
    int choice;
    const int patternHeight = 5;

    cout << "========================================" << endl;
    cout << "        PATTERN & UTILITY MENU          " << endl;
    cout << "========================================" << endl;
    cout << "1. Check Leap Year\n";
    cout << "2. Left-Aligned Inverted Triangle (*)\n";
    cout << "3. Right-Aligned Inverted Triangle (*)\n";
    cout << "4. Centered Pyramid (*)\n";
    cout << "========================================" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    cout << endl;

    switch (choice) {
        case 1: {
            int year;
            cout << "Enter a year to check: ";
            cin >> year;

            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                cout << year << " is a LEAP YEAR.\n";
            } else {
                cout << year << " is NOT a leap year.\n";
            }
            break;
        }

        case 2:
            cout << "=== Left-Aligned Inverted Triangle ===" << endl;
            for (int i = patternHeight; i >= 1; --i) {
                for (int j = 1; j <= i; ++j) {
                    cout << "*";
                }
                cout << endl;
            }
            break;

        case 3:
            cout << "=== Right-Aligned Inverted Triangle ===" << endl;
            for (int i = patternHeight; i >= 1; --i) {
                for (int space = 1; space <= patternHeight - i; ++space) {
                    cout << " ";
                }
                for (int j = 1; j <= i; ++j) {
                    cout << "*";
                }
                cout << endl;
            }
            break;

        case 4:
            cout << "=== Centered Pyramid ===" << endl;
            for (int i = 1; i <= patternHeight; ++i) {
                for (int k = patternHeight - i; k > 0; --k) {
                    cout << " ";
                }
                for (int j = 1; j <= i; ++j) {
                    cout << "* ";
                }
                cout << endl;
            }
            break;

        default:
            cout << "Invalid choice! Please enter a number from 1 to 4.\n";
            break;
    }

    return 0;
}

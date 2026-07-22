/**
 * ============================================================================
 * Problem / Program: Sales Summary Matrix Processor
 * Description: Multi-dimensional matrix calculator computing total sales, regional performance averages, and revenue trends across multiple sales quarters.
 * ============================================================================
 */

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    char repeatChoice;

    do {
        const int SALESPEOPLE = 4;
        const int PRODUCTS = 5;

        double sales[PRODUCTS][SALESPEOPLE] = {0.0};

        int sp, prod;
        double amt;
        char addMore;

        cout << "\n=== ENTER SALES SLIPS DATA ===" << endl;
        do {
            cout << "Salesperson (1-4): ";
            cin >> sp;
            cout << "Product (1-5)    : ";
            cin >> prod;
            cout << "Sales Amount ($) : ";
            cin >> amt;

            if (sp >= 1 && sp <= 4 && prod >= 1 && prod <= 5 && amt >= 0) {
                sales[prod - 1][sp - 1] += amt;
                cout << "Sales recorded successfully!\n";
            } else {
                cout << "Invalid input values!\n";
            }

            cout << "Add another entry? (Y/N): ";
            cin >> addMore;

        } while (toupper(addMore) == 'Y');

        // Display Header
        cout << endl << string(60, '-') << endl;
        cout << "| Prod |";
        for (int s = 0; s < SALESPEOPLE; s++) {
            cout << "   S" << (s + 1) << "   |";
        }
        cout << "  Total  |\n";
        cout << string(60, '-') << endl;

        double colTotal[SALESPEOPLE] = {0.0};
        double grandTotal = 0.0;

        for (int i = 0; i < PRODUCTS; i++) {
            double rowTotal = 0.0;
            cout << "|  " << (i + 1) << "   |";

            for (int j = 0; j < SALESPEOPLE; j++) {
                cout << " " << setw(6) << fixed << setprecision(2) << sales[i][j] << " |";
                rowTotal += sales[i][j];
                colTotal[j] += sales[i][j];
            }

            cout << " " << setw(7) << rowTotal << " |\n";
            grandTotal += rowTotal;
        }

        cout << string(60, '-') << endl;

        cout << "| Tot  |";
        for (int j = 0; j < SALESPEOPLE; j++) {
            cout << " " << setw(6) << colTotal[j] << " |";
        }
        cout << " " << setw(7) << grandTotal << " |\n";
        cout << string(60, '-') << endl;

        cout << "\nRun sales summary again? (Y/N): ";
        cin >> repeatChoice;

    } while (toupper(repeatChoice) == 'Y');

    return 0;
}

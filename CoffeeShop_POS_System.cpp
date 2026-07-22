/**
 * ============================================================================
 * Problem / Program: Coffee Shop POS System
 * Description: Interactive point-of-sale ordering menu for a coffee shop. Allows users to order drinks/snacks and calculates total cost with receipts.
 * ============================================================================
 */

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char menuChoice;
    char itemChoice;
    int quantity = 0;

    // Price list definition
    const int PRICE_AMERICANO = 120;
    const int PRICE_OREO = 140;
    const int PRICE_COOKIES = 99;
    const int PRICE_BURGER = 65;

    cout << "========================================" << endl;
    cout << "       WELCOME TO BEANLEAF STORE        " << endl;
    cout << "========================================" << endl;
    cout << "Would you like to see our menu? (Y/N): ";
    cin >> menuChoice;

    if (toupper(menuChoice) == 'Y') {
        cout << "\n---------------- MENU ----------------" << endl;
        cout << "DRINKS:" << endl;
        cout << "  A. Oreo Cheesecake  - P" << PRICE_OREO << endl;
        cout << "  B. Americano        - P" << PRICE_AMERICANO << endl;
        cout << "\nSNACKS:" << endl;
        cout << "  C. Cookies          - P" << PRICE_COOKIES << endl;
        cout << "  D. Burgers          - P" << PRICE_BURGER << endl;
        cout << "--------------------------------------" << endl;

        cout << "\nWhat would you like to order? (A/B/C/D): ";
        cin >> itemChoice;

        switch (toupper(itemChoice)) {
            case 'A':
                cout << "How many orders of Oreo Cheesecake? ";
                cin >> quantity;
                cout << "TOTAL AMOUNT: P" << (PRICE_OREO * quantity) << endl;
                break;
            case 'B':
                cout << "How many orders of Americano? ";
                cin >> quantity;
                cout << "TOTAL AMOUNT: P" << (PRICE_AMERICANO * quantity) << endl;
                break;
            case 'C':
                cout << "How many orders of Cookies? ";
                cin >> quantity;
                cout << "TOTAL AMOUNT: P" << (PRICE_COOKIES * quantity) << endl;
                break;
            case 'D':
                cout << "How many orders of Burgers? ";
                cin >> quantity;
                cout << "TOTAL AMOUNT: P" << (PRICE_BURGER * quantity) << endl;
                break;
            default:
                cout << "Invalid item selection!" << endl;
                break;
        }
    } else {
        cout << "Thank you for visiting Beanleaf Store!" << endl;
    }

    return 0;
}

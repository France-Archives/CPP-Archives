/**
 * ============================================================================
 * Problem / Program: ATM Currency Denomination Breakdown
 * Description: Cash withdrawal breakdown calculator determining exact counts of bills/notes needed for any monetary withdrawal amount.
 * ============================================================================
 */

#include <iostream>

using namespace std;

int main() {
    int amount;

    cout << "=== ATM CURRENCY DENOMINATION BREAKDOWN ===" << endl;
    cout << "Enter amount to breakdown (PHP/USD): ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid monetary amount entered!" << endl;
        return 1;
    }

    int denominations[] = {1000, 500, 200, 100, 50, 20, 10, 5, 1};
    int numDenominations = sizeof(denominations) / sizeof(denominations[0]);

    cout << "\nCurrency Breakdown for $" << amount << ":" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < numDenominations; i++) {
        int count = amount / denominations[i];
        if (count > 0) {
            cout << "$" << denominations[i] << " bills/coins : " << count << endl;
            amount %= denominations[i];
        }
    }

    return 0;
}

/**
 * ============================================================================
 * Problem / Program: Simple Array Printer & Traversal
 * Description: Basic array initialization and loop traversal program printing element values and index positions.
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int count;
    cout << "=== SIMPLE ARRAY INPUT & PRINT ===" << endl;
    cout << "How many numbers to input? ";
    cin >> count;

    if (count <= 0) {
        cout << "Invalid count specified!" << endl;
        return 1;
    }

    vector<int> numbers(count);
    for (int i = 0; i < count; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << "\nOutput Numbers List:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Index " << i << " : " << numbers[i] << endl;
    }

    return 0;
}

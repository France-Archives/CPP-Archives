/**
 * ============================================================================
 * Problem / Program: Right-Triangle Star Pattern Generator
 * Description: Nested loop pattern generator rendering an ascending right-angled triangle pattern of stars.
 * ============================================================================
 */

#include <iostream>

using namespace std;

int main() {
    int triangleHeight;

    cout << "=== RIGHT TRIANGLE STAR GENERATOR ===" << endl;
    cout << "Enter height of triangle: ";
    cin >> triangleHeight;

    if (triangleHeight <= 0) {
        cout << "Invalid height!" << endl;
        return 1;
    }

    for (int i = 1; i <= triangleHeight; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}

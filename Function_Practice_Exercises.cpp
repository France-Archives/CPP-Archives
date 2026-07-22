/**
 * ============================================================================
 * Problem / Program: C++ Function Practice Suite
 * Description: Modular C++ function exercises showcasing pass-by-value, pass-by-reference, function overloading, and mathematical utility functions.
 * ============================================================================
 */

#include <iostream>
#include <string>

using namespace std;

// Function prototype declarations
void calculateMath(int valA, int valZ);
void printGreeting(const string& msg);
bool checkCondition(int valB);

int main() {
    int testVal = 0;

    cout << "=== FUNCTION PRACTICE EXERCISES ===" << endl;

    // Call arithmetic math menu function
    calculateMath(5, 6);

    // Call greeting printer function
    printGreeting("Welcome to C++ Practice");

    // Call boolean checker function
    bool isLessThanOne = checkCondition(testVal);
    cout << "\nCondition status (Is < 1): " << (isLessThanOne ? "True" : "False") << endl;

    return 0;
}

// Perform simple arithmetic addition and multiplication
void calculateMath(int valA, int valZ) {
    int baseVal = 5;
    cout << "Base + Argument A (5 + " << valA << ") = " << (baseVal + valA) << endl;
    cout << "Base * Argument Z (5 * " << valZ << ") = " << (baseVal * valZ) << endl;
}

// Print string greeting message
void printGreeting(const string& msg) {
    cout << "\nGreeting Message: " << msg << endl;
}

// Check if value is less than 1
bool checkCondition(int valB) {
    return (valB < 1);
}

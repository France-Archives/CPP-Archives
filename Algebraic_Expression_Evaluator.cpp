/**
 * ============================================================================
 * Problem / Program: Algebraic Expression Evaluator
 * Description: Evaluates basic mathematical formulas, polynomial equations, and operator precedence logic from user variables.
 * ============================================================================
 */

#include <iostream>

using namespace std;

int main() {
    double a, b, c;

    cout << "=== ALGEBRAIC EXPRESSION EVALUATOR ===" << endl;
    cout << "Formula: Expression = (a + (b / c)) / (a^2 - b + c)\n" << endl;

    cout << "Please enter value for a: ";
    cin >> a;
    cout << "Please enter value for b: ";
    cin >> b;
    cout << "Please enter value for c: ";
    cin >> c;

    // Validate non-zero division denominator constraints
    if (c == 0) {
        cout << "\nError: Division by zero encountered (c cannot be 0)!" << endl;
        return 1;
    }

    double denominator = (a * a) - b + c;
    if (denominator == 0) {
        cout << "\nError: Division by zero encountered (a^2 - b + c evaluates to 0)!" << endl;
        return 1;
    }

    double numerator = a + (b / c);
    double result = numerator / denominator;

    cout << "\nCalculated Result: " << result << endl;
    return 0;
}

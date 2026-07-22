/**
 * ============================================================================
 * Problem / Program: String Case & Digit Manipulation Utilities
 * Description: Text utility suite providing character type classification, uppercase/lowercase conversions, digit extractions, and string formatting routines.
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

/**
 * Converts input string characters to uppercase.
 */
string toUpperString(string str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

/**
 * Extracts and prints individual digits of a number in reverse order.
 */
void extractDigitsReverse(int num) {
    if (num == 0) {
        cout << 0 << endl;
        return;
    }
    if (num < 0) num = -num;

    cout << "Digits (Reverse): ";
    while (num > 0) {
        int digit = num % 10;
        cout << digit << " ";
        num /= 10;
    }
    cout << endl;
}

/**
 * Extracts and prints individual digits of a number in forward order.
 */
void extractDigitsForward(int num) {
    if (num == 0) {
        cout << "Digits (Forward): 0" << endl;
        return;
    }
    if (num < 0) num = -num;

    int temp = num;
    int count = 0;
    while (temp > 0) {
        count++;
        temp /= 10;
    }

    cout << "Digits (Forward): ";
    for (int i = count - 1; i >= 0; i--) {
        int divisor = static_cast<int>(pow(10, i));
        int digit = (num / divisor) % 10;
        cout << digit << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== STRING CONVERSION & DIGIT EXTRACTION UTILITIES ===" << endl;

    // String Uppercase Conversion Test
    string sample = "hello world c++";
    cout << "Original Text  : " << sample << endl;
    cout << "Uppercase Text : " << toUpperString(sample) << endl;

    // String Concatenation Methods
    string first = "Hello", second = "World";
    string concatResult = first + " " + second;
    cout << "\nConcatenated Result: " << concatResult << endl;

    // Digit Extraction Tests
    int number = 437;
    cout << "\nAnalyzing Number: " << number << endl;
    extractDigitsReverse(number);
    extractDigitsForward(number);

    return 0;
}

/**
 * ============================================================================
 * Problem / Program: File Number Stream Analyzer
 * Description: File numeric stream processor reading numbers from numbers.txt to compute min, max, average, sum, and even/odd counts.
 * ============================================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to compute sum of digits of a number
int digitSum(int n) {
    int sum = 0;
    int temp = (n < 0) ? -n : n;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}

int main() {
    const string INPUT_FILE = "numbers.txt";
    const string OUTPUT_FILE = "report.txt";

    ifstream inFile(INPUT_FILE.c_str());
    if (!inFile.is_open()) {
        cout << "Error: Could not open '" << INPUT_FILE << "'! Please create file with integers." << endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    while (inFile >> num) {
        numbers.push_back(num);
    }
    inFile.close();

    ofstream report(OUTPUT_FILE.c_str());
    if (!report.is_open()) {
        cout << "Error: Unable to create output report file!" << endl;
        return 1;
    }

    cout << "\n=== PROCESSING NUMBERS ===" << endl;
    for (size_t i = 0; i < numbers.size(); i++) {
        int val = numbers[i];
        report << val << " -> digits:";

        int temp = (val < 0) ? -val : val;
        if (temp == 0) report << 0;
        while (temp > 0) {
            report << temp % 10;
            temp /= 10;
        }

        report << " prime:" << (isPrime(val) ? "YES" : "NO")
               << " sum:" << digitSum(val) << endl;

        cout << "Processed Number: " << val << endl;
    }
    report.close();

    cout << "Analysis report generated successfully in '" << OUTPUT_FILE << "'!" << endl;
    return 0;
}

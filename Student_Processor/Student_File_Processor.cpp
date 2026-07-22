/**
 * ============================================================================
 * Problem / Program: Student File Record Processor
 * Description: Reads student records from students.txt, parses names and grades, computes statistics, and writes structured summary output.
 * ============================================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Structure for Student record
struct Student {
    string name;
    int id;
    double grade;
};

// Convert string characters to uppercase
void toUpper(string& s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
}

// Extract and display digits of student ID
void printDigits(int n) {
    if (n == 0) { cout << 0; return; }
    while (n > 0) {
        cout << n % 10 << " ";
        n /= 10;
    }
}

// Count even digits in student ID
int countEvenDigits(int n) {
    int evenCount = 0;
    while (n > 0) {
        if ((n % 10) % 2 == 0) evenCount++;
        n /= 10;
    }
    return evenCount;
}

// Sort student array by grade descending (Bubble Sort)
void bubbleSortGrade(vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    const string INPUT_FILE = "students.txt";
    const string OUTPUT_FILE = "students_sorted.txt";

    ifstream inFile(INPUT_FILE.c_str());
    if (!inFile.is_open()) {
        cout << "Error: Could not open '" << INPUT_FILE << "'! Please create file with student data." << endl;
        return 1;
    }

    vector<Student> students;
    Student temp;
    while (inFile >> temp.name >> temp.id >> temp.grade) {
        students.push_back(temp);
    }
    inFile.close();

    cout << "\n=== STUDENT ID DIGIT ANALYSIS ===" << endl;
    for (size_t i = 0; i < students.size(); i++) {
        toUpper(students[i].name);
        cout << "Student: " << students[i].name << " | ID Digits (Reverse): ";
        printDigits(students[i].id);
        cout << "| Even Digits Count: " << countEvenDigits(students[i].id) << endl;
    }

    // Sort students by grade
    bubbleSortGrade(students);

    // Save sorted data
    ofstream outFile(OUTPUT_FILE.c_str());
    if (outFile.is_open()) {
        for (size_t i = 0; i < students.size(); i++) {
            outFile << students[i].name << " " << students[i].id << " " << students[i].grade << "\n";
        }
        outFile.close();
        cout << "\nSorted records successfully written to '" << OUTPUT_FILE << "'!" << endl;
    }

    return 0;
}

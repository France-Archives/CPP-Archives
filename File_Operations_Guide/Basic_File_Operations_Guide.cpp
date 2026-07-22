/**
 * ============================================================================
 * Problem / Program: C++ File Stream Cheatsheet & Guide
 * Description: Demonstrates core C++ file handling (fstream, ifstream, ofstream), vectors, structs, and file persistence using data.txt.
 * ============================================================================
 */



#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Structure definition for Student record
struct Student {
    string name;
    int id;
    float grade;
};

// Writes student vector records to file
void saveStudents(const vector<Student>& students, const string& filename) {
    ofstream file(filename.c_str());
    if (file.is_open()) {
        for (const auto& s : students) {
            file << s.name << " " << s.id << " " << s.grade << "\n";
        }
        file.close();
    }
}

// Reads student records from file into vector
void loadStudents(vector<Student>& students, const string& filename) {
    ifstream file(filename.c_str());
    Student temp;
    if (file.is_open()) {
        while (file >> temp.name >> temp.id >> temp.grade) {
            students.push_back(temp);
        }
        file.close();
    }
}

int main() {
    cout << "=== C++ FILE OPERATIONS & POINTER CHEATSHEET ===" << endl;

    // 1. WRITING TO FILE
    ofstream outFile("data.txt");
    if (outFile.is_open()) {
        outFile << "Hello World\n";
        outFile << 123 << endl;
        outFile.close();
        cout << "1. Sample text written to data.txt successfully." << endl;
    }

    // 2. READING FROM FILE
    ifstream inFile("data.txt");
    string line;
    if (inFile.is_open()) {
        cout << "\n2. Reading contents from data.txt:" << endl;
        while (getline(inFile, line)) {
            cout << "   " << line << endl;
        }
        inFile.close();
    }

    // 3. VECTOR DEMONSTRATION
    vector<int> scores;
    scores.push_back(95);
    scores.push_back(88);
    scores.push_back(92);

    cout << "\n3. Vector scores iteration:" << endl;
    for (size_t i = 0; i < scores.size(); i++) {
        cout << "   Score " << i + 1 << ": " << scores[i] << endl;
    }

    // 4. DYNAMIC POINTER MEMORY ALLOCATION
    cout << "\n4. Dynamic memory allocation example:" << endl;
    Student* sPtr = new Student;
    sPtr->name = "Jane";
    sPtr->id = 101;
    sPtr->grade = 3.9f;

    cout << "   Student Name: " << sPtr->name << " | Grade: " << sPtr->grade << endl;
    delete sPtr; // Deallocate dynamic memory

    return 0;
}

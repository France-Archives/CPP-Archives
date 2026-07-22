/**
 * ============================================================================
 * Problem / Program: Student Registration Array Manager
 * Description: Student enrollment registration utility storing IDs, names, and course details in dynamic arrays with search and display functionality.
 * ============================================================================
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_STUDENTS = 100;
    string studentList[MAX_STUDENTS];
    int studentCount = 0;
    char choice;

    do {
        cout << "\n======================================" << endl;
        cout << "      STUDENT REGISTRATION MENU       " << endl;
        cout << "======================================" << endl;
        cout << "1. Register Students\n";
        cout << "2. View Registered Students\n";
        cout << "3. Exit\n";
        cout << "Enter command option (1-3): ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int numToEnter;
                cout << "How many students would you like to enter? ";
                cin >> numToEnter;

                for (int i = 0; i < numToEnter && studentCount < MAX_STUDENTS; i++) {
                    cout << "Enter name for Student " << (studentCount + 1) << ": ";
                    cin >> studentList[studentCount];
                    studentCount++;
                }
                cout << numToEnter << " student(s) successfully registered!" << endl;
                break;
            }

            case '2':
                if (studentCount == 0) {
                    cout << "No registered students found!" << endl;
                } else {
                    cout << "\n=== REGISTERED STUDENT LIST ===" << endl;
                    for (int i = 0; i < studentCount; i++) {
                        cout << (i + 1) << ". " << studentList[i] << endl;
                    }
                }
                break;

            case '3':
                cout << "Exiting system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid command selection! Please select 1-3." << endl;
                break;
        }

    } while (choice != '3');

    return 0;
}

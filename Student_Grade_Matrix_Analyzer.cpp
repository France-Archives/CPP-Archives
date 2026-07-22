/**
 * ============================================================================
 * Problem / Program: Student Grade Matrix Analyzer
 * Description: 2D matrix analyzer for student exam marks across multiple subjects, calculating subject averages, highest/lowest scores, and student rankings.
 * ============================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Display the matrix of grades along with student averages and highest grade.
 * @param grades  Pointer to 2D vector storing student grades
 * @param rows    Number of students
 * @param columns Number of subjects
 */
void displayMatrix(const vector<vector<int>>* grades, int rows, int columns) {
    cout << "\n================== GRADE MATRIX ==================\n";
    cout << "\t";
    for (int i = 0; i < columns; i++) {
        cout << "SUB" << i + 1 << "\t";
    }
    cout << "AVERAGE\n";

    for (int i = 0; i < rows; i++) {
        cout << "S" << i + 1 << "\t";
        int sum = 0;
        for (int j = 0; j < columns; j++) {
            int grade = (*grades)[i][j];
            cout << grade << "\t";
            sum += grade;
        }
        double avg = static_cast<double>(sum) / columns;
        cout << avg << '\n';
    }

    int highestGrade = (*grades)[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int grade = (*grades)[i][j];
            if (grade > highestGrade) {
                highestGrade = grade;
            }
        }
    }
    cout << "\nHIGHEST GRADE IN CLASS: " << highestGrade << endl;
}

/**
 * Prompt user to input grades for each student and subject.
 * @param grades  Pointer to 2D vector storing student grades
 * @param rows    Number of students
 * @param columns Number of subjects
 */
void inputMatrix(vector<vector<int>>* grades, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        cout << "Enter grades for Student " << i + 1 << ":" << endl;
        for (int j = 0; j < columns; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> (*grades)[i][j];
        }
        cout << endl;
    }
}

int main() {
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of subjects: ";
    cin >> subjects;

    if (students <= 0 || subjects <= 0) {
        cout << "Invalid input dimensions!" << endl;
        return 1;
    }

    // Dynamic 2D vector representation
    vector<vector<int>> grades(students, vector<int>(subjects));

    // Input & Display matrix using pointers to 2D vector
    inputMatrix(&grades, students, subjects);
    displayMatrix(&grades, students, subjects);

    return 0;
}

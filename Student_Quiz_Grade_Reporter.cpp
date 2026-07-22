/**
 * ============================================================================
 * Problem / Program: Student Quiz Grade Reporter
 * Description: Quiz score recorder generating student grade summaries, computing class pass percentages, and highlighting top performers.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    char repeatChoice;

    do {
        int students, quizzes;
        cout << "\nEnter number of students: ";
        cin >> students;
        cout << "Enter number of quizzes : ";
        cin >> quizzes;

        if (students <= 0 || quizzes <= 0) {
            cout << "Invalid student/quiz dimensions!" << endl;
            continue;
        }

        vector<vector<double>> scores(students, vector<double>(quizzes));
        vector<double> averages(students, 0.0);

        for (int i = 0; i < students; i++) {
            cout << "\nEnter scores for Student " << i + 1 << " (" << quizzes << " quizzes):\n";
            double sum = 0;
            for (int j = 0; j < quizzes; j++) {
                cout << "  Quiz " << (j + 1) << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }
            averages[i] = sum / quizzes;
        }

        // Header Border
        cout << endl << string(quizzes * 9 + 18, '-') << endl;

        // Table Header
        cout << "| Stud |";
        for (int q = 0; q < quizzes; q++) {
            cout << " Q" << setw(2) << (q + 1) << "    |";
        }
        cout << " Avg    |\n";

        cout << string(quizzes * 9 + 18, '-') << endl;

        // Table Rows
        for (int i = 0; i < students; i++) {
            cout << "| " << setw(4) << (i + 1) << " |";
            for (int j = 0; j < quizzes; j++) {
                cout << " " << setw(6) << scores[i][j] << " |";
            }
            cout << " " << setw(6) << fixed << setprecision(2) << averages[i] << " |\n";
        }

        cout << string(quizzes * 9 + 18, '-') << endl;

        cout << "\nRun program again? (Y/N): ";
        cin >> repeatChoice;

    } while (toupper(repeatChoice) == 'Y');

    return 0;
}

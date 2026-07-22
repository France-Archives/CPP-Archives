/**
 * ============================================================================
 * Problem / Program: Matrix Majority Element Finder
 * Description: Algorithms for 2D array analysis, identifying majority elements, row/column sums, and matrix frequency distributions.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    char repeatChoice;

    do {
        int rows, cols;
        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows <= 0 || cols <= 0) {
            cout << "Invalid matrix dimensions!" << endl;
            continue;
        }

        // Declare 2D vector matrix
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));

        cout << "Enter elements of the " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }

        // Display entered matrix
        cout << "\n=== ENTERED MATRIX ===" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }

        // Search for majority element (> total / 2)
        int majorityElement = -1;
        bool majorityFound = false;
        int totalElements = rows * cols;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int matchCount = 0;
                for (int r = 0; r < rows; r++) {
                    for (int c = 0; c < cols; c++) {
                        if (matrix[r][c] == matrix[i][j]) {
                            matchCount++;
                        }
                    }
                }
                if (matchCount > (totalElements / 2)) {
                    majorityElement = matrix[i][j];
                    majorityFound = true;
                    break;
                }
            }
            if (majorityFound) break;
        }

        if (majorityFound) {
            cout << "\nMajority Element Found: " << majorityElement << endl;
        } else {
            cout << "\nNo Majority Element Found (No element appears > " << (totalElements / 2) << " times)." << endl;
        }

        cout << "\nRepeat for another matrix? (Y/N): ";
        cin >> repeatChoice;

    } while (toupper(repeatChoice) == 'Y');

    return 0;
}

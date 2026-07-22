/**
 * ============================================================================
 * Problem / Program: Cinema Seat Reservation System
 * Description: Interactive 2D seating grid (5 Rows x 10 Columns) reservation manager for cinemas. Tracks available seats, reserved seats, and cinema capacity statistics.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Display full 2D seating layout map
void displaySeatLayout(const vector<vector<int>>& cinema, int rows, int cols) {
    char rowLabels[5] = {'A', 'B', 'C', 'D', 'E'};
    cout << "\n      ";
    for (int j = 0; j < cols; j++) {
        cout << setw(3) << j + 1 << " ";
    }
    cout << "\n     " << string(cols * 4 + 1, '_') << endl;

    for (int i = 0; i < rows; i++) {
        cout << "  " << rowLabels[i] << " | ";
        for (int j = 0; j < cols; j++) {
            if (cinema[i][j] == 0) {
                cout << " .  "; // Available seat
            } else {
                cout << " X  "; // Reserved seat
            }
        }
        cout << endl;
    }
    cout << "     Legend: [ . = Available ] [ X = Reserved ]\n" << endl;
}

int main() {
    const int rows = 5;
    const int cols = 10;
    char rowLabels[5] = {'A', 'B', 'C', 'D', 'E'};

    // 2D Vector representing cinema seats (0 = Available, 1 = Reserved)
    vector<vector<int>> cinema(rows, vector<int>(cols, 0));

    int choice;

    do {
        cout << "========================================" << endl;
        cout << "       MOVIE RESERVATION SYSTEM         " << endl;
        cout << "========================================" << endl;
        cout << "1. View Cinema Seat Layout\n";
        cout << "2. Reserve a Seat\n";
        cout << "3. Reset All Seating\n";
        cout << "4. Show Reservation Statistics\n";
        cout << "5. Exit\n";
        cout << "========================================" << endl;
        cout << "Enter Choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeatLayout(cinema, rows, cols);
                break;

            case 2: {
                displaySeatLayout(cinema, rows, cols);
                int rInput, cInput;
                cout << "Select Row Index (0 for A, 1 for B, 2 for C, 3 for D, 4 for E): ";
                cin >> rInput;
                cout << "Select Column Index (0-9 for Seat 1-10): ";
                cin >> cInput;

                if (rInput < 0 || rInput >= rows || cInput < 0 || cInput >= cols) {
                    cout << "\nError: Invalid seat coordinate selected!" << endl;
                } else if (cinema[rInput][cInput] == 1) {
                    cout << "\nNotice: Seat " << rowLabels[rInput] << (cInput + 1)
                         << " is already reserved!" << endl;
                } else {
                    cinema[rInput][cInput] = 1;
                    cout << "\nSuccess: Seat " << rowLabels[rInput] << (cInput + 1)
                         << " reserved successfully!" << endl;
                }
                break;
            }

            case 3:
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        cinema[i][j] = 0;
                    }
                }
                cout << "\nSystem Reset: All seats have been cleared and marked available!\n";
                break;

            case 4: {
                int reservedCount = 0;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (cinema[i][j] == 1) reservedCount++;
                    }
                }
                int totalSeats = rows * cols;
                int availableSeats = totalSeats - reservedCount;

                cout << "\n=== CINEMA RESERVATION STATISTICS ===\n";
                cout << "Total Seats    : " << totalSeats << endl;
                cout << "Reserved Seats : " << reservedCount << endl;
                cout << "Available Seats: " << availableSeats << endl;
                cout << "Occupancy Rate : " << (static_cast<double>(reservedCount) / totalSeats * 100.0) << "%\n";
                break;
            }

            case 5:
                cout << "\nThank you for using Movie Reservation System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please select an option between 1 and 5.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}

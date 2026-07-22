/**
 * ============================================================================
 * Problem / Program: Simple Name File Manager
 * Description: File handling practice program appending, reading, and displaying user names from name.txt.
 * ============================================================================
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void manageNameFile() {
    string name;
    cout << "What is your name? ";
    cin >> name;

    // Append entered name to file
    fstream nameAcc("name.txt", ios::out | ios::app);
    if (nameAcc.is_open()) {
        nameAcc << name << "\n";
        nameAcc.close();
        cout << "Name successfully saved to file!" << endl;
    }

    string enteredname;
    cout << "Enter name to search in records: ";
    cin >> enteredname;

    // Open file in read mode
    ifstream readAcc("name.txt");
    string storedName;
    bool found = false;

    if (readAcc.is_open()) {
        while (readAcc >> storedName) {
            if (storedName == enteredname) {
                found = true;
                break;
            }
        }
        readAcc.close();
    }

    if (found) {
        cout << "Search Result: Match Found (True)" << endl;
    } else {
        cout << "Search Result: Name Not Found (False)" << endl;
    }
}

int main() {
    manageNameFile();
    return 0;
}

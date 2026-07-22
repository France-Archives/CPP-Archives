/**
 * ============================================================================
 * Problem / Program: Book Rating System
 * Description: Book evaluation and rating recorder with score collection, weighted averages, statistical reporting, and catalog management.
 * ============================================================================
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

using namespace std;

// Structure representing a Book entity
struct Book {
    string barcode;
    string title;
    int year;
    int rating;
};

/**
 * Returns textual rating category string based on numeric rating (0-5)
 */
string getRatingCategory(int rating) {
    switch (rating) {
        case 0: return "No Rating";
        case 1: return "Poor";
        case 2: return "Fair";
        case 3: return "Good";
        case 4: return "Very Good!";
        case 5: return "Excellent!";
        default: return "Unknown";
    }
}

int main() {
    char repeatChoice;

    do {
        int numBooks = 0;
        cout << "\nInput number of books to rate: ";
        cin >> numBooks;

        if (numBooks <= 0) {
            cout << "Invalid number of books!" << endl;
            continue;
        }

        vector<Book> books(numBooks);

        for (int i = 0; i < numBooks; ++i) {
            string code;
            cout << "\n--- Book " << i + 1 << " Details ---\n";

            // Enforce unique barcode input
            bool isDuplicate;
            do {
                isDuplicate = false;
                cout << "Book's Barcode: ";
                cin >> ws;
                getline(cin, code);

                for (int j = 0; j < i; ++j) {
                    if (books[j].barcode == code) {
                        isDuplicate = true;
                        cout << "Error: Barcode already exists. Please enter a unique barcode.\n";
                        break;
                    }
                }
            } while (isDuplicate);

            books[i].barcode = code;

            cout << "Book's Title: ";
            getline(cin >> ws, books[i].title);

            cout << "Year Published: ";
            cin >> books[i].year;

            // Enforce rating bounds [0 - 5]
            int rate;
            do {
                cout << "Book's Rating (0-5): ";
                cin >> rate;

                if (rate < 0 || rate > 5) {
                    cout << "Invalid rating! Rating must be between 0 and 5.\n";
                }
            } while (rate < 0 || rate > 5);

            books[i].rating = rate;
        }

        // Display summary catalog table
        cout << endl << string(85, '-') << endl;
        cout << left << setw(17) << "Barcode"
             << setw(40) << "Title"
             << setw(8) << "Year"
             << setw(8) << "Rating"
             << setw(12) << "Category" << endl;
        cout << string(85, '-') << endl;

        for (int i = 0; i < numBooks; ++i) {
            cout << left << setw(17) << books[i].barcode
                 << setw(40) << books[i].title
                 << setw(8) << books[i].year
                 << setw(8) << books[i].rating
                 << setw(12) << getRatingCategory(books[i].rating) << endl;
        }

        cout << string(85, '-') << endl;

        cout << "\nDo you want to repeat for another set? (Y/N): ";
        cin >> repeatChoice;

    } while (toupper(repeatChoice) == 'Y');

    cout << "Thank you for using the Book Rating System!" << endl;
    return 0;
}

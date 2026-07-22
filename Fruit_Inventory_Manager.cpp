/**
 * ============================================================================
 * Problem / Program: Fruit Inventory Manager
 * Description: Interactive inventory management system for fruit stock, handling fruit records, price calculations, and availability updates.
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure for Fruit Inventory Item
struct Fruit {
    string code;
    string name;
    double price;
    int quantity;
};

// Check if fruit code already exists in vector inventory
bool isFruitExist(const vector<Fruit>& fruits, const string& code) {
    for (const auto& f : fruits) {
        if (f.code == code) return true;
    }
    return false;
}

// Search index of fruit by code (-1 if not found)
int searchFruit(const vector<Fruit>& fruits, const string& code) {
    for (size_t i = 0; i < fruits.size(); i++) {
        if (fruits[i].code == code) return static_cast<int>(i);
    }
    return -1;
}

// Add new fruit entry
void addFruit(vector<Fruit>& fruits) {
    string c, n;
    double p;
    int q;

    do {
        cout << "\nEnter Fruit Code: ";
        cin >> c;
        if (isFruitExist(fruits, c)) {
            cout << "Code already exists. Try again!\n";
        }
    } while (isFruitExist(fruits, c));

    cout << "Enter Name    : ";
    cin >> n;
    cout << "Enter Price   : $";
    cin >> p;
    cout << "Enter Quantity: ";
    cin >> q;

    fruits.push_back({c, n, p, q});
    cout << "Fruit successfully added to inventory!" << endl;
}

// Edit existing fruit entry
void editFruit(vector<Fruit>& fruits) {
    string c;
    cout << "Enter fruit code to update: ";
    cin >> c;
    int index = searchFruit(fruits, c);

    if (index > -1) {
        cout << "Enter new name    : ";
        cin >> fruits[index].name;
        cout << "Enter new price   : $";
        cin >> fruits[index].price;
        cout << "Enter new quantity: ";
        cin >> fruits[index].quantity;
        cout << "Fruit entry updated successfully!" << endl;
    } else {
        cout << "Fruit code does not exist!" << endl;
    }
}

// Delete fruit entry from vector
void deleteFruit(vector<Fruit>& fruits) {
    string c;
    cout << "Enter fruit code to delete: ";
    cin >> c;
    int index = searchFruit(fruits, c);

    if (index > -1) {
        fruits.erase(fruits.begin() + index);
        cout << "Fruit entry deleted successfully!" << endl;
    } else {
        cout << "Fruit not found!" << endl;
    }
}

// Display formatted fruit inventory list
void viewFruits(const vector<Fruit>& fruits) {
    cout << "\n---------------- FRUIT INVENTORY ----------------\n";
    cout << left << setw(6) << "No."
         << setw(10) << "Code"
         << setw(18) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Quantity" << endl;
    cout << string(54, '-') << endl;

    if (fruits.empty()) {
        cout << "No fruits currently in inventory." << endl;
        return;
    }

    for (size_t i = 0; i < fruits.size(); i++) {
        cout << left << setw(6) << (i + 1)
             << setw(10) << fruits[i].code
             << setw(18) << fruits[i].name
             << "$" << setw(9) << fruits[i].price
             << setw(10) << fruits[i].quantity << endl;
    }
}

int main() {
    vector<Fruit> inventory;
    int choice;

    do {
        cout << "\n======================================" << endl;
        cout << "      FRUIT INVENTORY SYSTEM          " << endl;
        cout << "======================================" << endl;
        cout << "1. Add Fruit\n";
        cout << "2. Edit Fruit\n";
        cout << "3. Delete Fruit\n";
        cout << "4. View Inventory\n";
        cout << "5. Exit Program\n";
        cout << "Enter Choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: addFruit(inventory); break;
            case 2: editFruit(inventory); break;
            case 3: deleteFruit(inventory); break;
            case 4: viewFruits(inventory); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Please select 1-5.\n"; break;
        }

    } while (choice != 5);

    return 0;
}

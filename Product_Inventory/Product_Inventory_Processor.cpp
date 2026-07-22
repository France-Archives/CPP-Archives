/**
 * ============================================================================
 * Problem / Program: Product Inventory File Processor
 * Description: Inventory file stream manager reading product items from products.txt, updating stock levels, and generating pricing summary reports.
 * ============================================================================
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// Structure defining Product properties
struct Product {
    string name;
    int id;
    double price;
};

// Reads products from text file
vector<Product> readProducts(const string& filename) {
    vector<Product> products;
    ifstream file(filename.c_str());
    Product p;

    if (file.is_open()) {
        while (file >> p.name >> p.id >> p.price) {
            products.push_back(p);
        }
        file.close();
    }
    return products;
}

// Saves products to text file
void saveProducts(const vector<Product>& products, const string& filename) {
    ofstream file(filename.c_str());
    if (file.is_open()) {
        for (const auto& p : products) {
            file << p.name << " " << p.id << " " << p.price << "\n";
        }
        file.close();
    }
}

int main() {
    const string INPUT_FILE = "products.txt";
    const string OUTPUT_FILE = "products_upper.txt";

    vector<Product> inventory = readProducts(INPUT_FILE);

    if (inventory.empty()) {
        cout << "No products loaded or '" << INPUT_FILE << "' missing!" << endl;
        return 1;
    }

    // Convert product names to uppercase
    for (size_t i = 0; i < inventory.size(); i++) {
        for (char& c : inventory[i].name) {
            c = toupper(c);
        }
    }

    // Save modified uppercase inventory
    saveProducts(inventory, OUTPUT_FILE);
    cout << "Updated inventory written to '" << OUTPUT_FILE << "'." << endl;

    // Extract & display digits from Product IDs
    cout << "\n=== PRODUCT ID DIGIT EXTRACTION ===" << endl;
    for (const auto& p : inventory) {
        cout << "Product: " << p.name << " (ID: " << p.id << ") Digits: ";
        int num = p.id;
        if (num == 0) cout << 0;
        while (num > 0) {
            cout << (num % 10) << " ";
            num /= 10;
        }
        cout << endl;
    }

    return 0;
}

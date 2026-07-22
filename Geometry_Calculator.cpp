/**
 * ============================================================================
 * Problem / Program: Geometry & Area Calculator
 * Description: Mathematical shape calculation menu computing perimeter, area, and volume for 2D and 3D geometric shapes (circles, triangles, rectangles, spheres).
 * ============================================================================
 */

#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char option;
    double base, height, length, width;

    cout << "========================================" << endl;
    cout << "         GEOMETRY CALCULATOR MENU       " << endl;
    cout << "========================================" << endl;
    cout << "A. Compute Perimeter of Rectangle\n";
    cout << "B. Compute Area of Rectangle\n";
    cout << "C. Compute Area of Triangle\n";
    cout << "========================================" << endl;
    cout << "Enter option (A/B/C): ";
    cin >> option;

    switch (toupper(option)) {
        case 'A':
            cout << "Input Length: ";
            cin >> length;
            cout << "Input Width : ";
            cin >> width;
            if (length > 0 && width > 0) {
                double perimeter = 2 * (length + width);
                cout << "\nPerimeter of Rectangle: " << perimeter << endl;
            } else {
                cout << "Invalid dimension values!" << endl;
            }
            break;

        case 'B':
            cout << "Input Length: ";
            cin >> length;
            cout << "Input Width : ";
            cin >> width;
            if (length > 0 && width > 0) {
                double areaRectangle = length * width;
                cout << "\nArea of Rectangle: " << areaRectangle << endl;
            } else {
                cout << "Invalid dimension values!" << endl;
            }
            break;

        case 'C':
            cout << "Input Base  : ";
            cin >> base;
            cout << "Input Height: ";
            cin >> height;
            if (base > 0 && height > 0) {
                double areaTriangle = 0.5 * base * height;
                cout << "\nArea of Triangle: " << areaTriangle << endl;
            } else {
                cout << "Invalid dimension values!" << endl;
            }
            break;

        default:
            cout << "Invalid option selected! Please select A, B, or C." << endl;
            break;
    }

    return 0;
}

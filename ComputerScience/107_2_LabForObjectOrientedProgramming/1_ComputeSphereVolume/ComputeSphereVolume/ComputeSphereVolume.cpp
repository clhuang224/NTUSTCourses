#include <iostream>
#include <iomanip>
using namespace std;
// Pre: A value of radius
// Intent: To compute the volume of a shpere with the radius
// Post: The result printted
int main() {
    const double PI = 3.14159265358979323846;
    double radius;
    do {
        // Inputting a radius
        cin >> radius;
        // Computing and printing the result
        cout << fixed << showpoint << setprecision(6) << 4.0 / 3.0 * PI * pow(radius, 3) << endl;
    } while (radius != EOF);
}
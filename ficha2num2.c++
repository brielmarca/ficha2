#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int number = 2; // Start at 2 (first number after 1)

    while (number < 20) { // Stop before reaching 20
        if (number % 2 == 0) {
            count++;
        }
        number++;
    }

    cout << "There are " << count << " even numbers between 1 and 20 (excluding limits)." << endl;
    return 0;
}
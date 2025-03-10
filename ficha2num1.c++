#include <iostream>
using namespace std;

int main() {
    int arr[12];
    
    // Read 12 values from the user
    for(int i = 0; i < 12; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    // Initialize max and min with the first element
    int max = arr[0];
    int min = arr[0];
    
    // Iterate through the array to find max and min
    for(int i = 1; i < 12; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    
    // Output the results
    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;
    
    return 0;
}
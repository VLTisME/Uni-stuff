#include <iostream>  

using namespace std;


int findMode(int* arr, int n) {
    int maxCount = 0;
    int mode = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i; j < n; j++) {
            if (*(arr + i) == *(arr + j)) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = *(arr + i);
        }
        else if (count == maxCount) {
            mode = -1;
        }
    }
    return maxCount > 1 ? mode : -1;
}

int main() {
    int SIZE;
    cout << "Enter the number of elements: ";
    cin >> SIZE;

    int* arr = new int[SIZE];

    cout << "Enter the elements: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> *(arr + i);
    }
    int mode = findMode(arr, SIZE);

    if (mode != -1) {   
        cout << "The mode is: " << mode << '\n';
    }
    else {
        cout << "No mode found.\n";
    }

    // Deallocate the memory  
    delete[] arr;

    return 0;
}
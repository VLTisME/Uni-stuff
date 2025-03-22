#include <iostream>  
#include <algorithm> 

using namespace std;

double findMedian(int* arr, int n) {
    if (n % 2 == 0) {
        double mid1 = *(arr + n / 2 - 1);
        double mid2 = *(arr + n / 2);
        return (mid1 + mid2) / 2.0;
    }
    else {
        return *(arr + n / 2);
    }
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
    std::sort(arr, arr + SIZE);
    double median = findMedian(arr, SIZE);
    cout << "The median is: " << median << '\n';
    delete[] arr;

    return 0;
}
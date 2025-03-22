// #include <iostream>  
// #include <cstdlib>  

// using namespace std;

// int* createDoubledArray(int* originalArray, int size) {
//     int newSize = size * 2;
//     int* newArray = (int*)malloc(newSize * sizeof(int));
//     if (newArray == NULL) {
//         return NULL;
//     }
//     for (int i = 0; i < size; i++) {
//         newArray[i] = originalArray[i];
//     }
//     for (int i = size; i < newSize; i++) {
//         newArray[i] = 0;
//     }
//     return newArray;
// }

// int main() {
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;
//     cout << "Enter the elements of the array:\n";
//     int* originalArray = (int*)malloc(size * sizeof(int));
//     for (int i = 0; i < size; i++) {
//         cin >> originalArray[i];
//     }

//     int* newArray = createDoubledArray(originalArray, size);
//     if (newArray != NULL) {
//         for (int i = 0; i < size * 2; i++) {
//             cout << newArray[i] << " ";
//         }
//         cout << endl;
//         free(newArray);
//     }

//     free(originalArray);
//     return 0;
// }






















#include <iostream>

using namespace std;

int* func(int* head, int n){
     int* a = new int[2 * n];
     for (int i = 0; i < n; ++i) *(a + i) = *(head + i);
     for (int i = n; i < 2 * n; ++i) *(a + i) = 0;
     return a;
}

signed main(){
       int n;
       cin >> n;
       int* a = new int[n];

       for (int i = 0; i < n; ++i){
            cin >> *(a + i);
       }
       
       cout << "\nNew array:\n";
       int* head = func(a, n);
       for (int i = 0; i < 2 * n; ++i){
            cout << *(head + i) << " ";
       }

       delete[] a;
}
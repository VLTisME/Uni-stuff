//#include <iostream>  
//#include <iomanip>  
//using namespace std;  
//
//int main() {  
//    int n; // Number of monkeys  
//    cout << "Enter the number of monkeys: ";  
//    cin >> n;  
//
//    // Dynamic allocation of 2D array (n x 7)  
//    int **foodEaten = new int*[n];  
//    for (int i = 0; i < n; ++i) {  
//        foodEaten[i] = new int[7];  
//    }  
//
//    // Input food data  
//    for (int i = 0; i < n; ++i) {  
//        cout << "Enter food eaten for monkey " << (i + 1) << " for each day of the week:\n";  
//        for (int j = 0; j < 7; ++j) {  
//            do {  
//                cout << "Day " << (j + 1) << ": ";  
//                cin >> foodEaten[i][j];  
//                if (foodEaten[i][j] < 0) {  
//                    cout << "Please enter a non-negative number.\n";  
//                }  
//            } while (foodEaten[i][j] < 0);  
//        }  
//    }  
//
//    // Generate report  
//    cout << fixed << setprecision(2);  
//    cout << "\n--- Weekly Food Consumption Report ---\n";  
//    
//    double totalFood = 0.0;  
//    int totalDays = n * 7;  
//
//    // Variables for tracking least and greatest food eaten  
//    int leastFood = INT_MAX;  
//    int greatestFood = INT_MIN;  
//
//    for (int i = 0; i < n; ++i) {  
//        int weeklyTotal = 0;  
//        for (int j = 0; j < 7; ++j) {  
//            weeklyTotal += foodEaten[i][j];  
//        }  
//        totalFood += weeklyTotal;  
//
//        // Update least and greatest  
//        leastFood = min(leastFood, weeklyTotal);  
//        greatestFood = max(greatestFood, weeklyTotal);  
//    }  
//
//    double averageFood = totalFood / totalDays;  
//
//    cout << "Average amount of food eaten per day by the whole family of monkeys: "   
//         << averageFood << " pounds." << endl;  
//    cout << "Least amount of food eaten during the week by any one monkey: "   
//         << leastFood << " pounds." << endl;  
//    cout << "Greatest amount of food eaten during the week by any one monkey: "  
//         << greatestFood << " pounds." << endl;  
//
//    // Cleaning up the allocated memory  
//    for (int i = 0; i < n; ++i) {  
//        delete[] foodEaten[i];  
//    }  
//    delete[] foodEaten;  
//
//    return 0;  
//}


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int n, m;

signed main() {
    cin >> n >> m;
    int** a = new int*[n + 1];
    int** p = new int* [n + 1];
    for (int i = 0; i <= n; ++i) {
        *(a + i) = new int[m + 1];
		*(p + i) = new int[m + 1];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            //a[i][j] = 0;
            *(*(a + i) + j) = 0;
			*(*(p + i) + j) = 0;
            //&a[i][j] = *(a + i) + j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> *(*(a + i) + j);
			*(*(p + i) + j) += a[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    while (1) {
        cin >> n >> m;
        if (n == -1) break;
        cout << p[n][m] << " :D?\n";
    }
}
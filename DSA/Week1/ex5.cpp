#include <iostream>

using namespace std;

const int N = 1e6;

int n, a[N + 5];

// explain the solution: we can check if the array is sorted in ascending order by using recursion. We start with the first element of the array and at each step, we compare the current element with the next element. If the current element is less than or equal to the next element, we continue the process. Otherwise, we return false. We continue this process until we reach the last element of the array. If we reach the last element of the array, we return true.
// check if the array is sorted in descending order
bool isdes(int x){
    if (x == 1) return 1;
    if (a[x - 1] >= a[x]) return isdes(x - 1);
    return 0;
}

// check if the array is sorted in ascending order
bool isinc(int x){
    if (x == n) return 1;
    if (a[x] <= a[x + 1]) return isinc(x + 1);
    return 0;
}


signed main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);
   cin >> n;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   cout << (isdes(n) || isinc(1) ? "YES" : "NO");
}
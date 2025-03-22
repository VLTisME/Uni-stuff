#include <iostream>

using namespace std;

int n;

int F(int n){
   if (n <= 1) return 1;
   return n * F(n - 1);
}

signed main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);
   cin >> n;
   cout << F(n);
}
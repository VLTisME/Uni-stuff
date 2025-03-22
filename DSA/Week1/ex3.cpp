#include <iostream>

using namespace std;

int n;

// generate all binary strings of length n
// n: length of the binary string
// s: the current binary string
// explain the solution: we can generate all binary strings of length n by using recursion. We start with an empty string and at each step, we add a '0' or a '1' to the string. We continue this process until the length of the string is equal to n. When the length of the string is equal to n, we print the string.
void F(int n, string s){
    if (!n){
        cout << s << "\n";
        return;
    }
    F(n - 1, s + '0');
    F(n - 1, s + '1');
}

signed main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);
   cin >> n;
   F(n, "");
}
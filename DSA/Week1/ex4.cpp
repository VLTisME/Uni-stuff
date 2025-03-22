#include <iostream>

using namespace std;

int n;

// n: number of disks
// from: the rod where the disks are initially placed
// to: the rod where the disks should be moved to
// mid: the rod that is used as an auxiliary rod
// explain the solution: we can solve the Tower of Hanoi problem by using recursion. We can move n - 1 disks from the initial rod to the auxiliary rod, then move the last disk from the initial rod to the destination rod, and finally move the n - 1 disks from the auxiliary rod to the destination rod. We continue this process until all disks are moved to the destination rod.
void Hanoi(int n, char from, char to, char mid){
     if (n == 1){
        cout << "Move disk from " << from << " to " << to << "\n";
        return;
     }
     Hanoi(n - 1, from, mid, to);
     cout << "Move disk from " << from << " to " << to << "\n";
     Hanoi(n - 1, mid, to, from);
   }

signed main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);
   cin >> n; // number of disks
   Hanoi(n, 'A', 'B', 'C');
}
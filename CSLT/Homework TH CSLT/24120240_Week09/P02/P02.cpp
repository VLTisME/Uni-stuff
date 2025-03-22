#include <iostream>

using namespace std;

int doSomething(int* x, int* y) {
	int tmp = *x;
	*x = *y * 10;
	*y = tmp * 10;
	return *x + *y;
}

signed main() {
	int x, y;
	cout << "Enter two numbers: ";
	cin >> x >> y;
	cout << doSomething(&x, &y);
	return 0;
}
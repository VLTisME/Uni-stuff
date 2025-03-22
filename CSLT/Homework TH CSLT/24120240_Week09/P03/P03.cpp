#include <iostream>  
#include <cstring>  

using namespace std;

bool isPalindrome(char* cstr) {
    char* front = cstr;
    char* back = cstr + strlen(cstr) - 1;
    while (front < back) {
        if (*front != *back) {
            return false;
        }
        front++;
        back--;
    }
    return true;
}

int main() {
    const int MAX_LEN = 100;  
    char str[MAX_LEN];

    cout << "Enter a string: ";
    cin >> str;
    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    }
    else {
        cout << str << " is not a palindrome." << endl;
    }
    return 0;
}
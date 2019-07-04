#include<iostream>

using namespace std;

int fib(int n) {
    if (n != 0 && n != 1) {
        return fib(n - 1) + fib(n - 2);
    }
    else 
        return n;
}


int main() {
    int n = 5;
    for (int i = 0; i <= n; i++)
        cout << fib(i) << endl;

    return 0;
}

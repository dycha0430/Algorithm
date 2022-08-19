#include <iostream>
#include <memory.h>

using namespace std;

int fib(int);
int fibonacci(int);
int ans1, ans2;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    
    ans1 = ans2 = 0;
    fib(n);
    fibonacci(n);
    
    cout << ans1 << " " << ans2;
    return 0;
}

int fib(int n) {
    if (n == 1 || n == 2) {
        ans1++;
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int fibonacci(int n) {
    int f[40];
    memset(f, 0, sizeof(f));
    f[0] = f[1] = 1;
    for (int i = 2; i < n; i++) {
        ans2++;
        f[i] = f[i-1] + f[i-2];
    }
    return f[n-1];
}

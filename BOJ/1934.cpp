#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int T, A, B;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> A >> B;
        int gcd = 0;
        if (A > B) {
            int tmp = B;
            B = A;
            A = tmp;
        }
        
        int mul = A * B;
        while (A != 0) {
            int mod = B % A;
            B = A;
            A = mod;
        }
        cout << mul / B << endl;
    }
    return 0;
}

#include <iostream>
#include <math.h>
#include <string>

using namespace std;
typedef int ll;
string solve(ll n);

    int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    while (n != 0) {
        /* 2^t < n <= 2^(t+1) 인 t를 구하면
        n - 2^t 번째 집합에 3^t를 포함시켜주면됨 */
        string ret = solve(n);
        ret.pop_back();
        cout << "{ " << ret << " }" << endl;

        cin >> n;
    }
    return 0;
}

string solve(ll n) {
    if (n == 1) return "";
    int i = 0;
    ll tmp = 1;
    while (tmp < n) {
        tmp = pow(2, ++i);
    }
    i--;
    string ret = solve(n - pow(2, i)) + to_string(floor(pow(3, i))) + ", ";
    return ret;
}
/*
0
1
3
1 3
9
1 9
3 9
1 3 9
27
1 27
3 27
1 3 27
9 27
1 9 27
3 9 27
1 3 9 27
81
*/

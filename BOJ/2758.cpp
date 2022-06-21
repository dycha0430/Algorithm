#include <iostream>
#include <cmath>

using namespace std;

long long solve(int, int);
int n, m;
long long cache[2001][11];
int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int i = 0; i <= 2000; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            cache[i][j] = -1;
        }
    }
    for (int tc = 0; tc < T; tc++) {
        cin >> n >> m;
        cout << solve(m, n) << endl;
    }
    return 0;
}


long long solve(int total, int num) {
    if (num == 0) return 1;
    else if (total == 0) return 0;

    long long &ret = cache[total][num];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = total; i >= pow(2, num-1); i--) {
        ret += solve(i/2, num-1);
    }

    return ret;
}
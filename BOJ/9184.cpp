#include <iostream>

using namespace std;

long long w(int, int, int);
long long cache[101][101][101];
int main(int argc, char const *argv[])
{
    int a, b, c;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            for (int k = 0; k < 101; k++)
            {
                cache[i][j][k] = -1;
            }
        }
    }
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;

        printf("w(%d, %d, %d) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}

long long w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;

    long long& ret = cache[a][b][c];
    if (ret != -1) return ret;
    else if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    else if (a < b && b < c)  {
        return ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    } else {
        return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
}

#include <iostream>

using namespace std;

long long solve(long long, long long);
long long min(long long, long long);
int main(int argc, char const *argv[])
{
    long long N, k;
    cin >> N >> k;
    cout << solve(N, k);
    return 0;
}

long long min(long long a, long long b) {
    if (a < b) return a;
    else return b;
}

long long solve(long long N, long long k) {
    long long start = 1;
    long long end = N*N;
    long long mid = 0;
    long long find = -1;
    while (start <= end) {
        mid = (start + end) / 2;
        find = 0;
        long long same = 0;
        for (long long i = 1; i <= min(N, mid); i++) {
            long long q = mid / i;
            find += min(N, q);
            if (mid % i == 0 && q <= N) same++;
        }

        if (k > find - same && k <= find) return mid;
        else if (k <= find-same) end = mid-1;
        else start = mid+1;
    }

    return -1;
}

/*
1 2 3
2 4 6
3 6 9

1 2 3 4 5 6 7 8 9
1 2 2 3 3 4 6 6 9
*/
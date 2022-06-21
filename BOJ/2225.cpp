#include <iostream>

using namespace std;

int solve(int, int);
int cache[201][201];
int N;

int main(int argc, char const *argv[])
{
    int K;
    cin >> N >> K;

    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            cache[i][j] = -1;
        }
    }

    cout << solve(K, N) << endl;
    
    return 0;
}

// 0부터 N까지의 정수 K개를 더해서 합이 sum이 되는 경우의 수
int solve(int K, int sum) {
    if (sum < 0) return 0;
    if (K == 0) {
        if (sum == 0) return 1;
        else return 0;
    }
    
    int& ret = cache[K][sum];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i <= N; i++) {
        ret += solve(K-1, sum-i);
        ret %= 1000000000;
    }

    return ret;
}

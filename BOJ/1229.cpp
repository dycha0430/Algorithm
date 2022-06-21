#include <iostream>
#include <string.h>

using namespace std;

int getHexagonNums();
int solve(int, int);
int N;
int *answer, *hexagonNums;
int main(int argc, char const *argv[])
{
    cin >> N;
    answer = new int[N+1];
    hexagonNums = new int[N];
    memset(answer, -1, (N+1) * sizeof(int));

    getHexagonNums();
    cout << solve(N, 0) << endl;

    return 0;
}

int solve(int num, int depth) {
    if (num == 0) return 0;
    if (depth >= 6) return 6;

    int& ret = answer[num];
    if (ret != -1) return ret;
    ret = 6;
    int i = 0;
    while (hexagonNums[i] <= num) {
        ret = min(ret, 1 + solve(num - hexagonNums[i], depth + 1));
        i++;
    }

    return ret;
}

int getHexagonNums() {
    hexagonNums[0] = 1;
    int i = 1;
    while (hexagonNums[i-1] <= N) {
        hexagonNums[i] = hexagonNums[i-1] + i*4 + 1;
        i++;
    }

    return i;
}
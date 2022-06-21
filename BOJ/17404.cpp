#include <iostream>

using namespace std;

int solve(int, int);
int cost[1000][3];
int cache[1000][3];
int first, N;

int main(int argc, char const *argv[])
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
            cache[i][j] = -1;
        }
    }
    
    int answer = 1000001;
    for (first = 0; first < 3; first++) {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cache[i][j] = -1;
            }
        }
        answer = min(answer, cost[0][first] + solve(first, 1));
    }

    cout << answer << endl;

    return 0;
}

int solve(int before_color, int start) {
    int& ret = cache[start][before_color];
    if (ret != -1) return ret;
    if (start == N-1) {
        ret = 1001;
        for (int i = 0; i < 3; i++) {
            if (i != first && i != before_color) {
                ret = min(ret, cost[start][i]);
            }
        }
        return ret;
    }

    ret = 1000001;
    for (int i = 0; i < 3; i++) {
        if (i != before_color) {
            ret = min(ret, cost[start][i] + solve(i, start+1));
        }
    }

    return ret;
}
#include <iostream>

using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
    int N;
    ll answer;
    ll len[100000];
    ll cost[100000];
    cin >> N;
    for (int i = 0; i < N-1; i++) cin >> len[i];
    for (int i = 0; i < N; i++) cin >> cost[i];

    ll min_cost = cost[0];
    answer = 0;
    for (int i = 0; i < N-1; i++) {
        min_cost = min(min_cost, cost[i]);
        answer += min_cost * len[i];
    }

    cout << answer;
    return 0;
}

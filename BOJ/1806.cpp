#include <iostream>
#include <queue>
#include <functional>
#define MAX 100000
using namespace std;

int arr[MAX+1];

int solve(int N, int S) {
    int start = 0, end = 1;
    int answer = N+1;
    while (true) {
        while (end <= N && arr[end] - arr[start] < S) end++;
        if (end > N) break;
        while (arr[end] - arr[start] >= S) start++;
        start--;
        answer = min(answer, end - start);
        start++;
    }    

    return answer;
}

int main(void) {
    int N, S;
    arr[0] = 0;
    cin >> N >> S;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int answer = solve(N, S);
    if (answer == N+1) answer = 0;
    cout << answer << endl;
    
}